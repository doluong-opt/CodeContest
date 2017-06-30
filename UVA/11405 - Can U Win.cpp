/***********************************************
* Author LUONG VAN DO                        *
* Problem 11405 - Can U Win?
* Algorithm
* Time Limit
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 111222333
#define N 10

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct point{
    int x, y;
    point(){}
    point(int xx, int yy){
        x = xx; y = yy;
    }
};
char s[N][N];
int n, mark[N][N], f[N][N], dp[N][1<<N], lim, d[N][N], m;
point S, p[N];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int isOk(int u, int v) {
    return (u >= 0 && u < 8 && v >= 0 && v < 8);
}
int bfs(int x, int y) {
    rep(i, 8)
        rep(j, 8) d[i][j] = INF;
    d[x][y] = 0;
    queue <point> q; q.push(point(x, y));
    while ( !q.empty()) {
        point u = q.front(); q.pop();
        rep(i, 8) {
            int nx = u.x + dx[i];
            int ny = u.y + dy[i];
            if (!isOk(nx, ny) || mark[nx][ny]) continue;
            if (d[nx][ny] > d[u.x][u.y] + 1) {
                d[nx][ny] = d[u.x][u.y] + 1;
                q.push(point(nx, ny));
            }
        }
    }
}
int run(int cur, int mask) {
    if (mask == lim - 1) return 0;
    int &res = dp[cur][mask];
    if ( res != -1) return res;
    res = INF;
    for (int i = 1;i <= m;i++) {
        if (!cur) {
            int Cost = f[0][i] + run(i, Or(mask, i - 1));
            res = min(res, Cost);
        }
        else
        if ( !And(mask, i - 1) ){
            int Cost = f[cur][i] + run(i, Or(mask, i - 1));
            res = min(res, Cost);
        }
    }
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        scanf(" %d ", &n);
        rep(i, 8) gets(s[i]);
        fill(mark, 0); m = 0;
        fill(f, 0);
        rep(i, 8)
            rep(j, 8)
                if (s[i][j] == 'p') mark[i][j] = 1;
                else
                if (s[i][j] == 'K') mark[i][j] = 1;
                else
                if (s[i][j] == 'k') S = point(i, j);
                else
                if (s[i][j] == 'P') p[++m] = point(i, j);
        fr(i, 1, m) {
            bfs(p[i].x, p[i].y);
            fr(j, 1, m)
                f[i][j] = d[p[j].x][p[j].y];
        }
        bfs(S.x, S.y);
        fr(i, 1, m)
            f[0][i] = d[p[i].x][p[i].y];
        fill(dp, -1); lim = (1<<m);
        if ( run(0, 0) <= n ) puts("Yes");
        else puts("No");
    }
}

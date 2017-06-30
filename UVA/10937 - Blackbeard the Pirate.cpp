/***********************************************
* Author LUONG VAN DO                        *
* Problem 10937 - Blackbeard the Pirate 
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
#define N 15
#define M 55

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
int m, n, l, lim;
point p[N], S;
int dx[] = {0, 1, 0, -1, -1, 1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int mark[M][M], f[N][N], d[M][M], dp[N][1<<11];
char s[M][M];
bool isOk(int u, int v) {
    return (u >= 0 && u < m && v >=0 && v < n);
}
void bfs(int x, int y) {
    rep(i, m)
        rep(j, n) d[i][j] = INF;
    d[x][y] = 0;
    queue <point> q; q.push(point(x, y));
    while ( !q.empty()) {
        point u = q.front(); q.pop();
        rep(i, 4) {
            int nx = u.x + dx[i];
            int ny = u.y + dy[i];
            if ( !isOk(nx, ny) || mark[nx][ny] ) continue;
            if ( d[nx][ny] > d[u.x][u.y] + 1) {
                d[nx][ny] = d[u.x][u.y] + 1;
                q.push(point(nx, ny));
            }
        }
    }
}
void check(int x, int y) {
    mark[x][y] = 1;
    rep(i, 8) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if ( isOk(nx, ny) ) mark[nx][ny] = 1;
    }
}
int run(int cur, int mask) {
    if (mask == lim - 1) return f[cur][0];
    int &res = dp[cur][mask];
    if ( res != -1) return res;
    res = INF;
    for (int i = 1;i <= l;i++) {
        if (!cur) {
            int Cost = f[0][i] + run(i, Or(mask, i - 1));
            res = min(Cost, res);
        }
        else
        if ( !And(mask, i - 1) ) {
            int Cost = f[cur][i] + run(i, Or(mask, i - 1));
            res = min(Cost, res);
        }
    }
    return res;
}
bool impos() {
    if ( mark[S.x][S.y] ) return true;
    fr(i, 1, l)
        if ( mark[p[i].x][p[i].y] ) return true;
    return false;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    while (scanf(" %d %d ", &m, &n) && (m + n)){
        rep(i, m) gets(s[i]);
        fill(mark, 0); l = 0;
        rep(i, m)
            rep(j, n)
                if (s[i][j] == '@') S = point(i, j);
                else
                if (s[i][j] == '~') mark[i][j] = 1;
                else
                if (s[i][j] == '#') mark[i][j] = 1;
                else
                if (s[i][j] == '*') check(i, j);
                else
                if (s[i][j] == '!') p[++l] = point(i, j);
        if ( impos() ) {
            puts("-1");
            continue;
        }
        fill(f, 0);
        fr(i, 1, l) {
            bfs(p[i].x, p[i].y);
            fr(j, 1, l)
                f[i][j] = d[p[j].x][p[j].y];
            f[i][0] = d[S.x][S.y];
        }
        bfs(S.x, S.y);
        fr(i, 1, l)
            f[0][i] = d[p[i].x][p[i].y];
            
        lim = (1<<l); fill(dp, -1);
        int ans = run(0, 0);
        if ( ans >= INF ) puts("-1");
        else printf("%d\n", ans);
    }
}

/***********************************************
* Author LUONG VAN DO                        *
* Problem 10944 - Nuts for nuts..
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
#define N 22

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
ii a[N], S;
char s[N][N];
int m, n, cost[N][N], d[N][N], lim, r;
int dp[N][1<<16];
int dx[] = {0, 1, 0, -1, -1, 1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int isOk(int u, int v) {
    return (u >= 0 && u < m && v >=0 && v < n);
}
void bfs(int x, int y) {
    fr(i, 0, m)
        fr(j, 0, n) d[i][j] = INF;
    d[x][y] = 0;
    queue <ii> q; q.push(ii(x, y));
    while ( !q.empty() ) {
        ii u = q.front(); q.pop();
        rep(i, 8) {
            int nx = u.ff + dx[i];
            int ny = u.ss + dy[i];
            if ( !isOk(nx, ny) ) continue;
            if (d[nx][ny] > d[u.ff][u.ss] + 1) {
                d[nx][ny] = d[u.ff][u.ss] + 1;
                q.push(ii(nx, ny));
            }
        }
    }
}

int run(int cur, int mask) {
    if (mask == lim - 1) return cost[cur][0];
    int &res = dp[cur][mask];
    if (res != -1) return res;
    res = INF;
    for (int i = 1;i <= r; i++) {
        if (!cur) {
            int tempCost = cost[0][i] + run(i, Or(mask, i - 1));
            res = min(res, tempCost);
        }
        else
        if ( !And(mask, i - 1) ) {
            int tempCost = cost[cur][i] + run(i, Or(mask, i - 1));
            res = min(res, tempCost);
        }
    }
    return res;
}

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int caseno = 0;
    while (scanf(" %d %d ", &m, &n) != EOF) {
        rep(i, m) gets(s[i]);
        r = 0;
        rep(i, m)
            rep(j, n)
                if (s[i][j] == '#') a[++r] = ii(i, j);
                else if (s[i][j] == 'L') S = ii(i, j);
        fill(cost, 0);
        fr(i, 1, r) {
            bfs(a[i].ff, a[i].ss);
            fr(j, 1, r)
                cost[i][j] = d[a[j].ff][a[j].ss];
            cost[i][0] = d[S.ff][S.ss];
        }
        bfs(S.ff, S.ss);
        fr(i, 1, r) cost[0][i] = d[a[i].ff][a[i].ss];
        lim = (1<<r); fill(dp, -1);
        printf("%d\n",run(0, 0));
    }
}

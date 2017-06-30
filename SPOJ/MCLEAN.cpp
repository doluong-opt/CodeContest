/***********************************************
* Author - LUONG VAN DO                        *
* Problem 
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

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 25

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
char s[N][N];
int cost[N][N], dp[N][1<<10], f[N][N];
ii d[N], st;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int r, c, lim, n, ans;
void bfs(int x, int y) {
    rep(i, r) rep(j, c) f[i][j] = INF;
    queue <ii> q; q.push(ii(x, y)); f[x][y] = 0;
    while ( !q.empty() ) {
        ii u = q.front(); q.pop();
        for (int i = 0;i < 4;i++) {
            int nx = u.ff + dx[i];
            int ny = u.ss + dy[i];
            if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
                if ( f[nx][ny] == INF && s[nx][ny] != 'x') {
                    f[nx][ny] = f[u.ff][u.ss] + 1;
                    q.push(ii(nx, ny));
                }
            }
        }
    }
}
int run(int cur, int mask) {
    if (mask == lim - 1) return 0;
    int &res = dp[cur][mask];
    if (res != -1) return res;
    res = INF;
    for (int i = 1;i <= n;i++) {
        if (!cur) {
            int temp = cost[0][i] + run(i, Or(mask, i - 1));
            res = min(res, temp);
        }
        else
        if ( !And(mask, i - 1) ) {
            int temp = cost[cur][i] + run(i, Or(mask, i - 1));
            res = min(res, temp);
        }
    }
    return res;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while ( scanf(" %d %d ",&c, &r) && (r + c)) {
        rep(i, r) gets(s[i]);
        n = 0;
        rep(i, r) rep(j, c)
            if (s[i][j] == 'o') st = ii(i, j);
        else
            if (s[i][j] == '*') d[n++] = ii(i, j);
        lim = (1<<n);
        for (int i = 0;i < n;i++) {
            bfs(d[i].ff, d[i].ss);
            for (int j = i + 1;j < n;j++)
                cost[i + 1][j + 1] = cost[j + 1][i + 1] = f[d[j].ff][d[j].ss];
        }
        bfs(st.ff, st.ss);
        for (int i = 1;i <= n;i++) cost[0][i] = cost[i][0] = f[d[i - 1].ff][d[i - 1].ss];
        fill(dp, -1); ans = INF;
        ans = run(0, 0);
        if (ans == INF) puts("-1");
        else printf("%d\n", ans);
	}
	return 0;
}

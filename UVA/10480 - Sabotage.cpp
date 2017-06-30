/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10480 - Sabotage ->AC
* Algorithm maxflow
* Time Limit 0.008s
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
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define frr(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i=n - 1; i>=0; i--)
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 200

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
int n, m;
int cap[N][N], deg[N], d[N], p[N], adj[N][N], mark[N][N], color[N];
int max_flow(int n, int s, int t) {
    int mf = 0, u, v, f;
    memset(deg, 0, sizeof(deg));
    for (u = 0; u < n; u++) for (v = 0; v < n; v++) if ( cap[u][v] || cap[v][u] )
        adj[u][ deg[u]++ ] = v;
    do{
        f = INF;
        for (int i=0; i < n;i++) d[i] = -1;
        p[s] = -1; d[s] = 0;
        queue <int> q; q.push(s);
        while ( !q.empty() ) {
            u = q.front(); q.pop();
            if (u == t) break;
            for (int i=0;i<deg[u];i++) {
                v = adj[u][i];
                if ( d[v] == -1 && cap[u][v] > 0) {
                    d[v] = d[u] + 1;
                    p[v] = u;
                    q.push( v );
                }
            }
        }
        for (v = t; p[v] != -1; v = p[v]) f = min(f, cap[p[v]][v]);
        for (v = t; p[v] != -1; v = p[v]) {
            cap[p[v]][v]-=f;
            cap[v][p[v]]+=f;
        }
        mf+=f;
    }while ( f );
    return mf;
}
void dfs(int u) {
    if ( color[u] ) return;
    color[u] = 1;
    for (int i=0;i<deg[u];i++) {
        int v = adj[u][i];
        if ( !color[v] && cap[u][v]) dfs( v );
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int ans, u, v, w;
    while ( scanf("%d %d",&n,&m) && (n + m)) {
        memset(cap, 0, sizeof(cap));
        memset(mark, 0, sizeof(cap));
        memset(color, 0, sizeof(color));
        for (int i=1;i <= n;i++)
            cap[i][i + n] = INF;
        for (int i=0;i < m;i++) {
            scanf("%d %d %d",&u,&v,&w);
            mark[u + n][v] = mark[v + n][u] = 1;
            cap[u + n][v] = w;
            cap[v + n][u] = w;
        }
        ans = max_flow(2 * n + 1, 1, 2 + n);
        dfs( 1 );
        //cout << ans <<endl;
        for (int i=1;i<=n + n;i++)
            for (int j=1;j<=n + n;j++)
                if (mark[i][j] && !cap[i][j] && color[i] != color[j])
                    if (i > n) printf("%d %d\n", i - n, j);
                else
                    if (j > n) printf("%d %d\n", i, j - n);
        puts("");
    }
}

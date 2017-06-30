
/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10806 - Dijkstra, Dijkstra. ->AC
* Algorithm mincost_maxflow
* Time Limit 0.012s
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
#define N 210

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
int cap[N][N], cost[N][N], adj[N][N], deg[N], p[N], d[N];
int source, sink;
bool bellmanford(int n, int s, int t) {
    for (int i=0;i < n;i++) d[i] = INF;
    d[s] = 0; p[s] = -1;
    bool flag = true;
    for (int it = 0; it < n && flag; it++) {
        flag = false;
        for (int u = 0; u < n; u++)
            for (int i = 0;i < deg[u]; i++) {
                int v = adj[u][i];
                if ( cap[u][v] > 0 && d[v] > d[u] + cost[u][v])
                    d[v] = d[u] + cost[u][v], p[v] = u, flag = true;
            }
    }
    return d[t] < INF;
}
int mcmf(int n, int s, int t, int &fcost) {
    int mf = 0, u, v, f;
    fcost = 0;
    memset(deg, 0, sizeof(deg));
    for (u = 0; u < n; u++ ) for (v = 0; v < n; v++) if ( cap[u][v] || cap[v][u] )
        adj[u][ deg[u]++ ] = v;
    while ( bellmanford(n, s, t) ) {
        int f = INF;
        for ( v = t; p[v] != -1; v = p[v] ) f = min(f, cap[p[v]][v]);
        for ( v = t; p[v] != -1; v = p[v] ) {
            cap[p[v]][v]-=f;
            cap[v][p[v]]+=f;
            fcost+=f * cost[p[v]][v];
        }
        mf+=f;
    }
    return mf;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int u, v, w, ans, mf;
    while ( scanf("%d",&n) && n) {
        scanf("%d",&m);
        source = 0; sink = 2 * n + 1;
        memset(cost, 0, sizeof(cost));
        memset(cap, 0, sizeof(cap));
        for (int i=1;i<=n;i++)
            cap[i][i + n] = INF;

        for (int i=0;i<m;i++) {
            scanf("%d %d %d",&u, &v, &w);
            cap[u + n][v] = 1;
            cost[u + n][v] = w;
            cost[v][u + n] = -w;

            cap[v + n][u] = 1;
            cost[v + n][u] = w;
            cost[u][v + n] = -w;
        }
        cap[source][1] = 2; cap[n + n][sink] = 2;
        ans = 0;
        mf = mcmf(sink + 1, source, sink, ans);
        if (mf != 2) puts("Back to jail");
        else printf("%d\n", ans);
    }
}

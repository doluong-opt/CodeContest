/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10746 - Crime Wave - The Sequel ->AC
* Algorithm mcmf
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
#define INF 2000000000
#define N 200
#define eps 1e-6
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
int n, m, source, sink;
int deg[N], cap[N][N], adj[N][N], p[N];
double cost[N][N], d[N];
bool bellmanford(int n, int s, int t) {
    for (int i = 0;i < n;i++) d[i] = INF;
    d[s] = 0; p[s] = -1;
    bool flag = true;
    for (int it = 0; it < n && flag; it++) {
        flag = false;
        for (int u = 0;u < n; u++)
            for (int i = 0;i < deg[u]; i++) {
                int v = adj[u][i];
                if ( cap[u][v] > 0 && d[v] > d[u] + cost[u][v] )
                    d[v] = d[u] + cost[u][v], p[v] = u, flag = true;
            }
    }
    return d[t] < INF;
}
int mcmf(int n, int s, int t, double &fcost) {
    int mf = 0, u, v;
    memset(deg, 0, sizeof(deg));
    for (u = 0; u < n; u++) for (v = 0; v < n; v++) if ( cap[u][v] || cap[v][u] )
        adj[u][ deg[u]++ ] = v;
    while ( bellmanford(n, s, t) ) {
        int f = INF;
        for (v = t; p[v] != -1; v = p[v] ) f = min(f, cap[p[v]][v]);
        for (v = t; p[v] != -1; v = p[v] ) {
            cap[p[v]][v]-=f;
            cap[v][p[v]]+=f;
            fcost+=((double)f * cost[p[v]][v]);
        }
        mf+=f;
    }
    return mf;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    double x, ans;
    int mf;
    while ( scanf("%d %d",&n,&m) && (n + m)) {
        source = 0; sink = 2 * m + 1;
        memset(cost, 0, sizeof(cost));
        memset(cap, 0, sizeof(cap));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++) {
                scanf("%lf",&x);
                cap[j + m][i] = 1;
                cost[j + m][i] = x;
                cost[i][j + m] = -x;
            }
        for (int i=1;i<=m;i++) cap[source][i + m] = 1;
        for (int i=1;i<=n;i++) cap[i][sink] = 1;
        ans = 0.0;
        mf = mcmf(sink + 1, source, sink, ans);
        printf("%.2lf\n", ans / (double)n + eps);
    }
}

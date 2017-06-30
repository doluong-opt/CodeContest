/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1237 - Cyber Cafe 
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
#define INF 2000000000LL
#define N 110

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
int n, k, g, source, sink;
int a[N], b[N], cap[N][N], cost[N][N], adj[N][N], deg[N];
int d[N], p[N], color[N];
int Cost(int x, int y) {
    int dx = y - x;
    int dy = (dx - k) * (dx - k);
    return min(g, dy);
}
bool bellmanford(int n, int s, int t) {
    for (int i=0;i<n;i++) d[i] = INF;
    d[s] = 0, p[s] = -1;
    bool flag = true;
    for (int it = 0; it < n && flag; it++ ) {
        flag = false;
        for (int u = 0; u < n; u++ )
            for (int i = 0; i < deg[u]; i++) {
                int v = adj[u][i];
                if (cap[u][v] > 0 && d[v] > d[u] + cost[u][v] )
                    d[v] =  d[u] + cost[u][v], p[v] = u, flag = true;
            }
    }
    return d[t] < INF;
}
void buildMin() {
    memset(cap, 0, sizeof(cap));
    memset(cost, 0, sizeof(cost));
    for (int i=1;i<=n;i++) {
        cap[source][i] = 1;
        cap[i + n][sink] = 1;
        for (int j=1;j<=n;j++) {
            if (a[i] >= b[j]) continue;
            cap[i][j + n] = 1;
            cost[i][j + n] = +Cost(a[i], b[j]);
            cost[j + n][i] = -Cost(a[i], b[j]);
        }
    }
}
void buildMax() {
    memset(cap, 0, sizeof(cap));
    memset(cost, 0, sizeof(cost));
    for (int i=1;i<=n;i++) {
        cap[source][i] = 1;
        cap[i + n][sink] = 1;
        for (int j=1;j<=n;j++) {
            if (a[i] >= b[j]) continue;
            cap[i][j + n] = 1;
            cost[i][j + n] = -Cost(a[i], b[j]);
            cost[j + n][i] = +Cost(a[i], b[j]);
        }
    }
}
int minCost(int n, int s, int t, int &fcost ) {
    buildMin();
    int mf = 0, u, v;
    fcost = 0;
    memset(deg, 0, sizeof(deg));
    for ( u=0;u < n;u++ ) for ( v=0; v < n; v++ ) if ( cap[u][v] || cap[v][u])
        adj[u][ deg[u]++ ] = v;
    while ( bellmanford(n, s, t) ) {
        int f = INF;
        for (v = t; p[v] != -1; v = p[v] ) f = min(f, cap[p[v]][v]);
        for (v = t; p[v] != -1; v = p[v] ) {
            cap[p[v]][v]-=f;
            cap[v][p[v]]+=f;
            fcost+=f * cost[p[v]][v];
        }
        if (!f) break;
        mf+=f;
    }
    return mf;
}
int maxCost(int n, int s, int t, int &fcost) {
    buildMax();
    int mf = 0, u, v;
    fcost = 0;
    memset(deg, 0, sizeof(deg));
    for ( u=0;u < n;u++ ) for ( v=0; v < n; v++ ) if ( cap[u][v] || cap[v][u] )
        adj[u][ deg[u]++ ] = v;
    while ( bellmanford(n, s, t) ) {
        int f = INF;
        for (v = t; p[v] != -1; v = p[v] ) {
            f = min(f, cap[p[v]][v]);
            //cout<<p[v]<<" "<<v<<endl;
        }
        
        for (v = t; p[v] != -1; v = p[v] ) {
            cap[p[v]][v]-=f;
            cap[v][p[v]]+=f;
            fcost+=f * cost[p[v]][v];
        }
//        cout<<endl;
        if (!f) break;
        mf+=f;
    }
    return mf;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    int r1, r2, mf1, mf2;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d %d",&n,&k,&g);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for (int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        source = 0; sink = 2 * n + 1;
        //mf1 = minCost(sink + 1, source, sink, r1);
        //cout<<mf1<<" "<<r1<<endl;
        mf2 = maxCost(sink + 1, source, sink, r2);
        //cout<<mf2<<" "<<r2<<endl;
        printf("Case %d: ",++caseno);
        if (mf1 < n || mf2 < n) puts("impossible");
        else printf("%d %d\n",r1, -r2);
    }
}

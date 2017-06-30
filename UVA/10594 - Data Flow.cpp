/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10594 - Data Flow ->AC
* Algorithm  max_flow
* Time Limit 0.48s
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
#define INF 500000000000000000LL
#define N 1000

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int64 min(int64 a, int64 b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node{
    int64 v, w;
    node(){}
    node(int64 vv, int64 ww){
        v = vv; w = ww;
    }
};

vector <node> adj[N];
int64 n, m, data, nheap;
int64 s, t, f;
int64 pos[N], heap[N], color[N], d[N];
int64 p[N], a[N][N];
ii edge[5100];
// run dijstra heap
/*void update(int64 v) {
    int64 child, parent;
    child = pos[v];
    if (!child) child = ++nheap;
    parent = child >> 1;
    while ( parent > 0 && d[ heap[parent] ] > d[v]) {
        heap[child] = heap[parent];
        pos[heap[child]] = child;
        child = parent;
        parent = child >> 1;
    }
    heap[child] = v;
    pos[v] = child;
}
int64 popHeap() {
    int64 u = heap[1], v = heap[nheap--];
    int64 r = 1;
    while ( 2 * r <= nheap ) {
        int c = 2 * r;
        if (c < nheap && d[heap[c + 1]] < d[heap[c]]) ++c;
        if (d[v] <= d[heap[c]]) break;
        heap[r] = heap[c];
        pos[heap[r]] = r;
        r = c;
    }
    heap[r] = v;
    pos[v] = r;
    return u;
}

void reset(int64 x) {
    nheap = 0;
    for (int i=0;i<=t;i++) {
        p[i] = -1;
        d[i] = INF;
        color[i] = 0;
        pos[i] = heap[i] = 0;
    }
    d[x] = 0;
}
void run_dijkstra(int64 x, int64 y) {
    int64 u, v, w;
    reset( x );
    update( x );
    while ( nheap  ) {
        u = popHeap();
        color[u] = 1;
        for (int i=0;i<adj[u].size();i++) {
            v = adj[u][i].v;
            w = adj[u][i].w;
            if ( !color[v] && a[u][v] > 0 && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                p[v] = u;
                update( v );
            }
        }
    }
}*/

// max_flow()
void findPath(int64 v, int64 minEdge) {
    if (v == s) {
        f = minEdge;
        return;
    }
    else
    if (p[v] != -1) {
        findPath(p[v], min(minEdge, a[p[v]][v]));
        a[p[v]][v]-=f;
        a[v][p[v]]+=f;
    }
}
void bellmanford(int x, int y) {
    for (int i=0;i<=t;i++) d[i] = INF, p[i] = -1;
    d[x] = 0;
    bool flag = true;
    int w, v;
    for (int i=0;i<=t && flag; i++) {
        flag = false;
        for (int j=0;j<=t;j++)
            for (int k=0;k<adj[j].size();k++) {
                v = adj[j][k].v;
                w = adj[j][k].w;
                if ( a[j][v] > 0 && d[v] > d[j] + w) {
                    d[v] = d[j] + w;
                    flag = true;
                    p[v] = j;
                }
            }
    }
}
int64 max_flow() {
    int64 mf = 0, res = 0;
    do{
        f = 0;
        bellmanford(s, t);
        //run_dijkstra(s, t);
        findPath(t, INF);
        mf+=f;
        res+=(f * d[t]);
    }while (f && data != mf);
    return (data == mf ? res : INF);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int64 u, v, c, w, ans, K;
    while ( scanf("%lld %lld",&n,&m) != EOF) {
        s = 2 * n; t = s + 1;
        for (int i=0;i<=t;i++) {
            adj[i].clear();
            for (int j=0;j<=t;j++)
                a[i][j] = 0;
        }
        
        for (int i=0;i<n;i++) {
            a[2 * i][2 * i + 1] = INF;
            adj[2 * i].pb( node(2 * i + 1, 0) );
            adj[2 * i + 1].pb( node(2 * i, 0) );
        }
        
        for (int i=0;i<m;i++) {
            scanf("%lld %lld %lld",&u, &v, &w);
            u--; v--;
            edge[i] = ii(u, v);
            
            adj[2 * u + 1].pb( node( 2 * v, w) );
            adj[2 * v].pb( node( 2 * u + 1, -w) );
            adj[2 * v + 1].pb( node( 2 * u, w) );
            adj[2 * u].pb( node( 2 * v + 1, -w) );
            
        }
        scanf("%lld %lld",&data, &K);
        for (int i=0;i<m;i++) {
            u = edge[i].ff; v = edge[i].ss;
            a[2 * u + 1][2 * v] = K;
            a[2 * v + 1][2 * u] = K;
        }
        a[s][0] = data; a[s - 1][t] = data;
        adj[s].pb(node( 0, 0) ); adj[s - 1].pb( node(t, 0) );
        adj[0].pb(node( s, 0) ); adj[t].pb( node(s - 1, 0) );
        
        ans = max_flow();
        if ( ans != INF ) printf("%lld\n", ans);
        else printf("Impossible.\n");
    }
}


/***********************************************
* Author LUONG VAN DO                        *
* Problem 10917 - Walk Through the Forest
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
#define N 1100
#define M 1000010
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
struct point {
    int x, y;
    point(){}
    point(int xx, int yy){
        x = xx; y = yy;
    }
};
vector <int> adj[N], cost[N], adjj[N];
int pos[N], heap[N], d[N], mark[N], q[N], ans[N];
int n, m, nheap, l;
point edge[M];
void update(int v) {
    int child, parent;
    child = pos[v];
    if (!child) child = ++nheap;
    parent = child >> 1;
    while ( parent > 0 && d[heap[parent]] > d[v]) {
        heap[child] = heap[parent];
        pos[heap[child]] = child;
        child = parent;
        parent = child >> 1;
    }
    heap[child] = v;
    pos[v] = child;
}
int popHeap() {
    int u = heap[1], v = heap[nheap--];
    int r = 1;
    while ( 2 * r <= nheap) {
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
void dijkstra() {
    int u, v, w;
    nheap = 0;
    fr(i, 1, n) {
        d[i] = INF;
        pos[i] = heap[i] = mark[i] = 0;
    }
    d[2] = 0; update( 2 );
    while ( nheap ) {
        u = popHeap();
        mark[u] = 1;
        rep(i, adj[u].size()) {
            v = adj[u][i];
            w = cost[u][i];
            if ( mark[v] ) continue;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                update( v );
            }
        }
    }
}

void topo(int u) {
    if ( mark[u] ) return;
    mark[u] = 1;
    rep(i, adjj[u].size()) {
        int v = adjj[u][i];
        if (!mark[v]) topo( v );
    }    
    q[l++] = u;
}

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int u, v, w;
    while ( scanf("%d", &n) && n) {
        scanf("%d", &m);
        fr(i, 1, n) {
            adj[i].clear();
            adjj[i].clear();
            cost[i].clear();
        }
        fr(i, 1, m) {
            scanf("%d %d %d", &u, &v, &w);
            edge[i] = point(u, v);
            adj[u].pb(v); adj[v].pb(u);
            cost[u].pb(w); cost[v].pb(w);
        }
        dijkstra();
        fr(i, 1, m) {
            u = edge[i].x; v = edge[i].y;
            if (d[u] > d[v]) adjj[u].pb(v);
            if (d[v] > d[u] ) adjj[v].pb(u);
        }
        fill(mark, 0); l = 0; fill(ans, 0);
        topo(1); ans[1] = 1;
        for (int i = l - 1; i>=0;i--) {
            u = q[i];
            for (int j = 0;j < adjj[u].size(); j++){
                v = adjj[u][j];
                ans[v]+=ans[u];
            }
        }
        printf("%d\n", ans[2]);
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11635 - Hotel booking ->AC
* Algorithm dijkstra + bfs
* Time Limit 0.852s
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
#define N 10010

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

int n, c, hotel[N], nheap;
vii adj[N], adjj[N];
int color[N], pos[N];
int d[N], heap[N];

void reset(int x) {
    nheap = 0;
    for (int i=1;i<=n;i++) {
        pos[i] = color[i] = 0;
        d[i] = INF;
    }
    d[x] = 0;
}

void update(int x) {
    int child, parent;
    child = pos[x];
    if (!child) child = ++nheap;
    parent = child >> 1;
    while ( parent > 0 && d[ heap[parent] ] > d[x] ) {
        heap[child] = heap[parent];
        pos[ heap[child] ] = child;
        child = parent;
        parent = child >> 1;
    }
    heap[child] = x;
    pos[x] = child;
}
int popHeap() {
    int u = heap[1], v = heap[nheap--];
    int r = 1;
    while ( 2 * r <= nheap ) {
        int c = 2 * r;
        if (c < nheap && d[ heap[c + 1] ] < d[ heap[c] ] ) ++c;
        if (d[v]<= d[heap[c]] ) break;
        heap[r] = heap[c];
        pos[ heap[r] ] = r;
        r = c;
    }
    heap[r] = v;
    pos[v] = r;
    return u;
}
void run(int x) {
    int u, v, w;
    reset( x );
    update( x );
    while ( nheap ) {
        u = popHeap();
        color[u] = 1;
        for (int i=0;i<adj[u].size();i++) {
            v = adj[u][i].ff;
            w = adj[u][i].ss;
            if (w > 600) continue;
            if ( !color[v] && w + d[u] <= 600 && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                update( v );
            }
        }
    }
    /*printf("%d\n",x);
    for (int i=1;i<=n;i++)
        printf("%d ",d[i]);
    puts("");*/
}
int bfs(int x, int y) {
    ii u;
    queue <ii> q;
    q.push(ii(x, 1));
    for (int i=1;i<=n;i++)
        color[i] = 0;
    color[x] = 1;
    while ( !q.empty() ) {
        u = q.front(); q.pop();
        if (u.ff == y) return u.ss;
        for (int i=0;i<adjj[u.ff].size();i++) {
            int v = adjj[u.ff][i].ff;
            if (!color[v]) {
                color[v] = 1;
                q.push(ii(v, u.ss + 1));
            }
        }
    }
    return INF;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int x, y, w, m, ans;
    while ( scanf("%d",&n) && n) {
        for (int i=1;i<=n;i++) {
            hotel[i] = 0;
            adjj[i].clear();
            adj[i].clear();
        }
        scanf("%d",&c);
        hotel[1] = hotel[n] = 1;
        for (int i=0;i<c;i++) {
            scanf("%d",&x);
            hotel[x] = 1;
        }
        scanf("%d",&m);
        for (int i=0;i<m;i++) {
            scanf("%d %d %d",&x, &y, &w);
            adj[x].pb(ii(y, w));
            adj[y].pb(ii(x, w));
        }
        for (int i=1;i<=n;i++)
            if ( hotel[i] ) {
                run( i );
                for (int j=1;j<=n;j++)
                    if (j != i && hotel[j] && d[j] != INF)
                        adjj[i].pb(ii(j, d[j]));
            }
        ans = bfs(1, n);
        if ( ans != INF ) printf("%d\n", ans - 2);
        else puts("-1");
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11377 - Airport Setup ->AC
* Algorithm djikstra + heap
* Time Limit 0.048s
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
#define N 2010

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
int mark[N];
vector <int> adj[N];
int heap[N], pos[N], d[N], nheap;
int color[N], n, m, k;
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
    while (2 * r <= nheap) {
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
void reset(int s) {
    nheap = 0;
    for (int i=1;i<=n;i++) {
        d[i] = INF;
        pos[i] = heap[i] = 0;
        color[i] = 0;
    }
    if (mark[s]) d[s] = 0;
    else d[s] = 1;
}
int run(int s, int t) {
    int u, v, w;
    reset(s);
    update( s );
    while ( nheap ) {
        u = popHeap();
        color[u] = 1;
        for (int i=0;i<adj[u].size();i++) {
            v = adj[u][i];
            if (!color[v] && d[v] > d[u] + (mark[v]^1) ) {
                d[v] = d[u] + (mark[v]^1);
                update( v );
            }
        }
    }
    return d[t];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    int x, y, q, ans;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d %d",&n,&m,&k);
        for (int i=1;i<=n;i++) {
            mark[i] = 0;
            adj[i].clear();
        }
        for (int i=0;i<k;i++) {
            scanf("%d",&x);
            mark[x] = 1;
        }
        for (int i=0;i<m;i++) {
            scanf("%d %d",&x, &y);
            adj[x].pb(y);
            adj[y].pb(x);
        }
        printf("Case %d:\n",++caseno);
        scanf("%d",&q);
        while ( q--) {
            scanf("%d %d",&x, &y);
            if (x == y) {
                printf("0\n");
                continue;
            }
            ans = run(x, y);
            if ( ans != INF ) printf("%d\n", ans);
            else puts("-1");
        }
        puts("");
    }
}

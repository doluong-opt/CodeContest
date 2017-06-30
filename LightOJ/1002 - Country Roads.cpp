/***********************************************
* Author LUONG VAN DO                        *
* Problem 1002 - Country Roads 
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
#define N 510

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
vii adj[N];
int n, m, nheap;
int d[N], color[N], heap[N], pos[N];


void update(int v) {
    int child, parent;
    child = pos[v];
    if ( !child ) child = ++nheap;
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

void solve(int s) {
    int u, v, w;
    rep(i, n)
        d[i] = INF;
    fill(color, 0); fill(heap, 0); fill(pos, 0);
    d[s] = nheap = 0; update(s);
    while ( nheap ) {
        u = popHeap();
        color[u] = 1;
        rep(i, adj[u].size()) {
            v = adj[u][i].ff;
            w = adj[u][i].ss;
            if ( color[v] ) continue;
            d[v] = min(d[v], max(d[u], w));
            update(v);
        }
    }
    
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, u, v, c, s;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d",&n,&m);
        rep(i, n) adj[i].clear();
        rep(i, m) {
            scanf("%d %d %d",&u, &v, &c);
            adj[u].pb(ii(v, c));
            adj[v].pb(ii(u, c));
        }
        scanf("%d",&s);
        solve(s);
        printf("Case %d:\n",++caseno);
        rep(i, n)
            if (d[i] == INF) puts("Impossible");
            else printf("%d\n", d[i]);
    }
}

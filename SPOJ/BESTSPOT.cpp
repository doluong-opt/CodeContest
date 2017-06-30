/***********************************************
* Author LUONG VAN DO                        *
* Problem BESTSPOT
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
vector <int> adj[N];
int n, k, m, nheap;
int f[N], a[N][N], heap[N], pos[N], d[N], color[N];
void reset() {
    nheap = 0;
    fr(i, 1, n) {
        heap[i] = color[i] = pos[i] = 0;
        d[i] = INF;
    }
}
void update(int v) {
    int child, parent;
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
void run_dijk(int s) {
    int u, v;
    reset();
    d[s] = 0;
    update(s);
    while ( nheap ) {
        u = popHeap();
        color[u] = 1;
        rep(i, adj[u].size()) {
            v = adj[u][i];
            if ( color[v] ) continue;
            if (d[v] > d[u] + a[u][v]) {
                d[v] = d[u] + a[u][v];
                update( v );
            }
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int u, v, c, best, cost, ans;
    scanf("%d %d %d",&n,&k,&m);
    //fr(i, 1, n)
        //fr(j, 1, n) a[i][j] = INF;
    fr(i, 1, k) scanf("%d",&f[i]);
    fr(i, 1, m) {
        scanf("%d %d %d",&u,&v,&c);
        adj[u].pb(v);
        adj[v].pb(u);
        a[u][v] = a[v][u] = c;
    }
    fr(j, 1, k) {
        run_dijk( f[j] );
        fr(i, 1, n)
        a[i][f[j]] = a[f[j]][i] = d[i];
    }
    best = INF;
    fr(i, 1, n) {
        cost = 0;
        fr(j, 1, k)
            cost+=a[i][f[j]];
        if (cost < best) best = cost, ans = i;
    }
    printf("%d\n", ans);
}

/***********************************************
* Author LUONG VAN DO                        *
* Problem 11813 - Shopping
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
#define N 100010
#define S 11
#define M 11
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

vector <int> adj[N], cost[N];
int n, m, s, nheap;
int f[M][M], shop[M], d[N];
int pos[N], heap[N], mark[N];
int dp[M][1<<S], lim;
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
void dijkstra(int s) {
    int u, v, w;
    nheap = 0;
    rep(i, n) {
        d[i] = INF;
        heap[i] = pos[i] = mark[i] = 0;
    }
    d[s] = 0; update( s );
    while ( nheap ) {
        u = popHeap();
        mark[u] = 1;
        rep(i, adj[u].size()) {
            v = adj[u][i];
            w = cost[u][i];
            if ( mark[v] ) continue;
            if ( d[v] > d[u] + w ) {
                d[v] = d[u] + w;
                update( v );
            }
        }
    }
}
int run(int cur, int mask) {
    if (mask == lim - 1) return f[cur][0];
    int &res = dp[cur][mask];
    if (res != -1) return res;
    res = INF;
    for (int i = 1;i <= s;i++) {
        if (!cur) {
            int Cost = f[0][i] + run(i, Or(mask, i - 1));
            res = min(res, Cost);
        }
        else
        if ( !And(mask, i - 1) ) {
            int Cost = f[cur][i] + run(i, Or(mask, i - 1));
            res = min(res, Cost);
        }
    }
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, u, v, c;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d", &n, &m);
        rep(i, n) {
            adj[i].clear();
            cost[i].clear();
        }
        rep(i, m) {
            scanf("%d %d %d",&u, &v, &c);
            adj[u].pb(v); adj[v].pb(u);
            cost[u].pb(c); cost[v].pb(c);
        }
        fill(f, 0);
        scanf("%d", &s);
        fr(i, 1, s)
            scanf("%d", &shop[i]);
        fr(i, 1, s) {
            dijkstra(shop[i]);
                fr(j, 1, s)
                    f[i][j] = d[shop[j]];
            f[i][0] = d[0];
        }
        dijkstra( 0 );
        fr(i, 1, s)
            f[0][i] = d[shop[i]]; 
        fill(dp, -1); lim = (1<<s);
        printf("%d\n", run(0, 0));
    }
}

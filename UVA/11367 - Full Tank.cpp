/***********************************************
* Author LUONG VAN DO                        *
* Problem 11367 - Full Tank?
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
#define N 1010

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector <ii> adj[N];
int p[N], n, m, nheap;
int pos[N][N], d[N][N];
ii heap[N * 110];
void update(int x, int y) {
    int child, parent;
    child = pos[x][y];
    if ( !child ) child = ++nheap;
    parent = child >> 1;
    while ( parent > 0 && d[heap[parent].ff][heap[parent].ss] > d[x][y]) {
        heap[child] = heap[parent];
        pos[heap[child].ff][heap[child].ss] = child;
        child = parent;
        parent = child >> 1;
    }
    heap[child] = ii(x, y);
    pos[x][y] = child;
}
ii popHeap() {
    ii u = heap[1], v = heap[nheap--];
    int r = 1;
    while (2 * r <= nheap) {
        int c = 2 * r;
        if (c < nheap && d[heap[c + 1].ff][heap[c + 1].ss] < d[heap[c].ff][heap[c].ss]) ++c;
        if (d[v.ff][v.ss] <= d[heap[c].ff][heap[c].ss]) break;
        heap[r] = heap[c];
        pos[heap[r].ff][heap[r].ss] = r;
        r = c;
    }
    heap[r] = v;
    pos[v.ff][v.ss] = r;
    return u;
}
int solve(int c, int s, int t) {
    for (int i = 0;i < n;i++) {
        heap[i].ff = heap[i].ss = -1;
        for (int j = 0;j <= c;j++) {
            pos[i][j] = 0;
            d[i][j] = INF;
        }
    }
    d[s][0] = 0; nheap = 0;
    update(s, 0);
    while ( nheap ) {
        ii u = popHeap();
        if (u.ss < c && d[u.ff][u.ss + 1] > d[u.ff][u.ss] + p[u.ff] ) {
            d[u.ff][u.ss + 1] = d[u.ff][u.ss] + p[u.ff];
            update(u.ff, u.ss + 1);
        }
        for (int i = 0;i < adj[u.ff].size();i++) {
            int v = adj[u.ff][i].ff;
            int w = adj[u.ff][i].ss;
            if (u.ss >= w)
                if (d[v][u.ss - w] > d[u.ff][u.ss]) {
                    d[v][u.ss - w] = d[u.ff][u.ss];
                    update(v, u.ss - w);
                }
        }
    }
    int ans = INF;
    for (int i = 0;i <= c;i++)
        ans = min(ans, d[t][i]);
    if (ans >= INF) return -1;
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int u, v, w, q, result;
    int c, s, t;
    while ( scanf("%d %d",&n, &m) != EOF){
        rep(i, n) {
            scanf("%d", &p[i]);
            adj[i].clear();
        }
        rep(i, m) {
            scanf("%d %d %d",&u, &v, &w);
            adj[u].pb(ii(v, w));
            adj[v].pb(ii(u, w));
        }
        scanf("%d", &q);
        while (q--) {
            scanf("%d %d %d", &c, &s, &t);
            result = solve(c, s, t);
            if (result != -1) printf("%d\n", result);
            else puts("impossible");
        }
    }
}

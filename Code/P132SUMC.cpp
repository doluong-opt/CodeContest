/***********************************************
* Author - LUONG VAN DO                        *
* Problem
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
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i = b;i >= a;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define pb push_back
#define ff first
#define ss second
#define fill(arr, val) memset(arr, val, sizeof(arr))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint32 unsigned int
#define INF 1000000000
#define N 333
#define MAX_LOG 10
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
int n, k, u, v, add, best, total;
vector <int> adj[N], val[N];
int depth[N], dist[N], parent[N][MAX_LOG], c[N][N];
void dfs(int at, int par, int cost, int lvl) {
    parent[at][0] = par;
    dist[at] = cost;
    depth[at] = lvl;
    rep(i, adj[at].size()) {
        int v = adj[at][i];
        int w = val[at][i];
        if (v != par) dfs(v, at, cost + w, lvl + 1);
    }
}
void buildLCA() {
    dfs(0, -1, 0, 0);
    for (k = 0;(1 << (k + 1)) <= n;k++);
    for (int j = 1;j <= k;j++)
        for (int i = 0;i < n;i++)
            if (parent[i][j - 1] == -1)
                parent[i][j] = parent[i][j - 1];
            else
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
}
int getRoot(int u, int v) {
    if (depth[v] > depth[u]) swap(u, v);
    for (int i = k;i >= 0;i--)
            if (parent[u][i] != -1 && depth[u] - (1 << i) >= depth[v])
                u = parent[u][i];
    if (u == v) return u;
    for (int i = k;i >= 0;i--)
        if (parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
            u = parent[u][i]; v = parent[v][i];
        }
    return parent[u][0];
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d", &n);
	    rep(i, n) rep(j, n)
            c[i][j] = (i == j) ? 0 : INF;
	    rep(i, n) {
	        val[i].clear();
	        adj[i].clear();
	    }
	    rep(i, n - 1) {
	        scanf("%d %d", &u, &v);
	        u--; v--;
	        adj[u].pb(v); val[u].pb(1);
	        adj[v].pb(u); val[v].pb(1);
	        c[u][v] = c[v][u] = 1;
	    }
	    buildLCA(); best = 0;
	    rep(i, n) fr(j, i + 1, n - 1) {
	        add = dist[i] + dist[j] - 2 * dist[getRoot(i, j)];
	        if (best < add) {
	            best = add;
	            u = i; v = j;
	        }
	    }
	    adj[u].pb(v); adj[v].pb(u);
	    val[u].pb(1); val[v].pb(1);
	    c[u][v] = c[v][u] = 1;
	    rep(k, n) rep(i, n) rep(j, n)
            c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
        total = 0;
        rep(i, n)
            fr(j, i + 1, n - 1) total += c[i][j];
	    printf("%d\n", total);
	}
	return 0;
}

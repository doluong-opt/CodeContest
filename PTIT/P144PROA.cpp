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
#define N 100100
#define MAX_LOG 18
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
inline int getInt(int &res) {
    res = 0; char c;
    do { c = getchar(); } while (c < '0' || c > '9');
    do { res = res * 10 + c - '0'; c = getchar(); } while (c >='0' && c <= '9');
}
inline void print(int64 res) {
    int m = 0;
    char digit[30];
    if (res == 0) digit[m++] = char(res + 48);
    while (res) {
        digit[m++] = char(res % 10 + 48);
        res /= 10;
    }
    repr(i, m) putchar(digit[i]);
}
int n, x, y, v, q, k, root;
vector <ii> adj[N];
int parent[N][MAX_LOG], depth[N];
int64 dist[N], ans;
inline void dfs(int at, int par, int64 cost, int lvl) {
    parent[at][0] = par;
    dist[at] = cost;
    depth[at] = lvl;
    rep(i, adj[at].size()) {
        int v = adj[at][i].ff;
        int w = adj[at][i].ss;
        if (v != par) dfs(v, at, cost + w, lvl + 1);
    }
}
inline void buildLCA() {
    dfs(0, -1, 0, 0);
    for (k = 0;(1 <<(k + 1)) <= n;k++);
    for (int j = 1;j <= k;j++)
        for (int i = 1;i <= n;i++) {
            if (parent[i][j - 1] == -1)
                parent[i][j] = parent[i][j - 1];
            else
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
}
inline int getLCA(int u, int v) {
    if (depth[v] > depth[u]) swap(u, v);
    for (int i = k;i >= 0;i--)
        if (parent[u][i] != -1 && depth[u] - (1 << i) >= depth[v])
            u = parent[u][i];
    if (v == u) return u;
    for (int i = k;i >= 0;i--)
        if (parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    return parent[u][0];
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while (scanf("%d", &n) && n) {
	    fr(i, 0, n) adj[i].clear();
	    fr(i, 1, n - 1) {
	        getInt(x); getInt(v);
	        adj[x].pb(ii(i, v));
	        adj[i].pb(ii(x, v));
	    }
	    buildLCA();
	    getInt(q);
	    rep(i, q) {
	        getInt(x); getInt(y);
	        root = getLCA(x, y);
	        ans = dist[x] + dist[y] - 2 * dist[root];
	        if (i) printf(" "), print(ans);
	        else print(ans);
	    }
	    puts("");
	}
	return 0;
}

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
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 200111
#define MAX_LOG 20
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

int p[N][MAX_LOG], depth[N], party[N];
int n, k, amounts, root, x, y;
vector <int> adj[N], listParty[N];

void dfs(int u, int par, int lvl) {
    p[u][0] = par;
    depth[u] = lvl;
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        if ( v != par ) dfs(v, u, lvl + 1);
    }
}
void build_LCA() {
    dfs(root, -1, 0);
    for (k = 0;(1<<(k + 1)) <= n;k++);
    for (int j = 1;j <= k;j++)
        for (int i = 1;i <= n;i++)
            if (p[i][j - 1] == -1)
                p[i][j] = p[i][j - 1];
            else 
                p[i][j] = p[p[i][j - 1]][j - 1];
}
int getLCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = k;i >= 0;i--)
        if (p[u][i] != -1 && depth[u] - (1<<i) >= depth[v]) u = p[u][i];
    if (u == v) return u;
    for (int i = k;i >= 0;i--)
        if (p[u][i] != -1 && p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    return p[u][0];
}
int getDist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[getLCA(u, v)];
}
int run(int p) {
    int res = -1, node = -1;
    for (int i = 0;i < listParty[p].size();i++)
        if (node == -1 || depth[listParty[p][i]] > depth[node]) node = listParty[p][i];
    for (int i = 0;i < listParty[p].size();i++)
        res = max(res, getDist(node, listParty[p][i]));
    return res;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d", &n, &amounts);
	fr(i, 1, n) {
	    adj[i].clear();
	    listParty[i].clear();
	}
	for (int i = 1;i <= n;i++) {
	    scanf("%d %d", &x, &y);
	    listParty[x].pb(i);
	    if (y != 0) {
            adj[i].pb(y);
            adj[y].pb(i);
	    }
	    else root = i;
	}
	build_LCA();
	fr(i, 1, amounts) printf("%d\n", run(i));
	return 0;
}

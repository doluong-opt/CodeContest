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
#define N 10111

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
struct edge{
    int x, y, c;
    edge(){}
    edge(int _x, int _y, int _c){
        x = _x; y = _y; c = _c;
    }
};
int n, a, b, ind;
edge e[N];
vector <ii> adj[N];
char s[N];
int depth[N], head[N], size[N], parent[N], number[N], val[N], child[N], mark[N];
int tree[8 * N];
bool heavy[N];
void build(int pos, int l, int r) {
    if (l == r) {
        tree[pos] = val[l];
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    build(c, l, mid); build(c + 1, mid + 1, r);
    tree[pos] = max(tree[c], tree[c + 1]);
}
void update(int pos, int curNode, int l, int r, int val) {
    if (l == r) {
        tree[pos] = val;
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    if (curNode <= mid) update(c, curNode, l, mid, val);
    else update(c + 1, curNode, mid + 1, r, val);
    tree[pos] = max(tree[c], tree[c + 1]);
}
int get(int pos, int u, int v, int l, int r) {
    if ( r < u || l > v ) return -(1 << 30);
    if (u <= l && r <= v) return tree[pos];
    int mid = (l + r) >> 1, c = 2 * pos;
    int a = get(c, u, v, l, mid);
    int b = get(c + 1, u, v, mid + 1, r);
    return max(a, b);
}
int dfs(int u, int par, int lvl) {
    depth[u] = lvl;
    parent[u] = par;
    size[u] = 1;
    rep(i, adj[u].size()) {
        int v = adj[u][i].ff;
        if (v == par) continue;
        size[u] += dfs(v, u, lvl + 1);
    }
    return size[u];
}
void buildHLD(int u, int first) {
    head[u] = first;
    child[u] = -1;
    rep(i, adj[u].size()) {
        int v = adj[u][i].ff;
        if (parent[u] == v) continue;
        if (size[v] > size[u] / 2) {
            heavy[v] = true;
            child[u] = v;
            buildHLD(v, first);
        }
        else buildHLD(v, v);
    }
}
void init(int u, int par) {
    mark[u] = 1;
    number[u] = ++ind;
    if ( child[u] != -1 ) init(child[u], u);
    rep(i, adj[u].size()) {
        int v = adj[u][i].ff;
        if ( !mark[v] ) init(v, u);
    }
}
void solveQ1(int u, int v) {
    if ( depth[e[u].x] < depth[e[u].y] )
        update(1, number[e[u].y], 1, n, v);
    else
        update(1, number[e[u].x], 1, n, v);
}
void solveQ2(int u, int v) {
    int res = -(1 << 30);
    while (u != -1 && head[u] != head[v] ) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        res = max(res, get(1, number[head[u]], number[u], 1, n));
        //u = (heavy[u] ? head[u] : parent[u]);
        u = parent[head[u]];
    }
    if (depth[u] > depth[v]) swap(u, v);
    if (u != v)
        res = max(res, get(1, number[u] + 1, number[v], 1, n));
    printf("%d\n", res);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d", &n);
	    fr(i, 1, n) {
	        adj[i].clear();
	        mark[i] = 0;
	    }
	    fr(i, 1, n - 1) {
	        scanf("%d %d %d", &e[i].x, &e[i].y, &e[i].c);
	        adj[e[i].x].pb(ii(e[i].y, e[i].c));
	        adj[e[i].y].pb(ii(e[i].x, e[i].c));
	    }
	    ind = 0;	    
	    dfs(1, -1, 0); buildHLD(1, 1); init(1, -1);
	    fr(i, 1, n - 1) {
	        if ( depth[e[i].x] < depth[e[i].y] )
                val[number[e[i].y]] = e[i].c;
            else
                val[number[e[i].x]] = e[i].c;
	    }
	    build(1, 1, n);
	    while ( true ) {
	        scanf("%s", &s);
	        if (s[0] == 'D') break;
	        if (s[0] == 'C') {
	            scanf("%d %d", &a, &b);
	            solveQ1(a, b);
	        }
	        else {
	            scanf("%d %d", &a, &b);
	            solveQ2(a, b);
	        }
	    }
	}
	return 0;
}

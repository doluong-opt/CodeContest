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
#define N 100111

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

struct node{
    int inc, total;
    node(){}
    node(int _inc, int _total){
        inc = _inc; total = _total;
    }
};

vector <int> adj[N], val[N];
int u, v, n, q, t, x, lo, hi, e, cnt, maxD;
int lf[N], rt[N], num[N], depth[N];
node tree[8 * N];
void dfs(int u, int par, int lvl) {
    depth[u] = lvl;
    maxD = max(maxD, lvl);
    lf[u] = ++cnt;
    val[lvl].pb(u);
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        if (v == par) continue;
        dfs(v, u, lvl + 1);
    }
    rt[u] = ++cnt;
}
void update(int pos, int u, int v, int l, int r, int val) {
    if ( r < u || l > v ) return;
    if ( u <= l && r <= v ) {
        tree[pos].inc += val;
        tree[pos].total += val * (r - l + 1);
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    if ( tree[pos].inc != 0 ) {
        tree[c].total += (mid - l + 1) * tree[pos].inc;
        tree[c + 1].total += (r - mid) * tree[pos].inc;
        tree[c].inc += tree[pos].inc;
        tree[c + 1].inc += tree[pos].inc;
        tree[pos].inc = tree[pos].total = 0;
    }
    update(c, u, v, l, mid, val);
    update(c + 1, u, v, mid + 1, r, val);
    tree[pos].total = tree[c].total + tree[c + 1].total;
}
int getValue(int pos, int u, int v, int l, int r) {
    if ( r < u || l > v ) return 0;
    if ( u <= l && r <= v ) return tree[pos].total;
    int mid = (l + r) >> 1, c = 2 * pos;
    if ( tree[pos].inc != 0 ) {
        tree[c].total += (mid - l + 1) * tree[pos].inc;
        tree[c + 1].total += (r - mid) * tree[pos].inc;
        tree[c].inc += tree[pos].inc;
        tree[c + 1].inc += tree[pos].inc;
        tree[pos].inc = 0;
    }
    return getValue(c, u, v, l, mid) + getValue(c + 1, u, v, mid + 1, r);
}
int findL(int key, int x, int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if ( lf[val[x][mid]] >= key ) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int findR(int key, int x, int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if ( rt[val[x][mid]] <= key ) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n);
	fr(i, 1, n - 1) {
	    scanf("%d %d", &u, &v);
	    adj[u].pb(v); adj[v].pb(u);
	}
	cnt = 0; maxD = 0;
	dfs(1, -1, 1);
	cnt = 0;
	fr(i, 1, maxD) rep(j, val[i].size())
        num[val[i][j]] = ++cnt;
	scanf("%d", &q);
	fr(i, 1, q) {
	    scanf("%d", &t);
	    if (t == 2) {
	        scanf("%d", &u);
	        printf("%d\n", getValue(1, num[u], num[u], 1, n));
	    }
	    else {
	        scanf("%d %d %d", &u, &x, &e);
	        x = x + depth[u];
	        lo = findL(lf[u], x, 0, val[x].size() - 1);
            hi = findR(rt[u], x, 0, val[x].size() - 1);
            if (lo <= hi) {
                lo = num[val[x][lo]];
                hi = num[val[x][hi]];
                update(1, lo, hi, 1, n, e);
            }
	    }
	}
	return 0;
}

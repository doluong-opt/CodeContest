// =============================================================================
// Author LUONG VAN DO
// Problem 1348 - Aladdin and the Return Journey
// Algorithm
// Time Limit
// =============================================================================
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
#define N 123456

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

int n, u, v, cnt, q, c, x;
vi adj[N];
int size[N], parent[N], s[N], e[N], head[N];
int tree[4 * N], flag[4 * N], ans;

int dfs(int u, int par, int lvl) {
	size[u] = 1;
	parent[u] = par;
	for (int i = 0;i < adj[u].size();i++) {
		int v = adj[u][i];
		if (v != par) size[u] += dfs(v, u, lvl + 1);
	}
	return size[u];
}
void buildHLD(int u, int first) {
	s[u] = ++cnt;
	head[u] = first;
	//if (p[first] == -1) p[first] = u;
	for (int i = 0;i < adj[u].size();i++) {
		int v = adj[u][i];
		if (parent[u] == v) continue;
		if (size[v] > size[u] / 2) {
			buildHLD(v, first);
		}
		else buildHLD(v, v);
	}
	e[u] = cnt;
}
void buildTree(int pos, int l, int r, int val) {
	if (l == r) {
		tree[pos] = val;
		flag[pos] = -1;
		return;
	}
	int mid = (l + r) >> 1, c = 2 * pos;
	buildTree(c, l, mid, val);
	buildTree(c + 1, mid + 1, r, val);
	tree[c] = tree[c + 1] = tree[pos];
	flag[c] = flag[c + 1] = flag[pos];
}
void updateTree(int pos, int l, int r, int u, int v, int val) {
	//cout<<"tree"<<" "<<pos<<" "<<l<<" "<<r<<" "<<u<<" "<<v<<endl;
	if (r < u || v < l) return;
	if (u <= l && r <= v) {
		tree[pos] = val;
		flag[pos] = val;
		return;
	}
	int mid = (l + r) >> 1, c = 2 * pos;
	if (flag[pos] != -1) {
		tree[c] = tree[c + 1] = flag[pos];
		flag[c] = flag[c + 1] = flag[pos];
		flag[pos] = -1;
	}
	updateTree(c, l, mid, u, v, val);
	updateTree(c + 1, mid + 1, r, u, v, val);
	tree[pos] = max(tree[c], tree[c + 1]);
}
int getTree(int pos, int l, int r, int u, int v) {
	if (r < u || v < l) return 0;
	if (u <= l && r <= v) {
		return tree[pos];
	}
	int mid = (l + r) >> 1, c = 2 * pos;
	if (flag[pos] != -1) {
		tree[c] = tree[c + 1] = tree[pos];
		flag[c] = flag[c + 1] = flag[pos];
		flag[pos] = -1;
	}
	return max(getTree(c, l, mid, u, v),getTree(c + 1, mid + 1, r, u, v));
}
int main() {
	#ifndef ONLINE_JUDGE
	    freopen("exam.inp","r", stdin);
	    freopen("exam.out","w", stdout);
    #endif
	scanf("%d", &n);
	for (int i = 0;i < n - 1;i++) {
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, -1, 0); cnt = 0;
	buildHLD(0, 0);
	//for (int i = 0;i < n;i++)
		//cout<<head[i]<<" "<<endl;
	buildTree(1, s[0], e[0], 0);
	scanf("%d", &q);
	for (int i = 0;i < q;i++) {
		scanf("%d %d", &c, &x); 
		x--;
		if (c == 1) {
			//cout<<"1: "<<s[0]<<" "<<e[0]<<" "<<s[x]<<" "<<e[x]<<endl;
			updateTree(1, s[0], e[0], s[x], e[x], 1);
		}
		else
		if (c == 2) {
			while (x != -1) {
				//cout<<"2: "<<s[head[x]]<<" "<<s[x]<<endl;
				updateTree(1, s[0], e[0], s[head[x]], s[x], 0);
				x = parent[head[x]];
			}
		}
		else
		if (c == 3) {
			//cout<<"d"<<" "<<s[x]<<endl;
			printf("%d\n", getTree(1, s[0], e[0], s[x], s[x]));
		}
	}
	return 0;
}
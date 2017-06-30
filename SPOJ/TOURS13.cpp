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
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 200000000
#define N 1011

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
int n, m, nheap;
int pos[N], mark[N], heap[N];
int d[N];
vii adj[N];
void update(int v) {
    int child, parent;
    child = pos[v];
    if ( !child ) child = ++nheap;
    parent = child >> 1;
    while (parent > 0 && d[heap[parent]] > d[v]) {
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
int solve(int st) {
    int res = INF;
    nheap = 0;
    fr(i, 1, n) {
        d[i] = INF;
        pos[i] = mark[i] = 0;
    }
    d[st] = 0; update(st);
    while ( nheap ) {
        int u = popHeap();
        mark[u] = 1;
        rep(i, adj[u].size()) {
            int v = adj[u][i].ff;
            int w = adj[u][i].ss;
            if (v == st) res = min(res, d[u] + w);
            if ( mark[v] ) continue;
            if ( d[v] > d[u] + w ) d[v] = d[u] + w, update(v);
        }
    }
    if (res != INF) return res;
    return -1;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, u, v, w;
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d %d", &n, &m);
	    fr(i, 1, n) adj[i].clear();
	    rep(i, m) {
	        scanf("%d %d %d", &u, &v, &w);
	        adj[u].pb(ii(v, w));
	    }
	    fr(i, 1, n) printf("%d\n", solve(i));
	}
	return 0;
}

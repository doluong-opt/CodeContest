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
vector <int> adj[N];
set <ii> st;
int n, m, s, u, v, nheap, ans;
int d[N], pos[N], heap[N], mark[N];
int nWay[N];
void update(int v) {
    int child, parent;
    child = pos[v];
    if (!child) child = ++nheap;
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
    int u, v, r;
    u = heap[1]; v = heap[nheap--];
    r = 1;
    while (2 * r <= nheap) {
        int c = 2 * r;
        if (c < nheap && d[heap[c + 1]] < d[heap[c]]) c++;
        if (d[v] <= d[heap[c]]) break;
        heap[r] = heap[c];
        pos[heap[r]] = r;
        r = c;
    }
    heap[r] = v;
    pos[v] = r;
    return u;
}
int dijkstra() {
    update(s);
    while ( nheap ) {
        int u = popHeap();
        mark[u] = 1;
        rep(i, adj[u].size()) {
            int v = adj[u][i];
            if ( mark[v] ) continue;
            if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                nWay[v] = nWay[u];
                update(v);
            }
            else 
            if (d[v] == d[u] + 1) {
                nWay[v] += nWay[u];
                nWay[v] = min(nWay[v], 2);
            }
        }
    }
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d %d", &n, &m, &s);
	nheap = 0;
	fr(i, 1, n) {
	    d[i] = INF;
	    pos[i] = heap[i] = mark[i] = 0;
	}
	d[s] = 0; nWay[s] = 1;
	rep(i, m) {
	    scanf("%d %d", &u, &v);
	    st.insert(ii(u, v));
	}
	for (set <ii>:: iterator it = st.begin(); it!=st.end(); it++) adj[it->first].pb(it->second);
	dijkstra();
	ans = 0;
	for (int i = 1;i <= n;i++)
        if (nWay[i] >= 2) ans++;
    printf("%d\n", ans);
	return 0;
}

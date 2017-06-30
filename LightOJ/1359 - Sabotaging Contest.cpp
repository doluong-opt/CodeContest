/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1359 - Sabotaging Contest 
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

char s[N];
vii adj[N];
int n, m, x, y, w, q, k, sl, nheap, id, len;
int d[N], heap[N], pos[N], mark[N];
int parent[N][20], depth[N], sum[N];

// -- Optimization input / output.....

int nextInt() {
    int v = 0;
    while (id < len && s[id] != ' ') v = v * 10 + s[id++] - '0';
    ++id;
    return v;
}
void print(int x, int y) {
    char buff[20];
    int sz = 0;
    while ( x ) {
        buff[sz++] = (x % 10 + 48);
        x /= 10;
    }
    repr(i, sz) putchar(buff[i]);
    printf(" ");
    sz = 0;
    while ( y ) {
        buff[sz++] = (y % 10 + 48);
        y /= 10;
    }
    repr(i, sz) putchar(buff[i]);
    puts("");
}

// End of input / output....
// function update for dijkstra algorithm..
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
// function popHeap for dijkstra algorithm..
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
// main of dijkstra algorithm.....

void dijsktra() {
    fr(i, 1, n) {
        heap[i] = pos[i] = mark[i] = 0;
        d[i] = INF;
    }
    d[1] = nheap = 0; update(1);
    while ( nheap ) {
        int u = popHeap();
        mark[u] = 1;
        rep(i, adj[u].size()) {
            int v = adj[u][i].ff;
            int w = adj[u][i].ss;
            if ( mark[v] ) continue;
            if (d[v] > d[u] + w) d[v] = d[u] + w, update(v);
        }
    }
}

bool cmp(ii a, ii b) {
    return (a.ss < b.ss);
}
// getLCA node x and y
int getLCA(int x, int y) {    
    if (depth[x] < depth[y]) swap(x, y);
    for (int j = k; j >= 0;j--)
        if (depth[x] - (1<<j) >= depth[y])
            x = parent[x][j];
    if (x == y) return x;
    for (int j = k;j >= 0;j--)
        if (parent[x][j] != parent[y][j])
            x = parent[x][j], y = parent[y][j];
    return parent[x][0];
}
// Solve problem
void solve() {
    vector <int> xx[N];
    for (k = 0;(1<<(k + 1)) <= n;k++);
    for (int i = 1;i <= n;i++) {
        if (d[i] == INF) continue;
        for (int j = 0;j < adj[i].size();j++) {
            int v = adj[i][j].ff;
            int w = adj[i][j].ss;
            if (d[i] + w == d[v]) xx[v].pb(i);
        }
    }
    xx[1].pb(0);
    vector <ii> temp;
    for (int i = 1;i <= n;i++) {
        if (d[i] != INF) temp.pb(ii(i, d[i]));
        depth[i] = 0;
    }
    sort(temp.begin(), temp.end(), cmp);
    for (int i = 0;i < temp.size();i++) {
        int u = temp[i].ff;
        int p = xx[u][0];
        for (int j = 1;j < xx[u].size();j++)
            p = getLCA(p, xx[u][j]);
        parent[u][0] = p; depth[u] = depth[p] + 1;
        for (int j = 1;j <= k;j++)
            parent[u][j] = parent[parent[u][j - 1]][j - 1];
    }
    for (int i = 1;i <= n;i++) sum[i] = 1;
    for (int i = temp.size() - 1;i>=0;i--) {
        int x = temp[i].ff;
        sum[parent[x][0]] += sum[x];
    }
}

int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
	len = (int)strlen(gets(s)); id = 0;
	cases = nextInt();
	while (cases--) {
	    gets(s);
	    len = (int)strlen(gets(s)); id = 0;
	    n = nextInt(); m = nextInt();
	    for (int i = 1;i <= n;i++) adj[i].clear();
	    for (int i = 0;i < m;i++) {
	        len = (int)strlen(gets(s)); id = 0;
	        x = nextInt() + 1; y = nextInt() + 1; w = nextInt();
	        adj[x].pb(ii(y, w));
	        adj[y].pb(ii(x, w));
	    }
	    dijsktra();
	    solve();
	    printf("Case %d:\n", ++caseno);
	    len = (int)strlen(gets(s)); id = 0;
	    q = nextInt();	    
	    while (q--) {
	        len = (int)strlen(gets(s)); id = 0;
	        sl = nextInt();
	        vector <int> node;
	        rep(i, sl) {
	            x = nextInt() + 1;
	            if (d[x] != INF) node.pb(x);
	        }
	        if (!node.size()) puts("0");
	        else {
	            int p = node[0];
	            for (int i = 1;i < node.size();i++) p = getLCA(p, node[i]);
                print(depth[p], sum[p]);
	        }
	    }
	}
	return 0;
}

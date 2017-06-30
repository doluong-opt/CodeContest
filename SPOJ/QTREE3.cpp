/***********************************************
* Author - LUONG VAN DO                        *
* Problem 
* Algorithm
* Time Limit
* *********************************************/

#pragma comment(linker, "/STACK: 100000000")
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
#define N 150111
#define M 250111
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

int n, q, u, v, cnt, ans, s, len, run;
int head[N], child[N], number[N], depth[N], size[N], parent[N], id[N], h[N], to[M];
int tree[8 * N], next[M], que[N];
char buff[1111];

inline void addEdge(int u, int v) {
    to[s] = v; next[s] = h[u]; h[u] = s++;
}

int init() {
    int first, last, u;
    first = last = 1;
    que[first] = 1; depth[first] = 0; parent[1] = -1;
    while (first <= last) {
        u = que[first++]; size[u] = 1; child[u] = -1;
        for (int i = h[u];i != -1;i = next[i]) {
            if (to[i] != parent[u]) {
                parent[to[i]] = u;
                depth[to[i]] = depth[u] + 1;
                que[++last] = to[i];
            }
        }
    }
    for (int j = last;j >= 1;j--) {
        u = que[j];
        for (int i = h[u];i != -1;i = next[i])
            if ( to[i] != parent[u] ) size[u] += size[to[i]];
    }    
    for (int j = last;j >= 1;j--) {
        u = que[j];
        for (int i = h[u];i != -1;i = next[i]) {
            if ( to[i] != parent[u] )
                if (size[to[i]] > size[u] / 2) child[u] = to[i];
        }
    }
    for (int i = 1;i <= last;i++) {
        u = que[i];
        if (parent[u] != -1 && child[parent[u]] == u ) head[u] = head[parent[u]];
        else head[u] = u;
    }
    
    for (int i = 1;i <= n;i++)
        if (head[i] == i)
            for (int j = i;j != -1; j = child[j]) {
                number[j] = ++cnt;
                id[number[j]] = j;
            }
}
void build(int pos, int l, int r) {
    tree[pos] = -1;
    if (l == r) return;
    int mid = (l + r) >> 1, c = 2 * pos;
    build(c, l, mid); build(c + 1, mid + 1, r);
}
void update(int pos, int l, int r, int curNode) {
    if (l == r) {
        if (tree[pos] == -1) tree[pos] = id[curNode];
        else tree[pos] = -1;
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    if (curNode <= mid) update(c, l, mid, curNode);
    else update(c + 1, mid + 1, r, curNode);
    if (tree[c] != -1) tree[pos] = tree[c];
    else tree[pos] = tree[c + 1];
}
int get(int pos, int u, int v, int l, int r) {
    if (r < u || l > v) return -1;
    if (u <= l && r <= v) return tree[pos];
    int mid = (l + r) >> 1, c = 2 * pos;
    if ( v <= mid ) return get(c, u, v, l, mid);
    else
    if ( u > mid ) return get(c + 1, u, v, mid + 1, r);
    else {
        int res = get(c, u, v, l, mid);
        if (res != -1) return res;
        else return get(c + 1, u, v, mid + 1, r);
    }
}
int nextInt() {
    int v = 0;
    while (run < len && buff[run] != ' ') v = v * 10 + buff[run++] - '0';
    ++run;
    return v;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	//freopen("QTREE3.INP","r", stdin); freopen("QTREE3.OUT","w", stdout);
	len = strlen(gets(buff)); run = 0;
	n = nextInt(); q = nextInt();
	fr(i, 0, 2 * n) h[i] = -1; s = cnt = 0;
	fr(i, 1, n - 1) {
	    len = strlen(gets(buff)); run = 0;
	    u = nextInt(); v = nextInt();
	    addEdge(u, v); addEdge(v, u);
	}
	init();
	build(1, 1, n);
	fr(i, 1, q) {
	    len = strlen(gets(buff)); run = 0;
	    u = nextInt(); v = nextInt();
	    if (u) {
	        ans = -1;
	        while (v != -1) {
	            int curNode = get(1, number[head[v]], number[v], 1, n);
	            if (curNode != -1) ans = curNode;
	            v = parent[head[v]];
	        }
	        printf("%d\n", ans);
	    }
	    else update(1, 1, n, number[v]);
	}
	return 0;
}

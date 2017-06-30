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
#define INF 1000000000000000000LL
#define N 1001
#define LMT 15
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int64 min(int64 a, int64 b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
inline void getInt(int &res) {
    res = 0; char c;
    do{ c = getchar(); } while (c < '0' || c > '9');
    do{ res = res * 10 + c - '0'; c = getchar(); } while (c >= '0' && c <= '9');
}
int n, m, k, x, y, c, nheap, lim;
int p[LMT + 1], heap[N], pos[N], mark[N];
int64 a[LMT + 1][LMT + 1], d[N], dp[1 << (LMT + 1)][LMT + 1], ans;
vector <int> adj[N], cost[N];
void update(int v) {
    int child, parent;
    child = pos[v];
    if (!child) child = ++nheap;
    parent = (child >> 1);
    while (parent > 0 && d[heap[parent]] > d[v]) {
        heap[child] = heap[parent];
        pos[heap[child]] = child;
        child = parent;
        parent = child >> 1;
    }
    heap[child] = v;
    pos[v] = child;
}
int getMin() {
    int st = heap[1], v = heap[nheap--];
    int r = 1;
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
    return st;
}
void dijk(int s) {
    fr(i, 1, n) {
        pos[i] = heap[i] = mark[i] = 0;
        d[i] = INF;
    }
    nheap = 0; update(s); d[s] = 0;
    while (nheap) {
        int u = getMin();
        mark[u] = 1;
        for (int i = 0;i < adj[u].size();i++) {
            int v = adj[u][i];
            int w = cost[u][i];
            if ( mark[v] ) continue;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                update(v);
            }
        }
    }
}
void init() {
    fill(a, 0);
    dijk(1);
	fr(i, 1, k) a[0][i] = d[p[i]];
    fr(i, 1, k) {
        dijk(p[i]);
        fr(j, 1, k)
            a[i][j] = d[p[j]];
        a[i][0] = d[1];
    }
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	getInt(n); getInt(m); getInt(k);
	//scanf("%d %d %d", &n, &m, &k);
	fr(i, 1, k) getInt(p[i]);
	rep(i, m) {
	    getInt(x); getInt(y); getInt(c);
	    //scanf("%d %d %d", &x, &y, &c);
	    adj[x].pb(y);
	    cost[x].pb(c);
	}
	init(); lim = (1 << k);
	rep(i, lim) fr(j, 0, k) dp[i][j] = INF;
	fr(i, 1, k) dp[1 << (i - 1)][i] = a[0][i];
	for (int mask = 1;mask < lim;mask++) {
	    for (int i = 1;i <= k;i++)
            for (int j = 1;j <= k;j++)
                if ( !And(mask, j - 1) )
                    if (dp[Or(mask, j - 1)][j] > dp[mask][i] + a[i][j])
                        dp[Or(mask, j - 1)][j] = dp[mask][i] + a[i][j];
	}
	ans = INF;
	fr(i, 1, k)
        if (ans > dp[lim - 1][i] + a[i][0]) ans = dp[lim - 1][i] + a[i][0];
	if (ans != INF) printf("%lld\n", ans);
	else puts("-1");
	return 0;
}

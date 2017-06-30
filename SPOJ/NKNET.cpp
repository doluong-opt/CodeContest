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
#define N 111

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
int m, n, l, r, ans;
int st, en, color[N];
int cap[N][N], adj[N][N], deg[N], a[N][N], p[N], mark[N][N];
bool check(int x, int s, int t) {
    int mf = 0, f, u, v, z;
    for (int i = 1;i <= n;i++) deg[i] = 0;
    for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++)
        if (cap[i][j] > 0 && cap[i][j] <= x) a[i][j] = 1;
        else
        if (cap[i][j] > 0 && cap[i][j] > x) a[i][j] = INF;
    for (u = 1;u <= n;u++) for (v = 1;v <= n;v++) if (a[u][v] || a[v][u])
        adj[u][deg[u]++] = v;
    while ( true ) {
        for (int i = 1;i <= n;i++) p[i] = -1;
        p[s] = -2;
        queue <int> q; q.push(s);
        while ( !q.empty() && p[t] == -1 ) {
            u = q.front(); q.pop();
            for (int i = 0;i < deg[u];i++) {
                v = adj[u][i];
                if (a[u][v] > 0 && p[v] == -1 )
                    p[v] = u, q.push(v);
            }
        }
        if (p[t] == -1) break;
        for (z = 1; z <= n;z++) if (p[z] != -1 && a[z][t] > 0) {
            f = a[z][t];
            for (v = z, u = p[v];u >= 0; v = u, u = p[v]) f = min(f, a[u][v]);
            a[z][t] -= f;
            a[t][z] += f;
            for (v = z, u = p[v];u >= 0; v = u, u = p[v]) {
                a[u][v] -=f;
                a[v][u] +=f;
            }
            mf += f;
        }
    }
    return mf < INF;
}
void dfs(int u) {
    if ( color[u] ) return;
    color[u] = 1;
    for (int i = 0;i < deg[u];i++) {
        int v = adj[u][i];
        if (!color[v] && a[u][v] > 0) dfs(v);
    }
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int u, v, t;
	scanf("%d %d", &n, &m);
	fr(i, 1, n) {
	    color[i] = 0;
	    fr(j, 1, n) cap[i][j] = mark[i][j] = 0;
	}
	rep(i, m) {
	    scanf("%d %d %d", &u, &v, &t);
	    cap[u][v] = cap[v][u] = t;
	    mark[u][v] = mark[v][u] = 1;
	}
	scanf("%d %d", &st, &en);
	l = 1; r = 101;
	while ( l <= r ) {
	    int mid = (l + r) >> 1;
	    if ( check(mid, st, en) ) {
	        ans = mid;
	        r = mid - 1;
	    }
	    else l = mid + 1;
	}
	dfs(st); vii res;
	for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            if (mark[i][j] && !a[i][j] && color[i] && !color[j]) res.pb(ii(i, j));
    printf("%d\n", res.size());
    rep(i, res.size())
        printf("%d %d\n", res[i].ff, res[i].ss);
	return 0;
}

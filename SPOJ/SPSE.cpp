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
#define INF 2000000000
#define N 2010

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
int cap[N][N], adj[N][N], deg[N], p[N];
int m, n;
int dinic(int n, int s, int t) {
    int mf = 0, f, u, v, z;
    for (int i = 0;i < n;i++) deg[i] = 0;
    for (u = 0;u < n;u++) for (v = 0;v < n;v++) if (cap[u][v] || cap[v][u])
        adj[u][deg[u]++] = v;
    while ( true ) {
        queue <int> q; q.push(s);
        for (int i = 0;i < n;i++) p[i] = -1;
        p[s] = -2;
        while ( !q.empty() && p[t] == -1 ) {
            u = q.front(); q.pop();
            for (int i = 0;i < deg[u];i++) {
                v = adj[u][i];
                if (p[v] == -1 && cap[u][v])
                    p[v] = u, q.push(v);
            }
        }
        if (p[t] == -1) break;
        for (z = 0;z < n;z++) if (p[z] != -1 && cap[z][t]) {
            f = cap[z][t];
            for (v = z, u = p[v]; u>=0; v = u, u = p[v]) f = min(f, cap[u][v]);
            cap[z][t] -= f;
            cap[t][z] += f;
            for (v = z, u = p[v]; u>=0; v = u, u = p[v]) {
                cap[u][v] -= f;
                cap[v][u] += f;
            }
            mf += f;
        }
    }
    return mf;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0, source, sink, w, l, total;
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d %d", &m, &n);
	    source = total = 0; sink = n + m + 1;
	    for (int i = 0;i <= sink;i++) for (int j = 0;j <= sink;j++) cap[i][j] = 0;
	    for (int i = 1;i <= m;i++) {
	        scanf("%d", &w);
	        cap[source][i] = w;
	        total += w;
	    }
	    for (int i = 1;i <= n;i++) {
	        scanf("%d", &w);
	        cap[i + m][sink] = w;
	    }
	    for (int i = 1;i <= m;i++) {
	        scanf("%d", &l);
	        while (l--) {
	            scanf("%d", &w);
	            cap[i][w + m] = INF;
	        }
	    }
	    total -= dinic(sink + 1, source, sink);
	    total = max(total, 0);
	    printf("Case %d: %d\n", ++caseno, total);
	}
}

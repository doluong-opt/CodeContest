/***********************************************
* Author - LUONG VAN DO                        *
* Problem  820 - Internet Bandwidth
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

int n, m, s, t, u, v, w;
int cap[N][N], deg[N], p[N], adj[N][N];

int maxflow(int n, int s, int t) {
    int u, v, f, z, mf = 0;
    fill(deg, 0);
    rep(i, n) rep(j, n) if ( cap[i][j] || cap[j][i] )
        adj[i][deg[i]++] = j;
    while ( true ) {
        rep(i, n) p[i] = -1;
        p[s] = -2;
        queue <int> q; q.push(s);
        while ( !q.empty() && p[t] == -1) {
            u = q.front(); q.pop();
            rep(i, deg[u]) {
                v = adj[u][i];
                if (p[v] == -1 && cap[u][v] )
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
                cap[u][v] -=f;
                cap[v][u] +=f;
            }
            mf += f;
        }
    }
    return mf;
}

int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
	while ( scanf("%d", &n) && n ) {
	    scanf("%d %d %d", &s, &t, &m);
	    fr(i, 1, n) fr(j, 1, n) cap[i][j] = 0;
	    rep(i, m) {
	        scanf("%d %d %d", &u, &v, &w);
	        cap[u][v] += w; cap[v][u] += w;
	    }
	    printf("Network %d\n", ++caseno);
	    printf("The bandwidth is %d.\n\n", maxflow(n + 1, s, t));
	}
	return 0;
}

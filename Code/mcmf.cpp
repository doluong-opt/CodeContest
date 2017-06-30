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
#define MAX_LOG 20
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

int u, v, c, fcost, n, m, cost, s, t;
char x, y;
int cap[N][N], adj[N][N], a[N][N], deg[N], p[N], dist[N];
int first, last, q[N];
bool bellmanford(int n, int s, int t) {
    for (int i = 0;i < n;i++) {
        dist[i] = INF;
        p[i] = -1;
    }
    dist[s] = 0;
    bool flag = true;
    for (int it = 0; it < n && flag; it++) {
        flag = false;
        for (int u = 0; u < n; u++)
            for (int i = 0;i < deg[u];i++) {
                int v = adj[u][i];
                if ( cap[u][v] > 0 && dist[v] > dist[u] + a[u][v] )
                    dist[v] = dist[u] + a[u][v], p[v] = u, flag = true;
            }
    }
    
    return dist[t] < INF;
}
int mcmf(int sz, int s, int t, int &fcost) {
    int res = 0, u, v;
    fcost = 0;
    for (int i = 0;i < sz;i++) deg[i] = 0;
    for (int u = 0;u < sz;u++) for (int v = 0;v < sz;v++) if (cap[u][v] || cap[v][u]) {
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }
    while ( bellmanford(sz, s, t) ) {
        int f = INF;
        for (v = t; p[v] != -1; v = p[v]) f = min(f, cap[p[v]][v]);
        
        for (v = t; p[v] != -1; v = p[v]) {
            cap[p[v]][v] -= f;
            cap[v][p[v]] += f;
            fcost += (f * a[p[v]][v]);
            printf("%c ", v + 'a');
        }
        printf("%c\n", s + 'a');
        for (int i = 0;i < sz;i++)
            for (int j = 0;j < sz;j++)
                if ( cap[i][j] != 0 ) printf("%c %c %d\n", i + 'a', j + 'a', cap[i][j]);
        res += f;
    }
    return res;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
    scanf(" %d %d %d %d ", &n, &m, &s, &t);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) {
            cap[i][j] = 0;
            a[i][j] = 0;
        }
        
    for (int i = 0;i < m;i++) {
        scanf(" %c %c %d %d ", &x, &y, &c, &cost);
        u = x - 'a'; v = y - 'a';
        cap[u][v] = c;
        a[u][v] = cost; a[v][u] = -cost;
    }
    int mf = mcmf(t + 1, s, t, fcost);
    printf("Max Flow : %d\n", mf);
    printf("Min Cost : %d\n", fcost);
	return 0;
}

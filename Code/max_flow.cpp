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
int u, v, n, m, cost, s, t;
char x, y;
int cap[N][N], adj[N][N], deg[N], p[N], dist[N];
int first, last, q[N];
bool findPath(int sz, int s, int t) {
    int u, v;
    for (int i = 0;i < sz;i++) dist[i] = p[i] = -1;
    dist[s] = 0;
    first = last = 0; q[0] = s;
    while (first <= last) {
        u = q[first++];
        if (u == t) return true;
        for (int i = 0;i < deg[u];i++) {
            v = adj[u][i];
            if (dist[v] == -1 && cap[u][v] > 0) {
                dist[v] = dist[u] + 1;
                p[v] = u;
                q[++last] = v;
            }
        }
    }
    return false;
}
int mf(int sz, int s, int t) {
    int res = 0, u, v;
    for (int i = 0;i < sz;i++) deg[i] = 0;
    for (int u = 0;u < sz;u++) for (int v = 0;v < sz;v++) if (cap[u][v] || cap[v][u]) {
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }
    while ( findPath(sz, s, t) ) {
        int f = INF;
        for (v = t; p[v] != -1; v = p[v]) f = min(f, cap[p[v]][v]);
        for (v = t; p[v] != -1; v = p[v]) {
            cap[p[v]][v] -= f;
            cap[v][p[v]] += f;
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
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++)
            cap[i][j] = 0;
    }
        
    for (int i = 0;i < m;i++) {
        scanf(" %c %c %d ", &x, &y, &cost);
        u = x - 'a'; v = y - 'a';
        cap[u][v] = cost;
    }
    printf("Max flow : %d\n", mf(t + 1, s, t));
	return 0;
}

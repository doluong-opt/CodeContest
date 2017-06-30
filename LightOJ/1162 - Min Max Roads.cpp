/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1162 - Min Max Roads
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

vector <ii> adj[N];
int n, m, x, y, w, k, id;
int parent[N][MAX_LOG], lenMax[N][MAX_LOG], lenMin[N][MAX_LOG], depth[N];
char s[N];

void dfs(int cur, int par, int cost, int lvl) {
    parent[cur][0] = par;
    lenMax[cur][0] = cost;
    lenMin[cur][0] = cost;
    depth[cur] = lvl;
    for (int i = 0;i < adj[cur].size();i++) {
        int v = adj[cur][i].ff;
        int w = adj[cur][i].ss;
        if (v != par) dfs(v, cur, w, lvl + 1);
    }
}

void buildLCA() {
    dfs(1, -1, 0, 0);
    for (k = 0;(1<<(k + 1)) <= n;k++);
    for (int j = 1;j <= k;j++)
        for (int i = 1;i <= n;i++)
            if (parent[i][j - 1] == -1) {
                parent[i][j] = parent[i][j - 1];
                lenMax[i][j] = lenMax[i][j - 1];
                lenMin[i][j] = lenMin[i][j - 1];
            }
            else {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
                lenMax[i][j] = max(lenMax[i][j - 1], lenMax[parent[i][j - 1]][j - 1]);
                lenMin[i][j] = min(lenMin[i][j - 1], lenMin[parent[i][j - 1]][j - 1]);
            }
}
ii get(int u, int v) {
    ii res;
    res.ff = 0; res.ss = INF;
    if ( depth[v] > depth[u] ) swap(u, v);
    for (int i = k;i >= 0;i--)
        if (parent[u][i] != -1 && depth[u] - (1<<i) >= depth[v]) {
            res.ff = max(res.ff, lenMax[u][i]);
            res.ss = min(res.ss, lenMin[u][i]);
            u = parent[u][i];
        }
    if (v == u) return res;
    for (int i = k;i >= 0;i--)
        if (parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
            res.ff = max(res.ff, max(lenMax[u][i], lenMax[v][i]));
            res.ss = min(res.ss, min(lenMin[u][i], lenMin[v][i]));
            u = parent[u][i]; v = parent[v][i];
        }
    res.ff = max(res.ff, max(lenMax[u][0], lenMax[v][0]));
    res.ss = min(res.ss, min(lenMin[u][0], lenMin[v][0]));
    return res;
}
int nextInt() {
    int v = 0;
    while (id < m && s[id] != ' ') v = v * 10 + s[id++] - '0';
    ++id;
    return v;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0, q;
	m = (int)strlen(gets(s)); id = 0;
	cases = nextInt();
	while (cases--) {
	    gets(s);
	    m = (int)strlen(gets(s)); id = 0;
	    n = nextInt();
	    for (int i = 1;i <= n;i++) adj[i].clear();	    
	    for (int i = 0;i < n - 1;i++) {
            m = (int)strlen(gets(s)); id = 0;
            x = nextInt(); y = nextInt(); w = nextInt();
            adj[x].pb(ii(y, w));
            adj[y].pb(ii(x, w));
	    }
        buildLCA();
        printf("Case %d:\n", ++caseno);
        m = (int)strlen(gets(s)); id = 0;
        q = nextInt();
        while (q--) {
            m = (int)strlen(gets(s)); id = 0;
            x = nextInt(); y = nextInt();
            ii ans = get(x, y);
            printf("%d %d\n", ans.ss, ans.ff);
        }
	}
	return 0;
}

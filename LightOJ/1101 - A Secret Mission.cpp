/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1101 - A Secret Mission
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
struct node{
    int x, y, w;
    node(){}
    node(int _x, int _y, int _w){
        x = _x; y = _y; w = _w;
    }
};
node edge[N];
vector <ii> adj[N];
int n, m, lab[N], x, y, k;
int parent[N][MAX_LOG], lenMax[N][MAX_LOG], depth[N];
bool cmp(node a, node b) {
    return (a.w < b.w);
}

int getRoot(int v) {
    if (lab[v] < 0) return v;
    else return lab[v] = getRoot( lab[v] );
}

void unionSet(int r1, int r2) {
    int x = lab[r1] + lab[r2];
    if ( lab[r1] > lab[r2] ) {
        lab[r2] = x;
        lab[r1] = r2;
    }
    else {
        lab[r1] = x;
        lab[r2] = r1;
    }
}

void dfs(int cur, int par, int cost, int lvl) {
    parent[cur][0] = par;
    lenMax[cur][0] = cost;
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
            }
            else {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
                lenMax[i][j] = max(lenMax[i][j - 1], lenMax[parent[i][j - 1]][j - 1]);
            }
}
int solve(int u, int v) {
    int res = 0;
    if ( depth[v] > depth[u] ) swap(u, v);
    for (int i = k;i >= 0;i--)
        if (parent[u][i] != -1 && depth[u] - (1<<i) >= depth[v]) {
            res = max(res, lenMax[u][i]);
            u = parent[u][i];
        }
    if (v == u) return res;
    for (int i = k;i >= 0;i--)
        if (parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
            res = max(res, max(lenMax[u][i], lenMax[v][i]));
            u = parent[u][i]; v = parent[v][i];
        }
    return max(res, max(lenMax[u][0], lenMax[v][0]));
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0, q;
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d %d", &n, &m);
	    for (int i = 1;i <= n;i++) {
	        lab[i] = -1;
	        adj[i].clear();
	    }
	    for (int i = 0;i < m;i++)
            scanf("%d %d %d", &edge[i].x, &edge[i].y, &edge[i].w);
        sort(edge, edge + m, cmp);
        for (int i = 0, cnt = 0;i < m && cnt < n - 1;i++) {
            x = getRoot(edge[i].x); y = getRoot(edge[i].y);
            if (x != y) {
                unionSet(x, y);
                cnt++;
                adj[edge[i].x].pb(ii(edge[i].y, edge[i].w));
                adj[edge[i].y].pb(ii(edge[i].x, edge[i].w));
            }
        }
        buildLCA();
        printf("Case %d:\n", ++caseno);
        scanf("%d", &q);        
        while (q--) {
            scanf("%d %d", &x, &y);
            printf("%d\n", solve(x, y));
        }
	}
	return 0;
}

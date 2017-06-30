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
    int id, x, y, w;
    node(){}
    node(int idd, int xx, int yy, int ww){
        id = idd; x = xx; y = yy; w = ww;
    }
};
node edge[N];
int cnt, u, v, n, m, k, maxCost;
int lab[N], visit[N], f[N], p[N][MAX_LOG], maxEdge[N][MAX_LOG], depth[N];
vector <ii> adj[N];
bool cmp(node a, node b) {
    return a.w < b.w;
}
int getRoot(int v) {
    if (lab[v] < 0) return v;
    return lab[v] = getRoot(lab[v]);
}
void unionTree(int r1, int r2) {
    int x = lab[r1] + lab[r2];
    if (lab[r1] > lab[r2]) {
        lab[r1] = r2;
        lab[r2] = x;
    }
    else {
        lab[r1] = x;
        lab[r2] = r1;
    }
}
void bfs() { //  Sử dụng bfs để tránh trường hợp cây suy biến.
    queue <int> q; q.push(1);
    for (int i = 1;i <= n;i++) visit[i] = 0;
    p[1][0] = -1;
    maxEdge[1][0] = 0;
    depth[1] = 0;
    while ( !q.empty() ) {
        u = q.front(); q.pop();
        visit[u] = 1;
        for (int i = 0;i < adj[u].size();i++) {
            int v = adj[u][i].ff;
            int w = adj[u][i].ss;
            if ( visit[v] ) continue;
            p[v][0] = u;
            maxEdge[v][0] = w;
            depth[v] = depth[u] + 1;
            q.push(v);
        }
    }
}
void buildLCA() {
    bfs();
    for (k = 0;(1 << (k + 1)) <= n;k++);
    for (int j = 1;j <= k;j++)
        for (int i = 1;i <= n;i++)
            if (p[i][j - 1] == -1) {
                p[i][j] = p[i][j - 1];
                maxEdge[i][j] = maxEdge[i][j - 1];
            }
            else {
                p[i][j] = p[p[i][j - 1]][j - 1];
                maxEdge[i][j] = max(maxEdge[i][j - 1], maxEdge[p[i][j - 1]][j - 1]);
            }
}
int getMax(int u, int v) {
    int res = 0;
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = k;i >= 0;i--)
        if (p[u][i] != -1 && depth[u] - (1 << i) >= depth[v]) {
            res = max(res, maxEdge[u][i]);
            u = p[u][i];
        }
    if (u == v) return res;
    for (int i = k;i >= 0;i--) {
        if (p[u][i] != -1 && p[u][i] != p[v][i]) {
            res = max(res, maxEdge[u][i]);
            res = max(res, maxEdge[v][i]);
            u = p[u][i]; v = p[v][i];
        }
    }
    res = max(res, maxEdge[u][0]);
    res = max(res, maxEdge[v][0]);
    return res;
}
int main() {
	freopen("mst.inp","r", stdin); freopen("mst.out","w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 0;i < m;i++) {
	    scanf("%d %d %d", &edge[i].x, &edge[i].y, &edge[i].w);
	    edge[i].id = i; f[i] = 0;
	}
	sort(edge, edge + m, cmp);
	cnt = 0;
	for (int i = 1;i <= n;i++) lab[i] = -1;
	for (int i = 0;i < m;i++) {
	    u = getRoot(edge[i].x); v = getRoot(edge[i].y);
	    if (u != v) {
	        unionTree(u, v);
	        adj[edge[i].x].pb(ii(edge[i].y, edge[i].w));
	        adj[edge[i].y].pb(ii(edge[i].x, edge[i].w));
	        cnt++;
	        if (cnt == n - 1) break;
	    }
	}
	buildLCA();
	for (int i = 0;i < m;i++) {
	    maxCost = getMax(edge[i].x, edge[i].y);
	    if (edge[i].w == maxCost) f[edge[i].id] = 1;
	}
	for (int i = 0;i < m;i++)
        if (f[i]) puts("YES");
        else puts("NO");
	return 0;
}

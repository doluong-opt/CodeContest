// =============================================================================
// Author LUONG VAN DO
// Problem NUMLAND
// Algorithm
// Time Limit
// =============================================================================
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fillarr(arr, c) memset(arr, c, sizeof(arr))
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 100005
#define MAX_LOG 17
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct edge{
        int to;
        int next;
}edges[2 * N];

int cntEdge, k;
int head[N], x, y, u, v, n, m, xx, yy;
int parent[N][MAX_LOG], depth[N];

void init() {
        fillarr(head, -1);
        fillarr(edges, 0);
        fillarr(depth, 0);
        cntEdge = 0;
}
void addEdge(int u, int v) {
        edges[cntEdge].to = v; edges[cntEdge].next = head[u]; head[u] = cntEdge++;
        edges[cntEdge].to = u; edges[cntEdge].next = head[v]; head[v] = cntEdge++;
}
void dfs(int u, int par, int lvl) {
        parent[u][0] = par;
        depth[u] = lvl;
        for (int i = head[u]; i != -1; i = edges[i].next) {
                int v = edges[i].to;
                if (v != par) dfs(v, u, lvl + 1);
        }
}
void buildLCA() {
        dfs(1, -1, 0);
        for (k = 0;(1 << (k + 1)) <= n;k++);
        for (int j = 1;j <= k;j++)
                for (int i = 1;i <= n;i++)
                        if (parent[i][j - 1] == -1)
                                parent[i][j] = parent[i][j - 1];
                        else
                                parent[i][j] = parent[parent[i][j - 1]][j - 1];
}
int getLCA(int x, int y) {
        if (depth[x] < depth[y]) swap(x, y);
        for (int i = k; i >= 0;i--)
                if (depth[x] - (1 << i) >= depth[y])
                        x = parent[x][i];
        if (x == y) return x;
        for (int i = k;i >= 0;i--)
                if (parent[x][i] != parent[y][i])
                        x = parent[x][i], y = parent[y][i];
        return parent[x][0];
}
int getDist(int u, int v) {
        int x = getLCA(u, v);
        return depth[u] + depth[v] - 2 * depth[x];
}
bool check(int u, int v, int x) {
        return getDist(u, v) == getDist(u, x) + getDist(x, v);
}
int main() {
        //freopen("exam.inp","r", stdin);
        //freopen("exam.out","w", stdout);
        scanf("%d %d", &n, &m);
        init();
        for (int i = 0;i < n - 1;i++) {
                scanf("%d %d", &x, &y);
                addEdge(x, y);
        }
        buildLCA();
        for (int i = 0;i < m;i++) {
                scanf("%d %d %d %d", &u, &v, &x, &y);
                xx = getLCA(u, v); yy = getLCA(x, y);
                if (check(u, v, yy) || check(x, y, xx)) puts("war again");
                else puts("peace");
        }
        return 0;
}

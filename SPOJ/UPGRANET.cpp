/***********************************************
* Author LUONG VAN DO                        *
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

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 1000000000
#define N 100010
#define MAX_LOG 18
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int64 min(int64 a, int64 b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int64> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node{
    int x, y, mark;
    int w;
    node(){}
    node(int xx, int yy, int ww, int mm){
        x = xx; y = yy; w = ww; mark = mm;
    }
}edge[N];
int m, n, k, lab[N];
vector <ii> adj[N], q[N];
int P[N][MAX_LOG], depth[N];
int64 lmin[N][MAX_LOG];
bool cmp(const node& a, const node& b) {
    return (a.w > b.w);
}
int getSet(int64 v) {
    if (lab[v] < 0) return v;
    else return lab[v] = getSet( lab[v] );
}
void unionSet(int r1, int r2) {
    int x = lab[r1] + lab[r2];
    if (lab[r1] > lab[r2]) {
        lab[r2] = x;
        lab[r1] = r2;
    }
    else {
        lab[r1] = x;
        lab[r2] = r1;
    }
}
void dfs(int u, int p, int64 cost, int lvl) {
    P[u][0] = p;
    lmin[u][0] = cost;
    depth[u] = lvl;
    for (int i = 0;i < adj[u].size();i++) {
        int64 v = adj[u][i].ff;
        if (v != p) dfs(v, u, adj[u][i].ss, lvl + 1);
    }
}
void buildLCA() {
    dfs(1, -1, 0, 0);
    for (k = 0; (1<<(k + 1)) <= n;k++);
    for (int j = 1;j <= k;j++)
        for (int i = 1;i <= n;i++)
            if (P[i][j - 1] == -1) {
                P[i][j] = P[i][j - 1];
                lmin[i][j] = lmin[i][j - 1];
            }
            else {
                P[i][j] = P[P[i][j - 1]][j - 1];
                lmin[i][j] = min(lmin[i][j - 1], lmin[P[i][j - 1]][j - 1]);
            }
}
int getLCA(int u, int v, int64 w) {
    if (depth[v] > depth[u]) swap(u, v);
    int64 res = INF;
    for (int j = k;j>=0;j--) {
        if (P[u][j] != -1 && depth[u] - (1<<j) >= depth[v]) {
            res = min(res, lmin[u][j]);
            u = P[u][j];
        }
    }
    if (u == v) {
        if (res != INF && res > w) return res - w;
        return 0;
    }
    for (int j = k;j >= 0;j--)
        if (P[u][j] != -1 && P[u][j] != P[v][j]) {
            res = min(res, min(lmin[u][j], lmin[v][j]));
            u = P[u][j]; v = P[v][j];
        }
    res = min(res, min(lmin[u][0], lmin[v][0]));
    if (res != INF && res > w) return res - w;
    return 0;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int u, v, cnt;
    int64 ans;
    scanf("%d %d",&n, &m);
    for (int i = 0;i < m;i++) {
        scanf("%d %d %d", &edge[i].x, &edge[i].y, &edge[i].w);
        edge[i].mark = 0;
    }
    sort(edge, edge + m, cmp);
    for (int i = 1;i <= n;i++) lab[i] = -1;
    cnt = 0;
    for (int i = 0;i < m && cnt < n - 1;i++) {
        u = getSet(edge[i].x); v = getSet(edge[i].y);
        if (u != v) {
            adj[edge[i].x].pb(ii(edge[i].y, edge[i].w));
            adj[edge[i].y].pb(ii(edge[i].x, edge[i].w));
            unionSet(u, v);
            cnt++;
            edge[i].mark = 1;
        }
    }
    buildLCA();
    ans = 0;
    for (int i = 0;i < m;i++)
        if (!edge[i].mark) q[edge[i].x].pb(ii(edge[i].y,edge[i].w));
    for (int i = 1;i <= n;i++)
        for (int j = 0;j < q[i].size();j++)
            ans+=getLCA(i, q[i][j].ff, q[i][j].ss);
    printf("%lld\n", ans);
}

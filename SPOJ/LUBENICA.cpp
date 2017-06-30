/***********************************************
* Author LUONG VAN DO                        *
* Problem LUBENICA
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
#define INF 111222333
#define N 100010
#define MAX_LOG 17
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
vii adj[N];
int P[N][MAX_LOG], depth[N];
int lmin[N][MAX_LOG], lmax[N][MAX_LOG];
int n, k;
void dfs(int u, int p, int cost, int lvl) {
    P[u][0] = p;
    lmin[u][0] = cost;
    lmax[u][0] = cost;
    depth[u] = lvl;
    rep(i, adj[u].size()) {
        int v = adj[u][i].ff;
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
                lmax[i][j] = lmax[i][j - 1];
            }
            else {
                P[i][j] = P[P[i][j - 1]][j - 1];
                lmin[i][j] = min(lmin[i][j - 1], lmin[P[i][j - 1]][j - 1]);
                lmax[i][j] = max(lmax[i][j - 1], lmax[P[i][j - 1]][j - 1]);
            }
}
void solve(int u, int v, int &r1, int &r2) {
    r1 = INF;
    r2 = 0;
    if (depth[v] > depth[u]) swap(u, v);
    for (int j = k;j >= 0;j--) {
        if (P[u][j] != -1 && depth[u] - (1<<j) >= depth[v]) {
            r1 = min(r1, lmin[u][j]);
            r2 = max(r2, lmax[u][j]);
            u = P[u][j];
        }
    }
    if (u == v) return;
    for (int j = k;j>=0;j--) {
        if (P[u][j] != -1 && P[u][j] != P[v][j]) {
            r1 = min(r1, min(lmin[u][j], lmin[v][j]));
            r2 = max(r2, max(lmax[u][j], lmax[v][j]));
            u = P[u][j]; v = P[v][j];
        }
    }
    r1 = min(r1, min(lmin[u][0], lmin[v][0]));
    r2 = max(r2, max(lmax[u][0], lmax[v][0]));
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int u, v, w, r1, r2, q;
    scanf("%d", &n);
    for (int i = 1;i <= n - 1;i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u].pb(ii(v, w));
        adj[v].pb(ii(u, w));
    }
    buildLCA();
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &u, &v);
        solve(u, v, r1, r2);
        printf("%d %d\n", r1, r2);
    }
}

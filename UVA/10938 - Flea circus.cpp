/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10938 - Flea circus ->AC
* Algorithm LCA
* Time Limit 0.04s
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
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define frr(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i=n - 1; i>=0; i--)
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 5010
#define MAX_LOG 13
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
vector <int> adj[N];
int P[N][MAX_LOG];
int depth[N], k, n;
void dfs(int u, int p, int lev) {
    depth[u] = lev;
    P[u][0] = p;
    for (int i=0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if (v != p) dfs(v, u, lev + 1);
    }
}
void buildLCA() {
    dfs(0, -1, 0);
    for (k=0;(1<<(k + 1))<=n;k++);
    for (int j=1;j<=k;j++)
        for (int i=0;i<n;i++)
            if ( P[i][j - 1] == -1 )
                P[i][j] = P[i][j - 1];
            else
                P[i][j] = P[P[i][j - 1]][j - 1];
}
int findLCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int j=k;j>=0;j--)
        if ( P[u][j] != -1 && depth[u] - (1<<j) >= depth[v])
            u = P[u][j];
    
    if (u == v) return u;
    for (int j=k;j>=0;j--) {
        if ( P[u][j] != -1 && P[u][j] != P[v][j] ) {
            u = P[u][j];
            v = P[v][j];
        }
    }
    return P[u][0];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int u, v, q, x, ans, l, d, r1, r2;
    while ( scanf("%d",&n) && n) {
        for (int i=0;i<n;i++) adj[i].clear();
        for (int i=0;i<n-1;i++) {
            scanf("%d %d",&u,&v);
            u--; v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        buildLCA();
        scanf("%d",&q);
        while (q--) {
            scanf("%d %d",&u,&v);
            u--; v--;
            l = findLCA(u, v);
            d = depth[u] + depth[v] - 2 * depth[l];
            if (d % 2 == 0) {
                x = d >> 1;
                if ( depth[u] < depth[v]) swap(u, v);
                for (int j=k;j>=0;j--)
                    if ( P[u][j] != -1 && x - (1<<j) >= 0) {
                        u = P[u][j];
                        x-=(1<<j);
                    }
                printf("The fleas meet at %d.\n", u + 1);
            }
            else {
                x = d >> 1;
                if ( depth[u] < depth[v]) swap(u, v);
                r2 = u;
                for (int j=k;j>=0;j--)
                    if ( P[u][j] != -1 && x - (1<<j) >=0 ) {
                        u = P[u][j];
                        x-=(1<<j);
                    }
                    
                r1 = u; u = r2;
                x = (d >> 1) + 1;
                for (int j=k;j>=0;j--)
                    if ( P[u][j] != -1 && x - (1<<j) >=0 ) {
                        u = P[u][j];
                        x-=(1<<j);
                    }
                r2 = u;
                printf("The fleas jump forever between %d and %d.\n", min(r1, r2) + 1, max(r1, r2) + 1);
            }
        }
    }
}

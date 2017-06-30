/***********************************************
* Author - LUONG VAN DO                        *
* Problem 615 - Is It A Tree? ->AC
* Algorithm adhoc
* Time Limit 0.016s
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
#define N 100000

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
int deg[N];
vector <int> adj[N];
map <int, int> mx;
int mark[N], n, dist[N];
void dfs(int u) {
    if ( mark[u] ) return;
    mark[u] = 1;
    for (int i=0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if ( !mark[v] ) dfs( v );
    }
}
void bfs(int x) {
    int u, v;
    for (int i=1;i<=n;i++) dist[i] = 0;
    queue <int> q; q.push(x); dist[x] = 1;
    while ( !q.empty() ) {
        u = q.front(); q.pop();
        for (int i=0;i<adj[u].size();i++) {
            v = adj[u][i];
            dist[v] += dist[u];
            q.push( v );
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int caseno = 0, u, v, f, r, cnt, root;
    memset(deg, 0, sizeof(deg));
    while ( scanf("%d %d",&u,&v) && (u >= 0 && v >= 0) ) {
        if (u == 0 && v == 0) {
            printf("Case %d is a tree.\n",++caseno);
            continue;
        }
        n = 0; mx.clear();
        if (!mx[u]) mx[u] = ++n;
        if (!mx[v]) mx[v] = ++n;
        u = mx[u];
        v = mx[v];
        adj[u].pb(v);
        deg[v]++;
        while ( scanf("%d %d",&u,&v) && (u + v)) {
            if (!mx[u]) mx[u] = ++n;
            if (!mx[v]) mx[v] = ++n;
            u = mx[u];
            v = mx[v];
            adj[u].pb(v);
            deg[v]++;
        }
        r = 0; f = 1;
        for (int i=1;i<=n;i++) {
            if (deg[i] == 0) {
                root = i;
                r++;
            }
            else
            if (deg[i] > 1) f = 0;
            mark[i] = 0;
        }
        if (r != 1) f = 0;
        if ( !f ) printf("Case %d is not a tree.\n",++caseno);
        else {
            dfs(root);
            for (int i=1;i<=n;i++)
                if (!mark[i]) f = 0;
            if ( !f ) printf("Case %d is not a tree.\n",++caseno);
            else {
                bfs( root );
                for (int i=1;i<=n;i++) {
                    if (root == i) continue;
                    if (dist[i] != 1) f = 0;
                }
                if (f) printf("Case %d is a tree.\n",++caseno);
                else printf("Case %d is not a tree.\n",++caseno);
            }
        }
        for (int i=1;i<=n;i++) {
            adj[i].clear();
            mark[i] = deg[i] = 0;
        }
    }
}

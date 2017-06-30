/***********************************************
* Author - LUONG VAN DO                        *
* Problem 567 - Risk ->AC 
* Algorithm adhoc
* Time Limit 0.136
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
vector <int> adj[22];
int dist[22];
int bfs(int x, int y) {
    int u, v;
    for (int i=1;i<=20;i++) dist[i] = -1;
    queue <int> q;
    q.push(x); dist[x] = 0;
    while ( !q.empty()) {
        u = q.front(); q.pop();
        if (u == y) return dist[y];
        for (int i=0;i<adj[u].size();i++) {
            v = adj[u][i];
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return 0;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int q, v, caseno = 0, x, y;
    while ( scanf("%d",&q) != EOF) {
        for (int i=1;i<=20;i++) adj[i].clear();
        while (q--) {
            scanf("%d",&v);
            adj[1].pb(v);
            adj[v].pb(1);
        }
        for (int u=2;u<=19;u++) {
            scanf("%d",&q);
            while (q--) {
                scanf("%d",&v);
                adj[u].pb(v);
                adj[v].pb(u);
            }
        }
        printf("Test Set #%d\n",++caseno);
        scanf("%d",&q);
        while (q--) {
            scanf("%d %d",&x,&y);
            printf("%2d to %2d: %d\n",x, y, bfs(x, y));
        }
        puts("");
    }
}

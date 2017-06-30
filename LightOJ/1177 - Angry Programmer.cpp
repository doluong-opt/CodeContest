/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1177 - Angry Programmer ->AC
* Algorithm max_flow
* Time Limit 0.024s
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
#define N 510

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
int n, m, s, t, f;
int c[N][N], p[N], dist[N];
vi adj[N];
void findPath(int v, int minEdge) {
    if (v == s) {
        f = minEdge;
        return;
    }
    else
    if (p[v] != -1) {
        findPath(p[v], min(minEdge, c[p[v]][v]));
        c[p[v]][v]-=f;
        c[v][p[v]]+=f;
    }
}
int max_flow() { 
    int mf = 0, u, v;
    while ( true ) {
        f = 0;
        for (int i=0;i<=t;i++) dist[i] = p[i] = -1;
        queue <int> q; q.push(s); dist[s] = 0;
        while ( !q.empty() ) {
            u = q.front(); q.pop();
            if (u == t) break;
            for (int i=0;i<adj[u].size();i++) {
                v = adj[u][i];
                if (dist[v] == -1 && c[u][v] > 0) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    p[v] = u;
                }
            }
        }
        findPath(t, INF);
        if (!f) break;
        mf+=f;
    }
    return mf;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, x, y, w, caseno = 0;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d",&n,&m);
        s = 1; t = 2 * (n - 1);
        for (int i=0;i<=t;i++) {
            adj[i].clear();
            for (int j=0;j<=t;j++) c[i][j] = 0;
        }
        for (int i=1;i<=n-2;i++) {
            scanf("%d",&x);
            c[2 * i][2 * i + 1] = x;
            adj[2 * i].pb(2 * i + 1);
            adj[2 * i + 1].pb(2 * i);
        }
        for (int i=0;i<m;i++) {
            scanf("%d %d %d",&x,&y,&w);
            x--; y--;
            c[2 * x + 1][2 * y] = w;
            adj[2 * x + 1].pb(2 * y);
            adj[2 * y].pb(2 * x + 1);
            
            c[2 * y + 1][2 * x] = w;
            adj[2 * y + 1].pb(2 * x);
            adj[2 * x].pb(2 * y + 1);
        }
        printf("Case %d: %d\n",++caseno, max_flow());
    }
}

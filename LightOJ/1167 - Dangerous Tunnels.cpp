/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1167 - Dangerous Tunnels ->AC
* Algorithm max_flow
* Time Limit 0.049s
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
#define N 210

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
vector <int> adj[N], adjj[N];
int c[N][N], b[N][N];
int s, t, f;
int n, q, k;
int dist[N], p[N];
void findPath(int v, int minEdge) {
    if (v == s) {
        f = minEdge;
        return;
    }
    else
    if (p[v] != -1) {
        findPath(p[v], min(minEdge, b[p[v]][v]));
        b[p[v]][v]-=f;
        b[v][p[v]]+=f;
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
            for (int i=0;i<adjj[u].size();i++) {
                v = adjj[u][i];
                if (dist[v] == -1 && b[u][v] > 0) {
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
bool check(int X) {
    int v;
    for (int i=0;i<=t;i++) {
        adjj[i].clear();
        for (int j=0;j<=t;j++)
            b[i][j] = 0;
    }
    
    for (int i=0;i<=t;i++)
        for (int j=0;j<adj[i].size();j++) {
            v = adj[i][j];
            if ((c[i][v] > 0 && c[i][v] <= X) || (c[i][v] == INF)) {
                if (i == s || v == t) b[i][v] = INF;
                else b[i][v] = 1;
                adjj[i].pb( v );
                adjj[v].pb( i );
            }
        }
    return max_flow() >=k ;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, ans, lo, hi, caseno = 0;
    int x, y, w;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d",&n);
        s = 0; t = 2 * (n + 2) - 1;
        for (int i=0;i<=t;i++) {
            adj[i].clear();
            for (int j=0;j<=t;j++)
                c[i][j] = 0;
        }
        scanf("%d",&q);
        while (q--) {
            scanf("%d %d %d",&x,&y,&w);
            if (x > y) swap(x, y);
            
            c[2 * x + 1][2 * y] = w;
            adj[2 * x + 1].pb(2 * y);
            adj[2 * y].pb(2 * x + 1);
            
            c[2 * x][2 * x + 1] = INF;
            adj[2 * x].pb(2 * x + 1);
            adj[2 * x + 1].pb(2 * x);
            
            c[2 * y][2 * y + 1] = INF;
            adj[2 * y].pb(2 * y + 1);
            adj[2 * y + 1].pb(2 * y);
        }
        scanf("%d",&k);
        lo = 0; hi = 100000; ans = INF;
        while ( lo <= hi ) {
            int mid = (lo + hi) >> 1;
            if ( check(mid) ) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        if ( ans != INF ) printf("Case %d: %d\n",++caseno, ans);
        else printf("Case %d: no solution\n",++caseno);
    }
}

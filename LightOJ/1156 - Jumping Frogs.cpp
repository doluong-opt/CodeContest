/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1156 - Jumping Frogs ->AC
* Algorithm max_flow
* Time Limit 0.053s
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
#define N 300

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
int n, D, s, t, f;
vii a;
int c[N][N], dist[N], p[N];
void build_graph(int d) {
    s = 2 * n; t = s + 1;
    for (int i=0;i<=t;i++) adj[i].clear();
    for (int i=0;i<n;i++) {
        int type = a[i].ff;
        if (type) c[2 * i][2 * i + 1] = INF;
        else c[2 * i][2 * i + 1] = 1;
        adj[2 * i].pb(2 * i + 1);
        adj[2 * i + 1].pb(2 * i);
    }
    
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++) {
            if (i == j) continue;
            if ( abs(a[i].ss - a[j].ss) <= d ) {
                c[2 * i + 1][2 * j] = INF;
                adj[2 * i + 1].pb(2 * j);
                adj[2 * j].pb(2 * i + 1);
            }
        }
        
    for (int i=0;i<n;i++) {
        if (a[i].ss <= d) {
            c[s][2 * i] = INF;
            adj[s].pb(2 * i);
            adj[2 * i].pb(s);
        }
        
        if (abs(D - a[i].ss) <= d) {
            c[2 * i + 1][t] = INF;
            adj[2 * i + 1].pb(t);
            adj[t].pb(2 * t + 1);
        }
        
    }
}
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
        for (int i=0;i<=2 * n + 1;i++) dist[i] = p[i] = -1;
        dist[s] = 0;
        queue <int> q; q.push(s); dist[s] = 0;
        while (!q.empty()) {
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
        if (mf>=2) break;
    }
    return mf;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, p, ans, lo, hi;
    char c;
    scanf("%d",&cases);
    while (cases--) {
        scanf(" %d %d ",&n,&D);
        a.clear();
        for (int i=0;i<n;i++) {
            scanf(" %c-%d ",&c,&p);
            if (c == 'B') a.pb(ii(1, p));
            else a.pb(ii(0, p));
        }
        lo = 0; hi = D; ans = D;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            build_graph(mid);
            if ( max_flow() >= 2) {
                ans = min(ans, mid);
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        printf("Case %d: %d\n",++caseno, ans);
    }
}

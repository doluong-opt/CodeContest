/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11082 - Matrix Decompressing ->AC
* Algorithm maxflow
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
#define INF 50000000000000LL
#define N 100

using namespace std;

inline int64 max(int64 a, int64 b) { return a > b ? a : b; }
inline int64 min(int64 a, int64 b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int64 r, c;
int64 s, t, f;
int64 a[N][N], dist[N], trace[N];
int64 row[N], col[N], res[N][N];
vector <int64> adj[N];
void findPath(int64 v, int64 minEdge) {
    if (v == s) {
        f = minEdge;
        return;
    }
    else
    if (trace[v] != -1) {
        findPath(trace[v], min(minEdge, a[trace[v]][v]));
        a[trace[v]][v]-=f;
        a[v][trace[v]]+=f;
    }
}
int64 max_flow() {
    int64 mf, u, v;
    mf = 0;
    while ( true ) {
        f = 0;
        for (int i=0;i<=t;i++) {
            dist[i] = -1;
            trace[i] = -1;
        }
        dist[s] = 0;
        queue <int64> q;
        q.push(s); 
        while ( !q.empty() ) {
            u = q.front(); q.pop();
            if (u == t) break;
            for (int i=0;i<adj[u].size();i++) {
                v = adj[u][i];
                if (dist[v] == -1 && a[u][v] > 0) {
                    q.push(v);
                    dist[v] = dist[u] + 1;
                    trace[v] = u;
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
    int cases, caseno = 0;
    scanf("%d",&cases);
    while ( cases-- ) {
        scanf("%lld %lld",&r,&c);
        s = 2 * (r + c) ; t = s + 1;
        for (int i=0;i<=t;i++) {
            adj[i].clear();
            for (int j=0;j<=t;j++)
                a[i][j] = 0;
        }
        
        for (int i=0;i<r;i++) scanf("%lld",&row[i]);
        for (int i=0;i<c;i++) scanf("%lld",&col[i]);
        
        for (int i=0;i<r;i++)
            for (int j=0;j<c;j++) {
                a[2 * i][2 * j + 1] = 19;
                adj[2 * i].pb(2 * j + 1);
                adj[2 * j + 1].pb(2 * i);
            }
            
        for (int i=0;i<r;i++) {
            if (!i) a[s][2 * i] = row[i] - c;
            else a[s][2 * i] = row[i] - row[i - 1] - c;
            adj[s].pb(2 * i);
            adj[2 * i].pb(s);
        }
        for (int i=0;i<c;i++) {
            if (!i) a[2 * i + 1][t] = col[i] - r;
            else a[2 * i + 1][t] = col[i] - col[i - 1] - r;
            adj[2 * i + 1].pb(t);
            adj[t].pb(2 * i + 1);
        }
        max_flow();
        if ( caseno ) puts("");
        printf("Matrix %d\n",++caseno);
        for (int i=0;i<r;i++)
            for (int j=0;j<c;j++)
                res[i][j] = 20 - a[2 * i][2 * j + 1];
                
        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++) {
                if (j) printf(" ");
                printf("%lld",res[i][j]);
            }
            printf("\n");
        }
    }
}

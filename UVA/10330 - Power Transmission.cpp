/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1155 - Power Transmission ->AC
* Algorithm max_flow
* Time Limit 0.028s
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

#define M 210
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
int c[M][M], n, m;
int s, t, f;
int p[N], dist[N];
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
int max_flow(){ 
    int mf = 0, u, v;
    while ( true ) {
        f = 0;
        for (int i=0;i<=2 * n + 1;i++) dist[i] = p[i] = -1;
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
    int cases, x, y, w, B, D;
    while (scanf("%d",&n) != EOF) {
        for (int i=0;i<=2 * n + 1;i++) {
            adj[i].clear();
            for (int j=0;j<=2 * n + 1;j++)
                c[i][j] = 0;
        }
        for (int i=0;i<n;i++) {
            scanf("%d",&w);
            c[2 * i][2 * i + 1] = w;
            adj[2 * i].pb(2 * i + 1);
            adj[2 * i + 1].pb(2 * i);
        }
        scanf("%d",&m);
        for (int i=0;i<m;i++) {
            scanf("%d %d %d",&x,&y,&w);
            x--; y--;
            c[2 * x + 1][2 * y] = w;
            adj[2 * x + 1].pb(2 * y);
            adj[2 * y].pb(2 * x + 1);
        }
        s = 2 * n; t = 2 * n + 1;
        scanf("%d %d",&B, &D);
        for (int i=0;i<B;i++) {
            scanf("%d",&x);
            x--;
            c[s][2 * x] = INF;
            adj[s].pb(2 * x);
            adj[2 * x].pb(s);
        }
        for (int i=0;i<D;i++) {
            scanf("%d",&x);
            x--;
            c[2 * x + 1][t] = INF;
            adj[2 * x + 1].pb(t);
            adj[t].pb(2 * x + 1);
        }
        printf("%d\n",max_flow());
    }
}

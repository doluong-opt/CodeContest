/***********************************************
* Author - LUONG VAN DO                        *
* Problem 563 - Crimewave ->AC
* Algorithm max_flow
* Time Limit 0.404s
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
#define N 5100

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
int dist[N], c[N][N], p[N];
int s, t, f, n, m, b;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool isOk(int x, int y) {
    return (x>=0 && x < m && y>=0 && y < n);
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
int convert(int x, int y) {
    return (x * n + y);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, u, v, x, ans;
    scanf("%d",&cases);
    while ( cases-- ) {
        scanf("%d %d %d",&m,&n,&b);
        s = 2 * (m * n) + 1; t = s + 1;
        for (int i=0;i<=t;i++) {
            adj[i].clear();
            for (int j=0;j<=t;j++)
                c[i][j] = 0;
        }
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                u = convert(i, j);
                c[2 * u][2 * u + 1] = 1;
                adj[2 * u].pb(2 * u + 1);
                adj[2 * u + 1].pb(2 * u);
                for (int k=0;k<4;k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if ( isOk(nx, ny) ) {
                        v = convert(nx, ny);
                        c[2 * u + 1][2 * v] = INF;
                        adj[2 * u + 1].pb(2 * v);
                        adj[2 * v].pb(2 * u + 1);
                    }
                    else {
                        c[2 * u + 1][t] = INF;
                        adj[2 * u + 1].pb(t);
                        adj[t].pb(2 * u + 1);
                    }
                }
            }
        }
        for (int i=0;i<b;i++) {
            scanf("%d %d",&u,&v);
            u--; v--;
            x = convert(u, v);
            c[s][2 * x] = 1;
            adj[s].pb(2 * x);
            adj[2 * x].pb(s);
        }
        if ( max_flow() == b ) puts("possible");
        else puts("not possible");
    }
}

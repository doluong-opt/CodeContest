/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1262 - Diagonal Sum 
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
int r, c, di, s, t, f;
int d1[N], d2[N], dist[N], p[N];
int i1[N][N], i2[N][N];
int a[N][N];
void init() {
    int u, v, x;
    for (int i=0;i<r;i++) {
        u = i; v = 0;
        while (u>=0 && v < c) i1[u--][v++] = i;
    }
    x = r;
    for (int i=1;i<c;i++) {
        u = r - 1; v = i;
        while (u>=0 && v < c) i1[u--][v++] = x;
        x++;
    }
    
    for (int i=0;i<r;i++) {
        u = i; v = c - 1;
        while (u>=0 && v>=0) i2[u--][v--] = i;
    }
    x = r;
    for (int i=c-2;i>=0;i--) {
        u = r - 1; v = i;
        while (u>=0 && v>=0) i2[u--][v--] = x;
        x++;
    }
}
void findPath(int v, int minEdge) {
    if (v == s) {
        f = minEdge;
        return;
    }
    else
    if (p[v] != -1) {
        findPath(p[v], min(minEdge, a[p[v]][v]));
        a[p[v]][v]-=f;
        a[v][p[v]]+=f;
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
                if (dist[v] == -1 && a[u][v] > 0) {
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
    int cases, x, y, ans, caseno = 0;
    scanf("%d",&cases);
    while ( cases-- ) {
        scanf("%d %d",&r, &c);
        di = r + c - 1;
        for (int i=0;i<di;i++) scanf("%d",&d1[i]);
        for (int i=0;i<di;i++) scanf("%d",&d2[i]);
        init();
        s = 2 * di; t = s + 1;
        for (int i=0;i<=t;i++) {
            adj[i].clear();
            for (int j=0;j<=t;j++)
                a[i][j] = 0;
        }
        
        for (int i=0;i<r;i++)
            for (int j=0;j<c;j++) {
                d1[i1[i][j]]--;
                d2[i2[i][j]]--;
            }
            
        for (int i=0;i<di;i++) {
            a[s][2 * i] = d1[i];
            adj[s].pb(2 * i);
            adj[2 * i].pb(s);
            
            a[2 * i + 1][t] = d2[i];
            adj[t].pb(2 * i + 1);
            adj[2 * i + 1].pb( t );
        }
        
        for (int i=0;i<r;i++)
            for (int j=0;j<c;j++) {
                x = 2 * i1[i][j];
                y = 2 * i2[i][j] + 1;
                a[x][y] = 99;
                adj[x].pb(y);
                adj[y].pb(x);
            }
        ans = max_flow();
        printf("Case %d:\n",++caseno);
        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++) {
                x = 2 * i1[i][j];
                y = 2 * i2[i][j] + 1;
                if (j) printf(" ");
                printf("%d", 100 - a[x][y]);
            }
            puts("");
        }
    }
}

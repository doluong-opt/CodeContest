/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1154 - Penguins ->AC
* Algorithm max flow
* Time Limit 1.988s
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
struct node{
    int x, y, s1, s2;
    node(){}
    node(int xx, int yy, int ss1, int ss2){
        x = xx; y = yy; s1 = ss1; s2 = ss2;
    }
};

double D;
int n, f, s;
vector <int> adj[N];
node p[N];
int c[210][210], dist[N], trace[N];
int cc[210][210];
vector <int> res;
void copy(int a[210][210], int b[210][210]) {
    for (int i=0;i<=2 * n;i++)
        for (int j=0;j<=2 * n;j++) b[i][j] = a[i][j];
}
int64 Distance(node a, node b) {
    int64 dx = a.x - b.x;
    int64 dy = a.y - b.y;
    return (dx * dx + dy * dy);
}
void findPath(int v, int minEdge) {
    if (v == s) {
        f = minEdge;
        return;
    }
    else
    if (trace[v] != -1) {
        findPath(trace[v], min(minEdge, c[trace[v]][v]));
        c[trace[v]][v]-=f;
        c[v][trace[v]]+=f;
    }
}
int max_flow(int s, int t) {
    int mf, u, v;
    mf = 0;
    while ( true ) {
        f = 0;
        for (int i=0;i<=2 * n;i++) {
            dist[i] = -1;
            trace[i] = -1;
        }
        dist[s] = 0;
        queue <int> q;
        q.push(s); 
        while ( !q.empty() ) {
            u = q.front(); q.pop();
            if (u == t) break;
            for (int i=0;i<adj[u].size();i++) {
                v = adj[u][i];
                if (dist[v] == -1 && c[u][v] > 0) {
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
    int cases, total, caseno = 0;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %lf",&n,&D);
        D = D * D; res.clear();
        total = 0;
        for (int i=0;i<n;i++) {
            scanf("%d %d %d %d",&p[i].x,&p[i].y,&p[i].s1,&p[i].s2);
            total+=p[i].s1;
        }
        for (int i=0;i<=2 * n;i++) {
            adj[i].clear();
            for (int j=0;j<=2 * n;j++)
                c[i][j] = 0;
        }
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++) {
                if (i == j) continue;
                if (Distance(p[i], p[j]) <= D) {
                    c[i + n][j] = INF;
                    adj[i + n].pb(j);
                    adj[j].pb(i + n);
                }
            }
        s = (2 * n);
        for (int i=0;i<n;i++) {
            c[s][i] = p[i].s1;
            adj[s].pb(i);
            adj[i].pb(s);
            
            c[i][i + n] = p[i].s2;
            adj[i].pb(i + n);
            adj[i + n].pb(i);
        }
        copy(c, cc);
        for (int i=0;i<n;i++) {
            if (max_flow(s, i) == total) res.pb( i );
            copy(cc, c);
        }
        if (!res.size()) printf("Case %d: -1\n",++caseno);
        else {
            printf("Case %d:",++caseno);
            for (int i=0;i<res.size();i++) printf(" %d",res[i]);
            printf("\n");
        }
    }
}

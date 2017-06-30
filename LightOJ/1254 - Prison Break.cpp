/***********************************************
* Author - LUONG VAN DO                        *
* 1254 - Prison Break ->AC
* Algorithm dijkstra + priotity
* Time Limit 0.053s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
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
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 105
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct edge{
    int node, gas, cost;
    edge(){}
    edge(int nn, int gg, int cc){
        node = nn; gas = gg; cost = cc;
    }
    bool operator < (const edge &other) const{
        return cost > other.cost;
    }
};
int n, m;
vector <edge> adj[maxN];
int d[maxN][maxN];
int g[maxN];
int solve(int c, int s, int t){
    REP(i, n)
        REP(j, c + 1) d[i][j] = INF;
    d[s][0] = 0;
    priority_queue <edge> Q;
    Q.push(edge(s, 0, 0));
    while ( !Q.empty() ) {
        edge u = Q.top(); Q.pop();
        
        if (u.node == t) return u.cost;
        if (u.gas < c && u.cost + g[u.node] < d[u.node][u.gas + 1]) {
            d[u.node][u.gas + 1] = u.cost + g[u.node];
            Q.push(edge(u.node, u.gas + 1, u.cost + g[u.node]));
        }
        
        for (int i=0;i<adj[u.node].size();i++){
            int v = adj[u.node][i].node;
            int w = adj[u.node][i].cost;
            if (u.gas>=w) {
                int newgas = u.gas - w;
                if (d[v][newgas] > u.cost) {
                    d[v][newgas] = u.cost;
                    Q.push(edge(v, newgas, u.cost));
                }
            }
        }
    }
    return INF;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, u, v, w, q, c, s, tt, ans;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&n,&m);
        REP(i, n) scanf("%d",&g[i]);
        REP(i, n) adj[i].clear();
        REP(i, m) {
            scanf("%d %d %d",&u,&v,&w);
            adj[u].pb(edge(v, 0, w));
            adj[v].pb(edge(u, 0, w));
        }
        printf("Case %d:\n",t);
        scanf("%d",&q);
        while ( q--) {
            scanf("%d %d %d",&c,&s,&tt);
            ans = solve(c, s, tt);
            if (ans != INF) printf("%d\n",ans);
            else printf("impossible\n");
        }
    }
    return 0;
}

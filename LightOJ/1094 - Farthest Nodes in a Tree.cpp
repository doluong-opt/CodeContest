/***********************************************
* Author - LUONG VAN DO                        *
* 1094 - Farthest Nodes in a Tree ->AC
* Algorithm dfs
* Time Limit 0.19s
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
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 50001
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, r1, r2, s;
vector <ii> adj[maxN];
int color[maxN], dist[maxN];
void dfs(int u){
    if (color[u]) return;
    color[u] = 1;
    REP(i, adj[u].size()) {
        int v = adj[u][i].A;
        int w = adj[u][i].B;
        if (!color[v]) {
            dist[v] = dist[u] + w;
            dfs( v );
        }
    }
}
int solve(){
    int node;
    REP(i, n) {
        color[i] = 0;
        dist[i] = 0;
    }
    dfs( 0 );
    node = 0;
    REP(i, n)
        if (dist[node] < dist[i]) node = i;
    REP(i, n) {
        color[i] = 0;
        dist[i] = 0;
    }
    dfs( node );
    REP(i, n)
        if (dist[node] < dist[i]) node = i;
    return dist[node];
}
void Read_Input(){
    int test,u,v,w;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d",&n);
        REP(i, n) adj[i].clear();
        FOR(i,1,n-1) {
            scanf("%d %d %d",&u,&v,&w);
            adj[u].pb(ii(v, w));
            adj[v].pb(ii(u, w));
        }
        printf("Case %d: %d\n",t,solve());
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

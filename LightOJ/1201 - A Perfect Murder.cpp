/***********************************************
* Author - LUONG VAN DO                        *
* 1201 - A Perfect Murder ->AC
* Algorithm Bipartite Matching
* Time Limit 0.013s
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
#define maxN 1001

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, m, r1, r2;
vector <int> adj[maxN];
int color[maxN];
int distx[maxN], disty[maxN];
int matchx[maxN], matchy[maxN];
bool bfs(){
    bool found = false;
    queue <int> Q;
    FOR(i, 1, n) {
        distx[i] = disty[i] = 0;
        if ( !matchx[i] ) Q.push( i );                
    }
    while ( !Q.empty() ) {
        int u = Q.front(); Q.pop();
        REP(i, adj[u].size()) {
            int v = adj[u][i];
            if ( !disty[v] ) {
                disty[v] = distx[u] + 1;
                if ( !matchy[v] ) found = true;
                else {
                    distx[ matchy[v] ] = disty[v] + 1;
                    Q.push( matchy[v] );
                }                                
            }
        }
    }
    return found;
}
bool dfs(int u){
    REP(i, adj[u].size()){
        int v = adj[u][i];
        if ( disty[v] == distx[u] + 1 ){
            disty[v] = 0;
            if ( !matchy[v] || dfs( matchy[v] ) ){
                matchx[u] = v;
                matchy[v] = u;
                return true;
            }
        }
    }
    return false;
}
int solve() {
    int cnt = 0;
    FOR(i, 1, n) matchx[i] = matchy[i] = 0;
    while ( bfs() ) {
        FOR(i, 1, n)
            if ( !matchx[i] && dfs( i ) ) cnt++;
    }
    return n - (cnt / 2);
}
void Read(){
    int test, u, v;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&n,&m);
        FOR(i, 1, n) adj[i].clear();
        FOR(i, 1, m) {
            scanf("%d %d",&u,&v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        printf("Case %d: %d\n",t,solve());
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

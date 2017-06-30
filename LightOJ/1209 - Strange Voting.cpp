/***********************************************
* Author - LUONG VAN DO                        *
* 1209 - Strange Voting ->AC
* Algorithm bipartite matching
* Time Limit 0.058s
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
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node{
    string mm, ff;
    node(){}
    node(string xx, string yy){
        mm = xx; ff = yy;
    }
};
int n, m, v;
vector <int> adj[maxN];
int color[maxN];
int distx[maxN], disty[maxN];
int matchx[maxN], matchy[maxN];
node edge[maxN];
bool bfs(){
    bool found = false;
    queue <int> Q;
    FOR(i, 1, v) {
        distx[i] = 0;
        if ( !matchx[i] ) Q.push( i );                
    }
    FOR(i, 1, v) disty[i] = 0;
    while ( !Q.empty() ) {
        int u = Q.front(); Q.pop();
        REP(i, adj[u].size()) {
            int vv = adj[u][i];
            if ( !disty[vv] ) {
                disty[vv] = distx[u] + 1;
                if ( !matchy[vv] ) found = true;
                else {
                    distx[ matchy[vv] ] = disty[vv] + 1;
                    Q.push( matchy[vv] );
                }
            }
        }
    }
    return found;
}
bool dfs(int u){
    REP(i, adj[u].size()){
        int vv = adj[u][i];
        if ( disty[vv] == distx[u] + 1 ){
            disty[vv] = 0;
            if ( !matchy[vv] || dfs( matchy[vv] ) ){
                matchx[u] = vv;
                matchy[vv] = u;
                return true;
            }
        }
    }
    return false;
}
int solve() {
    int cnt = 0;
    FOR(i, 1, v) matchx[i] = 0;
    FOR(i, 1, v) matchy[i] = 0;
    while ( bfs() ) {
        FOR(i, 1, v)
            if ( !matchx[i] && dfs( i ) ) cnt++;
    }
    return v - (cnt / 2);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    string x, y;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d %d",&m,&n,&v);
        FOR(i, 1, v) adj[i].clear();
        FOR(i, 1, v) {
            cin >> x >> y;
            edge[i] = node(x, y);
        }
        FOR(i, 1, v - 1)
            FOR(j, i + 1, v)
                if ( (edge[i].mm == edge[j].ff ) || (edge[i].ff == edge[j].mm) ) {
                    adj[i].pb( j );
                    adj[j].pb( i );
                }
        printf("Case %d: %d\n",t,solve());
    }
    return 0;
}

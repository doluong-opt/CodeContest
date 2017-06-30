/***********************************************
* Author - LUONG VAN DO                        *
* 1184 - Marriage Media ->AC 
* Algorithm Bipartite Matching
* Time Limit 0.003s
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
#define maxN 55

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int m, n;
int h1[maxN], h2[maxN];
int a1[maxN], a2[maxN];
int d1[maxN], d2[maxN];
vector <int> adj[maxN];
int distx[maxN], disty[maxN];
int Matchx[maxN], Matchy[maxN];
bool bfs(){
    bool found = 0;
    int u,v;
    queue <int> Q;
    FOR(i, 1, m) {
        if ( !Matchx[i] ) Q.push( i );
        distx[i] = 0;
    }
    FOR(i, 1, n) disty[i] = 0;
    while ( !Q.empty() ) {
        u = Q.front(); Q.pop();
        REP(i, adj[u].size() ) {
            v = adj[u][i];
            if ( !disty[v] ) {
                disty[v] = distx[u] + 1;
                if ( !Matchy[v] ) found = true;
                else {
                    distx[ Matchy[v] ] = disty[v] + 1;
                    Q.push( Matchy[v] );
                }
            }
        }
    }
    return found;
}
bool dfs(int u){
    REP(i, adj[u].size() ) {
        int v = adj[u][i];
        if ( disty[v] == distx[u] + 1 ) {
            disty[v] = 0;
            if ( !Matchy[v] || dfs( Matchy[v] ) ) {
                Matchx[u] = v;
                Matchy[v] = u;
                return true;
            }
        }
    }
    return false;
}
int solve() {
    int res = 0;
    FOR(i, 1, m)
        FOR(j, 1, n)
            if ( abs(h1[i] - h2[j])<=12 && abs(a1[i] - a2[j]) <=5 && d1[i] == d2[j]) adj[i].pb( j );
    FOR(i, 1, m) Matchx[i] = 0;
    FOR(i, 1, n) Matchy[i] = 0;
    while ( bfs() ) {
        FOR(i, 1, m)
            if ( !Matchx[i] && dfs(i) ) res++;
    }
    return res;
}
void Read() {
    int test;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&m,&n);
        FOR(i, 1, max(n,m)) adj[i].clear();
        FOR(i, 1, m) scanf("%d %d %d",&h1[i],&a1[i],&d1[i]);
        FOR(i, 1, n) scanf("%d %d %d",&h2[i],&a2[i],&d2[i]);
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

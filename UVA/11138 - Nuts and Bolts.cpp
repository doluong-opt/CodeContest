/***********************************************
* Author - LUONG VAN DO                        *
* 11138 - Nuts and Bolts ->AC
* Algorithm Bipartite graph
* Time Limit 0.108s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define For(i, a, b) for (int i=a; i<=b; i++)
#define Ford(i,a,b) for (int i=a;i>=b;i--)
#define Rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 50005
using namespace std;
int MatchX[maxN], MatchY[maxN];
int DistX[maxN], DistY[maxN];
vector <int> adj[maxN];
int rs, n ,m;
bool bfs(){
    int u,v,found;
    queue <int> Q;
    For(i,1,m) {
        DistX[i] = 0;
        if (!MatchX[i]) Q.push( i );
    }
    For(i,1,n) DistY[i] = 0;
    found = 0;
    while ( !Q.empty() ){
        u = Q.front(); Q.pop();
        Rep(i,adj[u].size()) {
            v = adj[u][i];
            if (!DistY[v]) {
                DistY[v] = DistX[u] + 1;
                if (!MatchY[v]) found = 1;
                else {
                    DistX[ MatchY[v] ] = DistY[v] + 1;
                    Q.push( MatchY[v] );
                }
            }
        }
    }
    return found;
}
bool dfs(int u){
    int v;
    Rep(i,adj[u].size()){
        v = adj[u][i];
        if (DistY[v] == DistX[u] + 1) {
            DistY[v] = 0;
            if ( !MatchY[v] || dfs( MatchY[v] ) ){
                MatchX[u] = v;
                MatchY[v] = u;
                return true;
            }
        }
    }
    return false;
}
void Solve(int Case){
    
    For(i,1,m) MatchX[i] = 0;
    For(j,1,n) MatchY[j] = 0;
    rs = 0;
    while ( bfs() ){
        For(i,1,m)
            if (!MatchX[i] && dfs( i )) rs++;
    }
    printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",Case,rs);
}
void Read_Input(){
    int t,Case = 0;
    scanf("%d",&t);
    while (t--){
        scanf("%d %d",&m,&n);
        for (int i=1;i<=500;i++) adj[i].clear();
        For(i,1,m)
            For(j,1,n) {
                int b;
                scanf("%d",&b);
                if (b) adj[i].pb(j);
            }
        Solve(++Case);
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    //Write_Output();
}

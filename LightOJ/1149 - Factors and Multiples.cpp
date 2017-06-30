/***********************************************
* Author - LUONG VAN DO                        *
* 11159 - Factors and Multiples ->AC
* Algorithm Bipartite graph
* Time Limit 0.004s
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
#define maxN 105
using namespace std;
int n,m,rs;
int a[maxN], b[maxN];
int MatchX[maxN], MatchY[maxN];
int DistX[maxN], DistY[maxN];
vector <int> adj[maxN];
bool bfs(){
    int u,v,found;
    queue <int> Q;
    For(i,1,m) {
        DistX[i] = 0;
        if ( !MatchX[i] ) Q.push(i);
    }    
    For(i,1,n) DistY[i] = 0;
    found = 0;
    while ( !Q.empty()  ){
        u = Q.front(); Q.pop();
        Rep(i,adj[u].size()){
            v = adj[u][i];
            if ( !DistY[v] ) {
                DistY[v] = DistX[u] + 1;
                if ( !MatchY[v] ) found = 1;
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
            if (!MatchY[v] || dfs( MatchY[v] )) {
                MatchX[u] = v;
                MatchY[v] = u;
                return true;
            }
        }
    }
    return false;
}
void Solve(int Case){
    rs = 0;
    For(i,1,n) MatchY[i] = 0;
    For(i,1,m) MatchX[i] = 0;
    For(i,1,n)
        For(j,1,m) {
            if (!a[i] && !b[j]) adj[j].pb( i );
            if (!a[i]) continue;
            else
                if (b[j] % a[i] == 0) adj[j].pb( i );
        }
    while ( bfs() ){
        For(i,1,m)
            if (!MatchX[i] && dfs(i)) rs++;
    }
    printf("Case %d: %d\n",Case,rs);
}
void Read_Input(){
    int t, Case = 0;
    scanf("%d",&t);
    while (t--){
        For(i,1,100) adj[i].clear();
        scanf("%d",&n);
        For(i,1,n) scanf("%d",&a[i]);
        scanf("%d",&m);     
        For(i,1,m)
        scanf("%d",&b[i]);
        Solve(++Case);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

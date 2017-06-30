/***********************************************
* Author - LUONG VAN DO                        *
* MATCH1 ->AC
* Algorithm Cap Ghep Cuc Dai
* Time Limit 0.01s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <map>
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
#define maxN 101
using namespace std;
vector <int> adj[maxN];
int MatchX[maxN], MatchY[maxN];
int Distx[maxN], Disty[maxN];
int nm,m,n;
void Read_Input(){
    int u,v;
    scanf("%d %d",&n,&m);
    while ( scanf("%d %d",&u,&v)!=EOF)
        adj[u].pb( v );
}
bool bfs(){
    queue <int> Q;
    int found = 0;
    For(i,1,m) Disty[i] = 0;
    For(i,1,n)
    {
        Distx[i] = 0;
        if ( !MatchX[i] ) Q.push( i );
    }
    while ( !Q.empty() )
    {
        int u = Q.front(); Q.pop();
        Rep(i,adj[u].size())
        {
            int v = adj[u][i];
            if ( !Disty[v] )
            {
                Disty[v] = Distx[u] + 1;
                if ( !MatchY[v] ) found = 1;
                else
                {
                    Distx[ MatchY[v] ] = Disty[v] + 1;
                    Q.push( MatchY[v] );
                }
            }
        }
    }
    return found;
}
bool dfs(int u){
    Rep(i,adj[u].size())
    {
        int v = adj[u][i];
        if ( Disty[v] == Distx[u] + 1)
        {
            Disty[v] = 0;
            if ( !MatchY[v] || dfs( MatchY[v] ) )
            {
                MatchX[u] = v;
                MatchY[v] = u;
                return true;
            }
        }
    }
    return false;
}
void Solve(){
    nm = 0;
    For(i,1,n) MatchX[i] = 0;
    For(i,1,m) MatchY[i] = 0;
    while ( bfs() )
    {
        For(i,1,n)
            if ( !MatchX[i] && dfs(i)) nm++;
    }
}
void Write_Output(){
    printf("%d\n",nm);
    For(i,1,n)
        if ( MatchX[i] ) printf("%d %d\n",i,MatchX[i]);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}

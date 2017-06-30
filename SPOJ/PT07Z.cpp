/***********************************************
* Author - LUONG VAN DO                        *
* PT07Z ->AC
* Algorithm dp on tree
* Time Limit 0.06s
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
#define maxN 10001
using namespace std;
vector <int> adj[maxN];
int color[maxN], Dist[maxN];
int n;
void Read_Input(){
    scanf("%d",&n);
    For(i,1,n-1)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].pb( v );
        adj[v].pb( u );
    }
}
int dfs(int u, int Count)
{
    color[u] = 1;
    Dist[u] = Count;
    Rep(i,adj[u].size())
    {
        int v = adj[u][i];
        if ( !color[v] )
        dfs(v,Count + 1);
    }
}
void Solve(){
    For(i,1,n) color[i] = 0;
    dfs(1,0);
    int node = 1;
    For(i,1,n)
        if ( Dist[i] > Dist[node] ) node = i;
    For(i,1,n) color[i] = 0;
    dfs(node,0);
    sort(Dist+1,Dist+n+1);
}
void Write_Output(){
    printf("%d\n",Dist[n]);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}

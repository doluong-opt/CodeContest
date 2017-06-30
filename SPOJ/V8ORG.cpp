/***********************************************
* Author - LUONG VAN DO                        *
* V8ORG ->AC
* Algorithm DFS
* Time Limit 0.08s
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
#define maxN 10005
using namespace std;
vector <int> adj[maxN];
int color[maxN], f[maxN];
int rs, k, n;
void Read_Input(){
    scanf("%d %d",&k,&n);
    For(i,2,n)
    {
        int u;
        scanf("%d",&u);
        adj[u].pb( i );
    }
}
void dfs(int u){
    int v;
    f[u] = 1;
    color[u] = 1;
    Rep(i,adj[u].size())
    {
        v = adj[u][i];
        if ( !color[v] )
        dfs( v );
        f[u] = f[u] + f[v];
    }
    if (f[u]>=k)
    {
        f[u] = 0;
        rs++;
    }
}
void Solve(){
    rs = 0;
    dfs( 1 );
}
void Write_Output(){
    printf("%d\n",rs);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}

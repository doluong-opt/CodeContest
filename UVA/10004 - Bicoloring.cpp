/***********************************************
* Author - LUONG VAN DO                        *
* 10004 - Bicoloring ->AC
* Algorithm dfs
* Time Limit 0.008s
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
#define maxN 305
using namespace std;
int n, m;
int adj[maxN][maxN];
int color[maxN];
int Visit[maxN];
bool dfs(int n, int node){
    Rep(i,n) {
        if ( adj[node][i] && !Visit[i]) {
            Visit[node] = 1;
            if (color[node]==1) {
                if (!color[i]) color[i] = 2;
                else if (color[i]==1) return false;
            }
            else {
                if (!color[i]) color[i] = 1;
                else if (color[i]==2) return false;
            }
            dfs(n,i);
        }
    }
    return true;
}
void Solve(){
    Rep(i,n) {
        color[i] = 0;
        Visit[i] = 0;
    }
    color[0] = 1;
    if ( dfs(n,0) ) puts("BICOLORABLE.");
    else puts("NOT BICOLORABLE.");
}
void Read_Input(){
    while (scanf("%d",&n) && n){
        Rep(i,n)
            Rep(j,n) adj[i][j] = 0;
        scanf("%d",&m);
        For(i,1,m) {
            int u,v;
            scanf("%d %d",&u,&v);
            adj[u][v] = adj[v][u] = 1;
        }
        Solve();
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

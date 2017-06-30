/***********************************************
* Author - LUONG VAN DO                        *
* 10305 - Ordering Tasks ->AC
* Algorithm sort Topo
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
#define maxN 101
using namespace std;
int n,m,ind;
int adj[maxN][maxN];
int color[maxN], qu[maxN], idx[maxN];
void dfs(int u){
    color[u] = 1;
    For(i,1,n)
        if (!color[i] && adj[u][i]) dfs( i );
    idx[ind] = u;
    qu[u] = ind;
    ind--;
}
void Solve(){
    ind = n;
    For(i,1,n)
        if (!color[i]) dfs( i );  
    For(i,1,n) {
        if (i > 1) printf(" ");
        printf("%d",idx[i]);
    }
    puts("");
}
void Read_Input(){
    while (scanf("%d %d",&n,&m) && (n + m)){
        For(i,1,n) {
            color[i] = 0;
            For(j,1,n) adj[i][j] = 0;
        }
        For(i,1,m) {
            int u,v;
            scanf("%d %d",&u,&v);
            adj[u][v] = 1;
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

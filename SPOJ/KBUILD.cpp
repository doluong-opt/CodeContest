/***********************************************
* Author - LUONG VAN DO                        *
* KBUILD
* Algorithm
* Time Limit
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
#define Log2 16
using namespace std;
int n, p;
typedef pair <int, int> ii;
vector <ii> adj[maxN];
vector <ii>:: iterator it;
int anc[maxN][Log2], sum[maxN][Log2];
int color[maxN], d[maxN];
void Read_Input(){
    scanf("%d",&n);
    For(i,1,n-1) {
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].pb(make_pair(v,1));
        //adj[v].pb( u );
    }
}
void bfs(int root){    
    int v,u,k,l;
    queue <int> Q;
    d[root] = 0;
    color[root] = 1;
    Q.push( root );
    while ( !Q.empty() ){
        u = Q.front(); Q.pop();
        for (it=adj[u].begin();it!=adj[u].end();it++) {
            v = it->first;
            l = it->second;
            if (color[v]) continue;
            d[v] = d[u] + 1;
            anc[v][0] = u;
            sum[v][0] = 1;
            k = int(log2(d[v]));
            for (int i=1;i<=k;i++) {
                anc[v][i] = anc[anc[v][i-1]][i-1];
                sum[v][i] = sum[v][i-1] + sum[anc[v][i-1]][i-1];
            }
            color[v] = 1;
            Q.push( v );
        }
    }
}
int Find(int u, int v){
    int k;
    while (d[u]!=d[v]){
        k = int(log2(d[u]-d[v]));
        p+=sum[u][k];
        u = anc[u][k];
    }
    return u;
}
int Write_Output(int u, int v){
    if (d[u] < d[v]) swap(u,v);
    u = Find( u , v);
    if (u!=v) {
        for (int i=(int)log2(d[u]);i>=0;i--){
            if (anc[u][i]!=anc[v][i]) {
                p+=sum[u][i] + sum[v][i];
                u = anc[u][i];
                v = anc[v][i];
            }
        }
        p+=sum[u][0] + sum[v][0];
    }
    //return p;
    return anc[u][0];
}
void Solve(){
    bfs( 1 );
    int m;
    scanf("%d",&m);
    For(i,1,m) {
        int u,v;
        scanf("%d %d",&u,&v);
        p = 0;
        printf("%d\n",Write_Output(u,v));
    }
    //printf("%d\n",m - p);o
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    //Write_Output();
}

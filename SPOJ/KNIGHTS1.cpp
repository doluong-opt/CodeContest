/***********************************************
* Author - LUONG VAN DO                        *
* KNIGHTS1 ->AC
* Algorithm LCA
* Time Limit 0.74s
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
#define maxE 100001
#define maxN 3001
#define LogN 12
using namespace std;
typedef pair <int, int> ii;
typedef struct edge{
    int x,y,l;
    edge(){}
    edge(int xx, int yy, int ll){
        x = xx; y = yy; l = ll;
    }
    bool operator < (edge D) const{
        return ( l < D.l );
    }
};
edge e[maxE];
int Lab[maxN];
int d[maxN];
int anc[maxN][LogN];
int dmax[maxN][LogN];
int n,r;
vector <ii> adj[maxN];
vector <ii>:: iterator it;
int rs;
int color[maxN];
int Get(int v){
    if ( Lab[v] < 0) return v;
    else return Lab[v] = Get( Lab[v] );
}
int Union(int r1, int r2){
    int x = Lab[r1] + Lab[r2];
    if ( Lab[r1] > Lab[r2] ){
        Lab[r1] = r2;
        Lab[r2] = x;        
    }
    else {
        Lab[r1] = x;
        Lab[r2] = r1;
    } 
}
void Read_Input(){
    scanf("%d %d",&n,&r);
    Rep(i,r) {
        int u,v,l;
        scanf("%d %d %d",&u,&v,&l);
        e[i] = edge(u,v,l);
    }
    sort(e,e+r);
}
void Solve(){
    int Count = 0,u,v;
    For(i,1,n) Lab[i] = -1;
    Rep(i,r){
        u = Get( e[i].x ); v = Get( e[i].y );
        if (u!=v) {
            Union(u,v);
            adj[e[i].x].pb(make_pair(e[i].y,e[i].l));
            adj[e[i].y].pb(make_pair(e[i].x,e[i].l));
            if (++Count==n-1) break;
        }
    }
}
void bfs(int root){
    int u,v,w,k;
    color[root] = 1;
    d[root] = 0;
    queue <int> Q;
    Q.push( root );
    while ( !Q.empty() ){
        u = Q.front(); Q.pop();
        for (it=adj[u].begin(); it!=adj[u].end();it++){
            v = it->first;
            w = it->second;
            if (color[v]) continue;
            d[v] = d[u] + 1;
            anc[v][0] = u;
            dmax[v][0] = w;
            k = (int)log2(d[v]);
                for (int i=1;i<=k;i++) {
                    anc[v][i] = anc[anc[v][i-1]][i-1];
                    dmax[v][i] = max(dmax[v][i-1], dmax[anc[v][i-1]][i-1]);
                }
            color[v] = 1;
            Q.push( v );
        }
    }
}
int Find(int u, int v){
    int k;
    while (d[u]!=d[v]) {
        k = (int)log2(d[u] - d[v]);
        rs = max(rs, dmax[u][k]);
        u = anc[u][k];
    }
    return u;
}
void Cal(int u, int v){
    if (d[u] < d[v] ) swap(u,v);
    u = Find(u,v);
    if (u!=v) {
        for (int i=(int)log2(d[u]);i>=0;i--)
            if ( anc[u][i]!=anc[v][i] ) {
                rs = max(rs, max(dmax[u][i], dmax[v][i]));
                u = anc[u][i];
                v = anc[v][i];
            }
        rs = max(rs, max( dmax[u][0], dmax[v][0]));
    }
}
void Write_Output(){
    int m;
    bfs( 1 );
    scanf("%d",&m);
    Rep(i,m){
        int u,v;
        scanf("%d %d",&u,&v);
        rs = -INF;
        Cal(u,v);
        printf("%d\n",rs);
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}

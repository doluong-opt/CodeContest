/***********************************************
* Author - LUONG VAN DO                        *
* 1208 - Oreon ->AC
* Algorithm Kruskal
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
#define maxN 50001
using namespace std;
struct node{
    int u,v,x;
    bool Mark;
    node(){}
    node(int uu, int vv, int xx){
        u = uu; v = vv; x = xx;
    }
    bool operator < (node D) const{
        return x < D.x;
    }
};
char s[maxN];
node edge[maxN];
node ed[maxN];
int a[27][27];
int Lab[maxN];
int m,n;
int Get(int v){
    if (Lab[v] < 0) return v;
    else return Lab[v] = Get( Lab[v] );
}
void Union(int r1, int r2){
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
bool cmp(node c, node d){
    if (c.x!=d.x) return c.x < d.x;
    else
    if (c.u!=d.u) return c.u < d.u;
    else
    return c.v < d.v;
}
void Solve(int Case) {
    int cnt = 0,u,v;
    sort(edge+1,edge+1+m);
    Rep(i,n)
        Lab[i] = -1;
    For(i,1,m) edge[i].Mark = false;
    //For(i,1,m) cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].x<<endl;
    For(i,1,m) {
        u = Get(edge[i].u); v = Get(edge[i].v);
        if (u!=v) {
            Union(u,v);
            edge[i].Mark = true;
            if (++cnt==n-1) break;
        }
    }
    printf("Case %d:\n",Case);
    int nn = 0;
    For(i,1,m)
        if (edge[i].Mark) {
            if (edge[i].u > edge[i].v) swap(edge[i].u,edge[i].v);
            ed[++nn] = node(edge[i].u,edge[i].v,edge[i].x);
        }
    sort(ed+1,ed+1+nn,cmp);
    For(i,1,nn)
        printf("%c-%c %d\n",ed[i].u+65,ed[i].v+65,ed[i].x);
}
void Process(int u){
    int l = strlen(s);
    int i = 0,v = -1, val;
    while (i < l) {
        while (i<l && s[i]==' ') ++i;
        ++v;
        sscanf(s+i,"%d",&val);
        if (val && !a[u][v]) {
            edge[++m] = node(u,v,val);
            edge[++m] = node(v,u,val);
            a[u][v] = 1;
            a[v][u] = 1;
        }
        while (i<l && s[i]!=' ') ++i;
        ++i;
    }
}
void Read_Input() {
    int t, Case;
    scanf("%d",&t);
    Case = 0;
    while (t--) {
        m = 0;
        scanf("%d ",&n);
        Rep(i,27)
            Rep(j,27) a[i][j] = 0;
        Rep(i,n) {
            gets(s);
            Process( i );
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

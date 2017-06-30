/***********************************************
* Author - LUONG VAN DO                        *
* PWRFAIL ->AC
* Algorithm dijkstra heap
* Time Limit 1.85s
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
#define maxN 50001
#define esp 1e-7
using namespace std;
struct point
{
    double x,y;
};
vector < pair <int, double> > adj[maxN];
int n,w;
int pos[maxN], heap[maxN], color[maxN];
double d[maxN], m;
point a[maxN];
int nheap;
void update(int v){
    int child, parent;
    child = pos[v];
    if (!child) child = ++nheap;
    parent = child >> 1;
    while ( parent > 0 && d[heap[parent]] > d[v]+ esp)
    {
        heap[child] = heap[parent];
        pos[heap[child]] = child;
        child = parent;
        parent = child >> 1;        
    }
    heap[child] = v;
    pos[v] = child;
}
int Pop(){
    int u,v,r;
    u = heap[1];
    v = heap[nheap--];
    r = 1;
    while ( 2 * r<=nheap)
    {
        int c = 2 * r;
        if ( c < nheap && d[heap[c+1]] + esp < d[heap[c]]) ++c;
        if ( d[v] + esp < d[heap[c]] || fabs(d[v] - d[heap[c]]) < esp) break;
        heap[r] = heap[c];
        pos[heap[r]] = r;
        r = c;
    }
    heap[r] = v;
    pos[v] = r;
    return u;
}
double Dist(point a1, point a2){
    double dx,dy;
    dx = a1.x - a2.x;
    dy = a1.y - a2.y;
    return sqrt(dx * dx + dy * dy);
}
void Read_Input(){
    scanf("%d %d",&n,&w);
    scanf("%lf",&m);
    Rep(i,n) scanf("%lf %lf",&a[i].x,&a[i].y);
    for (int i=0;i<n-1;i++)    
        for (int j=i+1;j<n;j++)
        {
            double dd = Dist(a[i],a[j]);
            if (dd + esp < m || fabs(dd - m) < esp)
            {
                adj[i].pb(make_pair(j,dd));
                adj[j].pb(make_pair(i,dd));
            }
        }
    Rep(i,w)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        u--; v--;
        adj[u].pb(make_pair(v,0.0));
        adj[v].pb(make_pair(u,0.0));
    }
}
void Solve(){
    nheap = 0;
    Rep(i,n)    
    {
        d[i] = INF;
        pos[i] = heap[i] = 0;
        color[i] = 0;
    }
    d[0] = 0.0; update( 0 );
    while ( nheap )
    {
        int u = Pop();
        color[u] = 1;
        Rep(i,adj[u].size())
        {
            int v = adj[u][i].first;
            double w = adj[u][i].second;
            if (!color[v])
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                update( v );                
            }
        }
    }
}
void Write_Output(){
    if (d[n-1]!=INF) printf("%d\n",int(d[n-1]*1000));
    else puts("-1");
}
main(){    
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}

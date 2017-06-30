/***********************************************
* Author - LUONG VAN DO                        *
* QBSCHOOL ->AC
* Algorithm Dijkstra heap + Dp
* Time Limit 0.57s
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
#define maxN 5001
using namespace std;
typedef pair <int,int> ii;
vector <ii> adj[maxN];
int64 d[maxN], sl[maxN];
int pos[maxN], heap[maxN], nheap,n,m;
int color[maxN];
void update(int v){
    int Child, Parent;
    Child = pos[v];
    if (!Child) Child = ++nheap;
    Parent = Child >> 1;
    while ( Parent > 0 && d[heap[Parent]] > d[v] )
    {
        heap[Child] = heap[Parent];
        pos[heap[Child]] = Child;
        Child = Parent;
        Parent = Child >> 1;
    }
    heap[Child] = v;
    pos[v] = Child;
}
int Pop(){
    int u,v,r;
    u = heap[1];
    v = heap[nheap--];
    r = 1;
    while ( 2 * r<=nheap)
    {
        int c = 2 * r;
        if (c < nheap && d[heap[c+1]] < d[heap[c]]) ++c;
        if (d[v]<=d[heap[c]]) break;
        heap[r] = heap[c];
        pos[heap[r]] = r;
        r = c;
    }
    heap[r] = v;
    pos[v] = r;
    return u;       
}
void Read_Input(){
    scanf("%d %d",&n,&m);
    For(i,1,m)
    {
        int q,u,v,len;
        scanf("%d %d %d %d",&q,&u,&v,&len);
        if ( q == 1 ) adj[u].pb(make_pair(v,len));
        else
        {
            adj[u].pb(make_pair(v,len));
            adj[v].pb(make_pair(u,len));
        }
    }
}
void Solve(){
    For(i,1,n)
    {
        d[i] = INF; color[i] = 0;
        pos[i] = heap[i] = sl[i] = 0;
    }
    d[1] =  nheap = 0; sl[1] = 1;
    update( 1 );
    while ( nheap )
    {
        int u = Pop();
        color[u] = 1;
        Rep(i,adj[u].size())
        {
            int v = adj[u][i].first;
            int l = adj[u][i].second;
            if (!color[v])
            {
                if ( d[v] > d[u] + l)
                {
                    d[v] = d[u] + l;
                    sl[v] = sl[u];
                    update( v );
                }
                else
                if ( d[v] == d[u] + l) sl[v]+=sl[u];
            }
        }
    }
}
void Write_Output(){
    printf("%lld %lld\n",d[n],sl[n]);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();    
}

/***********************************************
* Author - LUONG VAN DO                        *
* MELE3 ->AC
* Algorithm Dijkstra heap
* Time Limit 0.15s
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
#define maxN 20001
using namespace std;
typedef pair <int,int> ii;
int pos[maxN], heap[maxN];
int d[maxN], nheap;
vector <ii> adj[maxN];
int n,k;
void update(int v){
    int child, parent;
    child = pos[v];
    if (!child) child = ++nheap;
    parent = child >> 1;
    while ( parent > 0 && d[heap[parent]] > d[v])
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
    while (2 * r<=nheap)
    {
        int c = 2 * r;
        if ( c < nheap && d[heap[c+1]] < d[heap[c]]) ++c;
        if ( d[v]<=d[heap[c]]) break;
        heap[r] = heap[c];
        pos[heap[r]] = r;
        r = c;
    }
    heap[r] = v;
    pos[v] = r;
    return u;
}
void Read_Input(){
    scanf("%d %d",&n,&k);
    For(i,1,k)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].pb(make_pair(v,(v - u)*5));
        adj[v].pb(make_pair(u,(v - u)*5));
    }
}
void Solve(){
    nheap = 0;
    For(i,1,n)
    {
        d[i] = INF;
        pos[i] = heap[i] = 0;
    }
    d[1] = 0; update( 1 );
    while ( nheap )
    {
        int u = Pop();
        int r;
        for (vector <ii>:: iterator it=adj[u].begin(); it!=adj[u].end();it++)
        {
            int v = it->first;
            int c = it->second;
            r = d[u] / c;
            if  ( d[u] % c ) r++;
            if ( u < v && r % 2) r++;
            if ( u > v && !(r % 2)) r++;
            r++;
            if ( d[v] > r * c)
            {
                d[v] = r * c;
                update( v );
            }
        }
    }
}
void Write_Output(){
    printf("%d\n",d[n]);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}

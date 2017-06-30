
/***********************************************
* Author - LUONG VAN DO                        *
* SUMS ->AC
* Algorithm Dijkstra Heap + Ly Thuyet Dong Du
* Time Limit 3.24s
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
#define maxN 50005
using namespace std;
int pos[maxN], heap[maxN], color[maxN];
int d[maxN], edge[maxN];
int a[maxN];
int nheap,n;
void update(int v){
    int child,parent;
    child = pos[v];
    if (!child) child = ++nheap;
    parent = child >> 1;
    while (parent > 0 && d[heap[parent]] > d[v] )
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
    while ( 2 * r<=nheap){
        int c = 2 * r;
        if ( c < nheap && d[heap[c+1]] < d[heap[c]]) ++c;
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
    scanf("%d",&n);
    For(i,1,n) scanf("%d",&a[i]);
    Rep(i,a[1])
        edge[i] = INF;
    For(i,2,n)
        edge[a[i] % a[1]] = min(edge[a[i] % a[1]], a[i]);
}
void Dijkstra(){
    nheap = 0;
    Rep(i,a[1])
    {
        d[i] = 4 * INF;
        pos[i] = heap[i] = 0;
        color[i] = 0;
    }
    d[0] = 0; update( 0 );
    int m = 0;
    Rep(i,a[1])
        if ( edge[i] < INF ) swap( edge[i], edge[m++] );
    while ( nheap )
    {
        int u = Pop();
        color[u] = 1;
        Rep(i,m){
            int v = ( u + edge[i] ) % a[1];
            if (!color[v])
            if (d[v] > d[u] + edge[i])
            {
                d[v] = d[u] + edge[i];
                update( v );
            }
        }
    }
}
void Write_Output(){
    Dijkstra();
    int value,m;
    scanf("%d",&m);
    Rep(i,m)
    {
        scanf("%d",&value);
        if (value>=d[value % a[1]]) puts("TAK");
        else puts("NIE");
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    Write_Output();
}

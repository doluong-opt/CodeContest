/***********************************************
* Author - LUONG VAN DO                        *
* MELE2 ->AC
* Algorithm Dijkstra heap + Dong Du
* Time Limit 1.03s
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
#define maxN 100005
using namespace std;
uint64 H,a,b,c;
uint64 d[maxN], rs;
int nheap;
int pos[maxN], heap[maxN];
int color[maxN];
void Read_Input(){
    scanf("%lld",&H);
    scanf("%lld %lld %lld",&a,&b,&c);
    if (a > b) swap(a,b);
    if (a > c) swap(a,c);    
}
void update(int v){
    int child, parent;
    child = pos[v];
    if (!child) child = ++nheap;
    parent = child >> 1;
    while ( parent > 0 && d[heap[parent]] > d[v] )
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
        if ( c < nheap && d[heap[c+1]] < d[heap[c]] ) c++;
        if (d[v]<=d[heap[c]]) break;
        heap[r] = heap[c];
        pos[heap[r]] = r;
        r = c;
    }
    heap[r] = v;
    pos[v] = r;
    return u;
}

uint64 lt(){
    uint64 t;
    t = 1;
    for (int i=1;i<=18;i++) t*=10;
    return t;
}
void Solve(){
    int u,v;
    rs = 0;
    uint64 Max = lt() + 1;
    Rep(i,a)
    {
        d[i] = Max;
        pos[i] = heap[i] = 0;
        color[i] = 0;
    }
    d[0] = 0;
    update( 0 );
    rs+=( H - 1 ) / a + 1;
    while ( nheap )
    {
        u = Pop();
        color[u] = 1;
        v = ( u + b ) % a;
        if (!color[v])
        if (d[v] > d[u] + b)
        {
            d[v] = d[u] + b;
            if (d[v]<=H-1) rs+=( H - d[v] - 1) / a + 1;
            update( v );
        }
        v = ( u + c ) % a;
        if (!color[v])
        if (d[v] > d[u] + c)
        {
            d[v] = d[u] + c;
            if (d[v]<=H-1) rs+=( H - d[v] - 1) / a + 1;
            update( v );
        }
    }
}
void Write_Output(){
    printf("%lld\n",rs);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}

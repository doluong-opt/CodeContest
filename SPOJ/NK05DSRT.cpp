/***********************************************
* Author - LUONG VAN DO                        *
* NK05DSRT
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
#define INF 1000000000
#define maxN 101
using namespace std;
typedef pair <int, int> ii;
vector <ii> adj[maxN];
vector <ii> :: iterator it;
int n,m,nheap;
int d[maxN], C;
int pos[maxN], heap[maxN], color[maxN];
void update(int v) {
    int child,parent;
    child = pos[v];
    if (!child) child = ++nheap;
    parent = child >> 1;
    while ( parent > 0 && d[heap[parent]] > d[v] ) {
        heap[child] = heap[parent];
        pos[heap[child]] = child;
        child = parent;
        parent = child >> 1;
    }
    heap[child] = v;
    pos[v] = child;
}
int Pop() {
    int u,v,r;
    u = heap[1];
    v = heap[nheap--];
    r = 1;
    while ( 2 * r<=nheap ) {
        int c = 2 * r;
        if (c < nheap && d[heap[c+1]] < d[heap[c]] ) ++c;
        if (d[v]<=d[heap[c]]) break;
        heap[r] = heap[c];
        pos[heap[r]] = r;
        r = c;
    }
    heap[r] = v;
    pos[v] = r;
    return u;
}
int Calc(int dd, int64 ww) {
    if (C >= dd + ww ) return dd + ww;
    
    if(C%2 && ww > C/2) return INF;
    if(C%2 == 0 && ww >= C/2) return INF;
   
    int64 once = C - 2 * ww;
    int delta = dd - ( C - ww);
    int nt = delta / once;
    int re = delta % once;
    if (re) re+=2 * ww;
    return C*(nt + 1) + re;
}
void Solve() {
    nheap = 0;
    For(i,1,n) {
        pos[i] = 0; heap[i] = 0;
        color[i] = 0; d[i] = INF;
    }
    d[n] = 0;  update( n );
    while ( nheap ) {
        int u = Pop();
        color[u] = 1;
        for (it=adj[u].begin(); it!=adj[u].end();it++) {
            if (color[it->first]) continue;
            int64 ww = Calc(d[u], it->second);
            if ( d[it->first] > ww ) {
                d[it->first] = ww;
                update( it->first );
            }
        }
    }
}
void Write_Output() {
    printf("%d\n",d[1]);
}
void Read_Input() {
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d %d",&n,&m,&C);
        For(i,1,n) adj[i].clear();
        Rep(i,m) {
            int u,v;
            int64 p;
            scanf("%d %d %d",&u,&v,&p);
            adj[u].pb(make_pair(v,p));
            adj[v].pb(make_pair(u,p));
        }
        Solve();
        Write_Output();
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

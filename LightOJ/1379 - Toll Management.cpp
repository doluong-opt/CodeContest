/***********************************************
* Author - LUONG VAN DO                        *
* 1379 - Toll Management ->AC
* Algorithm dijkstra
* Time Limit 0.256s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 10005
#define EM 0.5772156649015328606065120900824
using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node{
    int x, y;
    int64 c;
    node(){}
    node(int xx, int yy, int64 cc){
        x = xx; y = yy; c = cc;
    }
};
int n, m, s, t, p, nheap;
int pos[maxN], Heap[maxN], color[maxN];
int64 d[maxN], dd[maxN];
node edge[6 * maxN];
vector <ii> adja[maxN], adjb[maxN];
void reset(int s, int64 d[]) {
    nheap = 0;
    FOR(i, 1, n) {
        pos[i] = Heap[i] = 0;
        d[i] = INF; color[i] = 0;
    }
    d[s] = 0; color[s] = 1;
}
void update(int v, int64 d[]) {
    int child = pos[v];
    int parent;
    if (!child) child = ++nheap;
    parent = child >> 1;
    while ( parent > 0 && d[Heap[parent]] > d[v]) {
        Heap[child] = Heap[parent];
        pos[ Heap[child ]] = child;
        child = parent;
        parent = child >> 1;
    }
    Heap[child] = v;
    pos[v] = child;
}
int Pop(int64 d[]){
    int u = Heap[1];
    int v = Heap[nheap--];
    int r = 1;
    while (2 * r<= nheap) {
        int c = 2 * r;
        if (c < nheap && d[Heap[c+1]] < d[Heap[c]]) ++c;
        if (d[v]<=d[Heap[c]]) break;
        Heap[r] = Heap[c];
        pos[Heap[r]] = r;
        r = c;
    }
    Heap[r] = v;
    pos[v] = r;
    return u;
}
void dijkstra(vector <ii> adj[], int s, int t, int64 d[]) {
    reset( s, d );
    update( s, d );
    while ( nheap ) {
        int u = Pop( d );
        color[u] = 1;
        REP(i, adj[u].size()) {
            int v = adj[u][i].A;
            int w = adj[u][i].B;
            if ( color[v] ) continue;
            if ( d[v] > d[u] + w) {
                d[v] = d[u] + w;
                update( v, d);
            }
        }
    }
}
int solve() {
    int ans = -1;
    int64 xx, yy, cc;
    dijkstra(adja, s, t, d);
    dijkstra(adjb, t, s, dd);
    REP(i, m) {
        xx = edge[i].x; yy = edge[i].y; cc = edge[i].c;
        if ( d[xx] + dd[yy] + cc <= p ) ans = max(ans, cc);
    }
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, u, v;
    int64 c;
    scanf("%d",&test);
    FOR(tt, 1, test) {
        scanf("%d %d %d %d %d",&n,&m,&s,&t,&p);
        FOR(i, 1, n) {
            adja[i].clear();
            adjb[i].clear();
        }
        REP(i, m) {
            scanf("%d %d %lld",&u,&v,&c);
            adja[u].pb(ii(v, c));
            adjb[v].pb(ii(u, c));
            edge[i] = node(u, v, c);
        }
        printf("Case %d: %d\n",tt,solve());
    }
    return 0;
}

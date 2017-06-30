/***********************************************
* Author - LUONG VAN DO                        *
* 1281 - New Traffic System ->AC
* Algorithm dijkstra
* Time Limit 0.946s
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
#define INF 1000000000
#define maxN 10005
#define EM 0.5772156649015328606065120900824
using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct H {
    int x, sl;
    H(){}
    H(int xx, int ss){
        x = xx; sl = ss;
    }
};
struct Node {
    int y, ti, type;
    Node(){}
    Node(int yy, int tii, int tyy){
        y = yy; ti = tii; type = tyy;
    }
};
vector <Node> adj[maxN];
H heap[maxN * 15];
int color[maxN][15];
int dp[maxN][15], pos[maxN][15];
int n, m, k, d, nheap;
void update(int v, int sl){
    int child, parent;
    child = pos[v][sl];
    if (!child) child = ++nheap;
    parent = child >> 1;
    while (parent > 0 && dp[heap[parent].x][heap[parent].sl] > dp[v][sl]) {
        heap[child] = heap[parent];
        pos[heap[child].x][heap[child].sl] = child;
        child = parent;
        parent = child >> 1;
    }
    heap[child] = H(v, sl);
    pos[v][sl] = child;
}
H Pop() {
    H u = heap[1];
    H v = heap[nheap--];
    int r = 1;
    while (2 * r<=nheap) {
        int c = 2 * r;
        if (c < nheap && dp[heap[c + 1].x][heap[c + 1].sl] < dp[heap[c].x][heap[c].sl]) ++c;
        if (dp[v.x][v.sl]<=dp[heap[c].x][heap[c].sl]) break;
        heap[r] = heap[c];
        pos[heap[r].x][heap[r].sl] = r;
        r = c;
    }
    heap[r] = v;
    pos[v.x][v.sl] = r;
    return u;
}
void reset() {
    nheap = 0;
    FOR(i, 0, n) heap[i].x = heap[i].sl = 0;
    FOR(i, 0, n)
        FOR(j, 0, d) {
            dp[i][j] = INF;
            color[i][j] = 0;
            pos[i][j] = 0;
        }
}
void dijkstra() {
    int v, w, tp, x;
    reset();
    update(0, 0); dp[0][0] = 0;
    while ( nheap ) {
        H u = Pop();
        color[u.x][u.sl] = 1;
        REP(i, adj[u.x].size()) {
            v = adj[u.x][i].y;
            w = adj[u.x][i].ti;
            tp = adj[u.x][i].type;
            x = u.sl + tp;
            if (x<=d && !color[v][x])
            if (dp[v][x] > dp[u.x][u.sl] + w) {
                dp[v][x] = dp[u.x][u.sl] + w;
                update(v, x);
            }
        }
    }
}
int main(){
    /*#ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif*/
    int test, u, v, c, ans;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d %d %d",&n,&m,&k,&d);
        FOR(i, 0, n) adj[i].clear();
        FOR(i, 1, m) {
            scanf("%d %d %d",&u,&v,&c);
            adj[u].pb(Node(v, c, 0));
        }
        FOR(i, 1, k) {
            scanf("%d %d %d",&u,&v,&c);
            adj[u].pb(Node(v, c, 1));
        }
        dijkstra();
        ans = INF;
        FOR(i, 0, d)
            ans = min(ans, dp[n-1][i]);
        if (ans!=INF) printf("Case %d: %d\n",t,ans);
        else printf("Case %d: Impossible\n",t);
    }
    return 0;
}

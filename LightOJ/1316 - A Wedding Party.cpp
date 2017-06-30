/***********************************************
* Author - LUONG VAN DO                        *
* 1316 - A Wedding Party ->AC
* Algorithm dijk + dp bitmask
* Time Limit 0.349s
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
#define FOR(i, a, b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 505

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector <ii> adj[maxN];
int n, m, s, nheap;
int dp[maxN], pos[maxN], heap[maxN];
int cost[20][20], cur[1<<16], color[maxN];
int d[16][1<<16];
int shop[20];

void update(int v) {
    int child, parent;
    child = pos[v];
    if (!child) child = ++nheap;
    parent = child >> 1;
    while ( parent > 0 && dp[heap[parent]] > dp[v]) {
        heap[child] = heap[parent];
        pos[heap[child]] = child;
        child = parent;
        parent = child >> 1;
    }
    heap[child] = v;
    pos[v] = child;
}
int Pop(){
    int u = heap[1];
    int v = heap[nheap--];
    int r = 1;
    while (2 * r<=nheap) {
        int c = 2 * r;
        if (c < nheap &&  dp[heap[c + 1]] < dp[heap[c]]) ++c;
        if (dp[v]<=dp[heap[c]]) break;
        heap[r] = heap[c];
        pos[heap[r]] = r;
        r = c;
    }
    heap[r] = v;
    pos[v] = r;
    return u;
}
int run_dijk(int start, int end) { 
    nheap = 0;
    REP(i, n) {
        dp[i] = INF;
        color[i] = 0;
        pos[i] = heap[i] = 0;
    }
    dp[start] = 0; update( start );
    while ( nheap ) {
        int u = Pop();
        color[u] = 1;
        if (u == end) return dp[end];
        REP(i, adj[u].size()) {
            int v = adj[u][i].A;
            int w = adj[u][i].B;
            if ( color[v] ) continue;
            if (dp[v] > dp[u] + w) {
                dp[v] = dp[u] + w;
                update( v );
            }
        }
    }
    return INF;
}
int run(int start, int mask) {
    if (!mask) return cost[start][s + 1];
    int &res = d[start][mask];
    if (res!=-1) return res;
    res = INF;
    REP(i, s){
        if ( mask & (1<<i) ) {
            int temp = run(i, (mask & (~(1<<i)) )) + cost[start][i];
            res = min(res, temp);
        }
    }
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, u, v, w;
    int rs1, rs2, temp, best;
    REP(i, (1<<16)) cur[i] =__builtin_popcount( i );
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d %d",&n,&m,&s);
        REP(i, n) adj[i].clear();
        REP(i, s) scanf("%d",&shop[i]);
        shop[s] = 0;
        shop[s + 1] = n - 1;
        REP(i, m) {
            scanf("%d %d %d",&u,&v,&w);
            adj[u].pb(ii(v, w));
        }
        REP(i, s + 2)
            REP(j, s + 2)
                cost[i][j] = run_dijk(shop[i], shop[j]);
        
        rs1 = 0; rs2 = INF;
        memset(d, -1, sizeof(d));
        REP(i, (1<<s)) {
            temp = cur[i];
            best = run(s, i);
            if (best < INF) {
                if (temp > rs1) {
                    rs1 = temp;
                    rs2 = best;
                }
                else
                if (temp == rs1) rs2 = min(rs2, best);
            }
        }
        if (rs2 != INF) printf("Case %d: %d %d\n",t,rs1,rs2);
        else printf("Case %d: Impossible\n",t);
    }
    return 0;
}

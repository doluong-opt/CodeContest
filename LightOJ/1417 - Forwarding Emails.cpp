/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1417 - Forwarding Emails ->AC
* Algorithm SCC + dfs
* Time Limit 0.244s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
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
#define M 50000

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, scc, cnt, Count;
vector <int> adj[M + 1], adjj[M + 1];
int cur[M + 1], color[M + 1], low[M + 1], num[M + 1];
int amount[M + 1], inCom[M + 1];
stack <int> S;
void dfs_tajan(int u) {
    int v;
    low[u] = num[u] = ++cnt;
    S.push(u);
    REP(i, adj[u].size()) {
        v = adj[u][i];
        if (!color[v])
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            dfs_tajan( v );
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == num[u]) {
        scc++;
        int x, minx, sl; minx = INF; sl = 0;
        do{
            x = S.top(); S.pop();
            sl++;
            color[x] = 1;
            inCom[x] = scc;
            minx = min(minx, x);
        }while (x != u);
        cur[scc] = minx;
        amount[scc] = sl;
    }
}
void tajan(){
    scc = cnt = 0;
    FOR(i, 1, n) {
        color[i] = 0;
        num[i] = low[i] = 0;
    }
    FOR(i, 1, n)
        if (!color[i]) dfs_tajan(i);
        
    FOR(i, 1, n)
        REP(j, adj[i].size()) {
            int xx = i; int yy = adj[i][j];
            if (inCom[xx]!=inCom[yy])
                adjj[ inCom[xx] ].pb( inCom[yy] );
        }
}
void dfs(int u, int p){
    if (u == p) return;
    Count+=amount[u];
    REP(i, adjj[u].size()) {
        int v = adjj[u][i];
        dfs(v , u);
    }
}
int run() {
    tajan();
    FOR(i, 1, scc) color[i] = 0;
    int Ans, xmax;
    xmax = -INF;
    FOR(i, 1, scc) {
        Count = 0;
        dfs(i , 0);
        if (xmax  < Count) {
            xmax = Count;
            Ans = cur[i];
        }
    }
    return Ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, u, v;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        FOR(i, 1, n) {
            adj[i].clear();
            adjj[i].clear();
        }
        FOR(i, 1, n) {
            scanf("%d %d",&u,&v);
            adj[u].pb(v);
        }
        printf("Case %d: %d\n",t,run());
    }
}

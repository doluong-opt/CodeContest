/***********************************************
* Author - LUONG VAN DO                        *
* 1063 - Ant Hills ->AC
* Algorithm Articulation / Bridge
* Time Limit 0.018s
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

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector <int> adj[maxN];
int low[maxN], num[maxN], child[maxN];
int parent[maxN], iscut[maxN];
int n, cnt;
void reset() {
    FOR(i, 1, n) {
        low[i] = num[i] = child[i] = 0;
        parent[i] = iscut[i] = 0;
    }
    cnt = 0;
}
void dfs(int u) {
    int v;
    low[u] = ++cnt;
    num[u] = low[u];
    REP(i, adj[u].size()) {
        v = adj[u][i];
        if ( parent[v] == 0 ) {
            parent[v] = u;
            child[u]++;
            dfs( v );
            low[u] = min(low[u], low[v]);
            if ( parent[u] == -1 )
                iscut[u] = iscut[u] || (low[v]>=num[u] && child[u] > 1);
            else
                iscut[u] = iscut[u] || low[v]>=num[u];
        }
        else
        if ( parent[u]!=v ) low[u] = min(low[u], num[v]);
    }
}
int solve() {
    int khop, cau;
    khop = cau = 0;
    reset();
    FOR(i, 1, n)
        if ( !parent[i] ) {
            parent[i] = -1;
            dfs( i );
        }
    FOR(i, 1, n) {
        if ( parent[i]!=-1 && low[i]>=num[i] ) cau++;
        if (iscut[i]) khop++;
    }
    return khop;
}
void Read() {
    int test, u, v, m;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&n,&m);
        FOR(i, 1, n) adj[i].clear();
        FOR(i, 1, m) {
            scanf("%d %d",&u,&v);
            ++u; ++v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        printf("Case %d: %d\n",t,solve());
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

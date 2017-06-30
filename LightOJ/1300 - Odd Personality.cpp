/***********************************************
* Author - LUONG VAN DO                        *
* 1300 - Odd Personality 
* Algorithm Articulation / Bridge
* Time Limit 0.674s
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
int low[maxN], num[maxN];
int h[maxN], color[maxN], parent[maxN];
int dist[maxN];
stack <int> S;
int n, m, cnt, scc, Node;
bool mark;

void reset() {
    FOR(i, 1, maxN - 1) {
        low[i] = num[i] = color[i] = 0;
        parent[i] = 0;
    }
    cnt = scc = 0;
}

void dfs(int u) {
    low[u] = num[u] = ++cnt;
    S.push( u );
    REP(i, adj[u].size()) {
        int v = adj[u][i];
        if ( !parent[v] ) {
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else 
        if (parent[u] != v && low[u] > num[v]) low[u] = num[v];
    }
    if ( low[u] == num[u] ) {
        ++scc;
        int x;
        do{
            x = S.top(); S.pop();
            h[x] = scc;
        } while ( x != u);
    }
}
void dfs1(int u, int bit) {
    if ( color[u] ) return;
    color[u] = 1;
    dist[u] = bit;
    Node++;
    REP(i, adj[u].size()) {
        int v = adj[u][i];
        if (h[u]!=h[v]) continue;
        if (!color[v])
            dfs1(v, 1 - bit);
        if (dist[u] == dist[v]) mark = true;
    }
}
bool check(int u) {
    dfs1(u, -1);
    return mark;
}
int solve() {
    int ans = 0;
    reset();
    
    FOR(i, 1, n)
        if (!color[i]) {
            parent[i] = -1;
            dfs(i);
        }
    FOR(i, 1, n) color[i] = 0;
    
    FOR(i, 1, n) {
        memset(dist, -1, sizeof(dist));
        mark = false;
        if (!color[i]) {
            Node = 0;
            if ( check( i ) ) ans+=Node;
        }
    }
    return ans;
}
void Read() {
    int test, u, v;
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

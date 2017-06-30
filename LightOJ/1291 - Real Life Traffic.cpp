/***********************************************
* Author - LUONG VAN DO                        *
* 1291 - Real Life Traffic 
* Algorithm Articulation / Bridge
* Time Limit 0.175s
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
int s[maxN];
int n, m, cnt, com, top;
int h[maxN], col[maxN], parent[maxN];
void reset() {
    FOR(i, 1, maxN - 1) {
        low[i] = num[i] = col[i] = 0;
        parent[i] = 0;
    }
}
void dfs(int u) {
    num[u] = low[u] = ++cnt;
    s[++top] = u;
    REP(i, adj[u].size()) {
        int v = adj[u][i];
        if ( !parent[v] ) {
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else
        if ( parent[u] != v && low[u] > num[v]) low[u] = num[v];
    }
    if ( num[u] == low[u] ) {
        ++com;
        int x;
        do {
            x = s[top--];
            h[x] = com;
        } while (u != x);
    }
}
int solve() {
    int ans, v;
    ans = top = cnt = com = 0;
    reset();
    
    dfs(1); parent[1] = -1;
    FOR(i, 1, n)
        REP(j, adj[i].size()) {
            v = adj[i][j];
            if ( h[i] != h[v] ) col[ h[v] ]++;
        }
    FOR(i, 1, com)
        if ( col[i] == 1) ans++;
    return (ans + 1) / 2;
}
void Read() {
    int test, u, v;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&n,&m);
        FOR(i, 1, n)
            adj[i].clear();
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

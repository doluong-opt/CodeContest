/***********************************************
* Author - LUONG VAN DO                        *
* 12379 - Central Post Office ->AC
* Algorithm dfs
* Time Limit 0.32s
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
int n, ans, x;
int dist[maxN], color[maxN];
void dfs(int u) {
    if (color[u]) return;
    color[u] = 1;
    for (int i=0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if ( !color[v] ) {
            dist[v] = dist[u] + 1;
            dfs( v );
        }
    }
}
void Read() {
    int test,v,m;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d",&n); ans = 0;
        for (int i=1;i<=n;i++) adj[i].clear();
        for (int i=1;i<=n;i++) {
            scanf("%d",&m);
            while (m--) {
                scanf("%d",&v);
                adj[i].pb(v);
            }
        }
        for (int i=1;i<=n;i++) {
            dist[i] = 0;
            color[i] = 0;
        }
        dfs( 1 );
        int node = 1; color[1] = 0;
        for (int i=2;i<=n;i++) {
            if ( dist[i] > dist[node] ) node = i;
            color[i] = 0;
        }
        for (int i=1;i<=n;i++) dist[i] = 0;
        dfs(node);
        x = 0;
        for (int i=1;i<=n;i++)
            if (x < dist[i]) x = dist[i];
        printf("%d\n",2 * (n - 1) - x);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

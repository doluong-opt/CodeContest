/***********************************************
* Author - LUONG VAN DO                        *
* 11396 - Claw Decomposition ->AC
* Algorithm Bipartite Matching Check
* Time Limit 0.028s
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
#define maxN 301

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector <int> adj[maxN];
int color[maxN], deg[maxN], d[maxN];
int found, n;
void dfs(int x, int p){
    if ( !found ) return;
    if ( color[x] ) return;
    color[x] = 1;
    d[x] = p;
    REP(i, adj[x].size()) {
        int v = adj[x][i];
            if ( !color[v] ) dfs(v, 1 - p);
        else
            if ( d[x] == d[v] ) found = 0;
    }
}
bool check() {
    found = 1;
    FOR(i, 1, n)
        if (deg[i] == 3 && !color[i]) {
            dfs(i, 0);
            if ( !found ) return false;
        }
    FOR(i, 1, n)
        if ( !color[i] ) return false;
    return true;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int x, y;
    while ( scanf("%d",&n) && n) {
        FOR(i, 1, n) {
            adj[i].clear();
            deg[i] = 0;
        }
        while ( scanf("%d %d",&x,&y) && (x + y) ) {
            adj[x].pb(y);
            adj[y].pb(x);
            deg[x]++; deg[y]++;
        }
        FOR(i, 1, n) color[i] = 0, d[i] = -1;
        if ( !check() ) puts("NO");
        else puts("YES");
    }
    return 0;
}

/***********************************************
* Author - LUONG VAN DO                        *
* 1111 - Best Picnic Ever ->AC
* Algorithm dfs
* Time Limit 0.024s
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
#define maxN 50001

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vi adj[1001];
int person[101];
int inc[1001], color[1001];
int n, m, k;
void dfs(int u){
    if ( color[u] ) return;
    color[u] = 1;
    inc[u]++;
    REP(i, adj[u].size() ) {
        int v = adj[u][i];
        if ( !color[v] ) dfs( v );
    }
}
int solve() {
    int res = 0;
    FOR(i, 1, n) inc[i] = 0;
    REP(j, k) {
        FOR(i, 1, n) color[i] = 0;
        dfs( person[j] );
    }
    FOR(i, 1, n)
        if ( inc[i] == k ) res++;
    return res;
}
void Read() {
    int test, u, v;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d %d",&k,&n,&m);
        FOR(i, 1, n) adj[i].clear();
        REP(i, k) scanf("%d",&person[i]);
        REP(i, m) {
            scanf("%d %d",&u,&v);
            adj[u].pb(v);
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

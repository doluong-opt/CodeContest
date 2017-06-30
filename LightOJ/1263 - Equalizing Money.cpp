/***********************************************
* Author - LUONG VAN DO                        *
* 1263 - Equalizing Money ->AC
* Algorithm dfs
* Time Limit 0.230s
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
#define maxN 1000

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int sum, n, m, cnt;
vi adj[maxN + 10];
int a[maxN + 10];
int color[maxN + 10];
void dfs(int u) {
    if ( color[u] ) return;
    color[u] = 1;
    cnt++; sum+=a[u];
    REP(i, adj[u].size() ) {
        int v = adj[u][i];
        if ( !color[v] ) dfs( v );
    }
}
bool solve() {
    int tb;
    FOR(i, 1, n) color[i] = 0;
    cnt = sum = 0;
    dfs( 1 );
    if ( sum % cnt != 0) return false;
    tb = sum / cnt;
    FOR(i, 1, n)
        if ( !color[i] ) {
            sum = cnt = 0;
            dfs( i );
            if ( sum % cnt != 0 || sum / cnt != tb) return false;
        }
    return true;
}
void Read() {
    int test, u, v;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&n,&m);
        
        FOR(i, 1, n) scanf("%d",&a[i]);
        FOR(i, 1, n) adj[i].clear();
        FOR(i, 1, m) {
            scanf("%d %d",&u,&v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        if ( solve() ) printf("Case %d: Yes\n",t);
        else printf("Case %d: No\n",t);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

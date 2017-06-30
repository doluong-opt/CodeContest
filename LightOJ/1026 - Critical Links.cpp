/***********************************************
* Author - LUONG VAN DO                        *
* 1026 - Critical Links ->AC
* Algorithm Articulation / Bridge
* Time Limit 0.233s
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
#define maxN 10001

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector <int> adj[maxN];
int low[maxN], num[maxN];
int parent[maxN];
int n, cnt;
void reset() {
    FOR(i, 1, n) {
        low[i] = num[i] = 0;
        parent[i] = 0;
    }
    cnt = 0;
}
void dfs(int u) {
    int v;
    low[u] = ++cnt;
    num[u] = low[u];
    REP(i, adj[u].size()) {
        v = adj[u][i];
        if ( parent[v] == 0) {
            parent[v] = u;
            dfs( v );
            low[u] = min(low[u], low[v]);
        }
        else
        if ( parent[u] != v ) low[u] = min(low[u], num[v]);
    }
}
void solve() {
    int j;
    vector <ii> result;
    reset();
    FOR(i, 1, n)
        if ( !parent[i] ) {
            parent[i] = -1;
            dfs( i );
        }
    FOR(i, 1, n) {
        if ( parent[i]!=-1 && low[i]>=num[i] ) {
            j = parent[i];
            result.pb(ii(min(i,j),max(i,j)));
        }
    }
    sort(result.begin(), result.end());
    printf("%d critical links\n",result.size());
    for (vector <ii> :: iterator it = result.begin(); it!=result.end();it++)
        printf("%d - %d\n",(it->A)-1, (it->B)-1);
}
void Read() {
    int test, u, v, m;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        FOR(i, 1, n) adj[i].clear();
        FOR(i, 1, n) {
            scanf("%d (%d)",&u,&m);
            ++u;
            while (m--) {
                scanf("%d",&v);
                ++v;
                adj[u].pb(v);
            }
        }
        printf("Case %d:\n",t);
        solve();
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

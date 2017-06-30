/***********************************************
* Author - LUONG VAN DO                        *
* 1406 - Assassin's Creed ->AC
* Algorithm dp bitmask
* Time Limit 0.275s
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
#define M 20000
using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector <int> adj[16];
int dp[1<<16], n, m;
int mark[16][1<<16], color[1<<16];
void dfs(int cur, int mask) {
    if ( mark[cur][mask] ) return;
    mark[cur][mask] = 1;
    color[mask] = 1;
    for (int i=0;i<adj[cur].size();i++) {
        int v = adj[cur][i];
        if ( !mark[v][mask|(1<<v)] ) dfs(v, mask|(1<<v));
    }
}
int run(int mask) {
    if (mask == 0) return 0;
    int &res = dp[mask], cur;
    if ( res != -1 ) return res;
    res = INF; cur = mask;
    while ( cur > 0) {
        cur&= mask;
        if ( color[cur] ) res = min(res, run(mask ^ cur) + 1);
        cur--;
    }
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, u, v;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d",&n,&m);
        for (int i=0;i<n;i++) adj[i].clear();
        for (int i=0;i<m;i++) {
            scanf("%d %d",&u,&v);
            u--; v--;
            adj[u].pb(v);
        }
        memset(mark, 0, sizeof(mark));
        memset(color, 0, sizeof(color));
        memset(dp, -1, sizeof(dp));
        for (int i=0;i<n;i++)
            dfs(i, (1<<i));
        printf("Case %d: %d\n",++caseno, run((1<<n) - 1));
    }
}

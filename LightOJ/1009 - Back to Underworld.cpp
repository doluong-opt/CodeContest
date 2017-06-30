/***********************************************
* Author - LUONG VAN DO                        *
* 1009 - Back to Underworld ->AC
* Algorithm dfs
* Time Limit 0.244s
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
#define maxN 20005

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector <int> adj[maxN];
int color[maxN], r1, r2, m;
int Free[maxN];

void dfs(int u, int p){
    if (color[u]) return;
    color[u] = 1;
    Free[u] = 0;
    if (p) r1++;
    else r2++;
    for (int i=0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if ( !color[v] ) dfs(v, 1 - p);
    }
}
int solve() {
    int ans = 0;
    for (int i=1;i<=20000;i++)
        if ( Free[i] ) {
            r1 = r2 = 0;
            dfs( i, 0 );
            ans+=max(r1,r2);
        }
    return ans;
}
void Read_Input() {
    int test,u,v,n;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d",&n);
        for (int i=1;i<maxN;i++) {
            adj[i].clear();
            color[i] = Free[i] = 0;
        }
        for (int i=1;i<=n;i++) {
            scanf("%d %d",&u,&v);
            adj[u].pb(v);
            adj[v].pb(u);
            Free[u] = Free[v] = 1;
        }
        printf("Case %d: %d\n",t,solve());
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

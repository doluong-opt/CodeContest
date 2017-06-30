/***********************************************
* Author - LUONG VAN DO                        *
* 1049 - One Way Roads ->AC
* Algorithm dfs
* Time Limit 0.004s
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
#define maxN 101

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector <ii> adj[maxN];
int n, rs1,rs2;
int color[maxN];
void solve(int u, int pre){
    if (u==1 && pre!=0 ) return;
    REP(i, adj[u].size()) {
        int v = adj[u][i].A;
        int w = adj[u][i].B;
        if ( pre!=v ) {
            if (w > 0) rs1+=w;
            else rs2-=w;
            solve(v, u);
            return;
        }
    }
}
void Read_Input() {
    int u,v,w,test;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            adj[i].clear();
            color[i] = 0;
        }
        for (int i=1;i<=n;i++) {
            scanf("%d %d %d",&u,&v,&w);
            adj[u].pb(ii(v,w));
            adj[v].pb(ii(u,-w));
        }
        rs1 = rs2 = 0;
        solve( 1 , 0);
        printf("Case %d: %d\n",t,min(rs1,rs2));
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

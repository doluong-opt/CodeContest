/***********************************************
* Author - LUONG VAN DO                        *
* 1019 - Brush (V) ->AC
* Algorithm dijkstra
* Time Limit 0.023s
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
int a[maxN][maxN];
int d[maxN];
int color[maxN],m,n;
void solve(){
    int u,Min;
    while ( true ) {
        u = 0; Min = INF;
        for (int i=1;i<=n;i++)
            if ( color[i] && d[i] < Min ){
                Min = d[i];
                u = i;
            }
        if (u == 0) break;
        color[u] = 0;
        for (int v=1;v<=n;v++)
            if ( color[v] && d[v] > d[u] + a[u][v]) d[v] = d[u] + a[u][v];
    }
}
void Read() {
    int test,u,v,w;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d %d",&n,&m);
        for (int i=1;i<=n;i++) {
            color[i] = 1;
            d[i] = INF;
                for (int j=1;j<=n;j++) a[i][j] = INF;
        }
        d[1] = 0;
        for (int i=1;i<=m;i++){
            scanf("%d %d %d",&u,&v,&w);
            a[u][v] = min( a[u][v], w );
            a[v][u] = min( a[u][v], w );
        }
        solve();
        if ( d[n]!=INF ) printf("Case %d: %d\n",t,d[n]);
        else printf("Case %d: Impossible\n",t);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

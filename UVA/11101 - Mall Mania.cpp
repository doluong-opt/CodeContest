/***********************************************
* Author - LUONG VAN DO                        *
* 11101 - Mall Mania ->AC
* Algorithm bfs
* Time Limit 0.388s
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
#define For(i, a, b) for (int i=a; i<=b; i++)
#define Ford(i,a,b) for (int i=a;i>=b;i--)
#define Rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 2010
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
bool visit[maxN][maxN];
int cost[maxN][maxN];
int mark[maxN][maxN];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int bfs(queue <ii> &Q){
    ii k, p;
    while ( !Q.empty() ) {
        k = Q.front(); Q.pop();
        for (int i=0;i<4;i++) {
            p.A = k.A + dx[i]; p.B = k.B + dy[i];
            if ( p.A < 0 || p.A>=maxN || p.B < 0 || p.B>=maxN || visit[p.A][p.B]) continue;
            
            if ( mark[p.A][p.B] == 2 ) return cost[k.A][k.B] + 1;
            visit[p.A][p.B] = true;
            cost[p.A][p.B] = cost[k.A][k.B] + 1;
            Q.push( p );
        }
    }
    return 0;
}
void Read_Input(){
    int x,y,n,m;
    while ( scanf("%d",&n) && n){
        queue <ii> Q;
        for (int i=0;i<=2000;i++)
            for (int j=0;j<=2000;j++) {
                mark[i][j] = cost[i][j] = 0;
                visit[i][j] = false;
            }
        for (int i=1;i<=n;i++) {
            scanf("%d %d",&x,&y);
            Q.push(ii(x,y));
            mark[x][y] = 1;
            visit[x][y] = true;
        }
        scanf("%d",&m);
        for (int i=1;i<=m;i++) {
            scanf("%d %d",&x,&y);
            mark[x][y] = 2;
        }
        printf("%d\n",bfs( Q ));
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

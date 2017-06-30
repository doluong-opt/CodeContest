/***********************************************
* Author - LUONG VAN DO                        *
* 1238 - Power Puff Girls ->AC
* Algorithm bfs
* Time Limit 0.002s
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
int r, c;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int d[20 + 5][20 + 5];
char s[20 + 5][20 + 5];
bool ok(int u, int v){
    return (u>=0 && u<r && v>=0 && v<c);
}
int bfs(int x, int y) {
    REP(i, r)
        REP(j, c) d[i][j] = INF;
    d[x][y] = 0;
    queue <ii> Q;
    Q.push(ii(x,y));
    while ( !Q.empty() ) {
        ii tmp = Q.front(); Q.pop();
        REP(k, 4) {
            int nx = tmp.A + dx[k];
            int ny = tmp.B + dy[k];
            if ( !ok(nx, ny) || s[nx][ny] == '#' || s[nx][ny] == 'm' || d[nx][ny] != INF ) continue;
            d[nx][ny] = d[tmp.A][tmp.B] + 1;
            if (s[nx][ny] == 'h') return d[nx][ny];
            Q.push(ii(nx,ny));
        }
    }
}
void Read() {
    int test, ans;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d ",&r,&c);
        REP(i, r) gets(s[i]);
        ans = -INF;
        REP(i, r)
            REP(j, c)
                if ( s[i][j] == 'a' ) ans = max(ans, bfs(i,j));
            else
                if ( s[i][j] == 'b' ) ans = max(ans, bfs(i,j));
            else
                if ( s[i][j] == 'c' ) ans = max(ans, bfs(i,j));
        printf("Case %d: %d\n",t,ans);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

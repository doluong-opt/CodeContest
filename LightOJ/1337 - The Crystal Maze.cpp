/***********************************************
* Author - LUONG VAN DO                        *
* 1337 - The Crystal Maze ->AC
* Algorithm bfs
* Time Limit 0.076s
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
int r, c, q, cnt;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ans[1000 + 5];
int dp[500 + 5][500 + 5];
char s[500 + 5][500 + 5];
bool ok(int u, int v){
    return (u>=0 && u<r && v>=0 && v<c);
}
void bfs(int x, int y, int cons) {
    ii cur;
    queue <ii> Q;
    Q.push(ii(x,y)); dp[x][y] = cons;
    while ( !Q.empty() ) {
        cur = Q.front(); Q.pop();
        REP(k, 4) {
            int nx = cur.A + dx[k];
            int ny = cur.B + dy[k];
            if ( !ok(nx, ny) || s[nx][ny] == '#' || s[nx][ny] == 'X') continue;
            if (s[nx][ny] == 'C') cnt++;
            s[nx][ny] = 'X';
            dp[nx][ny] = cons;
            Q.push(ii(nx, ny));
        }
    }
}
void Read() {
    int test, x, y;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d %d ",&r,&c,&q);
        REP(i, r)
            REP(j, c) dp[i][j] = -1;
        REP(i, r) gets(s[i]);
        printf("Case %d:\n",t);
        FOR(i, 1, q) {
            scanf("%d %d",&x,&y);
            x--; y--;
            if ( dp[x][y] != -1 ) {
                printf("%d\n",ans[dp[x][y]]);
                continue;
            }
            cnt = 0;
            bfs(x, y, i);
            ans[i] = cnt;
            printf("%d\n",ans[i]);
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

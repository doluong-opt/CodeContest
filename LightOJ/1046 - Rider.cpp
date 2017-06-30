/***********************************************
* Author - LUONG VAN DO                        *
* 1046 - Rider ->AC
* Algorithm bfs
* Time Limit 0.022s
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
struct state{
    int x, y, c;
    state(){}
    state(int xx, int yy, int cc){
        x = xx; y = yy; c = cc;
    }
} a ;
int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
int r, c;
char b[11][11];
int d[11][11], f[11][11];
bool ok(int u, int v) {
    return (u>=0 && u<r && v>=0 && v<c);
}
void bfs(int ax, int ay) {
    int n = b[ax][ay] - '0';
    int color[11][11];
    REP(i, r)
        REP(j, c) color[i][j] = 0;
    queue <state> Q;
    Q.push(state(ax, ay, 0)); color[ax][ay] = 1;
    f[ax][ay]++;
    while ( !Q.empty() ) {
        a = Q.front(); Q.pop();
        REP(k, 8) {
            int nx = a.x + dx[k];
            int ny = a.y + dy[k];
            if ( !ok(nx, ny) || color[nx][ny] ) continue;
            color[nx][ny] = 1;
            f[nx][ny]++;
            d[nx][ny]+=(a.c / n + 1);
            Q.push(state(nx, ny, a.c + 1));
        }
    }
}
int solve() {
    int nm = 0;
    int ans;
    state St[105];
    REP(i, r)
        REP(j, c) d[i][j] = 0, f[i][j] = 0;
    REP(i, r)
        REP(j, c)
            if ( b[i][j] !='.' ) St[++nm] = state(i, j, 0);
    
    FOR(k, 1, nm)
        bfs( St[k].x, St[k].y );
        
    if (nm == 1) ans = 0;
    else ans = INF;
    
    REP(i, r) {
        REP(j, c)
        if (d[i][j] > 0 && ans > d[i][j] && f[i][j] == nm) ans = d[i][j];
    }
    if (ans == INF) return -1;
    else return ans;
}
void Read() {
    int test;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d ",&r,&c);
        REP(i, r) gets(b[i]);
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

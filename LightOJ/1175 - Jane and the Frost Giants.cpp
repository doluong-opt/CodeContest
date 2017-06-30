/***********************************************
* Author - LUONG VAN DO                        *
* 1175 - Jane and the Frost Giants ->AC
* Algorithm bfs
* Time Limit 0.115s
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

struct position {
    int x, y, w;
    position(){}
    position(int xx, int yy, int ww){
        x = xx; y = yy; w = ww;
    }
} a ;
int r, c;
char s[200 + 5][200 + 5];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int cost_jane[200 + 5][200 + 5];
int cost_fire[200 + 5][200 + 5];
bool Ok(int u, int v){
    return (u>=0 && u<r && v>=0 && v<c);
}
void reset() {
    REP(i, r)
        REP(j, c) cost_jane[i][j] = cost_fire[i][j] = INF;
}
void bfs_for_jane(int u, int v) {
    
    queue <position> Q;
    Q.push( position(u, v, 0) );
    cost_jane[u][v] = 0;
    
    while ( !Q.empty() ) {
        a = Q.front(); Q.pop();
        REP(i, 4) {
            int nx = a.x + dx[i];
            int ny = a.y + dy[i];
            if ( !Ok(nx, ny) || s[nx][ny] == '#' || cost_jane[nx][ny] != INF ) continue;
            cost_jane[nx][ny] = a.w + 1;
            Q.push( position(nx, ny, a.w + 1));
        }
    }
}
void bfs_for_fire() {
    
    queue <position> Q;
    REP(i, r)
        REP(j, c)
            if (s[i][j] == 'F') {
                cost_fire[i][j] = 0;
                Q.push(position(i,j,0));
            }
        
    while ( !Q.empty() ) {
        a = Q.front(); Q.pop();
        REP(i, 4) {
            int nx = a.x + dx[i];
            int ny = a.y + dy[i];
            if ( !Ok(nx, ny) || s[nx][ny] == '#' || cost_fire[nx][ny] <= a.w + 1 ) continue;
            cost_fire[nx][ny] = a.w + 1;
            Q.push( position( nx, ny, a.w + 1 ));
        }
    }
}
void Read() {
    int test;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d ",&r,&c);
        REP(i, r) gets(s[i]);
        reset();
        REP(i, r)
            REP(j, c)
                if (s[i][j] == 'J') bfs_for_jane(i,j);
            
        bfs_for_fire();
        int ans = INF;
        REP(i, c) {
            if ( cost_jane[0][i] < cost_fire[0][i] ) ans = min(ans, cost_jane[0][i]);
            if ( cost_jane[r-1][i] < cost_fire[r-1][i] ) ans = min( ans, cost_jane[r-1][i]);
        }
        REP(i, r) {
            if ( cost_jane[i][0] < cost_fire[i][0] ) ans = min(ans, cost_jane[i][0]);
            if ( cost_jane[i][c-1] < cost_fire[i][c-1] ) ans = min(ans, cost_jane[i][c-1]);
        }
        if ( ans == INF ) printf("Case %d: IMPOSSIBLE\n",t);
        else printf("Case %d: %d\n",t,ans + 1);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

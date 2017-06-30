/***********************************************
* Author - LUONG VAN DO                        *
* 1171 - Knights in Chessboard (II) ->AC
* Algorithm Bipartite matching
* Time Limit 1.299s
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
#define maxN 50000

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector <int> adj[maxN];

int distx[maxN], disty[maxN];
int matchx[maxN], matchy[maxN];

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool chess[205][205];
int m, n, k, MAX;

bool ok(int u, int v){
    return (u>=0 && u<m && v>=0 && v<n);
}
void reset() {
    REP(i, m)
        REP(j, n) chess[i][j] = false;
    REP(i, maxN) {
        adj[i].clear();
        matchx[i] = matchy[i] = 0;
    }
}
void init() {
    int x, y;
    MAX = 0;
    REP(i, m)
        REP(j, n) {
            REP(k, 8) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if ( !ok(nx, ny) || chess[nx][ny] || chess[i][j]) continue;
                x = i * n + j; y = nx * n + ny;
                adj[x + 1].pb( y + 1 );
            }
        }
    MAX = n * (m + 1);
}
bool bfs() {
    int u, v;
    bool found = false;
    queue <int> Q;
    REP(i, MAX) {
        distx[i] = 0;
        if ( !matchx[i] ) Q.push( i );
    }
    REP(i, MAX) disty[i] = 0;
    while ( !Q.empty() ) {
        u = Q.front(); Q.pop();
        REP(i, adj[u].size()) {
            v = adj[u][i];
            if ( !disty[v] ) {
                disty[v] = distx[u] + 1;
                if ( !matchy[v] ) found = true;
                else {
                    distx[ matchy[v] ] = disty[v] + 1;
                    Q.push( matchy[v] );
                }
            }
        }
    }
    return found;
}
bool dfs(int u) {
    REP(i, adj[u].size()) {
        int v = adj[u][i];
        if ( disty[v] == distx[u] + 1 ) {
            disty[v] = 0;
            if ( !matchy[v] || dfs( matchy[v] ) ) {
                matchx[u] = v;
                matchy[v] = u;
                return true;
            }
        }
    }
    return false;
}
int64 solve() {
    int res = 0;
    int ans;
    while ( bfs() ) {
        FOR(i, 1, MAX)
            if ( !matchx[i] && dfs( i ) ) res++;
    }
    ans = m * n - k;
    return (ans - res / 2);
}
void Read() {
    int test, x, y;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d %d",&m,&n,&k);
        reset();
        FOR(i, 1, k) {
            scanf("%d %d",&x,&y);
            x--; y--;
            chess[x][y] = true;
        }
        init();
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

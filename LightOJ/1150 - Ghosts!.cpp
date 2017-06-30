/***********************************************
* Author - LUONG VAN DO                        *
* 1150 - Ghosts! ->AC
* Algorithm bipartite matching
* Time Limit 0.709s
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
#define maxN 30

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct state{
    int x, y, v;
    state(){}
    state(int xx, int yy, int vv){
        x = xx; y = yy; v = vv;
    }
} a ;
int n, human, node;
char s[maxN][maxN];
int ind[maxN][maxN], d[maxN][maxN];
int c[700][700];
int distx[700], disty[700];
int matchx[700], matchy[700];

vector <int> adj[700];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool ok(int u, int v) {
    return (u>=0 && u<n && v>=0 && v<n);
}
void Cost(int sx, int sy) {
    queue <state> Q;
    Q.push(state(sx, sy, 0));
    REP(i, n)
        REP(j, n) d[i][j] = INF;
        d[sx][sy] = 0;
    while ( !Q.empty() ) {
        a = Q.front(); Q.pop();
        REP(k, 4) {
            int nx = a.x + dx[k];
            int ny = a.y + dy[k];
            if ( !ok(nx, ny) || d[nx][ny]!=INF || s[nx][ny] == '#' ) continue;
            d[nx][ny] = a.v + 1;
            Q.push(state(nx, ny, a.v + 1));
        }
    }
}
void reset() {
    int x, y;
    human = node = 0;
    REP(i, n)
        REP(j, n)
            ind[i][j] = ++node;
            
    FOR(i, 1, n * n)
        FOR(j, 1, n * n) c[i][j] = INF;
        
    REP(i, n)
        REP(j, n)
            if ( s[i][j] == 'G' ) {
                Cost(i, j);
                REP(k, n)
                    REP(h, n)
                        if (s[k][h] == 'H') c[ ind[i][j] ][ ind[k][h] ] = d[k][h] * 2 + 2;
            }
            else if ( s[i][j] == 'H' ) human++;
}
bool bfs(){
    bool found = false;
    queue <int> Q;
    FOR(i, 1, n * n) {
        distx[i] = 0;
        if ( !matchx[i] ) Q.push( i );
    }
    FOR(i, 1, n * n)
        disty[i] = 0;
    while ( !Q.empty() ){
        int u = Q.front(); Q.pop();
        REP(i, adj[u].size()) {
            int v = adj[u][i];
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
bool check(int X) {
    int res = 0;
    FOR(i, 1, n * n) adj[i].clear();
    
    FOR(i, 1, n * n)
        FOR(j, 1, n * n)
            if ( c[i][j] <= X ) adj[i].pb( j );
            
    FOR(i, 1, n * n) matchx[i] = 0;
    FOR(i, 1, n * n) matchy[i] = 0;
    while ( bfs() ) {
        FOR(i, 1, n * n)
            if (!matchx[i] && dfs(i)) res++;
    }
    return (res == human);
}
int solve() {
    int l, r, res;
    l = 0; r = n * n; res = -1;
    while (l<=r) {
        int mid = (l + r) >> 1;
        if ( check(mid) ) {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return res;
}
void Read() {
    int test, ans;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d ",&n);
        REP(i, n) gets(s[i]);
        reset();
        ans = solve();
        if ( ans == -1) printf("Case %d: Vuter Dol Kupokat\n",t);
        else printf("Case %d: %d\n",t,ans);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

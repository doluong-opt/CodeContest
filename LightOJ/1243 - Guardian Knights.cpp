/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1243 - Guardian Knights ->AC
* Algorithm mcmf
* Time Limit 1.290s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
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
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define frr(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i=n - 1; i>=0; i--)
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1000

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, k, m, source, sink;
int a[N], d[N][N], cost[N][N], p[N], cap[N][N], deg[N], dp[N], adj[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char ss[50][50];

bool isOk(int u, int v) {
    return (u>=0 && u<n && v>=0 && v<n);
}
void bfs(int x, int y) {
    queue <ii> q;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++) d[i][j] = INF;
    d[x][y] = 0;
    q.push(ii(x, y));
    while ( !q.empty() ) {
        ii u = q.front(); q.pop();
        for (int k=0;k<4;k++) {
            int nx = u.ff + dx[k];
            int ny = u.ss + dy[k];
            if ( !isOk(nx, ny) || ss[nx][ny] == '#') continue;
            if ( d[nx][ny] == INF ) {
                d[nx][ny] = d[u.ff][u.ss] + 1;
                q.push(ii(nx, ny));
            }
        }
    }
}
int convert(int x, int y) {
    return (x * n + y);
}
void buildMin(int x, int y) {
    int u = convert(x, y), v;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (ss[i][j] == 'm') {
                v = convert(i, j);
                if (d[i][j] != INF) {
                    cap[u][v] = 1;
                    cost[u][v] = d[i][j];
                    cost[v][u] = -d[i][j];
                }
            }
    for (int i=0;i<k;i++)
        if (ss[x][y] - 'A' == i) {
            cap[source][u] = a[i];
            break;
        }
}
bool bellmanford(int n, int s, int t) {
    for (int i=0;i < n;i++) dp[i] = INF;
    dp[s] = 0; p[s] = -1;
    bool flag = true;
    for (int it = 0; it < n && flag; it++) {
        flag = false;
        for (int u = 0; u < n; u++)
            for (int i = 0;i < deg[u];i++) {
                int v = adj[u][i];
                if ( cap[u][v] > 0 && dp[v] > dp[u] + cost[u][v] )
                    dp[v] = dp[u] + cost[u][v], p[v] = u, flag = true;
            }
    }
    return dp[t] < INF;
}
int mcmf(int n, int s, int t, int &fcost) {
    int mf = 0, u, v;
    fcost = 0;
    memset(deg, 0, sizeof(deg));
    for (u = 0; u < n; u++) for (v = 0; v < n; v++) if ( cap[u][v] || cap[v][u] )
        adj[u][ deg[u]++ ] = v;
    while ( bellmanford(n, s, t) ) {
        int f = INF;
        for (v = t; p[v] != -1; v = p[v] ) f = min(f, cap[p[v]][v]);
        for (v = t; p[v] != -1; v = p[v] ) {
            cap[p[v]][v]-=f;
            cap[v][p[v]]+=f;
            fcost+=(f * cost[p[v]][v]);
        }
        mf+=f;
    }
    return mf;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, ans, mf, u;
    scanf("%d",&cases);
    while ( cases--) {
        scanf(" %d %d %d ",&n,&k,&m);
        for (int i=0;i<n;i++) gets(ss[i]);
        for (int i=0;i<k;i++) scanf(" %d ",&a[i]);
        memset(cap, 0, sizeof(cap));
        memset(cost, 0, sizeof(cost));
        source = n * n; sink = source + 1;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (ss[i][j] >= 'A' && ss[i][j]<='Z' ) {
                    bfs(i, j);
                    buildMin(i, j);
                }
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if ( ss[i][j] == 'm' ) {
                    u = convert(i, j);
                    cap[u][sink] = 1;
                }
        mf = mcmf(sink + 1, source, sink, ans);
        printf("Case %d: %d\n", ++caseno, ans);
    }
}

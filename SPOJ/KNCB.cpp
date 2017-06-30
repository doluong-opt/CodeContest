/***********************************************
* Author - LUONG VAN DO                        *
* Problem 
* Algorithm
* Time Limit
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
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000

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
#define N 222
#define M 50000

vector <int> adj[M];

int mark[N][N], m, n, k, Len;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int distx[M], disty[M], matchx[M], matchy[M];

bool isOk(int u, int v) {
    return (u >= 0 && v >= 0 && u < m && v < n);
}
void init() {
    int x, y;
    Len = n * (m + 1);
    for (int i = 0;i < Len;i++) adj[i].clear();
    for (int i = 0;i < m;i++) for (int j = 0;j < n;j++) {
        for (int k = 0;k < 8;k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if ( !isOk(nx, ny) || mark[i][j] || mark[nx][ny]) continue;
            x = i * n + j; y = nx * n + ny;
            adj[x + 1].pb(y + 1);
        }
    }
}
bool bfs() {
    bool found = false;
    int u, v;
    queue <int> q;
    for (int i = 0;i < Len;i++) {
        if ( !matchx[i] ) q.push(i);
        distx[i] = disty[i] = 0;
    }
    while ( !q.empty() ) {
        u = q.front(); q.pop();
        for (int i = 0;i < adj[u].size();i++) {
            v = adj[u][i];
            if ( !disty[v] ) {
                disty[v] = distx[u] + 1;
                if ( !matchy[v] ) found = true;
                else {
                    distx[ matchy[v] ] = disty[v] + 1;
                    q.push( matchy[v] );
                }
            }
        }
    }
    return found;
}
bool dfs(int u) {
    for (int i = 0;i < adj[u].size();i++) {
        int v = adj[u][i];
        if ( disty[v] == distx[u] + 1 ) {
            disty[v] = 0;
            if ( !matchy[v] || dfs( matchy[v]) ) {
                matchx[u] = v;
                matchy[v] = u;
                return true;
            }
        }
    }
    return false;
}
int solve() {
    init();
    for (int i = 0;i < Len;i++) matchx[i] = matchy[i] = 0;
    int res = 0;
    while ( bfs() ) {
        for (int i = 0;i < Len;i++)
            if (!matchx[i] && dfs(i)) res++;
    }
    return (n * m - k - res / 2);
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0, u, v;
	scanf("%d",&cases);
	while (cases--) {
	    scanf("%d %d %d", &m, &n, &k);
	    for (int i = 0;i < m;i++) for (int j = 0;j < n;j++) mark[i][j] = 0;
	    for (int i = 0;i < k;i++) {
	        scanf("%d %d", &u, &v);
	        u--; v--; mark[u][v] = 1;
	    }
	    printf("Case %d: %d\n", ++caseno, solve());
	}
}



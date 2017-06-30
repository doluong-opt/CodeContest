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
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i = b;i >= a;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1111

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
int n, m, x, y, cnt;
int low[N], num[N], parent[N], mark[N][N], child[N];
vector <int> adj[N];
vii ans;
void reset() {
    cnt = 0;
    fr(i, 1, n) {
        parent[i] = low[i] = num[i] = 0;
        child[i] = 0;
    }
}
void dfs(int u) {
    int v;
    low[u] = num[u] = ++cnt;
    for (int i = 0;i < adj[u].size();i++) {
        v = adj[u][i];
        if ( parent[v] == 0 ) {
            parent[v] = u;
            child[u]++;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (parent[u] == -1) {
                if (low[v] > num[u]) {
                    ans.pb(ii(u, v));
                    ans.pb(ii(v, u));
                }
                else ans.pb(ii(u, v));
            }
            else
            if (low[v] > num[u]) {
                ans.pb(ii(u, v));
                ans.pb(ii(v, u));
            }
            else
                ans.pb(ii(u, v));
            mark[u][v] = mark[v][u] = 1;
        }
        else 
        if (parent[u] != v) {
            low[u] = min(low[u], num[v]);
            if ( !mark[u][v] ) {
                ans.pb(ii(u, v));
                mark[u][v] = mark[v][u] = 1;
            }
        }
    }
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int caseno = 0;
	while ( scanf("%d %d", &n, &m) && (n + m) ) {
	    fr(i, 1, n) {
	        adj[i].clear();
	        fr(j, 1, n) mark[i][j] = 0;
	    }
	    rep(i, m) {
	        scanf("%d %d", &x, &y);
	        adj[x].pb(y); adj[y].pb(x);
	    }
	    reset(); ans.clear(); parent[1] = -1;
	    dfs(1);
	    printf("%d\n\n", ++caseno);
	    for (int i = 0;i < ans.size();i++)
            printf("%d %d\n", ans[i].ff, ans[i].ss);
        puts("#");
	}
	return 0;
}

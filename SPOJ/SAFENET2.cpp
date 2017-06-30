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
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 30100

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
int n, m, cnt, mark[N], ans;
int parent[N], low[N], num[N], isCut[N], child[N];
vector <int> adj[N];
void dfs(int u) {
    low[u] = num[u] = ++cnt;
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        if ( !parent[v] ) {
            parent[v] = u;
            child[u]++;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if ( parent[u] == -1 )
                isCut[u] = isCut[u] | (low[v] >= num[u] && child[u] > 1);
            else 
                isCut[u] = isCut[u] | (low[v] >= num[u]);
        }
        else 
        if (parent[u] != v) low[u] = min(low[u], num[v]);
    }
}
void run(int u) {
    if ( mark[u] ) return;
    cnt++;
    mark[u] = 1;
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        if ( !mark[v] && !isCut[v] ) run(v);
    }
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int u, v;
	scanf("%d %d", &n, &m);
	rep(i, m) {
	    scanf("%d %d", &u, &v);
	    adj[u].pb(v); adj[v].pb(u);
	}
	cnt = 0;
	fr(i, 1, n) {
	    num[i] = low[i] = child[i] = 0;
	    parent[i] = isCut[i] = mark[i] = 0;
	}
	fr(i, 1, n)
        if ( !parent[i] ) {
            parent[i] = -1;
            dfs(i);
        }
    ans = 0;
    fr(i, 1, n)
        if ( !mark[i] && !isCut[i] ) {
            cnt = 0;
            run(i);
            ans = max(ans, cnt);
        }
    printf("%d\n", ans + 1);
	return 0;
}

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
#define N 100111

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
int n, m, x, y, cnt, top, com;
vector <int> adj[N];
int low[N], num[N], child[N], parent[N], isCut[N];
int s[N], h[N];
ii ans[N];
void reset() {
    cnt = top = com = 0;
    fr(i, 1, n) {
        low[i] = num[i] = 0;
        parent[i] = child[i] = isCut[i] = 0;
    }
}
void dfs(int u) {    
    int v;
    low[u] = num[u] = ++cnt;
    s[++top] = u;
    for (int i = 0;i < adj[u].size();i++) {
        v = adj[u][i];
        if ( parent[v] == 0 ) {
            parent[v] = u;
            child[u]++;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (parent[u] == -1) {
                isCut[u] = isCut[u] || (low[v] >= num[u] && child[u] > 1);
                if (low[v] >= num[u] && child[u] > 1) ans[u].ss++;
            }
            else {
                isCut[u] = isCut[u] || (low[v] >= num[u]);
                if (low[v] >= num[u]) ans[u].ss++;
            }
            
        }
        else
        if (parent[u] != v) {
            low[u] = min(low[u], num[v]);
        }
    }
    if (low[u] == num[u]) {
        ++com; int x;
        do {
            x = s[top--];
            h[x] = com;
        }while (x != u);
    }
}
bool cmp(ii x, ii y) {
    if (x.ss != y.ss) return x.ss > y.ss;
    return x.ff < y.ff;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
    while ( scanf("%d %d", &n, &m) && (n + m)){
        fr(i, 1, n) {
            adj[i].clear();
            ans[i].ff = i; ans[i].ss = 0;
        }
        while ( scanf("%d %d", &x, &y)) {
            if (x == -1 && y == -1) break;
            x++; y++;
            adj[x].pb(y); adj[y].pb(x);
        }
        reset();
        parent[1] = -1;
        dfs(1);
        sort(ans + 1, ans + n + 1, cmp);
        for (int i = 1;i <= m;i++) printf("%d %d\n", ans[i].ff - 1, ans[i].ss + 1);
        puts("");
	}
	return 0;
}

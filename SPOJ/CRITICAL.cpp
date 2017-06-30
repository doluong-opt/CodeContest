/***********************************************
* Author LUONG VAN DO                        *
* Problem CRITICAL
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

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 111222333
#define N 20010

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
vector <int> adj[N];
int n, m, cnt;
int low[N], num[N], parent[N], child[N], isCut[N];
int mark[N];
void dfs(int u) {
    num[u] = low[u] = ++cnt;
    for (int i = 0;i < adj[u].size();i++) {
        int v = adj[u][i];
        if (!parent[v]) {
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
        if (parent[u] != v && low[u] > num[v]) low[u] = num[v];
    }
}
void findX(int u) {
    int v;
    if ( mark[u] ) return;
    mark[u] = 1;
    for (int i = 0;i < adj[u].size();i++) {
        v = adj[u][i];
        findX(v);
    }
    child[u]+=child[v];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int u, v;
    double res;
    scanf("%d %d", &n, &m);
    for (int i = 0;i < m;i++) {
        scanf("%d %d",&u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 1;i <= n;i++) {
        low[i] = num[i] = 0;
        parent[i] = child[i] = 0;
        isCut[i] = mark[i] = 0;
    }
    cnt = 0;
    for (int i = 1;i <= n;i++)
        if (!parent[i]) {
            parent[i] = -1;
            dfs(i);
        }
    for (int i = 1;i <= n;i++)
        if (!mark[i]) findX(i);
    res = 0.0;
    cnt = 0;
    for (int i = 1;i <= n;i++)
        printf("%d %d %d %d\n", i, isCut[i], child[i], n - child[i]);
    for (int i = 1;i <= n;i++)
        if ( isCut[i] ) res+=(n - child[i]) * (child[i] - 1);
    res/=n;
    printf("%.2lf\n", res);
}

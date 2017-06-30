/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1257 - Farthest Nodes in a Tree (II) ->AC
* Algorithm dfs
* Time Limit 0.194s
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
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 30010

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

vector <ii> adj[N];
int d1[N], d2[N], d3[N], id, n;
char s[N];

void dfs(int u, int p, int d[]) {
    for (int i=0;i<adj[u].size();i++) {
        int v = adj[u][i].ff;
        if (!d[v] && v!=p) {
            d[v] = d[u] + adj[u][i].ss;
            dfs(v, p, d);
        }
    }
}

int getInt(int n) {
    int v = 0;
    while (id < n && s[id] !=' ') v = v * 10 + s[id++] - '0';
    ++id;
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, node, x, y, w, caseno = 0, m;
    gets(s); id = 0; cases = getInt(strlen(s)); 
    while (cases--) {
        gets(s); id = 0; n = getInt(strlen(s));
        for (int i=0;i<n;i++) {
            adj[i].clear();
            d1[i] = d2[i] = d3[i] = 0;
        }
        for (int i=0;i<n-1;i++) {
            gets(s); m = strlen(s); id = 0;
            x = getInt(m); y = getInt(m); w = getInt(m);
            adj[x].pb(ii(y, w));
            adj[y].pb(ii(x, w));
        }
        dfs(0, 0, d1); w = 0;
        for (int i=0;i<n;i++)
            if (w < d1[i]) {
                w = d1[i];
                node = i;
            }
        dfs(node, node, d2); w = 0;
        for (int i=0;i<n;i++)
            if (w < d2[i]) {
                w = d2[i];
                node = i;
            }
        dfs(node, node, d3);
        printf("Case %d:\n",++caseno);
        for (int i=0;i<n;i++)
            printf("%d\n",max(d1[i], max(d2[i], d3[i])));
    }
}

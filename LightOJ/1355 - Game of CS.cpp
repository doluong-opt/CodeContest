/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1355 - Game of CS ->AC
* Algorithm game
* Time Limit 0.056s
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
#define N 1010

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
int n;
vector <int> adj[N], cost[N];
int f[N], ind;
char s[N];
void dfs(int u, int par) {
    int w, v;
    f[u] = 0;
    for (int i=0;i<adj[u].size();i++) {
        v = adj[u][i];
        if (v != par) {
            dfs(v, u);
            if ( cost[u][i] == 1 ) w = f[v] + 1;
            else
            if ( cost[u][i] % 2 == 0) w = f[v];
            else
            if ( f[v] % 2 ) w = f[v] - 1;
            else w = f[v] + 1;
            f[u]^=w;
        }
    }
}
int getInt(int m) {
    int v = 0;
    while (ind < m && s[ind] !=' ') v = v * 10 + s[ind++] - '0';
    ++ind;
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    int u, v, w, m;
    gets(s); ind = 0; cases = getInt(strlen(s));
    while (cases--) {
        gets(s); ind = 0; n = getInt(strlen(s));
        for (int i=0;i<n;i++) {
            adj[i].clear();
            cost[i].clear();
            f[i] = 0;
        }
        for (int i=0;i<n-1;i++) {
            gets(s); ind = 0; m = strlen(s);
            u = getInt(m);
            v = getInt(m);
            w = getInt(m);
            adj[u].pb(v);
            adj[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
        }
        dfs(0, -1);
        printf("Case %d: ",++caseno);
        if (f[0]) puts("Emily");
        else puts("Jolly");
    }
}

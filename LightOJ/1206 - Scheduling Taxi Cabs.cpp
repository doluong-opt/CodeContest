/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1206 - Scheduling Taxi Cabs ->AC
* Algorithm BP
* Time Limit 0.021s
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
#define N 501

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
ii x[N], y[N];
vector <int> adj[N];
int distX[N], distY[N];
int matchX[N], matchY[N];
int n, tie[N], id;
char s[N];
bool connect(int u, int v) {
    int a = abs(x[u].ff - y[u].ff);
    int b = abs(x[u].ss - y[u].ss);
    int c = abs(y[u].ff - x[v].ff);
    int d = abs(y[u].ss - x[v].ss);
    return (tie[u] + a + b + c + d < tie[v]);
}
bool bfs() {
    bool found = false;
    queue <int> Q;
    for (int i=1;i<=n;i++) {
        if ( !matchX[i] ) Q.push( i );
        distX[i] = distY[i] = 0;
    }
    while ( !Q.empty() ) {
        int u = Q.front(); Q.pop();
        for (int i=0;i<adj[u].size();i++) {
            int v = adj[u][i];
            if ( !distY[v] ) {
                distY[v] = distX[u] + 1;
                if (!matchY[v]) found = true;
                else {
                    distX[ matchY[v] ] = distY[v] + 1;
                    Q.push( matchY[v] );
                }
            }
        }
    }
    return found;
}
bool dfs(int u) {
    for (int i=0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if (distY[v] == distX[u] + 1) {
            distY[v] = 0;
            if (!matchY[v] || dfs( matchY[v] ) ) {
                matchX[u] = v;
                matchY[v] = u;
                return true;
            }
        }
    }
    return false;
}
int hkp() {
    int mx = 0;
    for (int i=1;i<=n;i++)
        matchX[i] = matchY[i] = 0;
    while ( bfs() ) {
        for (int i=1;i<=n;i++)
            if ( !matchX[i] && dfs(i) ) mx++;
    }
    return mx;
}
int getInt(int n) { 
    int v = 0;
    while (id < n && s[id] !=' ') {
        if (s[id] == ':') break;
        v = v * 10 + s[id++] - '0';
    }
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, h, m, caseno = 0, l;
    gets(s); id = 0; cases = getInt(strlen(s));
    while (cases--) {
        gets(s); id = 0; n = getInt(strlen(s));
        for (int i=1;i<=n;i++) {
            gets(s); id = 0; l = strlen(s);
            h = getInt(l); ++id;
            m = getInt(l); ++id;
            x[i].ff = getInt(l); ++id;
            x[i].ss = getInt(l); ++id;
            y[i].ff = getInt(l); ++id;
            y[i].ss = getInt(l);
            tie[i] = (h * 60) + m;
            adj[i].clear();
        }
        for (int i=1;i<=n;i++)
            for (int j=i + 1;j<=n;j++)
                if (connect(i, j)) adj[i].pb(j);
            
        printf("Case %d: %d\n",++caseno, n - hkp());
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10308 - Roads in the North ->AC
* Algorithm dfs
* Time Limit 0.016s
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
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define M 10010

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int64, int64> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
char s[M];
vector <ii> adj[M];
int64 color[M], mark[M];
int64 d[M];
void dfs(int64 u){
    if (color[u]) return;
    color[u] = 1;
    for (int i=0;i<adj[u].size();i++) {
        int64 v = adj[u][i].A;
        int64 w = adj[u][i].B;
        if (!color[v]) {
            d[v] = d[u] + w;
            dfs( v );
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int64 x, y, c, node;
    while ( gets(s) ){
        for (int i=1;i<=10000;i++) {
            adj[i].clear();
            mark[i] = 0;
            adj[i].clear();
        }
        if (strlen(s)) {
            sscanf(s,"%lld %lld %lld",&x,&y,&c); 
            mark[x] = mark[y] = 1;
            adj[x].pb(ii(y, c)); adj[y].pb(ii(x, c));
            while ( gets(s) && strlen(s)) {
                sscanf(s,"%lld %lld %lld",&x,&y,&c); 
                mark[x] = mark[y] = 1;
                adj[x].pb(ii(y, c)); adj[y].pb(ii(x, c));
            }
        }
        for (int i=1;i<=10000;i++) {
            color[i] = 0;
            d[i] = 0;
        }
        dfs( 1 );
        node = 0;
        for (int i=1;i<=10000;i++)
            if (mark[i] && d[node] < d[i]) node = i;
        for (int i=1;i<=10000;i++) {
            color[i] = 0;
            d[i] = 0;
        }
        dfs(node);
        for (int i=1;i<=10000;i++)
            if (mark[i] && d[node] < d[i]) node = i;
        printf("%lld\n",d[node]);
    }
}

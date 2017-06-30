/***********************************************
* Author LUONG VAN DO                        *
* Problem BRIDGES
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
#define N 10010

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
struct bridge {
    int64 x, y, t;
    bridge(){}
    bridge(int64 xx, int64 yy, int64 tt){
        x = xx; y = yy; t = tt;
    }
} edge[N];
int64 color[N], child[N];
vector <int64> adj[N];
int64 n, k, vp, vc;
ii res[N];
void dfs(int64 u) {
    if ( color[u] ) return;
    color[u] = 1;
    child[u] = 1;
    rep(i, adj[u].size()) {
        int64 v = adj[u][i];
        if ( color[v] ) continue;
        dfs( v );
        child[u]+=child[v];
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    scanf("%lld %lld %lld %lld",&n, &k, &vp, &vc);
    fr(i, 1, n - 1) {
        scanf("%lld %lld %lld",&edge[i].x,&edge[i].y,&edge[i].t);
        adj[edge[i].x].pb(edge[i].y);
        adj[edge[i].y].pb(edge[i].x);
    }
    fr(i, 1, n) color[i] = child[i] = 0;
    dfs( 1 );
    fr(i, 1, n - 1) {
        int64 x = min(child[edge[i].x], child[edge[i].y]);
        res[i].ss = i;
        res[i].ff = edge[i].t * x * (n - x) * (vp - vc);
    }
    sort(res + 1, res + n);
    fr(i, 1, k) {
        if (i > 1) printf(" ");
        printf("%lld",res[i].ss);
    }
    puts("");
}

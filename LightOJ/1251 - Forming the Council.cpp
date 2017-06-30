/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1251 - Forming the Council ->AC 
* Algorithm 2-SAT
* Time Limit 0.081s
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
vector <int> adj[2 * N], adjj[2 * N];
vector <int> v;
int Index[2 * N], color[2 * N];
int topo[2 * N];
int n, m, scc, sz;
void process(int a, int b, int x, int y) {
    int u, v, uu, vv;
    if (a > 0) {
        u = 2 * x;
        v = 2 * x + 1;
    }
    else {
        u = 2 * x + 1;
        v = 2 * x;
    }
    if (b > 0) {
        uu = 2 * y;
        vv = 2 * y + 1;
    }
    else {
        uu = 2 * y + 1;
        vv = 2 * y;
    }
    adj[u].pb(vv);
    adj[uu].pb(v);
    
    adjj[v].pb(uu);
    adjj[vv].pb(u);
}
void reset() {
    for (int i=0;i<2 * m;i++)
        color[i] = 0;
}
void dfs1(int u) {
    if (color[u]) return;
    color[u] = 1;
    for (int i=0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if (!color[v]) dfs1( v );
    }
    topo[sz++] = u;
}
void dfs2(int u, int s) {
    if (color[u]) return;
    color[u] = 1;
    Index[u] = s;
    for (int i=0;i<adjj[u].size();i++) {
        int v = adjj[u][i];
        if (!color[v]) dfs2(v, s);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, a, b, sc, f;
    int x, y;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d",&n,&m); v.clear();
        for (int i=0;i<2 * m;i++) {
            adj[i].clear();
            adjj[i].clear();
        }
        for (int i=0;i<n;i++) {
            scanf("%d %d",&a,&b);
            x = abs(a) - 1; y = abs(b) - 1;
            process(a, b, x, y);
        }
        reset(); sz = 0;
        for (int i=0;i<2 * m;i++)
            if (!color[i]) dfs1( i );
            
        reset(); scc = 0;
        
        //for (int i=0;i<sz;i++) cout<<topo[i]<<" "<<adjj[topo[i]].size()<<endl;
        
        for (int i=sz-1;i>=0;i--)
            if (!color[topo[i]]) dfs2(topo[i], ++scc);
        
        f = 1; v.clear(); sc = 0;
        printf("Case %d: ",++caseno);
        
        for (int i=0;i<2 * m && f;i+=2) {
            sc++;
            if (Index[i] == Index[i + 1]) f = 0;
        else
            if (Index[i] < Index[i + 1]) v.pb(sc);
        }
        if (!f) puts("No");
        else {
            puts("Yes"); sc = 0;
            printf("%d",v.size());
            for (int i=0;i<v.size();i++) printf(" %d",v[i]);
            puts("");
        }
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* 1168 - Wishing Snake ->AC
* Algorithm Strongly Com....
* Time Limit 0.067s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
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
#define maxN 50001
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector <int> adj[maxN];
vector <int> adjj[maxN];
int cnt, scc, zero;
int mark[maxN], color[maxN];
int low[maxN], num[maxN];
int inCom[maxN], degu[maxN], degv[maxN];
stack <int> S;
void tajan(int u){
    num[u] = ++cnt;
    low[u] = num[u];
    S.push( u );
    REP(i, adj[u].size()) {
        int v = adj[u][i];
        if (!color[v])
        if ( num[v] ) low[u] = min(low[u], num[v]);
        else {
            tajan( v );
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == num[u]) {
        ++scc;
        int x;
        do{
            x = S.top(); S.pop();
            color[x] = 1;
            inCom[x] = scc;
        }while (x != u);
    }
}
bool check() {
    scc = cnt = zero = 0;
    while (!S.empty()) S.pop();
    FOR(i, 1, 1000)
        low[i] = num[i] = inCom[i] = color[i] = 0;
        
    FOR(i, 1, 1000)
        if (mark[i] && !color[i]) tajan( i );
    
    FOR(i, 1, 1000)
        if (mark[i])
        REP(j, adj[i].size()) {
            int v = adj[i][j];
            if (i == 1) zero = inCom[i];
            if (v == 1) zero = inCom[v];
            if (mark[v] && inCom[i]!= inCom[v])
                adjj[ inCom[i] ].pb( inCom[v] );
        }
    if (zero == 0) return false;
    if (scc == 1) return true;
    FOR(i, 1, scc){
        REP(j, adjj[i].size()) {
            int v = adjj[i][j];
            degu[i]++;
            degv[v]++;
        }
    }
    int x, y, z;
    x = y = z = 0;
    FOR(i, 1, scc) {
        if (degu[i] == 0 && degv[i] == 1) x++;
        if (i == zero && degu[i] == 1 && degv[i] == 0) y++;
        if (degu[i] == 1 && degv[i] == 1) z++;
    }
    if (x == 1 && y == 1 && x + y + z == scc) return true;
    return false;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, u, v, k, n;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        FOR(i, 1, 1000) {
            adj[i].clear();
            adjj[i].clear();
            degu[i] = degv[i] = mark[i] = 0;
        }
        FOR(i, 1, n) {
            scanf("%d",&k);
            REP(i, k) {
                scanf("%d %d",&u,&v);
                ++u; ++v;
                mark[u] = mark[v] = 1;
                adj[u].pb(v);
            }
        }
        if (check()) printf("Case %d: YES\n",t);
        else printf("Case %d: NO\n",t);
    }
    return 0;
}

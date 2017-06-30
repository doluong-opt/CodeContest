/***********************************************
* Author - LUONG VAN DO                        *
* 1210 - Efficient Traffic System ->AC
* Algorithm Strong Com....
* Time Limit 0.186s
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
#define maxN 20001
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector <int> adj[maxN], adjj[maxN];
int low[maxN], num[maxN], color[maxN];
int inCom[maxN];
int degin[maxN], degout[maxN];
int n, m, cnt, scc;
stack <int> S;
void tajan(int u) {
    low[u] = num[u] = ++cnt;
    S.push(u);
    REP(i, adj[u].size()){
        int v = adj[u][i];
        if (!color[v])
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            tajan(v);
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
        } while (x != u);
    }
}
int solve(){
    int x, y;
    scc = cnt = x = y = 0;
    FOR(i, 1, n) low[i] = num[i] = color[i] = 0;
    FOR(i, 1, n)
        if (!color[i]) tajan(i);
    FOR(i, 1, n) {
        REP(j, adj[i].size()) {
            int v = adj[i][j];
            if (inCom[i] != inCom[v]) {
                degin[ inCom[v] ]++;
                degout[ inCom[i] ]++;
            }
        }
    }
    if (scc == 1) return 0;
    x = y = 0;
    FOR(i, 1, scc) {
        if (degin[i] == 0) x++;
        if (degout[i] == 0) y++;
    }
    if (x == y) return (x);
    else return max(x, y);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, u, v;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&n,&m);
        FOR(i, 1, n) {
            adj[i].clear();
            adjj[i].clear();
            degin[i] = degout[i] = 0;
        }
        FOR(i, 1, m) {
            scanf("%d %d",&u,&v);
            adj[u].pb(v);
        }
        printf("Case %d: %d\n",t,solve());
    }
    return 0;
}

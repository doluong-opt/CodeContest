/***********************************************
* Author LUONG VAN DO                        *
* Problem BIC
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
#define MOD 1000000000
#define N 10010

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
vector <int> adj[N], amo[N];
int n, m, scc, cnt, flag;
int color[N], mark[N], low[N], num[N], q[N];
int64 dp[N];
stack <int> s;

void check(int u) {
    if ( color[u] ) return;
    color[u] = 1;
    if (u == 2) mark[u] = 1;
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        check( v );
        mark[u] = mark[u] | mark[v];
    }
}

void tajan(int u) {
    num[u] = ++cnt;
    low[u] = num[u];
    s.push(u);
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        if (!color[v])
        if ( num[v] ) low[u] = min(low[u], num[v]);
        else {
            tajan(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == num[u]) {
        ++scc;
        int x;
        do{
            x = s.top(); s.pop();
            color[x] = 1;
            amo[scc].pb( x );
        }while (x != u);
    }
}
void dfs(int u) {
    if ( color[u] ) return;
    color[u] = 1;
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        dfs( v );
    }
    q[m--] = u;
}
void solve() {
    fr(i, 1, n) color[i] = q[i] = dp[i] = 0;
    m = n;
    fr(i, 1, n)
        if (!color[i]) dfs(i);
    dp[1] = 1; flag = 0;
    int u, v;
    fr(i, 1, n)
        if ( mark[q[i]] ) {
            u = q[i];
            rep(j, adj[u].size()) {
                v = adj[u][j];
                dp[v]+=dp[u];
                if (dp[u] >= MOD) flag = 1;
                if (dp[v] >= MOD) flag = 1;
                if (dp[u] + dp[v] >= MOD) flag = 1;
                dp[v]%=MOD;
            }
        }
    if (!flag) printf("%d\n", dp[2]);
    else printf("%09d\n", dp[2]);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int u, v, f;
    scanf("%d %d",&n, &m);
    fr(i, 1, m) {
        scanf("%d %d",&u, &v);
        adj[u].pb(v);
    }
    cnt = scc = 0;
    fr(i, 1, n) color[i] = mark[i] = low[i] = num[i] = 0;
    check( 1 );
    fr(i, 1, n) color[i] = 0; tajan( 1 );
    f = 0;
    fr(i, 1, scc) if ( amo[i].size() > 1 && !f) {
        rep(j, amo[i].size())
            if ( mark[ amo[i][j] ] ) {
                f = 1;
                break;
            }
    }
    if (f) printf("inf\n");
    else solve();
}

/***********************************************
* Author LUONG VAN DO                        *
* Problem ADS
* Algorithm dfs
* Time Limit 0.09s
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
#define N 2010

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
int n, m, k, cnt;
int low[N], num[N], color[N]; 
stack <int> s;

void dfs(int u) {
    num[u] = ++cnt;
    low[u] = num[u];
    s.push(u);
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        if (!color[v])
        if ( num[v] ) low[u] = min(low[u], num[v]);
        else {
            dfs( v );
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == num[u]) {
        k++;
        int x;
        do{
            x = s.top(); s.pop();
            color[x] = 0;
        }while (x != u);
    }
}
int tajan() {
    k = cnt = 0;
    fr(i, 1, n) color[i] = num[i] = low[i] = 0;
    fr(i, 1, n)
        if (!color[i]) dfs( i );
    return k;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int u, v;
    scanf("%d %d",&n,&m);
    rep(i, m) {
        scanf("%d %d",&u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    printf("%d\n", m - n + tajan());
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1382 - The Queue ->AC
* Algorithm count
* Time Limit 0.124s
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
#define MOD 1000000007
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
char s[10];
int ind;
int64 x, y, d, f[N];
int isRoot[N], child[N];
int getInt(int m) {
    int v = 0;
    while (ind < m && s[ind] !=' ') v = v * 10 + s[ind++] - '0';
    ind++;
    return v;
}
void dfs(int u) {
    child[u] = 1;
    for (int i=0;i<adj[u].size();i++) {
        int v = adj[u][i];
        dfs(v);
        child[u]+=child[v];
    }
}
void extended(int64 a, int64 b) {
    if (b == 0) {
        x = 1; y = 0; d = a;
        return;
    }
    extended(b, a % b);
    int64 x1 = y;
    int64 y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}
void fact() {
    f[0] = f[1] = 1;
    for (int i=2;i<=1000;i++) {
        f[i] = f[i - 1] * i;
        f[i]%=MOD;
    }
}
int64 c(int n, int k) {
    int64 res = f[n];
    extended(f[k], MOD);
    while (x < 0) x+=MOD; res*=x;
    res%=MOD;
    extended(f[n-k], MOD);
    while (x < 0) x+=MOD; res*=x;
    res%=MOD;
    return res;
}
int64 Count(int u, int r) {
    int64 res = c(r, child[u]);
    r = child[u] - 1;
    for (int i=0;i<adj[u].size();i++) {
        int v = adj[u][i];
        res*=Count(v, r);
        res%=MOD;
        r-=child[v];
    }
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, m, n, x, y, caseno = 0;
    int64 ans;
    fact();
    gets(s); ind = 0; cases = getInt(strlen(s));
    while ( cases--) {
        gets(s); ind = 0; n = getInt(strlen(s));
        for (int i=0;i<n;i++) {
            isRoot[i] = 1; child[i] = 0;
            adj[i].clear();
        }
        for (int i=0;i<n-1;i++) {
            gets(s); ind = 0; m = strlen(s);
            x = getInt(m) - 1; y = getInt(m) - 1;
            adj[x].pb(y);
            isRoot[y] = 0;
        }
        for (int i=0;i<n;i++)
            if (isRoot[i]) dfs(i);
        printf("Case %d: ",++caseno);
        ans = 1LL;
        for (int i=0;i<n;i++)
            if (isRoot[i]) {
                ans*=Count(i, n);
                ans%=MOD;
            }
        printf("%lld\n",ans);
    }
}

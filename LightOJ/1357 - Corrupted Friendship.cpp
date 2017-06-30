/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1357 - Corrupted Friendship ->AC
* Algorithm dfs
* Time Limit 0.036s
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
#define N 100010

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
int64 n, id, ans;
int size[N], color[N];
char s[N];
void dfs(int u) {
    int v;
    if (color[u]) return;
    color[u] = 1;
    size[u] = 1;
    for (int i=0;i<adj[u].size();i++) {
        v = adj[u][i];
        dfs(v);
        size[u]+=size[v];
    }
    ans-=(size[u] - 1);
}
int64 getInt(int m) {
    int64 v = 0;
    while (id < m && s[id] != ' ') v = v * 10 + s[id++] - '0';
    ++id;
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, x, y, caseno = 0, m;
    int64 n;
    gets(s); id = 0; cases = getInt(strlen(s));
    while (cases--) {
        gets(s); id = 0; n = getInt(strlen(s));
        for (int i=0;i<n;i++) {
            adj[i].clear();
            size[i] = color[i] = 0;
        }
        for (int i=0;i<n-1;i++) {
            gets(s); id = 0; m = strlen(s);
            x = getInt(m); y = getInt(m); x--; y--;
            adj[x].pb(y);
        }
        ans = (n * (n - 1)) >> 1;
        dfs(0);
        printf("Case %d: %lld %lld\n",++caseno, n - 1, ans);
    }
}

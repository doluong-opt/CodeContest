/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1219 - Mafia ->AC
* Algorithm dfs
* Time Limit 0.001s
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
int n, Ans, id;
char s[5000];
vector <int> adj[N];
int boys[N], city[N];
bool cannot[N];
int dfs(int u) {
    int x = boys[u] - 1;
    for (int i=0;i<adj[u].size();i++)
        x+=dfs(adj[u][i]);
    Ans+=(x > 0) ? x : -x;
    return x;
}
int getInt(int n){
    int v = 0;
    while (id < n && s[id] !=' ') v = v * 10 + s[id++] - '0';
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, root, q, v, caseno = 0;
    int l;
    gets(s); id = 0; cases = getInt(strlen(s));
    while (cases--) {
        gets(s); id = 0; n = getInt(strlen(s));
        for (int i=1;i<=n;i++) {
            adj[i].clear();
            cannot[i] = true;
        }
        for (int i=1;i<=n;i++) {
            gets(s); id = 0; l = strlen(s);
            city[i] = getInt(l); ++id;
            boys[i] = getInt(l); ++id;
            q = getInt(l); ++id;
            while (q--) {
                v = getInt(l); ++id;
                adj[city[i]].pb(v);
                cannot[v] = false;
            }
        }
        root = 0;
        for (int i=1;i<=n && !root;i++)
            if (cannot[i]) root = i;
        Ans = 0; dfs(root);
        printf("Case %d: %d\n",++caseno, Ans);
    }
}

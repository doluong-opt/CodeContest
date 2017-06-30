/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10243 - Fire ! Fire !! Fire !!! ->AC
* Algorithm MVC
* Time Limit 0.028s
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
#define N 100000

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
int color[N], dp[N][3];
int n, m;
void MVC(int u) {
    if (color[u]) return;
    color[u] = 1;
    
    for (int i=0;i<=1;i++)
        dp[u][i] = i;
        
    for (int i=0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if (!color[v]) {
            MVC( v );
            dp[u][0]+=dp[v][1];
            dp[u][1]+=min(dp[v][0], dp[v][1]);
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int u, v, ans;
    while ( scanf("%d",&n) && n) {
        for (int i=1;i<=n;i++) {
            adj[i].clear();
            color[i] = 0;
        }
        for (int u=1;u<=n;u++) {
            scanf("%d",&m);
            while (m--) {
                scanf("%d",&v);
                adj[u].pb(v);
            }
        }
        MVC( 1 );
        ans = min(dp[1][0], dp[1][1]);
        if (n == 1) ans = 1;
        printf("%d\n",ans);
    }
}

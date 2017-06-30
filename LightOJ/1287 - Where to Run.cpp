/***********************************************
* Author - LUONG VAN DO                        *
* Problem 
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

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 15

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

double dp[N][1<<N];
int n, m, u, v, w, lim;
int mark[N][1<<N];
vector <ii> adj[N];

bool run(int cur, int mask) {    
    if (mask == lim - 1) return true;    
    if ( mark[cur][mask] ) return dp[cur][mask];
    mark[cur][mask] = 1;
    dp[cur][mask] = 5.0;
    int cnt = 0;
    rep(i, adj[cur].size()) {
        int v = adj[cur][i].ff;
        int w = adj[cur][i].ss;
        if ( !And(mask, v) && run(v, Or(mask, v)) ) {
            int mask0 = Or(mask, v);
            dp[cur][mask] += dp[v][mask0] + w;
            cnt++;
        }
    }
    if (cnt > 0) {
        dp[cur][mask] /= cnt;
        return true;
    }
    else {
        dp[cur][mask] = 0;
        return false;
    }
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d %d", &n, &m);
	    rep(i, n) adj[i].clear();
	    rep(i, m) {
	        scanf("%d %d %d", &u, &v, &w);
	        adj[u].pb(ii(v, w)); adj[v].pb(ii(u, w));
	        
	    }	    
	    lim = (1<<n);
	    rep(i, n) rep(j, lim) {
	        dp[i][j] = 0.0;
	        mark[i][j] = 0;
	    }
	    run(0, 1);
	    printf("Case %d: %.10lf\n", ++caseno, dp[0][1]);
	}
	return 0;
}

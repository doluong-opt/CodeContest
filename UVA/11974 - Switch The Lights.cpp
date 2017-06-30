/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11974 - Switch The Lights ->AC
* Algorithm dp
* Time Limit 1.147s
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
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define frr(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i=n - 1; i>=0; i--)
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
int dp[1<<15];
int s[110], n, m;
int cal(int mask, int x) {
    for (int j=0;j<n;j++)
        if ( And(s[x], j) ) mask^=(1<<j);
    return mask;
}
int run(int mask) {
    if (mask == 0) return 0;
    int &res = dp[mask];
    if (res != -1) return res;
    res = INF;
    for (int i=0;i<m;i++)
        res = min(res, 1 + run( cal(mask, i) ));
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, lim, caseno = 0, c, ans;
    scanf("%d",&cases);
    while ( cases-- ) {
        scanf("%d %d",&n,&m);
        for (int i=0;i<m;i++) s[i] = 0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                scanf("%d",&c);
                s[i] = s[i] * 2 + c;
            }
        }
        lim = (1<<n);
        memset(dp, -1, sizeof(dp));
        ans = run( lim - 1 );
        if ( ans != INF ) printf("Case %d: %d\n",++caseno, ans);
        else printf("Case %d: IMPOSSIBLE\n",++caseno);
    }
}

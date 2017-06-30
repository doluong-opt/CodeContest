/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10943 - How do you add? ->AC
* Algorithm dp
* Time Limit 0.02s
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
#define INF 1000000
#define N 110

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
int64 dp[N][N];
int64 run(int n, int k) {
    if (k == 1) return dp[n][k] = 1;
    else
    if (n < 0 || k < 0) return 0;
    int64 &res = dp[n][k];
    if (res != -1) return res % INF;
    res = 0;
    for (int i=0;i<=n;i++) {
        res+=(run(n - i, k - 1) % INF);
        res%=INF;
    }
    return res % INF;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, k;
    memset(dp, -1, sizeof(dp));
    for (int i=0;i<=100;i++)
        for (int j=0;j<=100;j++)
            run(i, j);
    while ( scanf("%d %d",&n,&k) && (n + k)) printf("%lld\n", dp[n][k]);
}

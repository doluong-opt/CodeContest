/***********************************************
* Author LUONG VAN DO                        *
* Problem LEM3
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
#define N 17

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
int dp[1<<N][N], lim, ans, n;
int a[N][N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    scanf("%d", &n);
    for (int i = 1; i<= n;i++)
        for (int j = 1;j <= n;j++) scanf("%d", &a[i][j]);
    lim = (1<<n);
    for (int i = 1; i < lim; i++)
        for (int j = 1;j <= n;j++) dp[i][j] = INF;

    for (int i = 1;i <= n;i++)
        dp[1<<(i - 1)][i] = 0;

    for (int mask = 1;mask < lim;mask++)
        for (int j = 1;j <= n;j++)
            for (int k = 1;k <= n;k++) {
                if ( !And(mask, k - 1) )
                    dp[Or(mask, k - 1)][k] = min(dp[Or(mask, k - 1)][k], dp[mask][j] + a[j][k]);
            }
    ans = INF;
    for (int i = 1;i <= n;i++)
        ans = min(ans, dp[lim - 1][i]);
    printf("%d\n", ans);
}

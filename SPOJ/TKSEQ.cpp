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
#define INF 50000000000000000LL
#define N 10000

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
int n, val[N], k;
int64 dp[N][N], ans;
int calc(int x) {
    x %= 3;
    if (x == 1) return 1;
    if (x == 2) return -1;
    if (x == 0) return 1;
}
int main() {
	freopen("TKSEQ.INP","r", stdin); freopen("TKSEQ.OUT","w", stdout);
	scanf("%d %d", &n, &k); k *= 3;
	fr(i, 1, n) scanf("%d", &val[i]);
	fr(i, 0, n) fr(j, 0, k) dp[i][j] = -INF;
    dp[0][0] = 0; fr(i, 1, n) dp[i][0] = 0;
	fr(i, 1, n)
        fr(j, 1, k) {
            dp[i][j] = dp[i - 1][j];
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + calc(j) * val[i]);
        }
    printf("%lld\n", dp[n][k]);
	return 0;
}

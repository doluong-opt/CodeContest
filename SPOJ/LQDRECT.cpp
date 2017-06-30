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
#define N 1111

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

int a[N][N], f[N][N], Left[N], n, m;
int64 ans, dp[N];

int64 calc(int u) {
    f[u][0] = -1;
    fill(Left, 0);
    for (int i = 1;i <= n;i++) {
        Left[i] = i - 1;
        while (f[u][i] <= f[u][Left[i]]) Left[i] = Left[ Left[i] ];
    }
    int64 res = 0LL;
    dp[0] = 0;
    for (int i = 1;i <= n;i++) {
        dp[i] = f[u][i] * (i - Left[i]) + dp[Left[i]];
        res += dp[i];
    }
    return res;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d", &m, &n);
	fr(i, 1, m) fr(j, 1, n) scanf("%d", &a[i][j]);
	fill(f, 0);
	fr(i, 1, n)
        fr(j, 1, m)
            if (a[j][i]) f[j][i] = f[j - 1][i] + 1;
    ans = 0LL;
    fr(i, 1, m)
        ans += calc(i);
    printf("%lld\n", ans);
	return 0;
}

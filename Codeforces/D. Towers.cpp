// =============================================================================
// Author LUONG VAN DO
// Problem D. Towers
// Algorithm
// Time Limit
// =============================================================================
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
#define N 5010

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int dp[N][N], g[N][N], sum[N], a[N], n;

int f(int x, int y) {
    return (sum[y] - sum[x - 1]);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int lo, hi, k, i, j, res;
    scanf("%d", &n);
    sum[0] = 0; res = n - 1;
    for (i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
        for (int  j = 1; j <= n;j++) g[i][j] = -1;
    }
    for (i = 1;i <= n;i++) dp[1][i] = (i - 1);
    g[1][1] = dp[1][1];
    for (i = 2;i <= n;i++) {
        for (j = i;j <= n;j++) {
            lo = 1; dp[i][j] = INF;
            hi = i - 1; k = -1;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (f(mid, i - 1) <= f(i, j)) {
                    k = mid;
                    hi = mid - 1;
                }
                else lo = mid + 1;
            }
            if (k != -1 && g[k][i - 1] == -1) k = -1;
            if (k == -1) dp[i][j] = -1;
            else {
                dp[i][j] = g[k][i - 1] + (j - i);
                if (j == n) res = min(res, dp[i][j]);
            }
        }
        g[i][i] = dp[i][i];
        for (j = i - 1;j >= 1;j--) {
            g[j][i] = g[j + 1][i];
            if (g[j + 1][i] == -1) g[j][i] = dp[j][i];
            else if (dp[j][i] != -1) g[j][i] = min(g[j][i], dp[j][i]);
        }
    }
    printf("%d\n", res);
    return 0;
}

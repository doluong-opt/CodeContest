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
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i = b;i >= a;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define pb push_back
#define ff first
#define ss second
#define fill(arr, val) memset(arr, val, sizeof(arr))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 50000000000000LL
#define N 77

using namespace std;

inline int64 max(int64 a, int64 b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int64 dp[N][N][8], a[N][N], ans;
int64 lf[8][N], rt[8][N];
int n, k;
void goLeft(int row) {
    for (int i = 0;i <= k;i++)
        for (int j = 1;j <= n;j++)
            lf[i][j] = dp[row][j][i];
            
    for (int t = 0;t <= k;t++)
        for (int j = 1;j < n;j++) {
            if (lf[t][j] == -INF) continue;
            if ( a[row][j + 1] >= 0 )
                lf[t][j + 1] = max(lf[t][j + 1], lf[t][j] + a[row][j + 1]);
            else
                lf[t + 1][j + 1] = max(lf[t + 1][j + 1], lf[t][j] + a[row][j + 1]);
        }
}
void goRight(int row) {
    for (int i = 0;i <= k;i++)
        for (int j = 1;j <= n;j++)
            rt[i][j] = dp[row][j][i];
            
    for (int t = 0;t <= k;t++)
        for (int j = n;j > 1;j--) {
            if (rt[t][j] == -INF) continue;
            if ( a[row][j - 1] >= 0 )
                rt[t][j - 1] = max(rt[t][j - 1], rt[t][j] + a[row][j - 1]);
            else
                rt[t + 1][j - 1] = max(rt[t + 1][j - 1], rt[t][j] + a[row][j - 1]);
        }
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int caseNo = 0;
	while ( scanf("%d %d", &n, &k) && (n + k)) {
	    fr(i, 1, n) fr(j, 1, n) scanf("%lld", &a[i][j]);
	    fr(i, 1, n) fr(j, 1, n) fr(t, 0, k) dp[i][j][t] = -INF;
	    if (a[1][1] < 0) dp[1][1][1] = a[1][1];
	    else dp[1][1][0] = a[1][1];
	    
        fr(i, 0, k) fr(j, 1, n - 1)
            if (dp[1][j][i] != -INF) {
                if ( a[1][j + 1] >= 0 )
                    dp[1][j + 1][i] = max(dp[1][j + 1][i], dp[1][j][i] + a[1][j + 1]);
                else
                    dp[1][j + 1][i + 1] = max(dp[1][j + 1][i + 1], dp[1][j][i] + a[1][j + 1]);
            }
        for (int i = 2;i <= n;i++) {
            for (int t = 0;t <= k;t++)
                for (int j = 1;j <= n;j++)
                    if ( dp[i - 1][j][t] != -INF )
                        if ( a[i][j] >= 0 )
                            dp[i][j][t] = max(dp[i][j][t], dp[i - 1][j][t] + a[i][j]);
                        else
                            dp[i][j][t + 1] = max(dp[i][j][t + 1], dp[i - 1][j][t] + a[i][j]);
            
            goLeft(i); goRight(i);
            for (int t = 0;t <= k;t++)
                for (int j = 1;j <= n;j++)
                    dp[i][j][t] = (lf[t][j] > rt[t][j] ? lf[t][j] : rt[t][j]);
        }
        ans = -INF;
        fr(i, 0, k) if (ans < dp[n][n][i]) ans = dp[n][n][i];
        if ( ans != -INF ) printf("Case %d: %lld\n", ++caseNo, ans);
        else printf("Case %d: impossible\n", ++caseNo);
	}
	return 0;
}

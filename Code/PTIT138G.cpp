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
#define N 41
#define MAX_LOG 20
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
int n, t[N], total, ans;
int dp[N][N * 30][ N * 30];
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
       while ( scanf("%d", &n) && n) {
              total = 0;
              for (int i = 1;i <= n;i++) {
                     scanf("%d", &t[i]);
                     total += t[i];
              }
              for (int i = 0;i <= n;i++) for (int j = 0;j <= total;j++) for (int k = 0;k <= total;k++) dp[i][j][k] = 0;
              dp[0][0][0] = 1;
              for (int i = 1;i <= n;i++)
                     for (int j = 0;j <= total;j++)
                            for (int k = 0;k <= total;k++) {
                                   if (k >= t[i] && dp[i - 1][j][k - t[i]] == 1) dp[i][j][k] = 1;
                                   if (j >= t[i] && dp[i - 1][j - t[i]][k] == 1) dp[i][j][k] = 1;
                                   if (dp[i - 1][j][k] == 1) dp[i][j][k] = 1;
                            }
              ans = INF;
              for (int i = 0;i <= total;i++) for (int j = 0;j <= total;j++)
                     if ( dp[n][i][j] == 1 ) ans = min(ans, max(max(i, j), total - i - j));
              printf("%d\n", ans);
       }
	return 0;
}

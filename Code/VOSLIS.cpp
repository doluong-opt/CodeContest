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
#define N 5555
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
int n, m;
int a[N], b[N];
int64 dp[N], f, maxj, ans;
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
       scanf("%d %d", &n, &m);
       for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
       for (int i = 1;i <= m;i++) scanf("%d",&b[i]);
       for (int i = 1;i <= n;i++) {
              f = 0;
              for (int j = 1;j <= m;j++) {
                     maxj = f;
                     f = max(f, dp[j] + abs(a[i] - b[j]));
                     if (a[i] == b[j]) dp[j] = max(dp[j], maxj);
              }
       }
       ans = 0;
       for (int i = 1;i <= m;i++) ans = max(ans, dp[i]);
       printf("%lld\n", ans);
	return 0;
}

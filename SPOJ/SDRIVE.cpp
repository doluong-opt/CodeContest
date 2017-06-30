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
#define PI 3.141592654
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 10111

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline double min(double a, double b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, m;
int l[N], s[N];
double ans, dp[N][22];
double calc(int i, int j, int k) {
    double dx = abs(j - k) * 10;
    double dy = s[i];
    return sqrt(dx * dx + dy * dy);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d", &n, &m);
	fr(i, 1, n) scanf("%d", &l[i]);
	fr(i, 1, n) scanf("%d", &s[i]);
	ans = INF * 1.0;
	fr(i, 1, n) fr(j, 1, m) dp[i][j] = INF * 1.0;
	fr(i, 1, m) dp[0][i] = 0.0;
	fr(i, 1, n) {
	    if (l[i] == 0) {
	        fr(j, 1, m)
                fr(k, 1, m)
                    if ( 100 * abs(j - k) <= s[i] )
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + calc(i, j, k));
	    }
	    if (l[i] == 1) {
	        fr(j, 1, m)
                dp[i][j] = dp[i - 1][j] + 0.5 * PI * (s[i] + j * 10 - 5);
	    }
	    if (l[i] == 2) {
	        fr(j, 1, m)
                dp[i][j] = dp[i - 1][j] + 0.5 * PI * (s[i] + (m - j + 1) * 10 - 5);
	    }
	}
	//fr(i, 1, m) cout<<dp[n][i]<<" ";
	//cout<<endl;
	fr(i, 1, m)
        if (ans > dp[n][i]) ans = dp[n][i];
    printf("%.2lf\n", ans);
	return 0;
}

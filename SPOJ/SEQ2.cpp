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
#define N 310

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
int n, ans;
int a[N], dp[N][N];
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	freopen("SEQ2.INP","r", stdin);
	freopen("SEQ2.OUT","w", stdout);
	scanf("%d", &n);
	fr(i, 1, n) scanf("%d", &a[i]);
	ans = 0;
	fr(k, 1, n) {
	    fill(dp, 0);
	    for (int i = 1;i <= k;i++)
            for (int j = n;j>= i + 1;j--)
                if (a[i] < a[j]) dp[i][j] = dp[i - 1][j + 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j + 1]);
        
        for (int i = 1;i <= k;i++)
            for (int j = n;j >= i + 1;j--)
                ans = max(ans, dp[i][j]);
	}
	printf("%d\n", ans);
	return 0;
}

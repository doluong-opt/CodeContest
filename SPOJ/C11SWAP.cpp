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
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1010

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
#define M 1000000007

int64 c[N][N], dp[N][N];
int a[N], b[N], mark[N], n;
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n);
	for (int i = 0;i <= 100;i++) c[i][0] = 1;
	for (int i = 1;i <= 100;i++)
        for (int j = 1;j <= i;j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]);
            c[i][j] %= M;
        }
        
	for (int i = 0;i < n;i++) scanf("%d", &a[i]);
	
	for (int i = n - 1;i >= 0;i--) for (int j = i;j < n;j++) {
	    if (i == j) dp[i][j] = 1LL;
	    else {
	        dp[i][j] = 0LL;
	        for (int k = i;k <= j;k++) b[k] = a[k];
	        sort(b + i, b + j + 1);
	        for (int k = i;k < j;k++) {
	            for (int l = 0;l < n;l++) mark[l] = 0;
	            
	            for (int l = i;l < k;l++) mark[b[l]] = 1;
	            mark[b[k + 1]] = 1; int flag = 1;
	            for (int l = i;l <= k;l++)
                    if (!mark[a[l]]) {
                        flag = 0;
                        break;
                    }
                if (flag) {
                    int64 f = (dp[i][k] * dp[k + 1][j]) % M;
                    f = (f * c[j - i - 1][k - i]) % M;
                    dp[i][j] += f; dp[i][j] %= M;
                }
	        }
	    }
	}
	printf("%lld\n", dp[0][n - 1]);
}

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
#define N 1001

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
int m, n;
int c[N][N];
int dp[N][N][2];
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
	scanf("%d", &cases);
	while (cases--) {
        scanf("%d %d", &m, &n);
        fr(i, 1, m) fr(j, 1, n) {
            scanf("%d", &c[i][j]);
            dp[i][j][0] = dp[i][j][1] = INF;       
        }
        fr(i, 1, n) {
            dp[0][i][0] = INF;
            dp[0][i][1] = 0;
        }
        fr(i, 1, m) {
            dp[i][0][0] = 0;
            dp[i][0][1] = INF;
        }
        fr(len, 2, m + n) {
            fr(i, 1, m) {
                int j = len - i;
                if (j >= 1 && j <= n) dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + c[i][j]);
                if (j >= 1 && j <= n) dp[i][j][1] = min(dp[i][j - 1][1], dp[i][j - 1][0] + c[i][j]);
            }
        }
        printf("%d\n", min(dp[m][n][0], dp[m][n][1]));
	}
	return 0;
}

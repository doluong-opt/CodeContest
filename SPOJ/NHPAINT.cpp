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
#define N 17
#define M 10100
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
int a[N][N], ans, lim;
char s[M][N];
int dp[1<<N][N], n, m;
int f(int x, int y) {
    int cnt = 0;
    for (int i = 0;i < m;i++)
        if (s[i][x] != s[i][y]) cnt++;
    return cnt;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf(" %d %d ", &m, &n);
	rep(i, m) gets(s[i]);
	for (int i = 0;i < n;i++) {
	    int cnt = 0;
        for (int j = 0;j < m;j++)
            if ( s[j][i] == '1' ) cnt++;
        a[i][i] = cnt;
	}
	for (int i = 0;i < n - 1;i++)
        for (int j = i + 1;j < n;j++) {
            int cnt = f(i, j);
            a[i][j] = a[j][i] = cnt;
            if (j == i - 1 || j == i + 1)
                a[i][j] = min(cnt, a[j][j]);
            if (i == j - 1 || i == j + 1)
                a[j][i] = min(cnt, a[i][i]);
        }
    lim = (1<<n);
    rep(i, lim) rep(j, n) dp[i][j] = INF;
    rep(i, n) dp[(1<<i)][i] = a[i][i];
    for (int mask = 0;mask < lim;mask++) {
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                if ( !And(mask, j) )
                    dp[Or(mask, j)][j] = min(dp[Or(mask, j)][j], dp[mask][i] + a[i][j]);                
    }
    ans = INF;
    rep(i, n) ans = min(ans, dp[lim - 1][i]);
    printf("%d\n", ans);
	return 0;
}

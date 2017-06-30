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
#define N 100111
#define mod 2370823708
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
int64 m, n, k;
int64 c[8][8], f[8], ans;
int64 power(int64 x, int64 y) {
    int64 res = 1LL;
    while ( y ) {
        if (y & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res % mod;
}
int64 solve(int64 x) {
    int64 total = power(x, n), tempA;
    int sign = 0; total %= mod;
    for (int i = x - 1;i >= 1;i--) {
        tempA = c[x][i] * power(i, n); tempA %= mod;
        if ( !sign ) total -= tempA;
        else total += tempA;
        sign ^= 1;
        if (total < 0) total += mod;
        total %= mod;
    }
    return total % mod;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	c[0][0] = 1;
	fr(i, 1, 8) {
	    c[i][0] = 1;
        fr(j, 1, i)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
	while ( scanf("%lld %lld %lld", &m, &n, &k) != EOF ) {
        if (n < k) {
            puts("0");
            continue;
        }
        ans = 0LL;
        fr(i, 1, 7) {
            f[i] = solve(i) * c[7][i];
            f[i] %= mod;
        }
        fr(i, k, 7) {
            ans += f[i];
            ans %= mod;
        }
        ans = power(ans, m) % mod;
        printf("%lld\n", ans);
	}
	return 0;
}

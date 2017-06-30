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
#define uint32 unsigned int
#define INF 1000000000
#define N 150
#define S 555
#define base 1000000000
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
int64 res[N];
struct bigint {
    vector <int64> digits;
    bigint(){}
    void add(int64 x) {
        digits.pb(x);
    }
    void output() {
        int n = digits.size();
        while (n > 1 && digits[n - 1] == 0) n--;
        printf("%lld", digits[--n]);
        repr(i, n) printf("%09lld", digits[i]);
        puts("");
    }
    void operator += (const bigint &b) {
        int64 carry = 0;
        for (int i = 0;i < digits.size() || i < b.digits.size() || carry;i++) {
            int64 x = carry;
            if (i < digits.size()) x += digits[i];
            if (i < b.digits.size()) x += b.digits[i];
            carry = (x >= base);
            if ( carry ) x -= base;
            if (i < digits.size()) digits[i] = x;
            else digits.pb(x);
        }
    }
    void operator *= (const bigint &b) {
        int n = digits.size(), m = b.digits.size();
        int64 x;
        for (int i = 0;i < n + m;i++) res[i] = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++) {
                x = digits[i] * b.digits[j];
                res[i + j] += (x % base);
                res[i + j + 1] += (res[i + j] / base);
                res[i + j] %= base;
                res[i + j + 1] += (x / base);
            }
        for (int i = 0;i < n + m;i++)
            if (res[i] >= base) {
                res[i + 1] += (res[i] / base);
                res[i] %= base;
            }
        digits.clear();
        for (int i = 0;i < n + m;i++) digits.pb(res[i]);
    }
};
int n, s;
bigint dp[N][S];
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while ( scanf("%d %d", &n, &s) != EOF) {
	    if (s & 1) {
	        puts("0");
	        continue;
	    }
	    s >>= 1;
	    dp[0][0].add(1LL);
	    for (int i = 1;i <= n;i++)
            for (int j = 0;j <= s;j++) {
                dp[i][j].add(0LL);
                for (int k = 0;k <= 9;k++)
                    if (j >= k) dp[i][j] += dp[i - 1][j - k];
            }
        dp[n][s] *= dp[n][s];
        dp[n][s].output();
	}
	return 0;
}

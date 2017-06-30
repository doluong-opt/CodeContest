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
#define N 100100

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
int64 phi[8], p[8];
int64 val, mu;
int64 power(int64 x, int64 y, int64 md) {
    int64 res = 1;
    while (y) {
        if (y & 1) res = (res * x) % md;
        x = (x * x) % md;
        y >>= 1;
    }
    return res;
}
int64 b, k, n, ans, len;
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	phi[1] = 4; p[0] = 1; p[1] = 10;
	fr(i, 2, 7) {
	    phi[i] = phi[i - 1] * 10;
	    p[i] = p[i - 1] * 10;
	}
	while ( scanf("%lld", &b) ) {
	    if (b == 0) break;
        scanf("%lld %lld", &k, &n);
        mu = 1;
        fr(i, 2, k) {
            val = power(b, mu, phi[n]);
            mu = val;
            if (val == 0) mu = phi[n];
            else mu = val;
        }
        ans = power(b, mu, p[n]);
        if (ans != 0) len = (int)log10(ans) + 1;
        else len = 1;
        rep(i, n - len) printf("0");
        printf("%lld\n", ans);
	}
	return 0;
}

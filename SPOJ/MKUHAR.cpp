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
#define N 111

using namespace std;

inline int64 max(int64 a, int64 b) { return a > b ? a : b; }
inline int64 min(int64 a, int64 b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int64 x[N], y[N], sm[N], pm[N], sv[N], pv[N];
int64 lo, hi, ans, m, n;
bool check(int64 k) {
    int64 temp, money = m, moneyI;
    int64 i2;
    for (int i = 1;i <= n;i++) {
        moneyI = INF;
        for (int i1 = 0;i1 <= 10000;i1++) {
            temp = (k * x[i] - y[i] - sm[i] * i1);
            if (temp < 0) i2 = 0;
            else 
            if (temp % sv[i] == 0) i2 = temp / sv[i];
            else i2 = (temp / sv[i]) + 1;
            moneyI = min(moneyI, i1 * pm[i] + i2 * pv[i]);
        }
        money -= moneyI;
        if (money < 0) return false;
    }
    return true;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%lld %lld", &n, &m);
	fr(i, 1, n) scanf("%lld %lld %lld %lld %lld %lld", &x[i], &y[i], &sm[i], &pm[i], &sv[i], &pv[i]);
	lo = 0; hi = 1000000000000LL;
	while (lo <= hi) {
	    int mid = (lo + hi) >> 1;
	    if ( check( mid ) ) {
	        ans = mid;
	        lo = mid + 1;
	    }
	    else hi = mid - 1;
	}
	printf("%lld\n", ans);
	return 0;
}

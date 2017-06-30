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
#define INF 500000000000000LL
#define N 100111

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int64 gcd(int64 a, int64 b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int64 a, b, c, d, u, x, y, p, q;
void solve(int64 a, int64 b, int64 c, int64 d) {
    x = y = 1LL;
    int64 k1, k2;
    while ( true ) {
        k1 = k2 = INF;
        if (a >= b && c >= d) {
            if (b > 0) k1 = a / b;
            if (d > 0) k2 = c / d;
            if (k1 > k2) k1 = k2;
            a -= k1 * b;
            c -= k1 * d;
        }
        else 
        if (a <= b && c <= d) {
            swap(a, b);
            swap(c, d);
        }
        else break;
    }
    x = abs(c - d);
    y = abs(a - b);
    x = max(x, 1);
    y = max(y, 1);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while ( scanf("%lld %lld %lld %lld", &a, &b, &c, &d) != EOF) {
	    u = gcd(a, b); a /= u; b /= u;
	    u = gcd(c, d); c /= u; d /= u;
        solve(a, b, c, d);
        p = a * x + c * y;
        q = b * x + d * y;
        u = gcd(p, q);
        printf("%lld/%lld\n", p / u, q / u);
	}
	return 0;
}

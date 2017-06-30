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
int cases;
int64 ans, n, a, b, d;
void euclid(int64 a, int64 b, int64 &x, int64 &y) {
    if (b == 0) {
        x = 1; y = 0; d = a;
        return;
    }
    euclid(b, a % b, x, y);
    int64 x1 = y;
    int64 y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}
int64 power(int64 x, int64 y, int64 md) {
    int64 res = 1LL;
    while (y) {
        if (y & 1) res = (res * x) % md;
        y >>= 1;
        x = (x * x) % md;
    }
    return res;
}
int64 legendre(int64 a, int64 n) {
    return power(a, (n - 1) >> 1, n);
}
int64 inverse(int64 a, int64 n) {
    int64 x, y;
    euclid(a, n, x, y);
    while (x < 0) x += n;
    return x % n;
}
int64 solve(int64 a, int64 n) {
    if (n == 2 || a == 1) return 1;
    if (n == 1) return 0;
    int64 l, t, s, b, rev;
    l = legendre(a, n);
    if (l > 1) return -1;
    //n - 1 = (2 ^ t) * s;
    t = 0; s = n - 1;
    while (s % 2 == 0) t++, s /= 2;
    do{
        b = 1 + (rand() % (n - 1));
    }while (legendre(b, n) <= 0);
    rev = inverse(a, n);
    
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%lld %lld", &a, &n);
	    a %= n;
	    ans = solve(a, n);
	    if (ans == -1) puts("Khong co");
	    else
	    if (ans != n - ans) printf("%lld %lld\n", ans, n - ans);
	    else printf("%lld\n", ans);
	}
	return 0;
}

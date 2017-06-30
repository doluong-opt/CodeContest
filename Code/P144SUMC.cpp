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
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1000111
#define md 1000000007
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
int a, b, n;
int64 ans, f[N];
int64 power(int64 x, int y) {
    int64 res = 1;
    while (y) {
        if (y & 1) res = (res * x) % md;
        x = (x * x) % md;
        y >>= 1;
    }
    return res;
}
int64 solve(int x) {
    int64 res = f[n];
    int64 add = (f[x] * f[n - x]) % md;
    res = res * power(add, md - 2);
    res %= md;
    return res;
}
bool isOk(int sum) {
    while (sum) {
        int x = sum % 10;
        if (x != a && x != b) return false;
        sum /= 10;
    }
    return true;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d %d", &a, &b, &n);
	ans = 0; f[0] = 1;
	for (int i = 1;i <= n;i++) {
	    f[i] = (f[i - 1] * i);
	    f[i] %= md;
	}
	for (int i = 0;i <= n;i++)
	    if (isOk(a * i + b * (n - i))) {
            ans += solve(i);
            ans %= md;
	    }
    printf("%lld\n", ans);
	return 0;
}

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
int n, k, neg, existPos, existNeg, zero1, zero2;
int64 a[N], res, r1, r2;
bool cmp(int64 x, int64 y) {
    if (abs(x) != abs(y)) return abs(x) > abs(y);
    if (x * y < 0) return x > y;
    return x >= y;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while ( scanf("%d %d", &n, &k) && (n + k)) {
	    fr(i, 1, n) scanf("%lld", &a[i]);
	    sort(a + 1, a + n + 1, cmp); neg = res = 0;
	    fr(i, 1, k) {
	        res += a[i];
	        if (a[i] < 0) neg++;
	    }
	    if (neg % 2 == 0 || n == k) {
	        printf("%lld\n", res);
	        continue;
	    }
	    r1 = res; r2 = res; existNeg = existPos = zero1 = zero2 = 0;
	    for (int i = k;i >= 1;i--)
            if (a[i] < 0) {
                r1 -= a[i];
                break;
            }
        for (int i = k + 1;i <= n;i++)
            if (a[i] >= 0) {
                existPos = 1;
                r1 += a[i];
                if (a[i] == 0) zero1 = 1;
                break;
            }
        for (int i = k;i >= 1;i--)
            if (a[i] > 0) {
                r2 -= a[i];
                break;
            }
        for (int i = k + 1;i <= n;i++)
            if (a[i] <= 0) {
                r2 += a[i];
                existNeg = 1;
                if (a[i] == 0) zero2 = 1;
                break;
            }
        if (existNeg && existPos) {
            //cout << zero1<<" "<<zero2<<endl;
            if (zero1 && zero2) printf("%lld\n", max(r1, r2));
            else
            if (!zero1 && zero2) printf("%lld\n", r1);
            else
            if (zero1 && !zero2) printf("%lld\n", r2);
            else printf("%lld\n", res);
        }
        else 
        if (existNeg) printf("%lld\n", r2);
        else 
        if (existPos) printf("%lld\n", r1);
        else printf("%lld\n", res);
	}
	return 0;
}

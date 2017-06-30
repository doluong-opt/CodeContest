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
#define N 70

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
int64 f[N], power[N], n, lo, hi, pos, ans;
int64 a, maxMid, b, cases;
inline int64 calc(int64 l, int64 r, int64 x, int64 y) {
    while (l + 1 < r) {
        int64 mid = (l + r) >> 1;
        int64 valMid = (x + y);
        if ( x + valMid > y + valMid) {
            y = valMid;
            r = mid;
        }
        else {
            x = valMid;
            l = mid;
        }
    }
    return max(x, y);
}
inline int64 nextint(int64 &res) {
    bool sign = false; res = 0;
    char c;
    do { c = getchar(); } while ((c < '0' || c > '9') && (c != '-'));
    if ( c == '-' ) sign = true, c = getchar();
    do {
        res = res * 10 + c - '0'; c = getchar();
    }while (c >= '0' && c <= '9');
    if (sign) res = -res;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	f[0] = 1; f[1] = 1; f[2] = 2; power[0] = 1; power[1] = 2; power[2] = 4;
    for (int i = 3;i <= 60;i++) {
        f[i] = f[i - 1] + f[i - 2];
        power[i] = power[i - 1] * 2;
    }
	nextint(cases);
	rep(i, cases) {
	    nextint(n);
	    lo = 0; hi = 60;
	    while (lo <= hi) {
	        int mid = (lo + hi) >> 1;
	        if ( power[mid] <= n ) {
	            pos = mid;
	            lo = mid + 1;
	        }
	        else hi = mid - 1;
	    }
	    ans = f[pos];
	    if (power[pos] == n) {
	        printf("%lld\n", ans);
	        continue;
	    }
	    lo = power[pos]; hi = power[pos + 1]; a = 1; maxMid = 2; b = 1;
	    while (lo + 1 < hi) {
	        int64 mid = (lo + hi) >> 1;
	        if (mid > n) {
	            b = maxMid;
	            maxMid = a + maxMid;
	            hi = mid;
	        }
	        else {
	            ans = max(ans, calc(lo, mid, a, maxMid));
	            a = maxMid;
	            maxMid = b + maxMid;
	            lo = mid;
	        }
	    }
	    printf("%lld\n", ans);
	}	
}

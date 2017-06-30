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
#define N 555

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
int m, n, q, l, r, c1, r2, c2, lo, hi;
int a[N][N], xMin, xMax, ans;
inline bool isInside(int u, int v) {
    return (u >= 1 && v >= 1 && u <= m && v <= n);
}
inline void nextint(int &num) {
    char c; num = 0;
    do { c = getchar(); } while (c < '0' || c > '9');
    do { num = num * 10 + c - '0'; c = getchar();
    }while (c >= '0' && c <= '9');
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while ( true ) {
	    nextint(m); nextint(n);
	    if (m + n == 0) break;
	    xMin = INF; xMax = -INF;
	    fr(i, 1, m) fr(j, 1, n) {
	        nextint(a[i][j]);
	        xMin = min(xMin, a[i][j]);
	        xMax = max(xMax, a[i][j]);
	    }
	    nextint(q);
	    fr(i, 1, q) {
	        nextint(l); nextint(r); ans = 0;
	        if (l <= xMin && xMax <= r) {
	            printf("%d\n", min(m, n));
	            continue;
	        }
	        for (int r1 = 1;r1 <= m;r1++) {
	            lo = 1; hi = n;
	            while (lo <= hi) {
	                int mid = (lo + hi) >> 1;
	                if ( a[r1][mid] >= l ) hi = mid - 1;
	                else lo = mid + 1;
	            }
	            c1 = lo;
	            if (!isInside(r1, c1) || a[r1][c1] < l || a[r1][c1] > r) continue;
	            lo = 0; hi = min(m - r1, n - c1);
	            while (lo <= hi) {
	                int mid = (lo + hi) >> 1;
	                if ( a[r1 + mid][c1 + mid] <= r ) lo = mid + 1;
	                else hi = mid - 1;
	            }
	            r2 = r1 + hi; c2 = c1 + hi;
	            if (!isInside(r2, c2) || a[r2][c2] < l || a[r2][c2] > r) continue;
	            ans = max(ans, r2 - r1 + 1);
	        }
	        printf("%d\n", ans);
	    }
	    puts("-");
	}
	return 0;
}

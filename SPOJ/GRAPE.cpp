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
int m, n, q, lo, hi, L, R;
int c1, c2, r2, xMin, xMax;
int a[N][N], ans;
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d %d", &m, &n, &q);
	xMin = INF; xMax = -INF;
	fr(i, 1, m) fr(j, 1, n) {
	    scanf("%d", &a[i][j]);
	    xMin = min(a[i][j], xMin);
	    xMax = max(a[i][j], xMax);
	}
	rep(i, q) {
	    scanf("%d %d", &L, &R); ans = 0;
	    if (L <= xMin && xMax <= R) {
	        printf("%d\n", min(n, m) * min(n, m));
	        continue;
	    }
	    fr(r1, 1, m) {
	        lo = 1; hi = n; int mid;
	        while (lo <= hi) {
	            mid = (lo + hi) >> 1;
	            if (a[r1][mid] >= L) lo = mid + 1;
	            else hi = mid - 1;
	        }
	        c2 = hi;
	        //while (c2 < n && a[r1][c2 + 1] >= L) c2++;
	        //while (c2 > 1 && a[r1][c2 - 1] < L) c2--;
	        if (a[r1][c2] < L || a[r1][c2] > R) continue;
	        lo = 0; hi = min(m - r1, c2 - 1);
	        while (lo <= hi) {
	            mid = (lo + hi) >> 1;
	            if (a[r1 + mid][c2 - mid] <= R) lo = mid + 1;
	            else hi = mid - 1;
	        }
	        r2 = r1 + hi; c1 = c2 - hi;
	        //while (r2 < m && c1 > 1 && a[r2 + 1][c1 - 1] <= R) r2++, c1--;
	        //while (r2 > 1 && c1 < n && a[r2 - 1][c1 + 1] > R) r2--, c1++;
	        if (a[r2][c1] < L || a[r2][c1] > R) continue;
	        ans = max(ans, r2 - r1 + 1);
	    }
        printf("%d\n", ans * ans);
	}
	return 0;
}

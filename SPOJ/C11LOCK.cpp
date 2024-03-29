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
#define INF 1000000000
#define N 555
#define M 250111
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
int a[6][N], n, k, m, lo, hi, tA, tB;
int sumA[M], sumB[M];
int64 res, lA, lB;
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d", &n, &k);
	fr(i, 1, 5) fr(j, 1, n) scanf("%d", &a[i][j]); m = 0;
	fr(i, 1, n) fr(j, 1, n) {
	    sumA[m] = a[1][i] + a[2][j];
	    sumB[m] = a[3][i] + a[4][j];
	    m++;
	}
	sort(sumA, sumA + m); sort(sumB, sumB + m);
	res = 0LL;
	for (int i = 1;i <= n;i++) {
	    int x = k - a[5][i];
	    lo = 0; hi = m - 1;
        while (lo <= m - 1 && hi >= 0) {
            if ( sumA[lo] + sumB[hi] == x ) {
                lA = lo; lB = hi;
                while (lA + 1 <= m - 1 && sumA[lA + 1] == sumA[lA]) lA++;
                while (lB - 1 >= 0 && sumB[lB - 1] == sumB[lB]) lB--;
                tA = lA; tB = lB;
                lA = lA - lo + 1; lB = hi - lB + 1;
                if (lA >= 0 && lB >= 0) res += lA * lB;
                lo = tA + 1; hi = tB - 1;
            }
            else
            if ( sumA[lo] + sumB[hi] > x ) hi--;
            else
            if ( sumA[lo] + sumB[hi] < x ) lo++;
        }
	}
	printf("%lld\n", res);
	return 0;
}

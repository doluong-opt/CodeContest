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
#define N 111

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
int n, ans, a[N][N], total[N][N];
int getSum(int x1, int y1, int x2, int y2) {
    return total[x2][y2] - total[x1 - 1][y2] - total[x2][y1 - 1] + total[x1 - 1][y1 - 1];
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while ( scanf("%d", &n) != EOF) {
	    fr(i, 1, n) fr(j, 1, n) scanf("%d", &a[i][j]);
	    fr(i, 0, n) fr(j, 0, n) total[i][j] = 0;
	    fr(i, 1, n) total[1][i] = total[1][i - 1] + a[1][i];
	    fr(i, 2, n) {
	        fr(j, 1, n) total[i][j] = total[i][j - 1] + a[i][j];
	        fr(j, 1, n) total[i][j] += total[i - 1][j];
	    }
	    ans = -INF;
	    fr(i1, 1, n) fr(i2, 1, n)
            fr(i3, i1, n) fr(i4, i2, n)
                ans = max(ans, getSum(i1, i2, i3, i4));
        printf("%d\n", ans);
	}
	return 0;
}

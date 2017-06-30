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
#define N 500

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
int n, a[N][N];
int ans;
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n);
	rep(i, n) rep(j, n) scanf("%d", &a[i][j]);
	ans = 0;
	rep(i, n) rep(j, n) {
	    int x = a[i][j];
	    int y = a[i][j];
	    for (int len = 1;;len++) {
	        if (i - len < 0 || i + len >= n || j - len < 0 || j + len >= n) break;
	        x += a[i - len][j - len] + a[i + len][j + len];
	        y += a[i + len][j - len] + a[i - len][j + len];
	        ans = max(ans, x - y);
	    }
	}
	rep(i, n - 1) rep(j, n - 1) {
	    int x = 0;
	    int y = 0;
	    int r1 = i, r2 = i + 1;
	    int c1 = j, c2 = j + 1;
	    for (int len = 1;;len++) {
	        x += a[r1][c1] + a[r2][c2];
	        y += a[r2][c1] + a[r1][c2];
	        ans = max(ans, x - y);
	        r1--; c1--; r2++; c2++;
	        if (r1 < 0 || c1 < 0 || r2 >= n || c2 >= n) break;
	    }
	}
	printf("%d\n", ans);
	return 0;
}

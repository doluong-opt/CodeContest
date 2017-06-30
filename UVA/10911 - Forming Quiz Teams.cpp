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
string name[17];
int x[17], y[17];
double dp[1 << 16], cost[17][17];
int n, lim;
double dist(int a1, int b1, int a2, int b2) {
    double dx = a1 - a2;
    double dy = b1 - b2;
    return sqrt(dx * dx + dy * dy);
}
double solve(int mask) {
    if (mask == lim - 1) return 0.0;
    double &res = dp[mask];
    if (res != -1.0) return res;
    res = INF;
    for (int i = 0;i < 2 * n;i++)
        if ( !And(mask, i) )
            for (int j = 0;j < 2 * n;j++)
                if (i != j && !And(mask, j))
                    res = min(res, solve(Or(Or(mask, i), j)) + cost[i][j]);
    return res;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int caseNo = 0;
	while ( scanf("%d", &n) && n) {
	    rep(i, 2 * n) cin >> name[i] >> x[i] >> y[i];
	    rep(i, 2 * n)
            rep(j, 2 * n) cost[i][j] = dist(x[i], y[i], x[j], y[j]);
        lim = (1 << (2 * n));
        rep(i, lim) dp[i] = -1.0;
        printf("Case %d: %.2lf\n", ++caseNo, solve(0));
	}
	return 0;
}

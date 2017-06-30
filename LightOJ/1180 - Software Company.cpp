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
int n, m, x[N], y[N];
int dp[N][N][N];
int ans, l, r;
int run(int cur, int sub1, int sub2, int curTime) {
    if (cur >= n + 1) {
        if (sub1 <= 0 && sub2 <= 0) return 1;
        return 0;
    }
    int &res = dp[cur][sub1][sub2];
    if (res != -1) return res;
    res = 0;
    for (int i = 0;i <= m;i++) {
        int nextSub1 = sub1 - i;
        int nextTime1 = x[cur] * i;
        if (curTime >= nextTime1) {
            int nextSub2 = sub2 - ((curTime - nextTime1) / y[cur]);
            res |= run(cur + 1, max(nextSub1, 0), max(nextSub2, 0), curTime);
        }
    }
    return res;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d %d", &n, &m);
	    fr(i, 1, n) scanf("%d %d", &x[i], &y[i]);
        l = 0; r = 50000;
        while (l <= r) {
            int mid = (l + r) >> 1;
            fill(dp, -1);
            if ( run(1, m, m, mid) ) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        printf("Case %d: %d\n", ++caseno, ans);
	}
	return 0;
}

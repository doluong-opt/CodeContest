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

inline int64 max(int64 a, int64 b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int64 n, l, u, ans, res, x;
int64 dp[33][2][2];
int64 solve(int cur, int x, int y) {
    if (cur < 0) return 0LL;
    int64 &res = dp[cur][x][y];
    if ( res != -1 ) return res;
    res = 0;
    int xx, yy;
    rep(i, 2) {
        xx = x; yy = y;
        if (!xx) {
            int k = ((l >> cur) & 1LL);
            if (i < k) continue;
            if (i > k) xx = 1;
        }
        if (!yy) {
            int k = ((u >> cur) & 1LL);
            if (i > k) continue;
            if (i < k) yy = 1;
        }
        int64 v = i ? (1LL << cur) : 0LL;
        res = max(res, n | (v | solve(cur - 1, xx, yy)));
    }
    return res;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while ( scanf("%lld %lld %lld", &n, &l, &u) != EOF ) {	    
	    fill(dp, -1);
	    res = solve(32, 0, 0); ans = 0;
	    for (int i = 31;i >= 0;i--) {
	        if (!And(n, i) && And(res, i)) ans |= (1LL << i);
	        else if ((ans | (1LL << i)) <= l) ans |= (1LL << i);
	    }
	    printf("%lld\n", ans);
	}
	return 0;
}

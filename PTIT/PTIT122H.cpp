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
int64 a, b;
int x, m;
int digit[65];
int64 dp[65][65][2];
int countBit(int n) {
    int cnt = 0, temp;
    while (n != 1) {
        cnt++; temp = 0;
        while ( n ) {
            if (n & 1) temp++;
            n >>= 1;
        }
        n = temp;
    }
    return cnt;
}
int64 run(int at, int cost, int s) {
    if (at == m) {
        if (cost == 0) return 0;
        return (countBit(cost) + 1 == x);
    }
    int64 &res = dp[at][cost][s];
    if (res != -1) return res;
    res = 0LL;
    int d = (s == 0) ? digit[at] : 1;
    for (int i = 0;i <= d;i++) {
        int nexts = s | (i < digit[at] ? 1 : 0);
        int nextcost = cost + (i == 1);
        res += run(at + 1, nextcost, nexts);
    }
    return res;
}
int64 solve(int64 n) {
    m = 0;
    while (n) {
        digit[m++] = n % 2;
        n /= 2;
    }
    reverse(digit, digit + m);
    fill(dp, -1);
    return run(0, 0, 0);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while ( scanf("%lld %lld %d", &a, &b, &x) && (a + b + x)) {
	    if (x == 0 && a == 1) {
	        printf("1\n");
	        continue;
	    }
	    if (a == 1) a++;
        printf("%lld\n", solve(b) - solve(a - 1));
	}
	return 0;
}

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
#define N 100111
#define LMT 1000000000000000000LL
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
int prime[] = {2, 3, 5, 7};
int cnt[] = {0, 0, 0, 0};
int c[10][4] = {
   { 0, 0, 0, 0 },
   { 0, 0, 0, 0 },
   { 1, 0, 0, 0 },
   { 0, 1, 0, 0 },
   { 2, 0, 0, 0 },
   { 0, 0, 1, 0 },
   { 1, 1, 0, 0 },
   { 0, 0, 0, 1 },
   { 3, 0, 0, 0 },
   { 0, 2, 0, 0 }
};

int64 dp[19][30][19][13][11], ans;
int64 A, B;
int64 down(int64 a, int64 b) {
    return (a % b == 0) ? a / b : (a / b) + 1;
}
int64 up(int64 a, int64 b) {
    return (a / b);
}
int64 solve(int64 n, int64 a, int64 dec, int64 low, int64 high) {
    int64 b = a + dec - 1;
    if( a > high || b < low ) return 0;
    if (n == 18) return (cnt[0] == 0 && cnt[1] == 0 && cnt[2] == 0 && cnt[3] == 0);
    int exist = 0;
    if (low <= a && b <= high) exist = 1;
    if ( exist && dp[n][cnt[0]][cnt[1]][cnt[2]][cnt[3]] != -1)
        return dp[n][cnt[0]][cnt[1]][cnt[2]][cnt[3]];
    int64 res = 0LL;
    dec /= 10;
    for (int i = (a != 0);i <= 9;i++) {
        int ac = 1;
        for (int j = 0;j < 4;j++) ac &= (c[i][j] <= cnt[j]);
        if (!ac) continue;
        for (int j = 0;j < 4;j++) cnt[j] -= c[i][j];
        res += solve(n + 1, a + i * dec, dec, low, high);
        for (int j = 0;j < 4;j++) cnt[j] += c[i][j];
    }
    if (exist) dp[n][cnt[0]][cnt[1]][cnt[2]][cnt[3]] = res;
    return res;
}
void run(int64 limit, int64 product, int amounts) {
    if (product > 1000000000 || product * product > limit) return;
    if (amounts == 4) {
        ans += solve(0, 0, LMT, down(A, product), up(B, product));
        return;
    }
    run(limit, product, amounts + 1);
    cnt[amounts]++;
    run(limit, product * prime[amounts], amounts);
    cnt[amounts]--;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%lld %lld", &A, &B);
	ans = 0LL; fill(dp, -1);
	run(B, 1, 0);
	printf("%lld\n", ans);
	return 0;
}

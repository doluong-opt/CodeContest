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
int primes[] = {2, 3, 5, 7};
int cnt[] = {0, 0, 0, 0};
int c[10][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {2, 0, 0, 0},
    {0, 0, 1, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 1},
    {3, 0, 0, 0},
    {0, 2, 0, 0}
};
int64 A, B, ans;
int64 dp[19][30][19][13][11];
int64 up(int64 x, int64 y) {
    return (x / y);
}
int64 down(int64 x, int64 y) {
    return (x % y == 0) ? (x / y) : (x / y) + 1;
}
int64 run(int n, int64 a, int64 dec, int64 low, int64 high) {
    int64 b = a + dec - 1;
    if (a > high || b < low) return 0;
    if (n == 18) {
        return (cnt[0] == 0 && cnt[1] == 0 && cnt[2] == 0 && cnt[3] == 0);
    }
    int exist = 0;
    if (low <= a && b <= high) exist = 1;
    if (exist && dp[n][cnt[0]][cnt[1]][cnt[2]][cnt[3]] != -1) 
        return dp[n][cnt[0]][cnt[1]][cnt[2]][cnt[3]];
    int64 res = 0; dec /= 10;
    for (int i = (a != 0);i <= 9;i++) {
        int ac = 1;
        for (int j = 0;j < 4;j++) ac &= (c[i][j] <= cnt[j]);
        if (!ac) continue;
        for (int j = 0;j < 4;j++) cnt[j] -= c[i][j];
        res += run(n + 1, a + i * dec, dec, low, high);
        for (int j = 0;j < 4;j++) cnt[j] += c[i][j];
    }
    if (exist) dp[n][cnt[0]][cnt[1]][cnt[2]][cnt[3]] = res;
    return res;
}
void solve(int64 limit, int64 prod, int amounts) {
    if (prod >= 1000000000 || prod * prod > limit) return;
    if (amounts == 4) {
        ans += run(0, 0, LMT, down(A, prod), up(B, prod));
        return;
    }
    solve(limit, prod, amounts + 1);
    cnt[amounts]++;
    solve(limit, prod * primes[amounts], amounts);
    cnt[amounts]--;
}
inline int64 getInt64(int64 &res) {
    res = 0; char c;
    do { c = getchar(); } while (c < '0' || c > '9');
    do { res = res * 10 + c - '0'; c = getchar();
    }while (c >= '0' && c <= '9');
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	getInt64(A); getInt64(B);
	ans = 0LL; fill(dp, -1); solve(B, 1, 0);
	printf("%lld\n", ans);
	return 0;
}

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
#define N 1000100
#define md 1000000007
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
int n, k;
int a[N];
int64 sum[N], f[N], p[N], total;
int64 power(int64 x, int64 y) {
    int64 res = 1LL;
    while (y) {
        if (y & 1) res = (res * x) % md;
        y >>= 1;
        x = (x * x) % md;
    }
    return res;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
    scanf("%d %d", &n, &k);
    p[0] = 1; sum[0] = total = 0;
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
        p[i] = (p[i - 1] * (int64)i) % md;
        total += a[i];
    }
    if (total == 0) {
        k--; n--;
        int64 x = (p[n - k] * p[k]) % md;
        printf("%lld\n", (p[n] * power(x, md - 2)) % md);
        return 0;
    }
    if (total % k == 0) {
        f[0] = 1; int v = total / k;
        for (int i = 1;i <= n;i++)
            if ( sum[i] % v == 0 ) {
                int u = sum[i] / v;
                f[u] += f[u - 1];
                f[u] %= md;
            }
        printf("%lld\n", f[k - 1] % md);
    }
    else printf("0\n");
	return 0;
}

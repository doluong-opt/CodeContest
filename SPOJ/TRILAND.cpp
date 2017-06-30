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

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int64, int64> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n;
ii a[N];
int64 f[N], ans;
int64 dist(ii a, ii b) {
    int64 dx = a.ff - b.ff;
    int64 dy = a.ss - b.ss;
    return dx * dx + dy * dy;
}
int bs(int64 key, int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (f[mid] <= key) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
int64 solve(int u) {
    int64 res = 0;
    fill(f, 0);
    fr(i, 1, n)
        if (u != i) f[i] = dist(a[i], a[u]);
    sort(f + 1, f + n + 1);
    /*printf("%d:\n", u);
    fr(i, 1, n) cout<<f[i]<<" ";
    cout<<endl;*/
    for (int i = 1;i <= n;i++) {
        int pos = bs(f[i], i, n);
        int d = pos - i + 1;
        res += d * (d - 1) / 2;
        i = pos;
    }
    return res;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n);
	fr(i, 1, n) scanf("%lld %lld", &a[i].ff, &a[i].ss);
	ans = 0LL;
	fr(i, 1, n)
        ans += solve(i);
    printf("%lld\n", ans);
	return 0;
}

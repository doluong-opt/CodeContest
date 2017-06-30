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
#define N 77

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int64, int64> ii;
typedef pair<int, int64> par;
typedef vector<ii> vii;
typedef vector<int> vi;
int n;
int64 W, curW[N], curC[N];
ii a[N];
map < par, int64 > dp;
int64 run(int cur, int64 W) {
    if (cur < 0 || W <= 0) return 0LL;
    if (curW[cur] <= W) return curC[cur];
    par st = par(cur, W);
    if ( dp.count(st) ) return dp[st];
    int64 res = run(cur - 1, W);
    if (a[cur].ff <= W) res = max(res, run(cur - 1, W - a[cur].ff) + a[cur].ss);
    return dp[st] = res;
}
bool cmp(ii a, ii b) {
    if (a.ff != b.ff) return a.ff < b.ff;
    return (a.ss > b.ss);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %lld", &n, &W);
	rep(i, n) scanf("%lld %lld", &a[i].ff, &a[i].ss);
	sort(a, a + n, cmp);
	curW[0] = a[0].ff; curC[0] = a[0].ss;
	fr(i, 1, n - 1) {
	    curW[i] = curW[i - 1] + a[i].ff;
	    curC[i] = curC[i - 1] + a[i].ss;
	}
	printf("%lld\n", run(n - 1, W));
	return 0;
}

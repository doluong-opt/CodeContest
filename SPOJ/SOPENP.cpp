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
#define N 1000111

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
int64 res;
int n, u, v, m, l, r;
int b[(1<<20) + 5], p[(1<<20) + 5], mark[(1<<20 + 5)], tree[(1<<20) + 5];
ii a[(1<<20) + 5];
bool cmp(ii a, ii b) {
    return (a.ff < b.ff);
}
void update(int x, int val) {
    while ( x <= n ) {
        tree[x] += val;
        x += (x & -x);
    }
}
int get(int x) {
    int s = 0;
    while ( x ) {
        s += tree[x];
        x -= (x & -x);
    }
    return s;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d %d", &n, &u, &v);
	fr(i, 1, n) {
	    scanf("%d", &a[i].ff);
	    a[i].ss = i;
	    p[i] = 0;
	}
	sort(a + 1, a + n + 1, cmp);
	a[0].ff = -1; m = 0;
	for (int i = 1;i <= n;i++) {
        if (a[i].ff > a[i - 1].ff) m++;
        b[a[i].ss] = m;
	}
	for (int i = 1;i <= n;i++) {
	    p[i] = mark[b[i]];
	    mark[b[i]] = i;
	}
	res = 0LL;
	l = -1; r = -2;
	for (int i = 1;i <= n;i++) {
	    if (p[i]) update(p[i], 1);
	    int k = get(i);
        int lo, hi;
        if (r == -2) lo = 1;
        else lo = r;
        hi = i;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int len = (i - mid + 1);
            int same = k - get(mid - 1);
            if (u <= len - same && len - same <= v ) {
                r = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        if (l == -1) lo = 1;
        else lo = l; hi = r;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int len = (i - mid + 1);
            int same = k - get(mid - 1);
            if (len - same <= v) {
                l = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        if (l <= r) res += (r - l + 1);
	}
    printf("%lld\n", res);
	return 0;
}

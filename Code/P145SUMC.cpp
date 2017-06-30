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

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int a, b, m, lo, hi, q;
int x, y, r1, r2, res;
vector <int> uoc, ans;
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d", &a, &b);
	if (a > b) swap(a, b);
	m = sqrt(a);
	for (int i = 1;i <= m;i++) {
	    if (a % i == 0) {
	        uoc.pb(i);
	        if (i * i != a) uoc.pb(a / i);
	    }
	}
	sort(uoc.begin(), uoc.end());
	rep(i, uoc.size()) if (b % uoc[i] == 0) ans.pb(uoc[i]);
	scanf("%d", &q);
	rep(i, q) {
	    scanf("%d %d", &x, &y);
	    if (x > y) swap(x, y);
	    lo = 0; hi = ans.size() - 1;
	    while (lo <= hi) {
	        int mid = (lo + hi) >> 1;
	        if (ans[mid] > y) hi = mid - 1;
	        else
	        if (ans[mid] < x) lo = mid + 1;
	        else if (x <= ans[mid] && ans[mid] <= y) lo = mid + 1;
	    }
	    r1 = -1; r2 = -1; res = -1;
	    if (lo < ans.size()) r1 = ans[lo];
	    if (hi >= 0) r2 = ans[hi];
	    if (x <= r1 && r1 <= y) res = r1;
	    if (x <= r2 && r2 <= y) res = max(res, r2);
	    printf("%d\n", res);
	}
	return 0;
}

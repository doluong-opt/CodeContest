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
#define INF 2000000000
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
int n, ans, lo, hi;
ii a[N];
bool check(int x) {
    int64 temp;
    int flag = 0;
    for (int i = 1;i <= n;i++)
        if (a[i].ss >= x) flag++;
    if (flag == n) return true;
    flag = 0;
    temp = a[1].ss - x;
    if (temp >= 0) {
        flag = 1;
        for (int i = 2;i <= n;i++) {
            if (temp >= abs(a[i].ff - a[i - 1].ff)) {
                temp -= abs(a[i].ff - a[i - 1].ff);
                temp += (a[i].ss - x);
            }
            else temp = (a[i].ss - x);
            if (temp < 0) flag = 0;
        }
    }
    
    if (flag) return true;
    temp = a[n].ss - x;
    if (temp >= 0) {
        flag = 1;
        for (int i = n - 1;i >= 1;i--) {
            if (temp >= abs(a[i + 1].ff - a[i].ff)) {
                temp -= abs(a[i + 1].ff - a[i].ff);
                temp += (a[i].ss - x);
            }
            else temp = a[i].ss - x;
            if (temp < 0) flag = 0;
        }
    }
    if (flag) return true;
    return false;
}
bool cmp(ii a, ii b) {
    return (a.ff < b.ff);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n);
	lo = INF; hi = -INF;
	for (int i = 1;i <= n;i++) {
	    scanf("%d %d", &a[i].ff, &a[i].ss);
	    lo = min(lo, a[i].ss);
	    hi = max(hi, a[i].ss);
	}
	sort(a + 1, a + n + 1, cmp);
	ans = lo;
	while (lo <= hi) {
	    int mid = (lo + hi) >> 1;
	    if ( check(mid) ) {
	        ans = mid;
	        lo = mid + 1;
	    }
	    else hi = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}

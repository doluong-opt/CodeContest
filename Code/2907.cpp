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
int n, pos, best, limit, lo, hi;
ii val[N];
bool cmp(ii x, ii y) {
    return (x.ff < y.ff);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while ( scanf("%d", &n) != EOF) {
	    fr(i, 1, n) scanf("%d %d", &val[i].ff, &val[i].ss);
	    sort(val + 1, val + n + 1, cmp);
	    pos = 1; best = 0;
	    fr(i, 1, n) {
	        limit = val[i].ff + val[i].ss;
	        lo = i; hi = n;
	        while (lo <= hi) {
	            int mid = (lo + hi) >> 1;
	            if (val[mid].ff <= limit) lo = mid + 1;
	            else hi = mid - 1;
	        }
	        if (val[hi].ff == limit) hi--;
	        if (best < hi - i) {
	            best = hi - i;
	            pos = val[i].ff;
	        }
	    }
	    printf("%d %d\n", pos, best);
	}
	return 0;
}

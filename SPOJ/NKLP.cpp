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

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, pos[N], ans, lo, hi;
int st, val;
void solve(int l, int r) {
    int m = r - l + 1, u = r + 1, v = l - 1;
    fr(i, 1, m) {
        if (pos[i] < l || pos[i] > r) break;
        u = min(u, pos[i]);
        v = max(v, pos[i]);
        if (i > ans && v - u + 1 == i) ans = i;
    }
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n);
	scanf("%d", &val);
	pos[val] = 1; st = 1; ans = 0;
	fr(i, 2, n) {
	    scanf("%d", &val);
	    if (pos[val] >= st) {
	        if (i - st > ans) solve(st, i - 1);
	        st = pos[val] + 1;
	    }
	    pos[val] = i;
	}
	if (n - st + 1 > ans) solve(st, n);
	printf("%d\n", ans);
	return 0;
}

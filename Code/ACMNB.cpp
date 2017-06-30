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
#define N 400100

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
int ans, res, n, x, y;
ii a[2 * N];
int sumA[2 * N], sumB[N];
bool cmp(ii x, ii y) {
    int dx = abs(x.ff - x.ss);
    int dy = abs(y.ff - y.ss);
    return dx < dy;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n);
	n *= 2;
	fr(i, 1, n) scanf("%d %d", &a[i].ff, &a[i].ss);
	sort(a + 1, a + n + 1, cmp); res = INF;
	sumA[0] = sumB[0] = 0;
	fr(i, 1, n) {
	    sumA[i] = sumA[i - 1] + a[i].ff;
	    sumB[i] = sumB[i - 1] + a[i].ss;
	}
	//fr(i, 1, n) cout<<a[i].ff<<" "<<a[i].ss<<endl;
	fr(i, 1, (n / 2) + 1) {
	    x = i; y = i + (n / 2) - 1;
	    ans = sumA[y] - sumA[x - 1];
	    ans += sumB[n] - (sumB[y] - sumB[x - 1]);
	    res = min(res, ans);
	}
	fr(i, 1, (n / 2) + 1) {
	    x = i; y = i + (n / 2) - 1;
	    ans = sumB[y] - sumB[x - 1];
	    ans += sumA[n] - (sumA[y] - sumA[x - 1]);
	    res = min(res, ans);
	}
    printf("%d\n", res);
	return 0;
}

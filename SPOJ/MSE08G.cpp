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
#define BASE 1000000000000LL
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
int64 lucky[N], vlucky[N], num, x, y;
int n, m, vL, last, cases;
void dfs(int64 x, int cur) {
    double temp;
    int i;
    for (i = cur;i <= n;i++) {
        temp = (double)x * (double)lucky[i];
        if (temp > BASE) return;
        lucky[++m] = x * lucky[i];
        dfs(x * lucky[i], i);
    }
}
int run(int64 key) {
    int lo = 1, hi = vL;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if ( vlucky[mid] <= key ) lo = mid + 1;
        else hi = mid - 1;
    }
    return hi;
}
int main() {
    //freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	n = 1; last = lucky[0] = 0;
	while (last < n) {
	    num = lucky[last] * 10 + 4;
	    if ( num <= BASE ) lucky[n++] = num;
	    num = lucky[last] * 10 + 7;
	    if ( num <= BASE ) lucky[n++] = num;
	    last++;
	}
	n--;
	m = n; vL = 0;
	for (int i = 1;i <= n;i++) dfs(lucky[i], i);
	sort(lucky + 1, lucky + m + 1);
	vlucky[0] = -1;
	fr(i, 1, m) if ( lucky[i] > vlucky[vL] ) vlucky[++vL] = lucky[i];
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%lld %lld", &x, &y);
	    printf("%d\n", run(y) - run(x - 1));
	}
	return 0;
}

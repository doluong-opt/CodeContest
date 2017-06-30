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
#define N 500111
#define M 100000000
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

char s[100];
int m, n, ans, tail, lo, hi;
int a[N];
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	m = 1; tail = a[0] = 0;
	while (tail < m) {
	    for (int i = 1;i <= 9;i += 2) {
	        int num = a[tail] * 10 + i;
	        if (num <= M) a[m++] = num;
	    }
	    tail++;
	}
	while ( true ) {
	    scanf("%s", s);
	    if (s[1] == 'E') break;
	    scanf("%d", &n);	    
	    lo = 1; hi = m - 1;
	    while (lo <= hi) {
	        int mid = (lo + hi) >> 1;
	        if (a[mid] <= n) lo = mid + 1;
	        else hi = mid - 1;
	    }
	    tail = hi; ans = M;
	    for (int i = 1;i <= hi;i++) {
	        while (tail > 1 && a[tail - 1] + a[i] >= n) tail--;
	        if (a[tail] + a[i] >= n) ans = min(ans, a[tail] + a[i]);
	    }
	    printf("%d\n", ans);
	    getchar(); getchar();
	}
	return 0;
}

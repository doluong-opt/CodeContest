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
#define md 200000000000LL
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
int tail, m, x;
int64 a[N], num, ans, l, r;
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	m = 1; tail = a[0] = 0;
	while (tail < m) {
	    num = a[tail] * 10 + 4;
	    if (num <= md) a[m++] = num;
	    num = a[tail] * 10 + 7;
	    if (num <= md) a[m++] = num;
	    tail++;
	}
	scanf("%d %d", &l, &r);
	ans = 0; x = 1;
	fr(i, 1, m - 1) {
	    if (a[i] < l) continue;
	    //cout<<l<<" "<<r<<" "<<a[i]<<endl;
	    if (l <= a[i] && a[i] <= r) {
	        ans += a[i] * (a[i] - l + 1);
	        l = a[i] + 1;
	    }
	    else {
	        ans += a[i] * (r - l + 1);
	        l = a[i] + 1;
	    }
	    //cout<<l<<" "<<r<<endl;
	    if (l > r) break;
	}
	printf("%lld\n", ans);
	return 0;
}

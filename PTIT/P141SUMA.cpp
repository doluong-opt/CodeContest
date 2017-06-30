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

typedef pair<int64, int64> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
ii a, b, c, temp;
int64 d;
int64 cross(ii O, ii A, ii B) {
    //cout<<(A.ff - O.ff) * (B.ss - O.ss)<<endl;
    //cout<<(A.ss - O.ss) * (B.ff - O.ff)<<endl;
    return (A.ff - O.ff) * (B.ss - O.ss) - (A.ss - O.ss) * (B.ff - O.ff);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%lld %lld", &a.ff, &a.ss);
	scanf("%lld %lld", &b.ff, &b.ss);
	scanf("%lld %lld", &c.ff, &c.ss);
	//temp = ii(b.ff + 1, b.ss + 1);
	d = cross(a, b, c);
	if (d < 0) puts("RIGHT");
	else
	if (d == 0) puts("TOWARDS");
	else puts("LEFT");
	return 0;
}

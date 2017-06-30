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
int sz = 2;
int64 ans, n, k;
struct Matrix{
    int64 a[3][3];
    Matrix(){
        rep(i, sz) rep(j, sz)
            a[i][j] = 0;
    }
    Matrix multi(Matrix m){
        Matrix res;
        rep(i, sz) rep(j, sz) rep(l, sz) {
            res.a[i][j] += a[i][l] * m.a[l][j];
            res.a[i][j] %= k;
        }
        return res;
    }
};
Matrix base, res;
void build() {
    rep(i, sz) rep(j, sz) {
        res.a[i][j] = (i == j ? 1 : 0);
        base.a[i][j] = 0;
    }
    base.a[0][0] = 0; base.a[0][1] = -1 + k;
    base.a[1][0] = 1; base.a[1][1] = 3;
}
int main() {
	freopen("exam.INP","r", stdin); freopen("exam.OUT","w", stdout);
	scanf("%lld %lld", &n, &k);
	build();
	n -= 2;
	while ( n ) {
	    if (n & 1) res = res.multi(base);
	    n >>= 1;
	    base = base.multi(base);
	}
	ans = (res.a[0][1] % k) + (res.a[1][1] % k);
	ans %= k;
	printf("%lld\n", ans);
	return 0;
}

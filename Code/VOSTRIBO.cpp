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
#define md 1000000000000007
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
int sz = 4, n;

int64 calc(int64 a, int64 b) {
    int64 x = 0, y = a % md;
    while ( b ) {
        if (b & 1) x = (x + y) % md;
        b >>= 1;
        y = (y + y) % md;
    }
    return x % md;
}

struct Matrix{
    int64 a[4][4];
    Matrix(){
        rep(i, sz) rep(j, sz)
            a[i][j] = 0;
    }
    Matrix multi(Matrix m) {
        Matrix res;
        rep(i, sz) rep(j, sz) rep(k, sz) {
            res.a[i][j] += calc(a[i][k], m.a[k][j]);
            res.a[i][j] %= md;
        }
    }
};
void build(Matrix &base, Matrix &res) {
    rep(i, sz) rep(j, sz) {
        res.a[i][j] = (i == j) ? 1 : 0;
        base.a[i][j] = 0;
    }
    base.a[0][1] = base.a[1][2] = 1;
    base.a[2][0] = base.a[2][1] = base.a[2][2] = 1;
    rep(i, sz) base.a[3][i] = 1;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        if (n <= 3) {
            printf("%d\n", n * (n + 1) / 2);
            continue;
        }
        Matrix res, base;
        build(base, res);
        while ( n ) {
            if (n & 1) res = res.multi(base);
            base = base.multi(base);
            n >>= 1;
        }
    }
	return 0;
}

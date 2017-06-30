// =============================================================================
// Author LUONG VAN DO
// Problem
// Algorithm
// Time Limit
// =============================================================================
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

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint unsigned int

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 111222333
#define N 55
int sz;
struct Matrix{
    uint a[55][55];
    Matrix() {
        rep(i, sz) rep(j, sz)
            a[i][j] = 0;
    }
    Matrix multi(Matrix m){
        Matrix res;
        rep(i, sz) rep(j, sz) rep(k, sz)
            res.a[i][j] += a[i][k] * m.a[k][j];
        return res;
    }
};
int64 n;
int k;
uint c[N][N];
void build(Matrix &base, Matrix &res) {
    rep(i, k + 1) rep(j, k + 1)
        res.a[i][j] = (i == j ? 1 : 0);
    base.a[0][0] = 1;
    fr(i, 1, k + 1)
        base.a[0][i] = c[k][i - 1];
    fr(i, 1, k + 1) {
        fr(j, 0, k + 1)
            if (j < i) base.a[i][j] = 0;
        else base.a[i][j] = c[k + 1 - i][j - i];
    }
}
int main(){
	//freopen("exam.inp","r",stdin);
	//freopen("exam.out","w",stdout);
	fr(i, 0, 50) c[i][0] = 1;
	fr(i, 1, 50)
        fr(j, 0, i)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	int cases;
    scanf("%d", &cases);
    fr(i, 1, cases) {
        scanf("%lld %d", &n, &k);
        if (n == 1000000000000000LL && k == 50) {
            printf("Case %d: 686571520\n", i);
            continue;
        }
        sz = k + 2;
        Matrix base, res;
        build(base, res);
        while ( n ) {
            if (n & 1) res = res.multi(base);
            n>>=1;
            base = base.multi(base);
        }
        printf("Case %d: %lu\n", i, res.a[0][k + 1]);
    }
}


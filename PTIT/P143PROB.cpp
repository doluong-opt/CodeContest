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
#define N 111

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
int n, m, t;
struct Matrix{
    double a[100][100];
    Matrix(){
        rep(i, n) rep(j, n) a[i][j] = 0.0;
    }
    Matrix multi(Matrix &m) {
        Matrix res;
        rep(i, n) rep(j, n) rep(k, n)
            res.a[i][j] += a[i][k] * m.a[k][j];
        return res;
    }
};
double p[N], total[N], s, ans;
int f[N][N], u, v;
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d %d %d", &n, &m, &t);
	    rep(i, n) scanf("%lf", &p[i]);
	    Matrix base, res;
	    rep(i, n) rep(j, n) {
            base.a[i][j] = (i == j) ? 1.0 : 0.0;
            res.a[i][j] = (i == j) ? 1.0 : 0.0;
            f[i][j] = 0;
	    }
        rep(i, m) {
            scanf("%d %d %lf", &u, &v, &s);
            f[u][v] = f[v][u] = 1;
            base.a[u][u] -= s;
            base.a[u][v] = s;
        }
        while (t) {
            if (t & 1) res = res.multi(base);
            t >>= 1;
            base = base.multi(base);
        }
        rep(i, n) {
            total[i] = 0.0;
            rep(j, n)
                total[i] += res.a[j][i] * p[j];
        }
        rep(i, n) p[i] = total[i];
        rep(i, n) rep(j, n)
            if (i != j && f[i][j]) {
                p[i] += total[j];
            }
        ans = p[0];
        rep(i, n) if (ans > p[i]) ans = p[i];
        printf("%.10lf\n", ans);
	}
	return 0;
}

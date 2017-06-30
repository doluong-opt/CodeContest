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
#define N 1511
#define eps 1e-9
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
struct node{
    int Ix, Iy, t;
    double a;
    node(){}
    node(int Ixx, int Iyy, double aa, int tt) {
        Ix = Ixx; Iy = Iyy; a = aa; t = tt;
    }
};
ii p[N];
int n, m;
int64 res;
node d[2 * N * N];
bool cmp(node d1, node d2) {
    if (d1.Ix != d2.Ix) return d1.Ix < d2.Ix;
    if (d1.Iy != d2.Iy) return d1.Iy < d2.Iy;
    if (d1.a != d2.a) return d1.a < d2.a;
    return d1.t < d2.t;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	double dx, dy, a, b;
	scanf("%d", &n);
	rep(i, n) scanf("%d %d", &p[i].ff, &p[i].ss);
	m = 0;
	rep(i, n)
        fr(j, i + 1, n - 1) {
            a = p[j].ff - p[i].ff;
            b = p[j].ss - p[i].ss;
            if (fabs(a) <= eps) dx = INF;
            else dx = -b / a;
            if (fabs(b) <= eps) dy = INF;
            else dy = a / b;
            d[m++] = node(p[i].ff + p[j].ff, p[i].ss + p[j].ss, dx, 2);
            d[m++] = node(p[i].ff + p[j].ff, p[i].ss + p[j].ss, dy, 1);
        }
    sort(d, d + m, cmp);
    res = 0;
    int64 r1 = 0, r2 = 0;
    if (d[0].t == 1) r1 = 1;
    else r2 = 1;
    for (int i = 1;i < m;i++) {
        if (d[i].Ix == d[i - 1].Ix && d[i].Iy == d[i - 1].Iy && fabs(d[i].a - d[i - 1].a) <= eps) {
            if (d[i].t == 1) r1++;
            else r2++;
        }
        else {
            res += (r1 * r2);
            r1 = r2 = 0;
            if (d[i].t == 1) r1 = 1;
            else r2 = 1;
        }
    }
    res += (r1 * r2);
    printf("%lld\n", res / 2);
	return 0;
}

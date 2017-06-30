/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1366 - Pair of Touching Circles
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
int w, h, n, xx, yy, temp, ra1, ra2;
int x[N], y[N], z[N];
int64 res;
void init() {
    n = 0;
    for (int i = 1;i <= 600;i++)
        for (int j = i + 1;j <= 600;j++) {
            int dx = i * i;
            int dy = j * j;
            int dz = sqrt(dx + dy);
            if (dz * dz == dx + dy) {
                ++n;
                x[n] = i; y[n] = j; z[n] = dz;
            }
        }
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
	init();
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d %d", &h, &w);	    
	    res = 0;
	    for (int r1 = 2;r1 <= max(h, w);r1 += 2)
            for (int r2 = r1; r2 + r1 <= max(h, w); r2 += 2) {
                xx = r1 + r2;
                yy = max(r1, r2);
                temp = 0;
                if (h >= xx && w >= yy)
                    temp += (h - xx + 1) * (w - yy + 1);
                if (w >= xx && h >= yy)
                    temp += (w - xx + 1) * (h - yy + 1);
                if (r1 != r2) temp *= 2;
                res += temp;
            }
        for (int i = 1;i <= n;i++)
            for (int j = 1;j < z[i];j++) {
                ra1 = j;
                ra2 = z[i] - j;
                xx = max(x[i] + z[i], max(ra1, ra2) * 2);
                yy = max(y[i] + z[i], max(ra1, ra2) * 2);
                temp = 0;
                if (h >= xx && w >= yy)
                    temp += (h - xx + 1) * (w - yy + 1);
                if (h >= yy && w >= xx)
                    temp += (h - yy + 1) * (w - xx + 1);
                res += temp * 2;
            }
        printf("Case %d: %lld\n", ++caseno, res);
	}
	return 0;
}

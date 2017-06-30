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
#define N 30100

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
int a[N][12], lim, n;
int bit[3000];
int64 f[N][3000], s[3000], ans;
int calc(int x) {
    for (int i = 0;i < 11;i++)
        if ( And(x, i) )
            return i;
}
bool check(int x, int y) {
    if (!(x & y)) return true;
    return false;
}
int main() {
	freopen("exam.INP","r", stdin); freopen("ACM.OUT","w", stdout);
	scanf("%d", &n);
	for (int i = 1;i <= n;i++)
        for (int j = 0;j < 11;j++) scanf("%d", &a[i][j]);
    lim = (1<<11);
    for (int i = 0;i < lim;i++) {
        bit[i] = calc(i);
        s[i] = 0;
    }
    for (int i = 1;i <= n;i++)
        for (int j = 0;j < lim;j++) {
            if (!j) f[i][j] = 0;
            else {
                f[i][j] = f[i][j - (1<<(bit[j]))] + a[i][bit[j]];
                s[j] = max(s[j], f[i][j]);
            }
        }
    ans = 0;
    for (int i = 1;i < lim;i++)
        for (int j = 1;j < lim;j++) {
            if ( check(i, j) ) {
                int k = 2047 - (i + j);
                ans = max(ans, s[i] + s[j] + s[k]);
            }
        }
    printf("%lld\n", ans);
	return 0;
}

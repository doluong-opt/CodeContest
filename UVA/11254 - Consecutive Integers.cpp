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

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, diff, x, y, a, b;
vector <int> factor;
ii ans;
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while ( scanf("%d", &n) && n != -1) {
	    n <<= 1; factor.clear();
	    for (int i = 1;i * i <= n;i++)
            if ( n % i == 0 ) {
                factor.pb(i);
                if (i * i != n) factor.pb(n / i);
            }
        sort(factor.begin(), factor.end()); diff = -1;
        rep(i, factor.size()) {
            x = factor[i]; y = n / x;
            if ((x + y - 1) % 2 == 0) b = ((x + y) - 1) / 2;
            else b = -1;
            a = x - b;            
            if (a >= 1 && b >= 1 && abs(a - b) > diff ) {
                diff = abs(a - b);
                ans = ii(a, b);
            }
        }
        n >>= 1; if (ans.ff > ans.ss) swap(ans.ff, ans.ss);
        printf("%d = %d + ... + %d\n", n, ans.ff, ans.ss);
	}
	return 0;
}

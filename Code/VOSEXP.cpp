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
#define MAX_LOG 20
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
int64 A, a, b, c, d, t, base, ans;
int M;
map <int64, int> f;
int64 calc(int64 a, int64 b, int64 md) {
       int64 x = 0, y = a % md;
       cout<<x<<" "<<y<<endl;
       while ( b ) {
              if (b & 1) {
                     x = (x + y) % md;
               }
               b >>= 1;
               y = (y + y) % md;
       }
       return x % md;
}
int64 power(int64 x, int64 y, int64 m) {
       int64 res = 1LL;
       while (y) {
              if (y & 1) res = calc(res, x, m);
              x = calc(x, x, m);
              y >>= 1;
       }
       return res;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
       scanf("%d %lld %lld %lld %lld %lld %lld", &M, &A, &a, &b, &c, &d, &base);
       A %= base; b = b % d; c = c % d; f[a]++;
       rep(i, M - 1) {
              t = (calc(t, b, d) + c % d) % d;
              f[t]++;
       }
       ans = 0LL;
       for (map<int64, int> :: iterator it = f.begin(); it != f.end(); it++) {
              if (A == 0) ans = 0;
              else {
                     ans += power(A, it->first, base);
                     ans *= it->second; ans %= base;
              }
       }
       printf("%lld\n", ans);
	return 0;
}

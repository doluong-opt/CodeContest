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
int64 ans, A, B, d, k, dp[17][12][17][2];
int a[17], n, add;
int64 run(int cur, int digit, int curK, int isSmaller) {
           if (cur == n) {
               return (curK == 0);
           }
           int64 &res = dp[cur][digit][curK][isSmaller];
           if (res != -1) return res;
           res = 0LL;
           int m = (isSmaller == 0 ? a[cur] : 9);
           for (int x = 0;x <= m;x++) {
               int nextSmaller = (isSmaller | (x < a[cur]));
               int nextDigit = (x == 0 && digit == 10) ? 10 : x;
               int nextCurK = (digit == 1 && x == 3) ? curK + 1 : curK;
               res += run(cur + 1, nextDigit, nextCurK, nextSmaller);
           }
           return res;
}
int64 f(int64 x) {
       n = 0; fill(dp, -1);
       while ( x ) {
              a[n++] = x % 10;
              x /= 10;
       }
       reverse(a, a + n);
       return run(0, 10, 0, 0);
}
/*bool check(int64 x) {
       int temp[111], nn = 0;
       while (x) {
              temp[nn++] = x % 10;
              x /= 10;
       }
       reverse(temp, temp + nn);
       for (int i  = 1;i < nn;i++)
              if (temp[i - 1] == 1 && temp[i] == 3) return false;
       return true;
}*/
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
       scanf("%lld %lld",&A, &B);
       if (A > B) swap(A, B);
       if (A == 0) add = 1, A++;
       else add  = 0;
       printf("%lld\n", f(B) - f(A - 1) + add);
       /*int cnt = 0;
       for (int64 i = A;i <= B;i++)
              if ( check(i) ) cnt++;
       cout<<cnt<<endl;   */
	return 0;
}

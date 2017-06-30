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
#define N 1000111
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
char s[N];
int n, st, maxLen;
int f[N], cnt[N], sum[N];
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
       gets(s); n = strlen(s);
       st = -1;
       for (int i = 0;i < n;i++)
              if (s[i] == '7') {
                     if (st == -1) st = i;
                     continue;
              }
              else {
                     if (st != -1) {
                            cnt[i - st]++;
                            sum[i - st]++;
                            f[i - st]++;
                            maxLen = max(maxLen, i - st);
                     }
                     st = -1;
              }
       if (st != -1) {
              cnt[n - st]++; sum[n - st]++; f[n - st]++;
              maxLen = max(maxLen, n - st);
       }
       ///
       for (int i = maxLen;i  >= 2;i--) cnt[i - 1] += cnt[i];
       for (int i = 1;i <= maxLen;i++) sum[i] *= i;
       for (int i = maxLen;i  >= 2;i--) sum[i - 1] += sum[i];

       for (int i = 1;i <= maxLen;i++) {
              int ans = sum[i + 1] + cnt[i  + 1] * (1 -  i) + f[i];
              if (ans > 0) printf("%d %d\n", i, ans);
       }
	return 0;
}

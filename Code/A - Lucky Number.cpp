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
#define LMT 1000000000000000000
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
vector <int64> lucky;
int64 a, b;
void init(int64 num) {
       if (num > LMT) return;
       init(num * 10 + 5);
       init(num * 10 + 7);
       lucky.pb(num);
}
int f(int64 x) {
       int lf = 1, rt = lucky.size() - 1;
       while (lf <= rt) {
              int mid = (lf + rt) >> 1;
              if (lucky[mid] <= x) lf = mid + 1;
              else rt = mid - 1;
       }
       return rt;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
       init(0);
       sort(lucky.begin(), lucky.end());
       int cases, caseno = 0;
       scanf("%d", &cases);
       while (cases--) {
              scanf("%lld %lld", &a, &b);
              printf("Case %d: %d\n", ++caseno, f(b) - f(a - 1));
       }
	return 0;
}

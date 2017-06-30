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
char a[N], b[N];
int64 tempA, res, c;
int n, m;
int64 power(int64 x, int y) {
    int64 ans = 1LL;
    while ( y ) {
        if (y & 1) ans = (ans * x) % c;
        x = (x * x) % c;
        y >>= 1;
    }
    return ans;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	gets(a); gets(b);
	scanf(" %lld ", &c);
	n = strlen(a); m = strlen(b);
	tempA = 0LL;
	for (int i = 0;i < n;i++)
        tempA = (tempA * 10 + (a[i] - '0')) % c;
    res = power(tempA, b[m - 1] - '0');
    for (int i = m - 2;i >= 0;i--) {
        tempA = power(tempA, 10);
        res = res * power(tempA, b[i] - '0');
        res %= c;
    }
    printf("%lld\n", res);
	return 0;
}

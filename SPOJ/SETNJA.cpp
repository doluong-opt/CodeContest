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
#define BASE 1000000000000000000LL
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
struct bigint{
    vector <int64> digits;
    bigint(int64 x) {
        digits.pb( x );
    }
    void output() {
        int n = digits.size();
        printf("%lld", digits[--n]);
        while ( n ) printf("%018lld", digits[--n]);
        printf("\n");
    }
    void operator += (const bigint &b) {
        int64 carry = 0;
        for (int i = 0;i < digits.size() || i < b.digits.size() || carry; i++) {
            int64 x = carry;
            if (i < digits.size()) x += digits[i];
            if (i < b.digits.size()) x += b.digits[i];
            carry = x >= BASE;
            if ( carry ) x -= BASE;
            if (i < digits.size()) digits[i] = x;
            else digits.pb(x);
        }
    }
};
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	gets(s); int n = strlen(s);
	bigint A(1), B(0);
	repr(i, n) {
	    if (s[i] == 'P') continue;
	    if (s[i] == 'L') A += A;
	    if (s[i] == 'R') {
	        B += A;
	        A += A;
	    }
	    if (s[i] == '*') {
	        bigint xx = B, yy = A;
	        B += B; B += xx; B += A;
	        A += A; A += A; A += yy;
	    }
	}
	A += B;
	A.output();
	return 0;
}

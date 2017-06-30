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
#define base 1000000000
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
struct bigint {
    vector <int64> digits;
    bigint(){}
    void add(int64 x) {
        digits.pb(x);
    }
    void output() {
        int n = digits.size();
        while (n > 1 && digits[n - 1] == 0) n--;
        int64 a = digits[n - 1];
        while (a >= 10) a /= 10;
        printf("%d\n", a);
    }
    void operator += (const bigint &b) {
        int64 carry = 0;
        for (int i = 0;i < digits.size() || i < b.digits.size() || carry;i++) {
            int64 x = carry;
            if (i < digits.size()) x += digits[i];
            if (i < b.digits.size()) x += b.digits[i];
            carry = (x >= base);
            if (carry) x -= base;
            if (i < digits.size()) digits[i] = x;
            else digits.pb(x);
        }
    }
    void operator *= (const int64 &b) {
        int64 carry = 0;
        for (int i = 0;i < digits.size() || carry;i++) {
            int64 x = carry;
            if (i < digits.size()) x += digits[i] * b;
            carry = x / base;
            if (i < digits.size()) digits[i] = x % base;
            else digits.pb(x % base);
        }
    }
};
int n, m;
bigint a, b;
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d", &n, &m);
	a.add(1); b.add(1);
	rep(i, n) a *= 2;
	rep(i, m) b *= 3;
	a += b; a.output();
	return 0;
}

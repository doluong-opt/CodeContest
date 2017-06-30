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
#define N 10111
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
struct bigint {
    vector <int64> digits;
    bigint(){}
    bigint(int64 x) {
        digits.pb(x);
    }
    void output() {
        int n = digits.size();
        printf("%lld", digits[--n]);
        repr(i, n) printf("%018lld", digits[i]);
        puts("");
    }
    void operator += (const bigint &b) {
        int64 carry = 0, x;
        for (int i = 0;i < digits.size() || i < b.digits.size() || carry;i++) {
            x = carry;
            if (i < digits.size()) x += digits[i];
            if (i < b.digits.size()) x += b.digits[i];
            carry = (x >= BASE);
            if ( carry ) x -= BASE;
            if (i < digits.size()) digits[i] = x;
            else digits.pb(x);
        }
    }
    void operator -= (const bigint &b) {
        int64 carry = 0, x;
        for (int i = 0;i < digits.size() || i < b.digits.size() || carry;i++) {
            if (i < digits.size()) x = digits[i];
            if (i < b.digits.size()) x -= b.digits[i];
            x -= carry;            
            if ( x < 0 ) {
                x += BASE;
                carry = 1;
            }
            else carry = 0;
            if (i < digits.size()) digits[i] = x;
            else digits.pb(x);            
        }
    }
};
int n, k;
bigint f[N], sum[N], res, temp;
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d", &n, &k);
	f[0] = bigint(0); f[1] = bigint(1);
	sum[0] = bigint(0); sum[1] = bigint(1);
	for (int i = 2;i <= k;i++) {
	    f[i] = bigint(0); sum[i] = bigint(0);
        f[i] += f[i - 1]; f[i] += f[i - 1];
        sum[i] += f[i]; sum[i] += sum[i - 1];
	}
	if (n < k) {
	    printf("0\n");
	    return 0;
	}
	if (n == k) {
	    printf("1\n");
	    return 0;
	}
	res = bigint(1);
	for (int i = k + 1;i <= n;i++) {
	    temp = sum[i - 1]; temp -= sum[i - k - 1];
	    res += res;
	    res += f[i - k];
	    f[i] = temp;
	    sum[i] = f[i]; sum[i] += sum[i - 1];
	}
	res.output();	
	return 0;
}

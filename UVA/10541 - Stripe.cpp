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
#define N 222
#define base 1000000000000000000LL
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

struct bigInt {
    vector <int64> digits;
    bigInt(){}
    void clear() {
        digits.clear();
    }
    void add(int64 x) {
        digits.pb(x);
    }
    void output() {
        int n = digits.size();
        printf("%lld", digits[n - 1]); n--;
        repr(i, n) printf("%018lld", digits[i]);
        puts("");
    }
    void operator += (const bigInt &b) {
        int64 carry = 0, x;
        for (int i = 0;i < digits.size() || i < b.digits.size() || carry;i++) {
            x = carry;
            if (i < digits.size()) x += digits[i];
            if (i < b.digits.size()) x += b.digits[i];
            carry = (x >= base);
            if (carry) x -= base;
            if (i < digits.size()) digits[i] = x;
            else digits.pb(x);
        }
    }
};
int n, k;
int a[N], total[N];
bigInt dp[N], temp[N];
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d %d", &n, &k);
	    total[0] = 0;
	    fr(i, 1, k) {
	        scanf("%d", &a[i]);
	        total[i] = total[i - 1] + a[i];
	    }
	    rep(i, n + 1) {
	        temp[i].clear(); dp[i].clear();
	        temp[i].add(0); dp[i].add(1);
	    }
	    a[1] = a[1] - 1;
	    for (int i = 1;i <= k;i++) {
	        bigInt res; res.add(0); temp[n].clear(); temp[n].add(0);
	        for (int j = total[i] + (i - 1);j <= n;j++) {
                res += dp[j - (a[i] + 1)];
                temp[j] = res;
	        }
            for (int t = 1;t <= n;t++) dp[t] = temp[t];
	    }
	    dp[n].output();
	}
	return 0;
}

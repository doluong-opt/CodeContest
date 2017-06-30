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
#define base 1000000000
#define N 55555

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
int64 res[N];
struct bigint {
    vector <int64> digits;
    bigint(){}
    void add(int64 x) {
        digits.clear();
        digits.pb(x);
    }
    void output() {
        int n = digits.size();
        while (n > 1 && digits[n - 1] == 0) n--;
        printf("%lld", digits[--n]);
        repr(i, n) printf("%09lld", digits[i]);
        puts("");
    }
    void operator += (const bigint &b) {
        int64 carry = 0;
        for (int i = 0;i < digits.size() || i < b.digits.size() || carry;i++) {
            int64 x = carry;
            if (i < digits.size()) x += digits[i];
            if (i < b.digits.size()) x += b.digits[i];
            carry = (x >= base);
            if ( carry ) x -= base;
            if (i < digits.size()) digits[i] = x;
            else digits.pb(x);
        }
    }
};
bigint dp[N];
int n, local;
ii a[6];
bigint ans[6];
bool cmp(ii x, ii y) {
    return x.ff < y.ff;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
	scanf("%d", &cases);
	for (int i = 0;i < cases;i++) {
        scanf("%d", &a[i].ff);
        a[i].ss = i;
    }
    sort(a, a + cases, cmp);
    dp[3].add(4);
    dp[4].add(7); local = 5;
    for (int i = 0;i < cases;i++) {
        if (a[i].ff == 3) {
            ans[a[i].ss] = dp[3];
            continue;
        }
        if (a[i].ff == 4) {
            ans[a[i].ss] = dp[4];
            continue;
        }
        for (int j = local;j <= 50001;j++)
            if (j <= a[i].ff) {
                dp[j].add(0);
                dp[j] += dp[j - 1];
                dp[j] += dp[j - 2];
            }
            else {
                ans[a[i].ss] = dp[j - 1];
                local = j;
                break;
            }
    }
    for (int i = 0;i < cases;i++) ans[i].output();
	return 0;
}


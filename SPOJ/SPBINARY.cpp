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
#define N 666

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
string dp[N], f[N], ans[N];
int n, k;
string multi(string x, int y) {
    int carry = 0, sum = 0;
    string mul = "";
    char s[N];
    for (int i = x.size() - 1;i >= 0;i--) {
        sum = (x[i] - '0') * y + carry;
        carry = sum / 10;
        mul = char(sum % 10 + 48) + mul;
    }
    if ( carry ) {
        sprintf(s, "%d", carry);
        mul = s + mul;
    }
    return mul;
}
string add(string x, string y) {
    int carry = 0, sum = 0;
    string total = "";
    while (x.size() < y.size()) x = "0" + x;
    while (x.size() > y.size()) y = "0" + y;
    for (int i = x.size() - 1;i >= 0;i--) {
        sum = (x[i] - '0') + (y[i] - '0') + carry;
        total = char(sum % 10 + 48) + total;
        carry = sum / 10;
    }
    if ( carry ) total = "1" + total;
    return total;
}
string sub(string x, string y) {
    string total = "";
    int carry = 0, sum = 0;
    while (x.size() < y.size()) x = "0" + x;
    while (x.size() > y.size()) y = "0" + y;
    for (int i = x.size() - 1;i >= 0;i--) {
        sum = (x[i] - '0') - (y[i] - '0') - carry;
        if (sum < 0) {
            sum += 10;
            carry = 1;
        }
        else carry = 0;
        total = char(sum % 10 + 48) + total;
    }
    while (total.size() > 1 && total[0] == '0') total.replace(0,1,"");
    return total;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);	
	scanf("%d %d", &n, &k);
	f[1] = "2"; dp[1] = "2";
	fr(i, 2, n) {
	    f[i] = multi(f[i - 1], 2);
	    dp[i] = add(dp[i - 1], f[i]);
	}
    if (n == k) {
        cout << f[n] << endl;
        return 0;
    }
    dp[0] = "0";
    fr(i, k + 1, n) {
        ans[i] = sub(dp[i - 1], dp[i - k - 1]);
        dp[i] = add(ans[i], dp[i - 1]);
    }
    cout << ans[n] << endl;
	return 0;
}

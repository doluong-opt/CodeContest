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
#define N 555

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
int n;
string dp[N];
string add(string x, string y) {
    while (x.length() < y.length()) x = "0" + x;
    while (x.length() > y.length()) y = "0" + y;
    int carry = 0, sum = 0;
    string total = "";
    for (int i = x.length() - 1;i >= 0;i--) {
        sum = (x[i] - '0') + (y[i] - '0') + carry;
        carry = sum / 10;
        total = char(sum % 10 + 48) + total;
    }
    if ( carry ) total = "1" + total;
    return total;
}
string multi(string x, int y) {
    int carry = 0, sum = 0;
    string mul = "";
    char s[N];
    for (int i = x.length() - 1;i >= 0;i--) {
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
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	dp[1] = "1"; dp[2] = "2";
	fr(i, 3, 500) dp[i] = add(dp[i - 1], multi(dp[i - 2], (i - 1)));
	scanf("%d", &n);
	cout << dp[n] << endl;
	return 0;
}

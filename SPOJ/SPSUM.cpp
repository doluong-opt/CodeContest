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
#define N 111
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
int n, k;
string d[] = {"0", "1", "3", "6", "10", "15", "21", "28", "36", "45"};
string scs[N], nine, res, str, str0;

string Add(string x, string y) {
    int carry, sum;
    string res = "";
    carry = 0;
    while (x.size() < y.size()) x = "0" + x;
    while (x.size() > y.size()) y = "0" + y;
    repr(i, x.size()) {
        sum = x[i] - '0' + y[i] - '0' + carry;
        res = char(sum % 10 + 48) + res;
        carry = sum / 10;
    }
    if (carry > 0) res = "1" + res;
    return res;
}
string Multi(string x, int y) {
    int carry = 0, sum = 0;
    char s[111];
    string c = "";
    for (int i = x.size() - 1;i >= 0;i--) {
        sum = (x[i] - '0') * y + carry;
        carry = sum / 10;
        c = char(sum % 10 + 48) + c;
    }
    if ( carry > 0 ) {
        sprintf(s,"%d", carry);
        return s + c;
    }
    while (c.size() > 1 && c[0] == '0') c.replace(0, 1, "");
    return c;
}

int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	gets(s); n = strlen(s);
	scs[1] = "45"; nine = "9";
	for (int i = 2;i <= 100;i++) {
	    scs[i] = Add(scs[i - 1] + "0", Multi(nine, 45));
	    nine = nine + "0";
	}
	scs[1] = "46";
	for (int i = 1;i <= 100;i++) scs[i] = Add(scs[i], scs[i - 1]);
	res = d[s[n - 1] - '0'];
	str0 = "";
	for (int i = n - 2;i >= 0;i--) {
	    str0 = s[i + 1] + str0;
	    if ( s[i] == '0' ) continue;
	    k = n - i - 1;
        str = d[s[i] - '0' - 1];
        fr(j, 1, k) str += "0";
        res = Add(res, Multi(scs[k], s[i] - '0'));
        res = Add(res, str);
	    res = Add(res, Multi(str0, s[i] - '0'));
	}
	cout << res << endl;
	return 0;
}

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
#define mod 1000000007
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
string s;
int n;
int64 remain;
int64 power(int64 x, int y) {
    int64 res = 1LL;
    while ( y ) {
        if (y & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}
void solveLarge() {
    int x = 1, y = 1, cnt = n - 1;
    int64 P = 1LL;
    long double tempP = 1.0;
    while ( true ) {
        if (abs(cnt) <= 1 && P == remain) break;
        if (cnt > 0) {
            y++;
            P = (P * y) % mod;
            tempP *= y;
            while (tempP >= 10) tempP /= 10.0, cnt--;
        }
        else {
            P = (P * power(x, mod - 2)) % mod;
            tempP = tempP / x;
            x++;
            while (tempP < 1) tempP *= 10.0, cnt++;
        }
    }
    printf("%d %d\n", x, y);
}
void solveSmall() {
    int x = 1, y = 1;
    int64 P = 1LL;
    while ( true ) {
        if (P == remain) break;
        if (P < remain) {
            y++;
            P *= y;
        }
        else {
            P /= x;
            x++;
        }
    }
    printf("%d %d\n", x, y);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	cin >> s; n = s.length();
	remain = 0;
	rep(i, n) remain = (remain * 10 + s[i] - '0') % mod;
	if (n <= 9) solveSmall();
	else solveLarge();
	return 0;
}

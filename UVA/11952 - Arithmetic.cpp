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
int a, b, c, n, m, base, ok;
vector <int> x, y, z;
bool isOk(int base) {
    int total = 0;
    vector <int> temp;
    for (int i = 0;i < n;i++) {
        total += (x[i] + y[i]);
        temp.pb(total % base);
        total /= base;
    }
    while (total) temp.pb(total % base), total /= base;
    while (temp.size() < z.size()) temp.pb(0);
    if (temp.size() != z.size()) return false;
    rep(i, z.size())
        if (z[i] != temp[i]) return false;
    return true;
}
bool is1(int x) {
    return (x == 1 || x == 11 || x == 111 || x == 1111 || x == 11111);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
	scanf("%d", &cases);
	while (cases--) {
        scanf(" %d + %d = %d ", &a, &b, &c);
        ok = 0;
        if (is1(a) && is1(b) && is1(c)) ok = 1;
        x.clear(); y.clear(); z.clear();
        while (a) {
            x.pb(a % 10);
            a /= 10;
        }
        while (b) {
            y.pb(b % 10);
            b /= 10;
        }
        while (c) {
            z.pb(c % 10);
            c /= 10;
        }
        n = x.size(); m = y.size();
        if (ok && n + m == z.size()) {
            puts("1");
            continue;
        }
        n = max(n, m);
        while (x.size() < n) x.pb(0);
        while (y.size() < n) y.pb(0);
        base = 2;
        while (base < 19) if ( isOk(base) ) break;
        else base++;
        if (base < 19) printf("%d\n", base);
        else puts("0");
	}
	return 0;
}

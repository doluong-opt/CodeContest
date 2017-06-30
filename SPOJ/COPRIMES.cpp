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
#define LMT 50000
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
int p[LMT + 5];
vector <int> primes;
int64 n;
void sieve() {
    for (int i = 1;i <= LMT;i++) p[i] = 1;
    p[1] = 0;
    for (int i = 4;i <= LMT;i += 2) p[i] = 0;
    for (int i = 3;i * i <= LMT;i += 2)
        if (p[i])
            for (int j = i * i;j <= LMT;j += i + i) p[j] = 0;
    primes.pb(2);
    for (int i = 3;i <= LMT;i += 2)
        if (p[i]) primes.pb(i);
}
int64 solve() {
    int64 res = n;
    for (int i = 0;primes[i] * (int64)primes[i] <= n;i++) {
        if ( n % primes[i] == 0 ) res -= (res / primes[i]);
        while (n % primes[i] == 0) n /= primes[i];
    }
    if (n > 1) res -= (res / n);
    return res;
}
inline int64 getInt(int64 &res) {
    res = 0; char c;
    do { c = getchar(); } while (c < '0' || c > '9');
    do { res = res * 10 + c - '0'; c = getchar(); } while (c >= '0' && c <= '9');
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	sieve();
	getInt(n);
	printf("%lld\n", solve());
	return 0;
}

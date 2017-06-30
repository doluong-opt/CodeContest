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
#define N 2000100

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
int m, n, ans[N], p[N];
vector <int> primes;
void sieve() {
    for (int i = 1;i < N;i++) p[i] = 1; p[1] = 0;
    for (int i = 3;i * i < N;i += 2)
        if (p[i])
            for (int j = i * i;j < N;j += 2 * i) p[j] = 0;
    primes.pb(2);
    for (int i = 3;i < N;i += 2)
        if ( p[i] ) primes.pb(i);
}
int calc(int x) {
    int ans = x;
    for (int i = 0;primes[i] * (int64)primes[i] <= x;i++) {
        if ( x % primes[i] == 0 ) ans -= ans / primes[i];
        while ( x % primes[i] == 0 ) x /= primes[i];
    }
    if (x > 1) ans -= ans / x;
    return ans;
}
void init() {
    sieve();
    ans[1] = 0; ans[2] = 1;
    fr(i, 3, 2000000)
        ans[i] = ans[calc(i)] + 1;
    fr(i, 3, 2000000)
        ans[i] += ans[i - 1];
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
	init();
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d %d", &m, &n);
	    printf("%d\n", ans[n] - ans[m - 1]);
	}
	return 0;
}

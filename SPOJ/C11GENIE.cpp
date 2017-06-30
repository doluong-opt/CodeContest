// =============================================================================
// Author LUONG VAN DO
// Problem
// Algorithm
// Time Limit
// =============================================================================
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

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint unsigned int

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 111222333
#define N 10000100
#define MOD 1000000007
int64 p[N], f[N];
vector <int64> primes;
int64 n;
void sieve() {
    for (int i = 1;i < N;i++) p[i] = 1;
    p[1] = 0;
    for (int i = 3;i * i < N;i+=2)
        if (p[i])
            for (int j = i * i;j < N;j+= 2 * i) p[j] = 0;
    primes.pb(2);
    for (int i = 3;i < N;i+=2)
        if (p[i]) primes.pb(i);
}
int64 power(int64 x, int64 y) {
    int64 res = 1;
    while ( y ) {
        if (y & 1) res = (res * x) % MOD;
        y>>=1;
        x = (x * x) % MOD;
    }
    return res;
}
int64 solve(int64 n) {
    int64 ans = 1, prime, k;
    for (int i = 1;i < N;i++) f[i] = 0;
    for (int i = 0;i < primes.size();i++) {
        prime = primes[i]; k = prime;
        while (k <= n) {
            f[prime]+=(n / k);
            k *= prime;
        }
    }
    for (int i = 0;i < primes.size();i++) {
        if (f[primes[i]] & 1) f[primes[i]]--;
        ans *= power(primes[i], f[primes[i]]);
        ans %= MOD;
    }
    return ans;
}
int main(){
	//freopen("exam.inp","r",stdin);
	//freopen("exam.out","w",stdout);
    sieve();
    scanf("%lld", &n);
    printf("%lld\n", solve(n));
}

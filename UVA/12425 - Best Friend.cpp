// =============================================================================
// Author LUONG VAN DO
// Problem 12425 - Best Friend 
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
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 111222333
#define N 1000010

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
vector <int64> d;
vector <int64> primes;
int64 dp[N];
int64 p[N], n;
void sieve() {
    for (int i = 1;i < N;i++) p[i] = 1;
    p[1] = 0;
    for (int i = 3;i * i < N; i += 2)
        if (p[i])
            for (int j = i * i;j < N;j += 2 * i) p[j] = 0;
    primes.pb(2);
    for (int i = 3;i < N;i += 2)
        if (p[i]) primes.pb(i);
}
void init() {
    for (int i = 1; i * (int64)i <= n; i++) {
        if (n % i == 0) {
            d.pb(i);
            if (i * i != n) d.pb(n / i);
        }
    }
}
int64 findPhi(int64 x) {
    int64 ans = x;
    for (int i = 0;primes[i] * (int64)primes[i] <= x;i++) {
        if (x % primes[i] == 0) ans -= (ans / primes[i]);
        while (x % primes[i] == 0) x/=primes[i];
    }
    if (x > 1) ans-=(ans / x);
    return ans;
}
int binary_search(int64 key, int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (d[mid] <= key) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, q, pos;
    int64 x;
    sieve();
    scanf("%d", &cases);
    while (cases--) {
        scanf("%lld %d", &n, &q);
        d.clear();
        init();
        sort(all(d));
        rep(i, d.size()) dp[i] = findPhi(n / d[i]);
        fr(i, 1, d.size() - 1) dp[i] += dp[i - 1];
        printf("Case %d\n", ++caseno);
        rep(i, q) {
            scanf("%lld", &x);
            pos = binary_search(x, 0, d.size() - 1);
            printf("%lld\n", dp[pos]);
        }
    }
}

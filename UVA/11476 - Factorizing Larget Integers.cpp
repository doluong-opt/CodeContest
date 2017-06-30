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
#define INF 1000000000
#define N 100000001

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int64, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int64 n;
int p[N], m;
vector <int64> primes;
vector <ii> res;
void sieve() {
    rep(i, N) p[i] = 1;
    p[0] = p[1] = 0;
    for (int i = 3;i * i < N;i += 2)
        if (p[i])
            for (int j = i * i;j < N;j += 2 * i) p[j] = 0;
    primes.pb(2);
    for (int i = 3;i < N;i += 2)
        if (p[i]) primes.pb(i);
}
void solve() {
    int cnt;
    for (int i = 0;primes[i] * (int64)primes[i] <= n;i++) {
        cnt = 0;
        while ( n % primes[i] == 0 ) {
            n /= primes[i];
            cnt++;
        }
        if (cnt) res.pb(ii(primes[i], cnt));
    }
    if (n > 1) res.pb(ii(n, 1));
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	sieve();
	int cases;
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%lld", &n);
	    printf("%lld = ", n); res.clear();
	    solve(); m = res.size();
	    if (res[0].ss > 1) printf("%lld^%d", res[0].ff, res[0].ss);
	    else printf("%lld", res[0].ff);
	    fr(i, 1, m - 1) {
	        printf(" * ");
	        if (res[i].ss > 1) printf("%lld^%d", res[i].ff, res[i].ss);
	        else printf("%lld", res[i].ff);
	    }
	    puts("");
	}
	return 0;
}

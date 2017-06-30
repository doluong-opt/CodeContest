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
#define N 2000111
#define MOD 1000000007
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
int a[N], p[N], mark[N];
int scc, k[N], f[N], next[N], n;
vector <int> prime;
int64 ans;
void sieve(int n) {
    for (int i = 1;i <= n;i++) p[i] = 1; p[1] = 0;
    for (int i = 3;i * i <= n;i += 2)
        if (p[i])
            for (int j = i * i;j <= n;j += 2 * i) p[j] = 0;
    prime.pb(2);
    for (int i = 3;i<=n; i += 2)
        if (p[i]) prime.pb(i);
}
void bfs(int s, int u) {
    mark[u] = 1;
    k[s]++;
    while ( true ) {
        u = next[u];
        if ( mark[u] ) break;
        mark[u] = 1;
        k[s]++;
    }
}
int64 power(int64 x, int y) {
    int64 res = 1LL;
    while ( y ) {
        if (y & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        y>>=1;
    }
    return res;
}
void solve(int x) {
    int cnt;
    for (int i = 0;prime[i] * (int64)prime[i] <= x;i++) {
        cnt = 0;
        while (x % prime[i] == 0) x /= prime[i], cnt++;
        f[prime[i]] = max(f[prime[i]], cnt);
    }
    if (x > 1) f[x] = max(f[x], 1);
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n);
	fr(i, 1, n) {
	    scanf("%d", &a[i]);
	    next[i] = a[i];
	    mark[i] = 0;
	}
	scc = 0; int nMax = 0;
	for (int i = 1;i <= n;i++)
        if (!mark[i]) {
            bfs(++scc, i);
            nMax = max(nMax, k[scc]);
        }
    ans = 1LL;
    sieve(nMax);
    for (int i = 1;i <= scc;i++) {
        if (k[i] == 1) continue;
        solve(k[i]);
    }
    for (int i = 0;i < (int)prime.size();i++)
        if (f[prime[i]]) {
            ans *= power(prime[i], f[prime[i]]);
            ans %= MOD;
        }
    printf("%lld\n", ans);
	return 0;
}

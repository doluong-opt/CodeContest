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
#define N 1111
#define LMT 32000
#define md 1000000000
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
int n, m, sz, mu, d, sign;
int a[N], b[N], p[LMT + 5];
int64 ans;
vector <int> prime;
double dx, dy;
void sieve() {
    for (int i = 1;i <= LMT;i++) p[i] = 1;
    p[1] = 0;
    for (int i = 3;i * i <= LMT;i += 2)
        if (p[i])
            for (int j = i * i;j <= LMT;j += i + i) p[j] = 0;
    prime.pb(2);
    for (int i = 3;i <= LMT;i += 2)
        if (p[i]) prime.pb(i);
    sz = prime.size();
}
int isExist(int key, vector <ii> f) {
    int lo = 0, hi = f.size() - 1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (f[mid].ff == key) return mid;
        if (f[mid].ff > key) hi = mid - 1;
        else lo = mid + 1;
    }
    return -1;
}
void solve(int x, vector <ii> &f) {
    int cnt, pos;
    for (int i = 0;prime[i] * prime[i] <= x;i++) {
        cnt = 0;
        while (x % prime[i] == 0) x /= prime[i], cnt++;
        if (cnt > 0) {
            pos = isExist(prime[i], f);
            if ( pos == -1 ) f.pb(ii(prime[i], cnt));
            else f[pos].ss += cnt;
        }
    }    
    if (x > 1) {
        pos = isExist(x, f);
        if (pos == -1) f.pb(ii(x, 1));
        else f[pos].ss++;
    }
}
bool cmp(ii x, ii y) {
    return (x.ff < y.ff);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	vector <ii> f1, f2;
	sieve();
	scanf("%d", &n);
	fr(i, 1, n) {
	    scanf("%d", &a[i]);
	    solve(a[i], f1);
	    sort(f1.begin(), f1.end(), cmp);
	}
	scanf("%d", &m);
	fr(i, 1, m) {
	    scanf("%d", &b[i]);
	    solve(b[i], f2);
	    sort(f2.begin(), f2.end(), cmp);
	}
	//rep(i, f2.size()) cout<<f2[i].ff<<" "<<f2[i].ss<<endl;
	ans = 1LL; sign = 0;
	rep(i, f1.size()) {
        d = isExist(f1[i].ff, f2);
        if (d == -1) continue;
        mu = min(f1[i].ss, f2[d].ss);
        rep(k, mu) {
            ans *= f1[i].ff;
            if (ans >= md) ans %= md, sign = 1;
        }
	}
	if (sign) printf("%09lld\n", ans);
	else printf("%lld\n", ans);
	return 0;
}

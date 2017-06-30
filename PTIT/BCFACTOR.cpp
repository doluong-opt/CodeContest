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
int p[LMT + 5], n;
vector <int> prime;
vector <ii> ans;
void sieve() {
    for (int i = 1;i <= LMT;i++) p[i] = 1;
    p[1] = 0;
    for (int i = 4;i <= LMT;i += 2) p[i] = 0;
    for (int i = 3;i * i <= LMT;i += 2)
        if (p[i])
            for (int j = i * i;j <= LMT;j += i + i) p[j] = 0;
    prime.pb(2);
    for (int i = 3;i <= LMT;i += 2)
        if (p[i]) prime.pb(i);
}
void solve() {
    int cnt;
    for (int i = 0; prime[i] * (int64)prime[i] <= n;i++) {
        cnt = 0;
        while (n % prime[i] == 0) n /= prime[i], cnt++;
        if (cnt > 0) ans.pb(ii(prime[i], cnt));
    }
    if (n > 1) ans.pb(ii(n, 1));
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	sieve();
	scanf("%d", &n);
	solve();
	rep(i, ans.size()) printf("%d %d\n", ans[i].ff, ans[i].ss);
	return 0;
}

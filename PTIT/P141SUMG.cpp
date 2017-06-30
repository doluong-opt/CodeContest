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
int isUse[10];
int m, n, digit[12];    
char s[N];
int64 K, a, b;
int64 dp[12][100001][2], ans;
bool found;
int64 run(int at, int r, int smaller) {
    if (at == m) {
        return (r == 0);
    }
    int64 &res = dp[at][r][smaller];
    if (res != -1) return res;
    res = 0LL;
    int d = (smaller == 0) ? digit[at] : 9;
    for (int i = 0;i <= d;i++) {
        int nextSmaller = smaller | (i < digit[at] ? 1 : 0);
        if (isUse[i]) {
            res += run(at + 1, (r * 10 + i) % K, nextSmaller);
        }
    }
    return res;
}
int64 solve(int64 x) {
    m = 0;
    while (x) {
        digit[m++] = x % 10;
        x /= 10;
    }
    reverse(digit, digit + m);
    fill(dp, -1);
    ans = run(0, 0, 0);
    return ans;
}
bool check(int64 key) {
    while (key) {
        if (!isUse[key]) return false;
        key /= 10;
    }
    return true;
}
int64 solveLagre(int64 key) {
    vector <int64> f; f.pb(0);
    int id = 1, res = 0;
    while ((int64)id * key <= b) {
        if (key * (int64)id >= a) f.pb(id * key);
        id++;
    }
    m = f.size();
    rep(i, m) if (check(f[i]) ) res++;
    return res;
}
bool isOk(int x) {
    if (x % K != 0) return false;
    int cnt = 0;
    while (x) {
        if (!isUse[x % 10]) return false;
        if ( x % 10 == 0 ) cnt++;
        x /= 10;
    }
    return (cnt == 3);
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf(" %lld %lld %lld ", &K, &a, &b);
	rep(i, 10) isUse[i] = 0;
	gets(s); n = strlen(s);
	rep(i, n) isUse[s[i] - '0'] = 1;
	found = false;
	if ( isUse[0] == 0 ) {
	    isUse[0] = 1;
	    found = true;
	}
	//cout<<solve(a - 1)<<endl;
	//fr(i, 0, b) if (isOk(i)) cout<<i<<endl;
	if (K <= 100000) printf("%lld\n", solve(b));
	else printf("%lld\n", solveLagre(K));
	return 0;
}

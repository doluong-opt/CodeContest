/***********************************************
* Author LUONG VAN DO                        *
* Problem 1068 - Investigation 
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
#define N 100000

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
int64 dp[19][2][172][345];
int digit[19], n, k;
bool check(int x, int y) {
    return (gcd(x, y) == 1);
}
int64 run(int cur, int smaller, int m1, int m2) {
    if (cur == n) {
        return (check(m1, m2) ? 1 : 0);
    }
    int64 &res = dp[cur][smaller][m1][m2];
    if ( res != -1) return res;
    res = 0;
    int m = (smaller == 0 ? digit[cur] : 9);
    for (int d = 0; d <= m; d++) {
        int nextSmaller = smaller | (d < digit[cur] ? 1 : 0);
        res += run(cur + 1, nextSmaller, (m1 + d), m2 + d * d);
    }
    return res;
}
int64 cal(int x) {
    n = 0;
    while ( x ) {
        digit[n++] = x % 10;
        x/=10;
    }
    reverse(digit, digit + n);
    fill(dp, -1);
    return run(0, 0, 0, 0);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("exam.inp","r", stdin);
        freopen("exam.out","w", stdout);
    #endif
    int cases;
    int64 ans, a, b;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%lld %lld",&a, &b);
        ans = cal(b) - cal(a - 1);
        printf("%lld\n", ans);
    }
    return 0;
}

// =============================================================================
// Author LUONG VAN DO
// Problem 12431 - Happy 10/9 Day
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
#define N 100000

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
int64 n, b, d, M;
int64 Multi(int64 a, int64 b) {
    int64 res = 0;
    while ( b ) {
        if (b & 1) res += a;
        if (res >= M) res -= M;
        a<<=1;
        if (a >= M) a -= M;
        b>>=1;
    }
    return res;
}
struct Maxtrix {
    int64 a[3][3];
    Maxtrix(){}
    Maxtrix(int sz) {
        rep(i, sz)
            rep(j, sz) a[i][j] = 0;
    }
    Maxtrix multi(Maxtrix m) {
        Maxtrix res(2);
        rep(i, 2) rep(j, 2) rep(k, 2) {
            res.a[i][j] += Multi(a[i][k], m.a[k][j]);
            res.a[i][j] %= M;
        }
        return res;
    }
};
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    int64 ans;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%lld %lld %lld %lld", &n, &b, &d, &M);
        if (n == 1) {
            printf("Case %d: %lld\n",++caseno, d % M);
            continue;
        }
        n--;
        Maxtrix base(2), res(2);
        rep(i, 2) rep(j, 2)
            res.a[i][j] = (i == j ? 1 : 0);
        base.a[0][0] = b; base.a[0][1] = 1;
        base.a[1][0] = 0; base.a[1][1] = 1;
        while ( n ) {
           if (n & 1) res = res.multi(base);
            n>>=1;
            base = base.multi(base);
        }
        ans = Multi(res.a[0][0], d) + Multi(res.a[0][1], d);
        ans %= M;
        printf("Case %d: %lld\n", ++caseno, ans);
    }
}

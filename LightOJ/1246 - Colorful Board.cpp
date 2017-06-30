/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1246 - Colorful Board ->AC
* Algorithm count
* Time Limit 0.571s
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
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define M 100000

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
int n, m, k;
int64 c[210][210];
int64 x, y, d;
int64 power(int64 a, int64 q) {
    int64 res = 1;
    while ( q ) {
        if (q & 1) res = (res * a) % MOD;
        q>>=1;
        a = (a * a) % MOD;
    }
    return res;
}
int init() {
    c[0][0] = 1;
    for (int i=0;i<=200;i++) c[i][0] = 1;
    for (int i=1;i<=200;i++)
        for (int j=1;j<=i;j++) {
            c[i][j] = c[i-1][j-1] + c[i-1][j];
            c[i][j]%=MOD;
        }
}
int64 cal(int64 k, int64 n) {
    int64 res, f, r;
    res = power(k, n); f = 0;
    if (k > n) return res;
    for (int i=k-1;i>=1;i--) {
        if (!f) {
            r = ((c[k][i] % MOD) * (power(i, n) % MOD)) % MOD;
            r%=MOD; res-=r;
            while (res < 0) res+=MOD;
            f^=1;
        }
        else {
            r = ((c[k][i] % MOD) * (power(i, n) % MOD)) % MOD;
            r%=MOD; res+=r;
            res%=MOD;
            f^=1;
        }
    }
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    int64 ans, res, xx, yy, a, b, r1, r2;
    scanf("%d",&cases);
    init();
    while (cases--) {
        scanf("%d %d %d",&n,&m,&k);
        m++; n++;
        if (m == 1 && n == 1) {
            printf("Case %d: %d\n",++caseno, k);
            continue;
        }
        a = (m * n) >> 1;
        b = (m * n) - a;
        ans = 0;
        for (int i=1;i<=k - 1 && i<=a;i++) {
            xx = c[k][i];
            r1 = cal(i, a) % MOD;
            r2 = power(k - i, b) % MOD;
            res = ((r1 % MOD) * (r2 % MOD)) % MOD;
            res*=xx; res%=MOD;
            ans+=res;
            ans%=MOD;
        }
        printf("Case %d: %lld\n",++caseno, ans);
    }
}

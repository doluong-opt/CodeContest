/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1419 - Necklace ->AC
* Algorithm math
* Time Limit 0.012s
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
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
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
int64 x, y, d;
vector <int64> uoc;
int color[1010];
int64 power(int64 x, int64 n) {
    int64 res = 1;
    while ( n ) {
        if (n & 1) res = ((res % MOD) * (x % MOD)) % MOD;
        n>>=1;
        x = ((x % MOD) * (x % MOD)) % MOD;
    }
    return res;
}
void extended(int64 a, int64 b) {
    if (b == 0) {
        x = 1; y = 0; d = a;
        return;
    }
    extended(b, a % b);
    int64 x1 = y;
    int64 y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    uint64 n, k, ans, run, m, cnt;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%lld %lld",&n,&k); uoc.clear();
        memset(color, 0, sizeof(color));
        for (int i=2;i<=n - 1;i++)
            if (n % i == 0) uoc.pb( i );
        extended(n, MOD);
        while (x < 0) x+=MOD;
        ans = power(k, n) % MOD; cnt = 0;
        for (int i=uoc.size()-1;i>=0;i--) {
            m = uoc[i]; run = m;
            while (run <= n - 1) {
                if (!color[run]) {
                    color[run] = 1;
                    ans+=power(k, m);
                    ans%=MOD;
                    cnt++;
                }
                run+=m;
            }
        }
        ans+=(k * (n - cnt - 1)); ans%=MOD;
        ans*=x; ans%=MOD;
        printf("Case %d: %lld\n",++caseno, ans);
    }
}

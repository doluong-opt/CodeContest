/***********************************************
* Author - LUONG VAN DO                        *
* 1170 - Counting Perfect BST ->AC
* Algorithm Catalan
* Time Limit 0.101s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
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
#define INF 100000007
#define maxN 210005

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
set <uint64> S;
uint64 xx[maxN];
int64 x, y, d;
int64 fac[maxN];
int n;
void init() {
    uint64 x, ans;
    FOR(i, 2, 100000) {
        x = i; ans = i;
        while ((uint64)ans * (uint64)x<= 10000000000LL) {
            S.insert(ans * x);
            ans*=x;
        }
    }
    
    fac[0] = 1;
    FOR(i, 1, maxN)
        fac[i] = (((i % INF) * (fac[i-1] % INF)) % INF);
    n = 0;
    for (set <uint64> ::iterator it = S.begin(); it!=S.end(); it++)
        xx[++n] = (*it);
}
int f(int64 x){
    int l, r;
    l = 1; r = n;
    while (l<=r) {
        int mid = (l + r) >> 1;
        if ( xx[mid] <= x ) l = mid + 1;
        else r = mid - 1;
    }
    return r;
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
int64 modpow(int64 a, int64 n) {
    int64 ret = 1;
    while (n > 0) {
        if (n & 1) ret = ((ret  % INF) * (a % INF)) % INF;
        a = ((a % INF) * (a % INF)) % INF;
        n >>= 1;
    }
    return ret;
}
int64 c(int64 n, int64 k) {
    int64 res = ((fac[n] % INF) * modpow(fac[k], INF - 2) % INF) % INF;
    res = ((res % INF) * modpow(fac[n - k], INF - 2) % INF) % INF;
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    int64 a, b, z, ans, cnt;
    init();
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%lld %lld",&a,&b);
        cnt = 0;
        FOR(i, 1, n)
            if (xx[i]>=a && xx[i]<=b) cnt++;
        z = f( b ) - f(a - 1);
        if (!z) {
            printf("Case %d: 0\n",t);
            continue;
        }
        extended(z + 1, INF);
        while (x < 0) x+=INF;
        x%=INF;
        ans = ((x % INF) * c(2 * z, z) % INF) % INF;
        printf("Case %d: %lld\n",t, ans % INF);
    }
    return 0;
}

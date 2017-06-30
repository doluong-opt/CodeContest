/***********************************************
* Author - LUONG VAN DO                        *
* 1318 - Strange Game ->AC
* Algorithm math
* Time Limit 0.15s
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
#define INF 500000000
#define maxN 100005
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int primes[maxN + 5], sz;
vector <int> p;
void sieve(){
    FOR(i, 1, maxN - 1) primes[i] = 1;
    primes[1] = 0;
    for (int i=3;i*i<=maxN;i+=2)
        if (primes[i])
            for (int j=i*i;j<=maxN;j+=i + i) primes[j] = 0;
    p.pb(2);
    for (int i=3;i<maxN;i+=2)
        if (primes[i]) p.pb(i);
    sz = p.size();
}
int64 power(int64 k, int64 l, int64 n){
    int64 a = 1;
    while ( l ) {
        if (l & 1) a = ((a % n) * (k % n)) % n;
        k = ((k % n) * (k % n)) % n;
        l>>=1;
    }
    return a;
}
int64 C(int64 k, int64 n, int64 MOD){
    int64 xx, ans, mu;
    ans = 1;
    for (int i=0;i<sz;i++) {
        xx = p[i]; mu = 0;
        if (xx > n) break;
        for (int j=xx;j<=n;j*=xx)
            mu+=(n / j);
        for (int j=xx;j<=k;j*=xx)
            mu-=(k / j);
        for (int j=xx;j<=n-k;j*=xx)
            mu-=((n-k) / j);
        for (int i=1;i<=mu;i++)
            ans = ((ans % MOD) * (xx % MOD)) % MOD;
    }
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    sieve();
    int test;
    uint64 r1, r2, ans, xx, n, k, l, m, res;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%lld %lld %lld %lld",&n,&k,&l,&m);
        r1 = power(k, l, 2 * n);
        r2 = power(k - 1, m, 2 * n);
        ans = (r1 * r2) % (2 * n);
        xx = C(m, l, 2 * n) % (2 * n);
        res = (ans * xx) % (2 * n);
        if (m != 0) printf("Case %d: %d\n",t,res / 2 + 1);
        else
        if (res >= n) printf("Case %d: %d\n",t,res - n + 1);
        else printf("Case %d: %d\n",t,res + 1);
    }
    return 0;
}

/***********************************************
* Author - LUONG VAN DO                        *
* 1054 - Efficient Pseudo Code ->AC
* Algorithm math + sieve + euclid
* Time Limit 0.597s
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
#define INF 1000000007
#define PHI 1000000006
#define maxN 50001

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int color[maxN];
vector <int64> prime;
int64 x, y, d;
void sieve() {
    FOR(i, 1, maxN - 1) color[i] = 1;
    color[1] = 0;
    for (int i=4;i<maxN;i+=2) color[i] = 0;
    for (int i=3;i*i<maxN;i+=2)
        if (color[i])
            for (int j=i*i;j<maxN;j+=2*i) color[j] = 0;
    prime.pb( 2 );
    for (int i=3;i<maxN;i+=2)
        if (color[i])
            prime.pb(i);
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
int64 square(int64 x){
    return ((x % INF) *(x % INF)) % INF;
}
int64 power(int64 x, int64 y){
    if (y == 0) return 1;
    if (y == 1) return x;
    if (y % 2 == 0) return square(power(x, y/2) % INF) % INF;
    else return ((x % INF) * power(x, (y-1)) % INF) % INF;
}
int64 solve(int64 n, int64 m) {
    int i = 0;
    int64 cnt, ans, tmp;
    ans = 1;
    while (i < prime.size() && (int64)prime[i] * (int64)prime[i]<= n) {
        cnt = 0;
        while ( n % prime[i] == 0) {
            n/=prime[i];
            cnt++;
        }
        cnt = ((cnt % PHI) * (m % PHI)) % PHI;
        cnt++;
        cnt%=PHI;
        tmp = (power(prime[i], cnt) % INF - 1) % INF;
        while (tmp < 0) tmp+=INF;
        ans = ((ans % INF) * (tmp % INF)) % INF;
        extended(prime[i] - 1, INF);
        while (x < 0) x+=INF;
        x%=INF;
        ans = ((ans % INF) * (x % INF)) % INF;
        ++i;
    }
    if ( n > 1 ) {
        m++;
        m = m % PHI;
        tmp = (power(n, m) % INF - 1) % INF;
        while (tmp < 0) tmp+=INF;
        ans = ((ans % INF) * (tmp % INF)) % INF;
        extended(n - 1, INF);
        while (x < 0) x+=INF;
        x%=INF;
        ans = ((ans % INF) * (x % INF)) % INF;
    }
    return ans % INF;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    sieve();
    int test;
    int64 n, m;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%lld %lld",&n,&m);
        printf("Case %d: %lld\n",t,solve(n, m));
    }
    return 0;
}

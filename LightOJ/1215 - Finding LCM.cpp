/***********************************************
* Author - LUONG VAN DO                        *
* 1215 - Finding LCM ->AC
* Algorithm math
* Time Limit 0.011s
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
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 1000005
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int Free[maxN];
vector <uint64> primes;
uint64 a,b,L;
int Size;
void sieve() {
    for (int i=1;i<maxN;i++) Free[i] = 1;
    Free[1] = 0;
    for (int i=4;i<maxN;i+=2) Free[i] = 0;
    for (int i=3;i*i<maxN;i+=2)
        if (Free[i])
            for (int j=i*i;j<maxN;j+=2*i) Free[j] = 0;
    primes.pb(2);
    for (int i=3;i<maxN;i+=2)
        if (Free[i]) primes.pb(i);
    Size = primes.size();
}
uint64 Max(uint64 a, uint64 b, uint64 c){
    a = max(a,b);
    return a > c ? a : c;
}
void solve(){
    if (L % a !=0 || L % b!=0) {
        printf("impossible\n");
        return;
    }
    int ind = 0;
    int64 c = 1, cnta,cntb,cntL,res;
    while (ind < Size && (uint64)primes[ind] * (uint64)primes[ind] <= Max(a,b,L) ) {
        cnta = cntb = cntL = 0; res = 1;
        while (a % primes[ind] == 0) {
            a/=primes[ind];
            cnta++;
        }
        while (b % primes[ind] == 0) {
            b/=primes[ind];
            cntb++;
        }
        while (L % primes[ind] == 0) {
            L/=primes[ind];
            cntL++;
            res*=primes[ind];
        }
        if ( cnta > cntL || cntb > cntL ) {
            printf("impossible\n");
            return;
        }
        if (max(cnta,cntb) < cntL) c*=res;
        ind++;
    }
    if (a == 1 && b == 1) c*=L;
    printf("%lld\n",c);
}
void Read_Input() {
    int test;
    sieve();
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%lld %lld %lld",&a,&b,&L);
        printf("Case %d: ",t);
        solve();
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

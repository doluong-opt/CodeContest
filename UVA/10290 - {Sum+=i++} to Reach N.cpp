/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10290 - {Sum+=i++} to Reach N ->AC
* Algorithm Adhoc
* Time Limit 2.796s
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
#define M 30000010

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
uint64 n, sz;
uint64 prime[M + 1];
vector <uint64> p;
void sieve(){
    for (int i=1;i<=M;i++) prime[i] = 1;
    prime[1] = 0;
    for (int i=3;i*i<=M;i+=2)
        if (prime[i])
            for (int j=i*i;j<=M;j+=i + i) prime[j] = 0;
    for (int i=3;i<=M;i+=2)
        if (prime[i]) p.pb(i);
    sz = p.size();
}
uint64 run(uint64 n) {
    uint64 res = 1;
    int ind = 0, cnt;
    while (n % 2 == 0) n/=2;
    while (ind < sz && p[ind] * p[ind] <= n) {
        cnt = 0;
        while ( n % p[ind] == 0) {
            cnt++;
            n/=p[ind];
        }
        res*=(cnt + 1);
        ++ind;
    }
    if (n > 1) res*=2;
    return res - 1;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    sieve();
    uint64 Ans;
    while ( scanf("%lld",&n) != EOF){
        Ans = run( n );
        printf("%lld\n",Ans + 1);
    }
}

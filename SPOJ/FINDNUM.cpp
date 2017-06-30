/***********************************************
* Author LUONG VAN DO                        *
* Problem FINDNUM
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
#define N 1010
#define C 1000000000000000000LL
#define MAX 2000000000
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
vi prime;
int p[N], n;
uint64 cur, res;
void sieve() {
    for (int i = 1;i < N;i++) p[i] = 1;
    p[1] = 0;
    for (int i = 3;i * i < N;i+=2)
        if (p[i])
            for (int j = i * i;j < N;j+=2*i) p[j] = 0;
    prime.pb(2);
    for (int i = 3;i < N;i+=2)
        if (p[i]) prime.pb(i);
}
uint64 power(int64 x, int64 y) {
    uint64 rs = 1;
    while ( y ) {
        if (y & 1) rs*=x;
        y>>=1;
        x*=x;
    }
    return rs;
}
void backtrack(int x) {
    uint64 temp;
    if (cur > C || cur > res) return;
    if (n == 1) {
        if (res > cur) res = cur;
        return;
    }
    
    for (int i = 2;i <= n;i++)
        if (n % i == 0) {
            n/=i;
            temp = power(prime[x], i - 1);
            if (temp >= MAX) {
                n*=i;
                return;
            }            
            cur*=temp;
            backtrack(x + 1);
            cur/=temp;
            n*=i;
        }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    sieve();
    scanf("%d", &n);
    cur = 1;
    res = C;
    backtrack( 0 );
    printf("%lld\n", res);
}

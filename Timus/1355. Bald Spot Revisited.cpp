/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1355. Bald Spot Revisited ->AC
* Algorithm math
* Time Limit 0.031s
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
#define N 100010

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
int prime[N];
vector <int64> p;
void sieve() {
    for (int i=1;i<N;i++) prime[i] = 1;
    prime[1] = 0;
    for (int i=3;i*i<N;i+=2)
        if (prime[i])
            for (int j=i*i;j<N;j+=2*i) prime[j] = 0;
    p.pb(2);
    for (int i=3;i<N;i+=2)
        if (prime[i]) p.pb(i);
}
int64 solve(int64 x) {
    int ans = 0;
    for (int i=0;p[i]*p[i]<=x;i++) {
        while (x % p[i] == 0) {
            ans++;
            x/=p[i];
        }
    }
    if (x != 1) ans++;
    return ans;
}
int check(int64 b) {
    for (int i=0;p[i]*p[i]<=b;i++)
        if (b % p[i] == 0) return 0;
    return 1;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    sieve();
    int cases;
    int64 a, b;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%lld %lld",&a,&b);
        if (b % a != 0) puts("0");
        else printf("%lld\n",solve(b/a) + 1);
    }
}

/***********************************************
* Author LUONG VAN DO                        *
* Problem COUNTCBG
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
#define N 32000

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
int n, p[N];
vector <int> prime;
void sieve() {
    for (int i = 1;i < N;i++) p[i] = 1;
    p[1] = 0;
    for (int i = 3;i * i < N;i+=2)
        if (p[i])
            for (int j = i * i;j < N;j+=2 * i) p[j] = 0;
    prime.pb(2);
    for (int i = 3;i < N;i+=2)
        if (p[i]) prime.pb(i);
}
int solve(int n) {
    int cnt, res;
    res = 1; n<<=1;
    for (int i = 0; prime[i] * (int64)prime[i] <= n; i++) {
        cnt = 0;
        while ( n % prime[i] == 0 ) {
            n/=prime[i];
            cnt++;
        }
        if (prime[i] == 2) continue;
        res*=(cnt + 1);
    }
    if (n > 1) res*=2;
    return res - 1;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    sieve();
    while (scanf("%d", &n) !=EOF )
        printf("%d\n", solve(n));
}

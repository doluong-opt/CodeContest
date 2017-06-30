/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1049 - Brave Balloonists -> AC
* Algorithm number theory
* Time Limit 0.015s
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
#define N 10000

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
int inc[N];
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

void solve(int x) {
    int n = p.size();
    int cnt;
    for (int i=0;p[i]*p[i]<=x;i++) {
        cnt = 0;
        while ( x % p[i] == 0) {
            cnt++;
            x/=p[i];
        }
        inc[p[i]]+=cnt;
    }
    if (x != 1) inc[x]++;
}

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int x, ans, n;
    sieve(); ans = 1;
    for (int i=0;i<10;i++) {
        scanf("%d",&x);
        solve(x);
    }
    for (int i=2;i<N;i++)
        if (inc[i]) {
            ans*=(inc[i] + 1);
            ans%=10;
        }
    printf("%d\n",ans);
}

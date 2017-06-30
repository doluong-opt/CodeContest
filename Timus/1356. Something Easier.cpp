/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1356. Something Easier ->AC
* Algorithm number theory
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
int prime[N];
vector <int64> p;
int inc[N], mark[N];
void sieve() {
    for (int i=1;i<N;i++) {
        prime[i] = 1;
        mark[i] = 0;
    }
    prime[1] = 0;
    for (int i=3;i*i<N;i+=2)
        if (prime[i])
            for (int j=i*i;j<N;j+=2*i) prime[j] = 0;
    p.pb(2); mark[2] = 1;
    for (int i=3;i<N;i+=2)
        if (prime[i]) {
            p.pb(i);
            mark[i] = 1;
        }
}
bool isPrime(int n) {
    for (int i=0;p[i]*p[i]<=n;i++)
        if (n % p[i] == 0) return false;
    return true;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, f;
    sieve();
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d",&n);
        if (isPrime(n)) {
            printf("%d\n",n);
            continue;
        }
        f = 0;
        for (int i=0;i<p.size() && p[i] < n;i++)
            if ( mark[p[i]] && isPrime(n - p[i]) ) {
                cout<<p[i]<<" "<<n - p[i]<<endl;
                f = 1;
                break;
            }
        if (!f) {
            printf("3"); n-=3;
            for (int i=0;i<p.size() && p[i] < n;i++)
            if ( mark[p[i]] && isPrime(n - p[i]) ) {
                cout<<" "<<p[i]<<" "<<n - p[i]<<endl;
                break;
            }
        }
    }
}

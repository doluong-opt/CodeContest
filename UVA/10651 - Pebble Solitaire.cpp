/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10651 - Pebble Solitaire ->AC
* Algorithm dp bitmask
* Time Limit 0.008s
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
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define frr(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i=n - 1; i>=0; i--)
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 100000

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
char s[N];
int n, dp[1<<13];
int run(int mask) {
    int &res = dp[mask];
    if (res != -1) return res;
    res = 0;
    for (int i=0;i<n;i++) res+=(And(mask, i) > 0);
    for (int i=0;i<n-2;i++) {
        if (!And(mask, i) && And(mask, i + 1) && And(mask, i + 2) ) {
            int msk = Or(Xor(Xor(mask, i + 1), i + 2), i);
            res = min(res, run(msk));
        }
        if (And(mask, i) && And(mask, i + 1) && !And(mask, i + 2) ) {
            int msk = Or(Xor(Xor(mask, i), i + 1), i + 2);
            res = min(res, run(msk));
        }
    }
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, mask;
    scanf(" %d ",&cases);
    while (cases--) {
        gets(s); n = strlen(s);
        mask = 0;
        for (int i=0;i<n;i++)
            if (s[i] == 'o') mask = Or(mask, i);
        memset(dp, -1, sizeof(dp));
        printf("%d\n",run(mask));
    }
}

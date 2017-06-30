/***********************************************
* Author LUONG VAN DO                        *
* Problem CRUELL2
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
int d;
double a[N];
double check(double y) {
    double x = 1.0, total = 0.0;
    rep(i, d) {
        total+=a[i] * x;
        x*=y;
    }
    return total;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    double lo, hi, ans, X, pivot;
    int res;
    scanf("%d", &d);
    rep(i, d + 1) scanf("%lf", &a[i]);
    d++;
    lo = -1000000.0; hi = 1000000.0;
    pivot = check(lo);
    for (int i = 0;i < 50;i++) {
        double mid = (lo + hi) * 0.5;
        X = check(mid);
        if ( fabs(X) <= 0.0005 ) {
            ans = mid;
            break;
        }
        if (X * pivot<= 0.0) hi = mid;
        else lo = mid;
    }
    res = (int)(ans * 1000.0);
    printf("%d\n", res);
}

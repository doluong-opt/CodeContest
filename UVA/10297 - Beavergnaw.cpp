/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10297 - Beavergnaw ->AC
* Algorithm Adhoc
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
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define M 100000

#define eps 1e-9
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
double D, V, V0;
bool check(double d) {
    double x, y;
    x = (D - d) / 3.0;
    y = (PI * d * d) / 4.0 + (PI * D * D) / 4.0 + (PI * d * D) / 4.0;
    V0 = 2.0 * x * y;
    return (fabs(V0 - V) <= eps);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    double lo, hi, d;
    while ( scanf("%lf %lf",&D,&V) && (D + V)) {
        lo = 0.0; hi = D;
        for (int i=0;i<=1000;i++) {
            double mid = (lo + hi) / 2.0;
            if ( check(mid) ) {
                d = mid;
                break;
            }
            if (V0 > V) lo = mid;
            else hi = mid;
        }
        printf("%.3lf\n",d);
    }
}

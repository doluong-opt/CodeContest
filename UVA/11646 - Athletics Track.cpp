/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11646 - Athletics Track ->AC
* Algorithm chat nhi phan
* Time Limit 0.016s
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

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    double a, b, lo, hi, this_arc;
    double L, W, arc_tmp, AB, BC, r, al;
    int cases = 0;
    while ( scanf("%lf : %lf",&a,&b) != EOF){
        lo = 0.0; hi = 400.0;
        while (fabs(hi - lo) >= eps) {
            L = (hi + lo) / 2.0;
            W = (b * L) / a;
            
            arc_tmp = (400.0 - 2.0 * L) / 2.0;
            AB = 0.5 * L; BC = 0.5 * W;
            r = sqrt(AB * AB + BC * BC);
            al = 2.0 * atan(BC / AB) * 180 / PI;
            this_arc = al / 360.0 * PI * (2 * r);
            if (this_arc > arc_tmp) hi = L; else lo = L;
        }
        printf("Case %d: %.10lf %.10lf\n",++cases, L, W);
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem  10347 - Medians ->AC
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

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    double m1, m2, m3, p;
    double s, a, b, c, S;
    while ( scanf("%lf %lf %lf",&m1,&m2,&m3) != EOF){
        p = (m1 * m1 + m2 * m2 + m3 * m3);
        a = (p * 8.0) / 3.0 - 4.0 * m1 * m1;
        a/=3.0;
        if (a < 0.0) {
            printf("-1.000\n");
            continue;
        }
        b = (p * 8.0) / 3.0 - 4.0 * m2 * m2;
        b/=3.0;
        if (b < 0.0) {
            printf("-1.000\n");
            continue;
        }
        c = (p * 8.0) / 3.0 - 4.0 * m3 * m3;
        c/=3.0;
        if (c < 0.0) {
            printf("-1.000\n");
            continue;
        }
        a = sqrt(a); b = sqrt(b); c = sqrt(c);
        p = (a + b + c) / 2.0;
        S = p * (p - a) * (p - b) * (p - c);
        if (S < 0.0 || fabs(S) <= eps) {
            printf("-1.000\n");
            continue;
        }
        printf("%.3lf\n",sqrt(S));
    }
}

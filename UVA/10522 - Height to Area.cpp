/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10522 - Height to Area ->AC
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
    int cases;
    double x, y, z, p, a, b, c;
    scanf("%d",&cases); 
    while ( cases ) {
        scanf("%lf %lf %lf",&x,&y,&z);
        if (fabs(x) <= eps || fabs(y) <= eps || fabs(z) <= eps) {
            cases--;
            puts("These are invalid inputs!");
            continue;
        }
        p = (1.0 / x + 1.0 / y + 1.0 / z);
        a = (1.0 / y + 1.0 / z - 1.0 / x);
        b = (1.0 / x + 1.0 / z - 1.0 / y);
        c = (1.0 / x + 1.0 / y - 1.0 / z);
        p*=(a * b * c);
        if (p < 0.0) {
            cases--;
            puts("These are invalid inputs!");
            continue;
        }
        printf("%.3lf\n",1.0 / sqrt(p));
    }
}

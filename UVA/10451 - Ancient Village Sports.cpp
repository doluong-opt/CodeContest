/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10451 - Ancient Village Sports ->AC
* Algorithm Adhoc
* Time Limit 0.028s
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
    int n, cases = 0;
    double s, r1, r2, a, theta, x;
    while ( scanf("%d %lf",&n,&s) ){
        if (n < 3) break;
        a = s / (2.0 * n);
        theta = 360 / (2.0 * n);
        theta = (theta * PI) / 180.0;
        r1 = sqrt((2.0 * a) / (sin(theta) * cos(theta)));
        x = r1 * sin(theta);
        r2 = sqrt(r1 * r1 - x * x);
        printf("Case %d: %.5lf %.5lf\n",++cases, PI * r1 * r1 - s, s - PI * r2 * r2);
    }
}

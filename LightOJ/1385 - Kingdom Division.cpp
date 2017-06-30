/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1385 - Kingdom Division ->AC
* Algorithm adhoc
* Time Limit 0.003s
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
#define M 100000
#define eps 1e-4
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
    int cases, caseno = 0;
    double a, b, c, d1, d2, S;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%lf %lf %lf",&a,&b,&c);
        printf("Case %d: ",++caseno);
        if (fabs(a) <= eps || fabs(b) <= eps || fabs(c) <= eps) {
            puts("-1");
            continue;
        }
        if (fabs(b * b * b - a * b * c) <= eps) {
            puts("-1");
            continue;
        }
        S = (((a * b + a * c) * (b * c + a * c)) / (b * b * b - a * b * c));
        if (S < 0) puts("-1");
        else printf("%.10lf\n",S + (a * c) / b);
    }
}

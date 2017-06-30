/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10573 - Geometry Paradox ->AC
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
    int cases, r1, r2, t, k;
    double s1, s2, s0;
    char s[100];
    scanf(" %d ",&cases);
    while ( cases--) {
        gets(s);
        k = sscanf(s,"%d %d",&r1, &r2);
        if (k == 2) {
            s1 = PI * r1 * r1;
            s2 = PI * r2 * r2;
            s0 = PI * (r1 + r2) * (r1 + r2);
            printf("%.4lf\n",s0 - (s1 + s2));
        }
        else {
            s1 = r1 / 4.0;
            s2 = r1 / 4.0;
            s0 = PI * (s1 + s2) * (s1 + s2);
            s1 = PI * s1 * s1;
            s2 = PI * s2 * s2;
            printf("%.4lf\n",s0 - (s1 + s2));
        }
    }
}

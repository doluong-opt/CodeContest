/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11524 - InCircle
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
    int cases;
    double r, m1, n1, m2, n2, m3, n3;
    double a, b, c, o, k;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%lf",&r);
        scanf("%lf %lf",&m1,&n1);
        scanf("%lf %lf",&m2,&n2);
        scanf("%lf %lf",&m3,&n3);
        a = 1 + n1 / m1;
        b = n1 / m1 + n1 * n2 / m1 / m2;
        c = 1 + n1 * n2 / m1 / m2;
        o=acos((a*a+b*b-c*c)/(2.0*a*b));
        k=r*m1/n1/tan(o/2);
        double ans=a*b*sin(o)*k*k/2+1e-10;
        printf("%.4lf\n",ans);
    }
}

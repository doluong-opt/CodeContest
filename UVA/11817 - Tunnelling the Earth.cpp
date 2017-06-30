/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11817 - Tunnelling the Earth ->AC
* Algorithm getDistance
* Time Limit 0.012s
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

#define R 6371009.0
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
double getDistance(double x1, double y1, double x2, double y2) {
    x1*=PI / 180.0; x2*=PI / 180.0;
    y1*=PI / 180.0; y2*=PI / 180.0;
    double dx = x1 - x2;
    double dy = y1 - y2;
    double a = (sin(dx / 2) * sin(dx / 2) + cos(x1) * cos(x2) * sin(dy / 2) * sin(dy / 2));
    double angle = 2.0 * atan2(sqrt(a) , sqrt(1 - a));
    return angle;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases;
    double d1, d2, alpha, Ans;
    double x1, x2, y1, y2;
    scanf("%d",&cases);
    while ( cases--) {
        scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
        alpha = getDistance(x1, y1, x2, y2);
        d1 = alpha * R;
        d2 = 2.0 * R * sin(alpha / 2.0);
        printf("%.0lf\n",d1 - d2);
    }
}

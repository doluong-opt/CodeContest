/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10897 - Travelling Distance ->AC
* Algorithm getDistance
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

#define R 6371.01
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
    double angle = 2.0 * atan2(sqrt(a), sqrt(1 - a));
    return angle * R;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases;
    char d1, d2;
    double a1, b1, c1, lat1, lat2, lon1, lon2;
    double a2, b2, c2, Ans;
    scanf("%d",&cases);
    while ( cases-- ) {
        scanf(" %lf %lf %lf %c ",&a1,&b1,&c1,&d1);
        scanf(" %lf %lf %lf %c ",&a2,&b2,&c2,&d2);
        lat1 = a1 + b1 / 60.0 + c1 / 3600.0;
        if (d1 == 'S') lat1*=-1;
        lon1 = a2 + b2 / 60.0 + c2 / 3600.0;
        if (d2 == 'W') lon1*=-1;
        
        scanf(" %lf %lf %lf %c ",&a1,&b1,&c1,&d1);
        scanf(" %lf %lf %lf %c ",&a2,&b2,&c2,&d2);
        lat2 = a1 + b1 / 60.0 + c1 / 3600.0;
        if (d1 == 'S') lat2*=-1;
        lon2 = a2 + b2 / 60.0 + c2 / 3600.0;
        if (d2 == 'W') lon2*=-1;
        Ans = getDistance(lat1, lon1, lat2, lon2);
        printf("%.2lf\n",Ans);
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1249 - Euclid
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
#define INF 5000000000LL
#define M 5000000

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
struct Point{
    double x, y;
    Point(){}
    Point(double xx, double yy){
        x = xx; y = yy;
    }
};
double xh, yh, xg, yg;
double dist(Point A, Point B){
    double dx = A.x - B.x;
    double dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}
double area(Point A, Point B, Point C){
    double a = dist(A, B);
    double b = dist(B, C);
    double c = dist(C, A);
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    double S0, S1, k;
    Point A, B, C, D, E, F;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y,&D.x,&D.y,&E.x,&E.y,&F.x,&F.y)!=EOF) {  
        if(!A.x && !A.y && !B.x && !B.y && !C.x && !C.y && !D.x && !D.y && !E.x && !E.y) break;
        S0 = area(D, E, F);
        S1 = area(A, B, C);
        k = S0 / S1;
        xh = A.x + k * (C.x - A.x) / 2.0;
        yh = A.y + k * (C.y - A.y) / 2.0;
        xg = B.x + k * (C.x - A.x) / 2.0;
        yg = B.y + k * (C.y - A.y) / 2.0;
        printf("%.3lf %.3lf %.3lf %.3lf\n",xg , yg, xh, yh);
    }
}

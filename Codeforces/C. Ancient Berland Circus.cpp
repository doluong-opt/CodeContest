/***********************************************
* Author - LUONG VAN DO                        *
* Problem C. Ancient Berland Circus ->AC
* Algorithm Adhoc
* Time Limit 30ms
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
#define eps 1e-3
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
struct point{
    double x, y;
    point(){}
    point(double xx, double yy){
        x = xx; y = yy;
    }
};
void get(point *I, point a, point b, point c) {
    double dx, dy, d, x, y, u, v;
    double a1, b1, c1;
    double a2, b2, c2;
    u = b.x - a.x;
    v = b.y - a.y;
    x = (a.x + b.x) / 2.0;
    y = (a.y + b.y) / 2.0;
    a1 = u; b1 = v; c1 = -u * x - v * y;
    u = c.x - a.x;
    v = c.y - a.y;
    x = (a.x + c.x) / 2.0;
    y = (a.y + c.y) / 2.0;
    a2 = u; b2 = v; c2 = -u * x - v * y;
    dx = b1 * c2 - b2 * c1;
    dy = c1 * a2 - c2 * a1;
    d = a1 * b2 - a2 * b1;
    I->x = dx / d;
    I->y = dy / d;
}
double dist(point a, point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return dx * dx + dy * dy;
}
bool Check(double a, double b) {
    int i;
    for (i=1;i<=100;i++) {
        double x = a * (double)i;
        if ( fabs(x - b) <= eps ) return true;
        if (x > b) return false;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    point A, B, C, I;
    double R, t;
    double t1, t2, t3;
    double d1, d2, d3;
    int c1, c2, c3;
    scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
    get(&I, A, B, C);
    R = sqrt(dist(I, A));
    d1 = dist(A, B);
    d2 = dist(B, C);
    d3 = dist(C, A);
    t1 = acos((2 * R * R - d1) / (2.0 * R * R));
    t2 = acos((2 * R * R - d2) / (2.0 * R * R));
    t3 = acos((2 * R * R - d3) / (2.0 * R * R));
    for (int i=3;i<=100;i++) {
        t = (2 * PI) / i;
        if (Check(t, t1) && Check(t, t2) && Check(t, t3)) {
            printf("%.6lf\n",R * R * sin(t) / 2 * i);
            break;
        }
    }
}

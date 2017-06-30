/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10577 - Bounding box ->AC
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
struct Point{
    double x, y;
    Point(){}
    Point(double xx, double yy){
        x = xx; y = yy;
    }
};
void center_of_circle(Point *c, Point A, Point B, Point C){
    double x, y, a, b, dx, dy, d;
    double a1, b1, c1, a2, b2, c2;
    a = B.x - A.x;
    b = B.y - A.y;
    x = (A.x + B.x) / 2.0;
    y = (A.y + B.y) / 2.0;
    a1 = a; b1 = b; c1 = -a * x - b * y;
    a = C.x - A.x;
    b = C.y - A.y;
    x = (A.x + C.x) / 2.0;
    y = (A.y + C.y) / 2.0;
    a2 = a; b2 = b; c2 = -a * x - b * y;
    d = a1 * b2 - a2 * b1;
    dx = b1 * c2 - b2 * c1;
    dy = a2 * c1 - a1 * c2;
    c->x = dx / d; c->y = dy / d;
}
Point cal(double coss, double sinn, Point c, Point b){
    b.x-=c.x; b.y-=c.y;
    c.x = b.x * coss - b.y * sinn + c.x;
    c.y = b.x * sinn + b.y * coss + c.y;
    return c;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, cases = 0;
    Point A, B, C, p;
    Point c;
    double xmin, ymin, xmax, ymax, a, Ans;
    while ( scanf("%d",&n) && n){
        scanf("%lf %lf",&A.x,&A.y);
        scanf("%lf %lf",&B.x,&B.y);
        scanf("%lf %lf",&C.x,&C.y);
        center_of_circle(&c, A, B, C);
        xmin = ymin = INF; xmax = ymax = -INF;
        a = 2.0 * PI / n;
        for (int i=0;i<n;i++) {
            p = cal(cos(i * a), sin(i * a), c, A);
            if (xmin > p.x) xmin = p.x;
            if (xmax < p.x) xmax = p.x;
            if (ymin > p.y) ymin = p.y;
            if (ymax < p.y) ymax = p.y;
        }
        Ans = (xmax - xmin) * (ymax - ymin);
        printf("Polygon %d: %.3lf\n",++cases, Ans);
    }
}

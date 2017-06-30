/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11437 - Triangle Fun ->AC
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
double dist(Point A, Point B){
    double dx = A.x - B.x;
    double dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}
void find_point(Point *c, Point A, Point B){
    c->x = (2.0 * A.x + B.x) / 3.0;
    c->y = (2.0 * A.y + B.y) / 3.0;
}
void intersection(Point *c, Point A, Point B, Point C, Point D) {
    double a, b, dx, dy, d;
    double a1, a2, b1, b2, c1, c2;
    a = B.x - A.x;
    b = B.y - A.y;
    a1 = -b; b1 = a; c1 = b * A.x - a * A.y;
    a = D.x - C.x;
    b = D.y - C.y;
    a2 = -b; b2 = a; c2 = b * C.x - a * C.y;
    d = a1 * b2 - a2 * b1;
    dx = b1 * c2 - b2 * c1;
    dy = a2 * c1 - a1 * c2;
    c->x = dx / d; c->y = dy / d;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Point A, B, C, F, E, D, R, Q, P;
    int cases;
    double S, a, b, c, p;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%lf %lf %lf %lf %lf %lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
        find_point(&F, A, B);
        find_point(&E, C, A);
        find_point(&D, B, C);
        intersection(&R, A, D, F, C);
        intersection(&P, A, D, B, E);
        intersection(&Q, B, E, F, C);
        a = dist(R, P);
        b = dist(R, Q);
        c = dist(Q, P);
        p = (a + b+ c) / 2.0;
        S = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("%.0lf\n",S);
    }
}

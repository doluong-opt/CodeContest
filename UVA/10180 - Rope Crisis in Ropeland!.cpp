/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10180 - Rope Crisis in Ropeland! ->AC
* Algorithm Adhoc
* Time Limit 0.124s
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

#define eps 1e-9
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
    bool operator ==(const Point &other) const{
        return (fabs(x - other.x) <= eps && fabs(y - other.y) <= eps);
    }
};
double dist(Point A, Point B){
    double dx = A.x - B.x;
    double dy = B.y - A.y;
    return sqrt(dx * dx + dy * dy);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases;
    Point A, B;
    double r, a, b, c, d;
    double delta, h;
    double l1, l2, arc, t;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%lf %lf %lf %lf %lf",&A.x,&A.y,&B.x,&B.y,&r);
        if (A == B) {
            printf("0.000\n");
            continue;
        }
        h = (B.y - A.y) * A.x - (B.x - A.x) * A.y;
        a = (B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y);
        b = -2.0 * (B.y - A.y) * h;
        c = h * h - (B.x - A.x) * (B.x - A.x) * r * r;
        delta = b * b - 4.0 * a * c;
        if ( delta < 0.0) {
            printf("%.3lf\n",dist(A, B));
            continue;
        }
        a = A.x * A.x + A.y * A.y;
        b = B.x * B.x + B.y * B.y;
        c = ((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
        if (a + c < b || b + c < a) printf("%.3lf\n",dist(A, B));
        else {
                d = dist(A, B);
                l1 = sqrt(a - r * r);
                l2 = sqrt(b - r * r);
                a = sqrt(a); b = sqrt(b);
                t = acos((a * a + b * b - d * d) / (2.0 * a * b)) - asin(l1 / a) - asin(l2 / b);
                arc = r * t;
                printf("%.3lf\n",l1 + l2 + arc);
            }
    }
}

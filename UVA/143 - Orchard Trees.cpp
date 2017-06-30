/***********************************************
* Author - LUONG VAN DO                        *
* Problem 143 - Orchard Trees ->AC
* Algorithm  Adhoc
* Time Limit 0.716s
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

#define eps 1e-6
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
    bool operator == (const Point& other) const{
        return (fabs(x - other.x)<=eps && fabs(y - other.y) <= eps);
    }
};
double cross(Point O, Point A, Point B){
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
double dist(Point A, Point B){
    double dx = A.x - B.x;
    double dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Point A, B, C, pivot;
    double s0, s1, s2, s3, S, tem;
    int Ans;
    while ( scanf("%lf %lf",&A.x,&A.y) ){
        scanf("%lf %lf %lf %lf",&B.x,&B.y,&C.x,&C.y);
        tem = (A.x + B.x + C.x + A.y + B.y + C.y);
        if ( fabs(tem) <= eps) break;
        s0 = fabs(cross(A, B, C));
        Ans = 0;
        for (int i=1;i<=99;i++)
            for (int j=1;j<=99;j++) {
                pivot = Point(double(i), double(j));
                if (pivot == A) Ans++;
                else
                if (pivot == B) Ans++;
                else
                if (pivot == C) Ans++;
                else {
                    s1 = fabs(cross(pivot, A, B));
                    s2 = fabs(cross(pivot, B, C));
                    s3 = fabs(cross(pivot, C, A));
                    S = s1 + s2 + s3;
                    if (s0 > 0.0 && fabs(S - s0) <= eps ) Ans++;
                    else
                    if ( fabs(s1) <= eps && fabs( dist(pivot, A) + dist(pivot, B) - dist(A, B) ) <= eps ) Ans++;
                    else
                    if ( fabs(s2) <= eps && fabs( dist(pivot, B) + dist(pivot, C) - dist(B, C) ) <= eps ) Ans++;
                    else
                    if ( fabs(s3) <= eps && fabs( dist(pivot, C) + dist(pivot, A) - dist(C, A) ) <= eps ) Ans++;
                }
            }
        printf("%4d\n",Ans);
    }
}

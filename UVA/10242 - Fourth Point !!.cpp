/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10242 - Fourth Point !! ->AC
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

#define eps 1e-15
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
        return (fabs(x - other.x) <= eps && fabs(y - other.y) <= eps);
    }
};
bool equal(double x, double y){
    return (fabs(x - y)<=eps);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    double x, y;
    Point A, B, C, D;
    while ( scanf("%lf %lf",&A.x,&A.y) != EOF){
        scanf("%lf %lf",&B.x,&B.y);
        scanf("%lf %lf",&C.x,&C.y);
        scanf("%lf %lf",&D.x,&D.y);
        if (A == B) {
            x = C.x + D.x - A.x;
            y = C.y + D.y - A.y;
        }
        else
        if (B == C) {
            x = A.x + D.x - B.x;
            y = A.y + D.y - B.y;
        }
        else
        if (C == D) {
            x = A.x + B.x - C.x;
            y = A.y + B.y - C.y;
        }
        else
        if (A == D) {
            x = B.x + C.x - D.x;
            y = B.y + C.y - D.y;
        }
        else
        if (A == C) {
            x = B.x + D.x - A.x;
            y = B.y + D.y - A.y;
        }
        else
        if (B == D) {
            x = A.x + C.x - B.x;
            y = A.y + C.y - B.y;
        }
        printf("%.3lf %.3lf\n",x, y);
    }
}

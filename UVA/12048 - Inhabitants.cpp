/***********************************************
* Author - LUONG VAN DO                        *
* Problem 12048 - Inhabitants ->AC
* Algorithm Adhoc
* Time Limit 0.084s
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
#define M 100010

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
    int64 x, y;
    Point(){}
    Point(int64 xx, int64 yy){
        x = xx; y = yy;
    }
    bool operator ==(const Point& other) const{
        return (x == other.x && y == other.y);
    }
}Convex[M + 1];
Point pivot;
double dist(Point A, Point B){
    double dx = A.x - B.x;
    double dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}
int64 cross(Point O, Point A, Point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
int64 area(Point A, Point B, Point C){
    int64 s = (int64)(A.x - B.x) * (int64)(A.y + B.y);
    s += (int64)(B.x - C.x) * (int64)(B.y + C.y);
    s += (int64)(C.x - A.x) * (int64)(C.y + A.y);
    return (s > 0) ? s : -s;
}
bool is_on_seg(Point p, Point A, Point B){
    if (p == A || p == B) return true;
    return (fabs(dist(p, A) + dist(p, B) - dist(A, B)) <= eps);
}
bool isInsidePolygon(Point p, int64 l, int64 r){
    while (l < r) {
        int64 mid = (l + r) >> 1;
        int64 turn = cross(Convex[0], Convex[mid], p);
        if (turn < 0) r = mid;
        else
        if (turn > 0) l = mid + 1;
        else return is_on_seg(p, Convex[0], Convex[mid]);
    }
    if (p == Convex[0] || p == Convex[r - 1] || p == Convex[r]) return true;
    int64 s0 = area(Convex[0], Convex[r - 1], Convex[r]);
    int64 s = area(p, Convex[0], Convex[r-1]) + area(p, Convex[0], Convex[r]) + area(p, Convex[r - 1], Convex[r]);
    if (s0) return (s0 == s);
    return (is_on_seg(p, Convex[0], Convex[r - 1]) || is_on_seg(p, Convex[0], Convex[r]) || is_on_seg(p, Convex[r - 1], Convex[r]));
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, q, sz, n;
    int caseno = 0;
    int64 x, y;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%lld %lld",&Convex[i].x,&Convex[i].y);
        scanf("%d",&q);
        while (q--) {
            scanf("%lld %lld",&x,&y);
            if ( isInsidePolygon(Point(x, y), 1, n - 1)) puts("y");
            else puts("n");
        }
    }
}

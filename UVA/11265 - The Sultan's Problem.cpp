/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11265 - The Sultan's Problem ->AC
* Algorithm cutPolygon
* Time Limit 0.144s
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
struct point{
    double x, y;
    point(){}
    point(double xx, double yy){
        x = xx; y = yy;
    }
};
vector <point> p;
double area(vector <point> p, int64 n){
    double s = 0.0;
    double x1, x2, y1, y2;
    for (int i=0;i<n;i++) {
        x1 = p[i].x; x2 = p[(i + 1) % n].x;
        y1 = p[i].y; y2 = p[(i + 1) % n].y;
        s+=(x1 * y2 - x2 * y1);
    }
    return fabs(s) / 2.0;
}
double cross(point o, point a, point b){
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
point intersection_seg(point a, point b, point c, point d){
    double ux = b.x - a.x, vx = d.x - c.x;
    double uy = b.y - a.y, vy = d.y - c.y;
    double a1, b1, c1, a2, b2, c2, dx, dy, dd;
    a1 = uy; b1 = -ux; c1 = ux * a.y - uy * a.x;
    a2 = vy; b2 = -vx; c2 = vx * c.y - vy * c.x;
    dd = a1 * b2 - a2 * b1;
    dx = b1 * c2 - b2 * c1;
    dy = a2 * c1 - a1 * c2;
    return point(dx / dd, dy / dd);
}
vector <point> cutPolygon_leftside(point a, point b, vector <point> q) {
    vector <point> p;
    int n = (int)q.size();
    for (int i=0;i<n;i++) {
        double left1 = cross(a, b, q[i]);
        double left2 = cross(a, b, q[(i + 1) % n]);
        if ( left1 >= 0) p.pb( q[i] );
        if ( left1 * left2 < 0 ) p.pb(intersection_seg(q[i], q[(i + 1) % n], a, b) );
    }
    return p;
}
vector <point> cutPolygon_rightside(point a, point b, vector <point> q) {
    vector <point> p;
    int n = (int)q.size();
    for (int i=0;i<n;i++) {
        double right1 = cross(a, b, q[i]);
        double right2 = cross(a, b, q[(i + 1) % n]);
        if ( right1 <= 0) p.pb( q[i] );
        if ( right1 * right2 < 0 ) p.pb(intersection_seg(q[i], q[(i + 1) % n], a, b) );
    }
    return p;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    point o, a, b;
    vector <point> po;
    int64 n, w, h, x, y, sz;
    double S;
    int cases = 0;
    while ( scanf("%lld %lld %lld %lld %lld",&n,&w,&h,&x,&y) != EOF) {
        p.clear(); o = point((double)x, (double)y);
        p.pb(point(0.0,0.0)); 
        p.pb(point(0.0,(double)h));
        p.pb(point((double)w,(double)h));
        p.pb(point((double)w,0.0));
        for (int i=0;i<n;i++) {
            scanf("%lf %lf %lf %lf",&a.x,&a.y,&b.x,&b.y);
            if ( cross(a, b, o) > 0)
                po = cutPolygon_leftside(a, b, p);
            else
                po = cutPolygon_rightside(a, b, p);
            p = po;
        }
        S = area(p, p.size());
        printf("Case #%d: %.3lf\n",++cases, S);
    }
}

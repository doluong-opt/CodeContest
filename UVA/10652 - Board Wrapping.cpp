/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10652 - Board Wrapping ->AC
* Algorithm Graham's scan
* Time Limit 0.056s
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
vector <point> p, convex;
point pivot;
double area_polygon(vector <point> p, int n){
    double s = 0.0;
    double x1, y1, x2, y2;
    for (int i=0;i<n;i++) {
        x1 = p[i].x; x2 = p[(i+1)%n].x;
        y1 = p[i].y; y2 = p[(i+1)%n].y;
        s+=(x1 * y2 - x2 * y1);
    }
    return fabs(s) / 2.0;
}
double dist(point a, point b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
double cross(point o, point a, point b){
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
bool angleCmp(point a, point b){
    if ( fabs(cross(pivot, a, b)) <= eps) return dist(pivot, a) < dist(pivot, b);
    double dx1 = a.x - pivot.x; double dx2 = b.x - pivot.x;
    double dy1 = a.y - pivot.y; double dy2 = b.y - pivot.y;
    return atan2(dy1, dx1) < atan2(dy2, dx2);
}
vector <point> ConvexHull(vector <point> p){
    int n = (int)p.size();
    int p0 = 0;
    for (int i=1;i<n;i++)
        if (p[i].y < p[p0].y || p[i].y == p[p0].y && p[i].x > p[p0].x) p0 = i;
    swap(p[0], p[p0]);
    pivot = p[0];
    sort(++p.begin(), p.end(), angleCmp);
    stack <point> s;
    point now, pre;
    s.push(p[n-1]); s.push(p[0]);
    int i = 1;
    while (i < n) {
        now = s.top(); s.pop();
        pre = s.top(); s.push(now);
        if ( cross(pre, now, p[i]) > 0) s.push(p[i++]);
        else s.pop();
    }
    vector <point> ans;
    while (!s.empty()) {
        ans.pb(s.top());
        s.pop();
    }
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n;
    double x, y, w, h, alpha, a, l, b;
    double area, area_convex;
    scanf("%d",&cases);
    while ( cases-- ) {
        scanf("%d",&n); area = 0.0; p.clear();
        for (int i=0;i<n;i++) {
            scanf("%lf %lf %lf %lf %lf",&x,&y,&w,&h,&alpha);
            area+=(w * h);
            a = alpha * PI / 180.0;
            l = sqrt(w * w + h * h) / 2.0;
            b = a + atan(w / h);
            p.pb(point(x - l * sin(b), y - l * cos(b)));
            p.pb(point(x + l * sin(b), y + l * cos(b)));
            b = atan(w / h) - a;
            p.pb(point(x + l * sin(b), y - l * cos(b)));
            p.pb(point(x - l * sin(b), y + l * cos(b)));
        }
        convex = ConvexHull( p );
        area_convex = area_polygon(convex, convex.size());
        printf("%.1lf %%\n",(area / area_convex) * 100.0);
    }
}

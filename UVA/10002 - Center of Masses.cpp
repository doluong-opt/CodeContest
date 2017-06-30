/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10002 - Center of Masses ->AC
* Algorithm Adhoc
* Time Limit 0.304s
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
point p[101];
vector <point> convex;
point pivot;
double cross(point o, point a, point b){
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
double dist(point a, point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
bool angleCmp(point a, point b){
    if ( fabs(cross(pivot, a, b) ) <= eps ) return dist(pivot, a) < dist(pivot, b);
    double dx1 = a.x - pivot.x, dx2 = b.x - pivot.x;
    double dy1 = a.y - pivot.y, dy2 = b.y - pivot.y;
    return atan2(dy1, dx1) < atan2(dy2, dx2);
}
vector <point> ConvexHull(point p[], int n) {
    int p0 = 0;
    for (int i=1;i<n;i++)
        if (p[i].y < p[p0].y || p[i].y == p[p0].y && p[i].x > p[p0].x) p0 = i;
    swap(p[0], p[p0]);
    pivot = p[0];
    sort(p + 1, p + n, angleCmp);
    stack <point> s;
    s.push(p[n-1]); s.push(p[0]);
    point now(0.0,0.0), pre(0.0,0.0);
    int i = 1;
    while ( i < n ) {
        now = s.top(); s.pop();
        pre = s.top(); s.push(now);
        if ( cross(pre, now, p[i] ) > 0) s.push(p[i++]);
        else s.pop();
    }
    vector <point> a;
    while (!s.empty()) {
        a.pb(s.top());
        s.pop();
    }
    return a;
}
point get_center(vector <point> p, int n) {
    point ans(0.0, 0.0);
    double ss, s = 0.0;
    for (int i=1;i<n-1;i++) {
        ss = fabs(cross(p[0], p[i], p[i + 1])) / 2.0;
        ans.x += (p[0].x + p[i].x + p[i+1].x) * ss;
        ans.y += (p[0].y + p[i].y + p[i+1].y) * ss;
        s+=ss;
    }
    ans.x = ans.x / (3.0 * s);
    ans.y = ans.y / (3.0 * s);
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n;
    point I, A;
    while ( scanf("%d",&n) ) {
        if (n < 3) break;
        for (int i=0;i<n;i++) scanf("%lf %lf",&p[i].x,&p[i].y);
        convex = ConvexHull(p, n);
        I = get_center(convex, convex.size());
        printf("%.3lf %.3lf\n",I.x,I.y);
    }
}

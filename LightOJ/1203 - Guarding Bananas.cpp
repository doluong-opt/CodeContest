/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1203 - Guarding Bananas ->AC
* Algorithm convex_hull
* Time Limit 0.331s
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
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define NM 100010

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
struct point {
    int64 x, y;
    point(){}
    point(int64 xx, int64 yy){
        x = xx; y = yy;
    }
    bool operator <(const point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};
vector <point> p, convex_hull;
point pivot;
point a[NM];
int id;
char s[NM];
int64 dist(point a, point b) {
    int64 dx = a.x - b.x;
    int64 dy = a.y - b.y;
    return (dx * dx + dy * dy);
}
int64 cross(point O, point A, point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
bool angCmp(point a, point b) {
    if (!cross(pivot, a, b)) return dist(pivot, a) < dist(pivot, b);
    double dx1 = a.x - pivot.x; double dx2 = b.x - pivot.x;
    double dy1 = a.y - pivot.y; double dy2 = b.y - pivot.y;
    return atan2(dy1, dx1) < atan2(dy2, dx2);
}
vector <point> ConvexHull(vector <point> p) { 
    pivot = point(0, 0);
    int N = p.size(); int p0 = 0;
    for (int i=1;i<N;i++)
        if (p[i].y < p[p0].y || p[i].y == p[p0].y && p[i].x > p[p0].x) p0 = i;
    point temp = p[0]; p[0] = p[p0]; p[p0] = temp;
    pivot = p[0];
    sort(++p.begin(), p.end(), angCmp);
    point now = point(0, 0), pre = point(0, 0);
    stack <point> S;
    S.push(p[N - 1]); S.push(p[0]);
    int i = 1;
    while (i < N) {
        now = S.top(); S.pop();
        pre = S.top(); S.push(now);
        if ( cross(pre, now, p[i]) >= 0) S.push(p[i++]);
        else S.pop();
    }
    vector <point> ans;
    while ( !S.empty() ) {
        ans.pb(S.top());
        S.pop();
    }
    return ans;
}
double angle(point a, point b, point c) {
    double ux = b.x - a.x, uy = b.y - a.y;
    double vx = c.x - a.x, vy = c.y - a.y;
    return acos((ux * vx + uy * vy) /
                sqrt((ux * ux + uy * uy) * (vx * vx + vy * vy)));
}
int64 getInt(int n) {
    int64 v = 0, sign = 0;
    while (id < n && s[id]!=' ') {
        if (s[id] =='-') {
            sign = 1;
            ++id;
        }
        else v = v * 10 + s[id++] - '0';
    }
    if (sign) return v*-1;
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, i1, i2, i3, caseno = 0;
    int64 x, y, l;
    double res, alpha;
    gets(s); id = 0; cases = getInt(strlen(s));
    while (cases--) {
        gets(s); id = 0; n = getInt(strlen(s)); p.clear();
        for (int i=0;i<n;i++) {
            gets(s); id = 0; l = strlen(s);
            x = getInt(l); ++id;
            y = getInt(l);
            a[i] = point(x, y);
        }
        sort(a, a + n); p.pb(a[0]);
        for (int i=1;i<n;i++) {
            if (a[i].x == a[i-1].x && a[i].y == a[i-1].y) continue;
            p.pb(a[i]);
        }
        convex_hull = ConvexHull( p ); n = convex_hull.size();
        res = 500.0;
        for (int i=0;i<n-1;i++) {
            i1 = i;
            i2 = (i + 1) % (n - 1);
            i3 = (i + 2) % (n - 1);
            alpha = angle(convex_hull[i2], convex_hull[i1], convex_hull[i3]);
            if (alpha < res) res = alpha;
        }
        if (n < 3) res = 0.0;
        printf("Case %d: %.7lf\n",++caseno, (res * 180.0) / PI);
    }
}

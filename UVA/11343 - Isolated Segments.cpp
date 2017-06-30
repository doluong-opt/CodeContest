/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11343 - Isolated Segments ->AC
* Algorithm intersection
* Time Limit 0.012s
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
#define N 110

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
struct point{
    double x, y;
    point(){}
    point(double xx, double yy){
        x = xx; y = yy;
    }
};
point p1[N], p2[N];
int n;
double cross(point o, point a, point b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
double dist(point a, point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
bool intersection(point a, point b, point c, point d) {
    double s1, s2, s3, s4;
    s1 = cross(a, c, d);
    s2 = cross(b, c, d);
    s3 = cross(c, a, b);
    s4 = cross(d, a, b);
    if ( fabs(s1) <= eps && fabs(dist(a, c) + dist(a, d) - dist(c, d)) <= eps) return true;
    if ( fabs(s2) <= eps && fabs(dist(b, c) + dist(b, d) - dist(c, d)) <= eps) return true;
    if ( fabs(s3) <= eps && fabs(dist(c, a) + dist(c, b) - dist(a, b)) <= eps) return true;
    if ( fabs(s4) <= eps && fabs(dist(d, a) + dist(d, b) - dist(a, b)) <= eps) return true;
    return (s1 * s2 < 0.0 && s3 * s4 < 0.0);
}
bool isCollide(int i) {
    for (int j=0;j<n;j++) {
        if (i == j) continue;
        if ( intersection(p1[i], p2[i], p1[j], p2[j]) ) return false;
    }
    return true;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, ans;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%lf %lf %lf %lf",&p1[i].x,&p1[i].y,&p2[i].x,&p2[i].y);
        ans = 0;
        for (int i=0;i<n;i++)
            if ( isCollide(i) ) ans++;
        printf("%d\n",ans);
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10135 - Herding Frosh
* Algorithm
* Time Limit
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
#define INF 50000000000000LL
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
};
vector <Point> p, convex, s;
Point pivot;
double dist(Point a, Point b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
double cross(Point O, Point A, Point B){
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
bool angleCmp(Point A, Point B) {
    if ( fabs(cross(pivot, A, B)) <= eps) return dist(pivot, A) < dist(pivot, B);
    double dx1 = A.x - pivot.x, dx2 = B.x - pivot.x;
    double dy1 = A.y - pivot.y, dy2 = B.y - pivot.y;
    return atan2(dy1, dx1) < atan2(dy2, dx2);
}
vector <Point> ConvexHull(vector <Point> P) {
    int P0 = 0, N = (int)P.size();
    for (int i=1;i<N;i++)
        if (P[i].y < P[P0].y || P[i].y == P[P0].y && P[i].x > P[P0].x) P0 = i;
    swap(P[0], P[P0]);
    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp);
    Point now(0.0, 0.0), pre(0.0, 0.0);
    stack <Point> S;
    S.push(P[N - 1]); S.push(P[0]);
    int i = 1;
    while ( i < N ) {
        now = S.top(); S.pop();
        pre = S.top(); S.push( now );
        if ( cross(pre, now, P[i]) > 0) S.push(P[i++]);
        else S.pop();
    }
    vector <Point> Ans;
    while ( !S.empty() ) {
        Ans.pb(S.top());
        S.pop();
    }
    return Ans;
}
bool cmp(Point a, Point b) {
    if ( fabs(a.x - b.x) > eps ) return (a.x < b.x);
    else return a.y < b.y;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, blank = 0;
    double Ans, x, y, mini, d;
    Point A;
    scanf("%d",&cases);
    while ( cases-- ) {
        scanf("%d",&n); p.clear(); s.clear();
        p.pb(Point(0.0, 0.0));
        for (int i=0;i<n;i++) {
            scanf("%lf %lf",&A.x,&A.y);
            p.pb( A );
        }
        sort(p.begin(), p.end(), cmp);
        s.pb(p[0]);
        for (int i=1;i<=n;i++) {
            if ( fabs(p[i].x - p[i-1].x) <= eps && fabs(p[i].y - p[i-1].y) <= eps) continue;
            s.pb(p[i]);
        }
        convex = ConvexHull( s );
        n = convex.size();
        //for (int i=0;i<n;i++) cout<<convex[i].x<<" "<<convex[i].y<<endl;
        Ans = 0.0;
        mini = INF;
        for (int i=0;i<n;i++) {
            Ans+=dist(convex[i], convex[(i + 1) % n]);
            d = sqrt(convex[i].x * convex[i].x + convex[i].y * convex[i].y);
            if (d < mini) mini = d;
        }
        if ( blank ) puts("");
        blank = 1;
        printf("%.2lf\n",Ans + 2.0);
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 109 - SCUD Busters ->AC
* Algorithm Garham's scan
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
#define M 110

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
    int x, y;
    Point(){}
    Point(int xx, int yy){
        x = xx; y = yy;
    }
};
int n, sz;
vector < vector <Point> > Kings, Convex;
vector <Point> p;
Point pivot;
int destroy[M + 1];
int dist(Point A, Point B){
    int dx = A.x - B.x;
    int dy = A.y - B.y;
    return (dx * dx + dy * dy);
}
int cross(Point O, Point A, Point B){
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
bool angleCmp(Point A, Point B) {
    if (!cross(pivot, A, B)) return dist(pivot, A) < dist(pivot, B);
    double dx1 = A.x - pivot.x; double dx2 = B.x - pivot.x;
    double dy1 = A.y - pivot.y; double dy2 = B.y - pivot.y;
    return (atan2(dy1, dx1) < atan2(dy2, dx2));
}
vector <Point> ConvexHull(vector <Point> P) {
    pivot = Point(0, 0);
    int P0 = 0, N = (int)P.size();
    for (int i=1;i<N;i++)
        if (P[i].y < P[P0].y || P[i].y == P[P0].y && P[i].x > P[P0].x) P0 = i;
    Point temp = P[0]; P[0] = P[P0]; P[P0] = temp;
    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp);
    Point now(0, 0), pre(0, 0);
    stack <Point> S;
    S.push(P[N-1]); S.push(P[0]);
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
double area(vector <Point> P){
    int N = (int)P.size();
    double result = 0.0;
    double x1, y1, x2, y2;
    for (int i=0;i<N-1;i++) {
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
        result+=(x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0;
}
bool inside(Point p, vector <Point> P){
    int N = (int)P.size();
    for (int i=1;i<N;i++)
        if (cross(P[i-1], P[i], p) > 0) return false;
    return true;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int x, y;
    double S;
    while ( scanf("%d",&n) ) {
        if (n == -1) break;
        p.clear();
        for (int i=0;i<n;i++) {
            scanf("%d %d",&x,&y);
            p.pb(Point(x, y));
        }
        Kings.pb( p );
    }
    sz = Kings.size(); S = 0.0;
    for (int i=0;i<sz;i++) {
        Convex.pb( ConvexHull(Kings[i]) );
        destroy[i] = 0;
    }
    while ( scanf("%d %d",&x,&y) != EOF){
        for (int i=0;i<sz;i++)
            if (!destroy[i] && inside(Point(x, y), Convex[i] )) destroy[i] = 1;
    }
    for (int i=0;i<sz;i++)
        if (destroy[i]) S+=area(Convex[i]);
    printf("%.2lf\n",S);
}

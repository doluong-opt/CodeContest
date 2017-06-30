/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11096 - Nails ->AC
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
};
vector <Point> p, convex;
Point pivot;
double dist(Point A, Point B){
    double dx = A.x - B.x;
    double dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}
int64 cross(Point O, Point A, Point B){
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
        if ( cross(pre, now, P[i]) >= 0) S.push(P[i++]);
        else S.pop();
    }
    vector <Point> Ans;
    while ( !S.empty() ) {
        Ans.pb(S.top());
        S.pop();
    }
    return Ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases;
    int64 x, y, in, m;
    double s;
    scanf("%d",&cases);
    for (int t=1;t<=cases;t++) {
        scanf("%lld %lld",&in, &m); p.clear(); convex.clear();
        for (int i=0;i<m;i++) {
            scanf("%lld %lld",&x,&y);
            p.pb(Point(x, y));
        }
        if (m == 1) printf("%.5lf\n",(double)in);
        else {
            convex = ConvexHull( p );
            m = convex.size(); s = 0.0;
            for (int i=0;i<m;i++)
                s+=dist(convex[i], convex[(i+1) % m]);
            if (s > in) printf("%.5lf\n",s);
            else printf("%.5lf\n",(double)in);
        }
    }
}

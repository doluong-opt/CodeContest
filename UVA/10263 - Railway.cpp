/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10263 - Railway ->AC
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
#define MM 11000

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
}P[MM + 1];
double dist(Point A, Point B){
    double dx = A.x - B.x;
    double dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}
double distToLine(Point M, Point A, Point B, Point *c){
    double scale = (double)
    ((M.x - A.x) * (B.x - A.x) + (M.y - A.y) * (B.y - A.y)) / 
    ((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
    c->x = A.x + scale * (B.x - A.x);
    c->y = A.y + scale * (B.y - A.y);
    return dist(M, *c);
}
double distToLineSegment(Point M, Point A, Point B, Point *c){
    if ((B.x - A.x) * (M.x - A.x) + (B.y - A.y) * (M.y - A.y) < eps) {
        c->x = A.x; c->y = A.y;
        return dist(M, A);
    }
    if ((A.x - B.x) * (M.x - B.x) + (A.y - B.y) * (M.y - B.y) < eps) {
        c->x = B.x; c->y = B.y;
        return dist(M, A);
    }
    return distToLine(M, A, B, c);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Point M, c, res;
    int n, u, v;
    while ( scanf("%lf %lf",&M.x,&M.y) != EOF){
        scanf("%d",&n); n++;
        for (int i=0;i<n;i++) scanf("%lf %lf",&P[i].x,&P[i].y);
        double d = INF;
        for (int i=0;i<n;i++) {
            u = (i % n);
            v = (i + 1) % n;
            double diff = distToLineSegment(M, P[u], P[v], &c);
            if (diff < d) {
                d = diff;
                res = c;
            }
        }
        printf("%.4lf\n",res.x);
        printf("%.4lf\n",res.y);
    }
}

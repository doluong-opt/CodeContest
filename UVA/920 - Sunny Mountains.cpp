/***********************************************
* Author - LUONG VAN DO                        *
* Problem 920 - Sunny Mountains ->AC
* Algorithm Adhoc
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
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define M 100

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
    bool operator < (const Point& other) const{
        if (x != other.x) return x > other.x;
        return y < other.y;
    }
}P[M + 1];
double dist(Point A, Point B){
    double dx, dy;
    dx = A.x - B.x;
    dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n;
    scanf("%d",&cases);
    double Ans, y0, k, m, xx;
    for (int t=1;t<=cases;t++) {
        scanf("%d",&n);
        REP(i, n) scanf("%lf %lf",&P[i].x,&P[i].y);
        sort(P, P + n);
        y0 = 0; Ans = 0.0;
        for (int i=1;i<n;i++) {
            if (P[i].y <= y0) continue;
            k = (double)(P[i].y - P[i-1].y) / (double)(P[i].x - P[i-1].x);
            m = (double)P[i].y - k * (double)P[i].x;
            xx = (y0 - m) / k;
            Ans+=dist(Point(xx, y0), P[i]);
            y0 = P[i].y;
        }
        printf("%.2lf\n",Ans);
    }
}

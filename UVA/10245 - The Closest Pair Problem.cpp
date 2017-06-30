/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10245 - The Closest Pair Problem ->AC
* Algorithm Adhoc
* Time Limit 0.072s
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
    double x, y;
    Point(){}
    Point(double xx, double yy){
        x = xx; y = yy;
    }
};
Point P[M + 1];
int n;
bool cmp(Point a, Point b){
    return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
}
double cal(Point a, Point b){
    double dx, dy;
    dx = (a.x - b.x);
    dy = (a.y - b.y);
    return (dx * dx + dy * dy);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    double Ans, dist;
    while ( scanf("%d",&n) && n) {
        REP(i, n) scanf("%lf %lf",&P[i].x,&P[i].y);
        sort(P, P + n, cmp);
        Ans = INF;
        for (int i=0;i<n - 1;i++)
            for (int j=i + 1;j<min(i + 20, n);j++) {
                dist = cal(P[i], P[j]);
                if (dist < Ans) Ans = dist;
            }
        Ans = sqrt(Ans);
        if (Ans >= 10000.0) puts("INFINITY");
        else printf("%.4lf\n",Ans);
    }
}

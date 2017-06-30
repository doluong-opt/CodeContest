/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10589 - Area ->AC
* Algorithm Adhoc
* Time Limit 0.096s
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

#define eps 1e-15
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
bool inside(Point A, double a, double b, double r){
    double dx, dy, d;
    dx = A.x - a;
    dy = A.y - b;
    d = sqrt(dx * dx + dy * dy);
    return  (d < r || fabs(d - r) <= eps);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, a, Ans;
    double x, y;
    while ( scanf("%d %d",&n,&a) && (n + a)){
        Ans = 0;
        REP(i, n) {
            scanf("%lf %lf",&x,&y);
            if (inside(Point(x, y), 0, 0, (double)a))
                if (inside(Point(x, y), (double)a, 0, (double)a))
                    if (inside(Point(x, y), 0, (double)a, (double)a))
                        if (inside(Point(x, y), (double)a, (double)a, (double)a)) Ans++;
        }
        printf("%.5lf\n",(double)(Ans * a * a) / (double) n);
    }
}

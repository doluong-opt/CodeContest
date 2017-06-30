/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10060 - A hole to catch a man ->AC
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
point p[M];
double area(point p[], int n) {
    double x1, x2, y1, y2;
    double s = 0.0;
    for (int i=0;i<n;i++) {
        x1 = p[i].x; x2 = p[(i + 1) % n].x;
        y1 = p[i].y; y2 = p[(i + 1) % n].y;
        s+=(x1 * y2 - x2 * y1);
    }
    return fabs(s) / 2.0;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, Ans;
    double s, r, t;
    while (scanf("%d",&cases) && cases) {
        s = 0.0;
        while ( cases-- ) {
            scanf("%lf",&t);
            n = 0;
            scanf("%lf %lf",&p[0].x,&p[0].y);
            do{
                n++;
                scanf("%lf %lf",&p[n].x,&p[n].y);
            }while (fabs(p[n].x - p[0].x) > eps || fabs(p[n].y - p[0].y) > eps);
            ++n;
            s+=area(p, n) * t;
        }
        scanf("%lf %lf",&r,&t);
        Ans = (int)(s / (PI * r * r * t));
        printf("%d\n",Ans);
    }
}

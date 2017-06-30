/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1146 - Closest Distance ->AC
* Algorithm ternary search
* Time Limit 0.011s
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
#define M 100000
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline double min(double a, double b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct point {
    double x, y;
    point(){}
    point(double xx, double yy) {
        x = xx; y = yy;
    }
};
point A, B, C, D;
double dist(point a, point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    double leftx, rightx, lefty, righty, leftxx, rightxx, leftyy, rightyy;
    double l1, r1, l2, r2, ans, d1, d2;
    double l11, r11, l22, r22;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%lf %lf",&A.x,&A.y); scanf("%lf %lf",&B.x,&B.y);
        scanf("%lf %lf",&C.x,&C.y); scanf("%lf %lf",&D.x,&D.y);
        
        leftx = A.x; lefty = A.y;
        rightx = B.x; righty = B.y;
        
        leftxx = C.x; leftyy = C.y;
        rightxx = D.x; rightyy = D.y;
        
        ans = INF;
        for (int i=0;i<=49;i++) {
            l1 = (2 * leftx + rightx) / 3.0;
            l2 = (2 * lefty + righty) / 3.0;
            r1 = (leftx + 2 * rightx) / 3.0;
            r2 = (lefty + 2 * righty) / 3.0;
            
            l11 = (2 * leftxx + rightxx) / 3.0;
            l22 = (2 * leftyy + rightyy) / 3.0;
            r11 = (leftxx + 2 * rightxx) / 3.0;
            r22 = (leftyy + 2 * rightyy) / 3.0;
            
            d1 = dist(point(l1, l2), point(l11, l22));
            d2 = dist(point(r1, r2), point(r11, r22));
            
            ans = min(ans, min(d1, d2));
            
            if (d1 < d2) {
                rightx = r1;
                righty = r2;
                rightxx = r11;
                rightyy = r22;
            }
            else
            if (d1 > d2) {
                leftx = l1;
                lefty = l2;
                leftxx = l11;
                leftyy = l22;
            }
            else {
                leftx = l1; rightx = r1;
                lefty = l2; righty = r2;
                leftxx = l11; rightxx = r11;
                leftyy = l22; rightyy = r22;
            }
        }
        printf("Case %d: %.10lf\n",++caseno, ans);
    }
}

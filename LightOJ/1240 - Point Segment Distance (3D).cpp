/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1240 - Point Segment Distance (3D) ->AC
* Algorithm ternary sreach
* Time Limit 0.090s
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

#define eps 1e-8
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline double min(double a, double b) { return a + eps < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct point{ 
    double x, y, z;
    point(){}
    point(double xx, double yy, double zz){
        x = xx; y = yy; z = zz;
    }
};
double dist(point a, point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    double leftx, lefty, leftz, rightx, righty, rightz;
    double ans, l1, l2, l3, d1, d2, r1, r2, r3;
    point A, B, P;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%lf %lf %lf",&A.x,&A.y,&A.z);
        scanf("%lf %lf %lf",&B.x,&B.y,&B.z);
        scanf("%lf %lf %lf",&P.x,&P.y,&P.z);
        leftx = A.x; rightx = B.x;
        lefty = A.y; righty = B.y;
        leftz = A.z; rightz = B.z;
        ans = INF;
        for (int i=0;i<=50;i++) {
            l1 = (2 * leftx + rightx) / 3;
            l2 = (2 * lefty + righty) / 3;
            l3 = (2 * leftz + rightz) / 3;
            d1 = dist(P, point(l1, l2, l3));
            
            r1 = (leftx + rightx * 2) / 3;
            r2 = (lefty + righty * 2) / 3;
            r3 = (leftz + rightz * 2) / 3;
            
            d2 = dist(P, point(r1, r2, r3));
            ans = min(ans, min(d1, d2));
            if (d1 < d2) {
                rightx = r1;
                righty = r2;
                rightz = r3;
            }
            else
            if (d1 > d2) {
                leftx = l1;
                lefty = l2;
                leftz = l3;
            }
            else {
                leftx = l1;
                lefty = l2;
                leftz = l3;
                rightx = r1;
                righty = r2;
                rightz = r3;
            }
        }
        printf("Case %d: %.10lf\n",++caseno, ans);
    }
}

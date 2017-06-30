/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1346 - Aladdin and the Rocky Mountains ->AC
* Algorithm adhoc
* Time Limit 0.186s
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
#define N 20010

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
struct point {
    double x, y;
    point(){}
    point(double xx, double yy){
        x = xx; y = yy;
    }
};
point p[N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, n;
    double ans, k1, k2, m1, m2, xx, yy, x, y;
    point P;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %lf",&n,&x);
        P = point(x, 0);
        for (int i=1;i<=n;i++) scanf("%lf %lf",&p[i].x,&p[i].y);
        x = p[1].x; y = p[1].y;
        ans = 0.0;
        for (int i=2;i<=n;i++) {
            if (p[i].y <= y) continue;
            k1 = (double)(p[i].y - p[i-1].y) / (double)(p[i].x - p[i-1].x);
            m1 = p[i].y - p[i].x * k1;
            k2 = (double)(y - P.y) / (double)(x - P.x);
            m2 = P.y - P.x * k2;
            if ( fabs(k1 - k2) <= eps) continue;
            xx = (m2 - m1) / (k1 - k2);
            yy = k1 * xx + m1;
            if (xx + eps <= p[i].x && yy + eps <= p[i].y && k1 > k2) {
                ans+=sqrt((p[i].x - xx) * (p[i].x - xx) + (p[i].y - yy) * (p[i].y - yy));
                x = p[i].x;
                y = p[i].y;
            }
        }
        printf("Case %d: %.5lf\n",++caseno, ans);
    }
}

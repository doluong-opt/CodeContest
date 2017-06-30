/***********************************************
* Author - LUONG VAN DO                        *
* 1118 - Incredible Molecules ->AC
* Algorithm Adhoc
* Time Limit 0.001s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
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
#define maxN 50001
#define eps 1e-9
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
double Dist(double x1, double y1, double x2, double y2) {
    double dx, dy;
    dx = x1 - x2;
    dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}
void Read() {
    int test;
    double AB, P, S, CAD, CBD, s1, s2;
    double x1, x2, y1, y2, r1, r2, rr, ans;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2);
        rr = r1 + r2;
        AB = Dist(x1, y1, x2, y2);
        if (AB > rr || abs(AB - rr) <= eps ) {
            printf("Case %d: 0\n",t); 
            continue;
        }
        else
        if (r1 <= r2) {
            if (AB < r2 - r1 || abs(AB - r2 + r1) <= eps) {
                ans = PI * r1 * r1;
                printf("Case %d: %.10lf\n",t,ans);
                continue;
            }
        }
        else
        if (r1 > r2) {
            if (AB < r1 - r2 || abs(AB - r1 + r2) <= eps) {
                ans = PI * r2 * r2;
                printf("Case %d: %.12lf\n",t,ans);
                continue;
            }
        }
        CAD = (AB * AB + r1 * r1 - r2 * r2) / (2 * r1 * AB);
        CAD = 2 * acos(CAD);
        
        CBD = (AB * AB + r2 * r2 - r1 * r1) / (2 * r2 * AB);
        CBD = 2 * acos(CBD);
        
        s1 = CBD * r2 * r2 - r2 * r2 * sin(CBD);
        s2 = CAD * r1 * r1 - r1 * r1 * sin(CAD);
        printf("Case %d: %.12lf\n",t,(s1 + s2)/2);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

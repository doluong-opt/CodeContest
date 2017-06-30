/***********************************************
* Author - LUONG VAN DO                        *
* 1056 - Olympics ->AC
* Algorithm Binary search
* Time Limit 0.008s
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
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    double L, W, r, AB, BC, arc_tmp, this_arc, al, a, b;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%lf : %lf",&a,&b);
        double lo, hi;
        lo = 0.0; hi = 400.0;
        while ( fabs(lo - hi) > eps ) {
            L = (lo + hi) / 2.0;
            W = (b * L)  / a;
            arc_tmp = (400.0 - 2.0 * L) / 2.0;
            AB = 0.5 * L; BC = 0.5 * W;
            r = sqrt(AB * AB + BC * BC);
            
            al = 2 * atan( BC / AB ) * 180  / PI;
            this_arc = al / 360.0 * PI * (2 * r);
            if (this_arc > arc_tmp) hi = L; else lo = L;
        }
        printf("Case %d: %.10lf %.10lf\n",t, L, W);
    }
    return 0;
}

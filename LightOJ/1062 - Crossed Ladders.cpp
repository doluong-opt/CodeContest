/***********************************************
* Author - LUONG VAN DO                        *
* 1062 - Crossed Ladders ->AC
* Algorithm Binary Search
* Time Limit 0.003s
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
    double L, a, b, c, x, y;
    double dx, dy;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%lf %lf %lf",&x,&y,&c);
        double lo, hi;
        lo = 0.0; hi = x + y;
        while ( fabs(hi - lo) >= eps ) {
            L = (hi + lo) / 2.0;
            if (L > x || L > y) {
                hi = L;
                continue;
            }
            dx = sqrt(y * y - L * L);
            dy = sqrt(x * x - L * L);
            a = (c * L) / dx;
            b = (c * L) / dy;
            
            if (a + b > L) hi = L; else lo = L;
        }
        printf("Case %d: %.10lf\n",t,L);
    }
    return 0;
}

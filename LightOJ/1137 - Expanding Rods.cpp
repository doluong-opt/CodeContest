/***********************************************
* Author - LUONG VAN DO                        *
* 1137 - Expanding Rods ->AC
* Algorithm Binary Search
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
void Read() {
    int test;
    double r;
    double L, n, C, y, M;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%lf %lf %lf",&L,&n,&C);
        if (L<=eps || n<=eps || C<=eps) {
            printf("Case %d: 0.0000000000\n",t);
            continue;
        }
        M = (1 + n * C) * L;
        double lo, hi, mid;
        lo = 0; hi = PI;
        while ( true ) {
            mid = (hi + lo) / 2.0;
            y = M - ((L * mid) / sin(mid));
            if ( fabs(y) <= eps ) break;
            else if (y > 0) lo = mid;
            else hi = mid;
        }
        
        printf("Case %d: %.10lf\n",t,L * tan(mid / 2) / 2);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

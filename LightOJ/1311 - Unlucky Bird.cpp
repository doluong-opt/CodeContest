/***********************************************
* Author - LUONG VAN DO                        *
* 1311 - Unlucky Bird ->AC
* Algorithm Adhoc
* Time Limit 0.002s
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
#define eps 1e-7
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
double v1,v2,v3,a1,a2;
double max(double a, double b){
    return a > b ? a : b;
}
void Read() {
    int test;
    double x,y,d,a,b,c,deta,t1,t2;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%lf %lf %lf %lf %lf",&v1,&v2,&v3,&a1,&a2);
        x = (v1 * v1) / (2.0 * a1);
        y = (v2 * v2) / (2.0 * a2);
        d = x + y;
        t1 = v2 / a2;
        t2 = v1 / a1;
        printf("Case %d: %.9lf %.9lf\n",t,d,v3 * max(t1,t2));
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

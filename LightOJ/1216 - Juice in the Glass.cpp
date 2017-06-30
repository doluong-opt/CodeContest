/***********************************************
* Author - LUONG VAN DO                        *
* 1216 - Juice in the Glass ->AC
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

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
void Read(){
    int test;
    double volume_juice, x, y, r, r1, r2, h, p;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%lf %lf %lf %lf",&r1,&r2,&h,&p);
        r = (p * (r1 - r2)) / h;
        r+=r2;
        volume_juice =  (PI * p * ( r2 * r2 + r * r + r2 * r )) / 3.0;
        printf("Case %d: %.10lf\n",t,volume_juice);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

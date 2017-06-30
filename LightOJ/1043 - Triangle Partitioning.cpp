/***********************************************
* Author - LUONG VAN DO                        *
* 1043 - Triangle Partitioning ->AC
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
#define eps 1e-6
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
void Read() {
    int test;
    double AB, AC, BC, k, S, p, SBDEC, SADE, k1;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%lf %lf %lf %lf",&AB,&AC,&BC,&k);
        p = (AB + AC + BC) / 2.0;
        S = sqrt(p * (p - AB) * (p - AC) * (p - BC) );
        SBDEC = S / (k + 1);
        SADE = (k * SBDEC);
        k1 = sqrt(SADE / S);
        printf("Case %d: %.10lf\n",t,k1 * AB);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
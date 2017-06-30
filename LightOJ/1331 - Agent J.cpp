/***********************************************
* Author - LUONG VAN DO                        *
* 1331 - Agent J ->AC
* Algorithm Adhoc
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

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
void Read(){
    int test;
    double r1,r2,r3,g1,g2,g3;
    double a,b,c,S,P,dx,dy,dz,s1,s2,s3;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%lf %lf %lf",&r1,&r2,&r3);
        a = r1 + r2;
        b = r2 + r3;
        c = r3 + r1;
        P = (a + b + c) / 2;
        S = sqrt(P * ( P - a ) * (P - b) * (P - c) );
        dx = a * a; dy = b * b; dz = c * c;
        g1 = (dx + dz - dy) / (2 * a * c);
        g2 = (dx + dy - dz) / (2 * a * b);
        g3 = (dy + dz - dx) / (2 * b * c);
        g1 = acos(g1); g2 = acos(g2); g3 = acos(g3);
        s1 = (g1 * r1 * r1) / 2;
        s2 = (g2 * r2 * r2) / 2;
        s3 = (g3 * r3 * r3) / 2;
        S = S - (s1 + s2 + s3);
        printf("Case %d: %.10lf\n",t,S);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

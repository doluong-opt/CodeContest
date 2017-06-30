/***********************************************
* Author - LUONG VAN DO                        *
* 1297 - Largest Box ->AC
* Algorithm math
* Time Limit 0.026s
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
double max(double a, double b){
    return (a > b) ? a : b;
}
void Read(){
    int test;
    double h,w;
    double a,b,c,deta;
    double x1,x2, V1, V2, V;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%lf %lf",&h,&w);
        a = 12;
        b = -4 * (h + w);
        c = h * w;
        deta = (b * b) - (4 * a * c);
        deta = sqrt(deta);
        x1 = (-b + deta) / (2 * a);
        x2 = (-b - deta) / (2 * a);
        V1 = (h - 2 * x2) * (w - 2 * x2) * x2;
        V2 = (h - 2 * x1) * (w - 2 * x1) * x1;
        V = max(V1,V2);
        printf("Case %d: %.10lf\n",t,V);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

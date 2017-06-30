/***********************************************
* Author - LUONG VAN DO                        *
* 1178 - Trapezium ->AC
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
#define eps 1e-8
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

void Read() {
    double a, b, c, d, dx, dy, h, tmp, S;
    int test;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
        tmp = (d * d - b * b) / (a - c);
        dx = (tmp + a - c) / 2;
        h = sqrt(d * d - dx * dx);
        S = ((a + c) * h) / 2.0;
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

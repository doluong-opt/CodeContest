/***********************************************
* Author - LUONG VAN DO                        *
* 1067 - Combinations ->AC
* Algorithm math
* Time Limit 0.126s
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
#define INF 1000003
#define MAX 1000005
using namespace std;
int n, k;
int64 x, y, d;
int64 f[MAX], g[MAX];
void extendedEuclid(int a, int b) {
    if (b == 0) {
        x = 1; y = 0; d = a;
        return;        
    }
    extendedEuclid(b, a % b);
    int x1 = y;
    int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}
void init() {
    f[0] = 1;
    g[0] = 1;
    FOR(i, 1, 1000000) {
        f[i] = ((f[i-1] % INF) * i) % INF;
        extendedEuclid(f[i], INF);
        if (x < 0) x+=INF;
        g[i] = x;
    }
}
void Read_Input(){
    int test;
    int64 res;
    init();
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d %d",&n,&k);
        res = ( ((f[n] % INF) * (g[n-k] % INF)) % INF * (g[k] % INF)) % INF;
        printf("Case %d: %lld\n",t,res);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

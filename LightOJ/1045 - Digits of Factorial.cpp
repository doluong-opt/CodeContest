/***********************************************
* Author - LUONG VAN DO                        *
* 1045 - Digits of Factorial ->AC
* Algorithm math
* Time Limit 0.039s
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
#define FOR(i, a, b) for (int i=a; i<=b; i++)
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
#define oo 2.302585093
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int64 n,base;
int solve(){
    double tmp = 0.0;
    int d;
    if (n<255) {
        for (int i=2;i<=n;i++)
            tmp+=log10(i);
        d = (int)(tmp / log10(base));
        return d + 1;
    }
    tmp = (n + 0.5) * log(n + 1) - (n + 1) + 0.5 * log(2 * PI) + 1 / (12 * (n + 1) );
    tmp/=(log(2) / log10(2));
    d = (int)(tmp / log10(base));
    return d + 1;
}
void Read_Input(){
    int test;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%lld %lld",&n,&base);
        printf("Case %d: %d\n",t,solve());
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

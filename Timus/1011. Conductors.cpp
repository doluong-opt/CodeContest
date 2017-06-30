/***********************************************
* Author - LUONG VAN DO                        *
* Conductors ->AC
* Algorithm Adhoc
* Time Limit 0.171s
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

#define For(i, a, b) for (int i=a; i<=b; i++)
#define Ford(i,a,b) for (int i=a;i>=b;i--)
#define Rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 50001
#define eps 1e-9
using namespace std;
double q,p;
void Read_Input(){
    scanf("%lf %lf",&p,&q);
}
void Solve(){
    int k,j;
    double tmp;
    k = 0;
    while ( true ) {
        for (j=0;j<=k;j++) {
            tmp = (double)(double(j) / (double)k) * 100.0;
            if (tmp > p + eps && tmp + eps < q) break;
        }
        if (tmp > p + eps && tmp + eps < q) break;
        ++k;
    }
    printf("%d\n",k);
}
int main(){
    //freopen("exam.inp","r",stdin);
    //freopen("exam.out","w",stdout);
    Read_Input();
    Solve();
    return 0;
}

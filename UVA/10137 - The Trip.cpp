/***********************************************
* Author - LUONG VAN DO                        *
* 10137 - The Trip ->AC
* Algorithm Adhoc
* Time Limit 0.012s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define For(i, a, b) for (int i=a; i<=b; i++)
#define Ford(i,a,b) for (int i=a;i>=b;i--)
#define Rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 1001
using namespace std;
double total, avg;
double a[maxN];
double am, pos, res, diff;
int n;
void Solve(){
    avg = total / n;
    am = pos = 0.0;
    For(i,1,n) {
        diff = (double)(long)((a[i] - avg) * 100.0) / 100.0;
        if (diff < 0) am+=diff;
        else pos+=diff;
    }
    res = -am > pos ? -am : pos;
    printf("$%.2lf\n",res);
}
void Read_Input(){
    
    while ( scanf("%d",&n) && n){
        total = 0.0;
        For(i,1,n) {
            scanf("%lf",&a[i]);
            total+=a[i];
        }
        Solve();
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    //Write_Output();
}

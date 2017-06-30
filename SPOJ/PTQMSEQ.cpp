/***********************************************
* Author - LUONG VAN DO                        *
* PTQMSEQ ->AC
* Algorithm Adhoc
* Time Limit 6.8s
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
#define INF 1094786
#define MAX 1000000000
#define maxN 1094786
using namespace std;
int64 a[maxN], n;
int64 Fmax[maxN];
int64 Fmin[maxN];
int64 rs,sum,Min,Max;
int64 LT(){
    int64 t = 1;
    For(i,1,15) t*=10;
    return t;
}
void Read_Input(){
    sum = 0; Min = LT(); Max = -LT();
    scanf("%lld",&n);
    For(i,1,n) {
        scanf("%lld",&a[i]);
        sum+=a[i];
        Min = min(a[i],Min);
        Max = max(a[i],Max);
    }
}
void Solve(){
    Fmax[1] = Fmin[1] = a[1];
    For(i,2,n) {
        if (Fmax[i-1] > 0) Fmax[i] = Fmax[i-1] + a[i];
        else Fmax[i] = a[i];
        if (Fmin[i-1] < 0) Fmin[i] = Fmin[i-1] + a[i];
        else Fmin[i] = a[i];
    }
    rs = -LT();
    For(i,1,n) {
        rs = max(rs,Fmax[i]);
        rs = max(rs,sum-Fmin[i]);
    }
    int cnt1,cnt2;
    cnt1 = cnt2 = 0;
    For(i,1,n)
        if (a[i] > 0) cnt1++;
        else cnt2++;
    if (cnt1==n) rs = sum - Min;
    else 
        if (cnt2==n) rs = Max;
}
void Write_Output(){
    printf("%lld\n",rs);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}

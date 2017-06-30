/***********************************************
* Author - LUONG VAN DO                        *
* INSUL ->AC
* Algorithm Adhoc
* Time Limit 0.33s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <map>
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
#define maxN 100001
using namespace std;
int a[maxN],n;
int res;
void Read_Input(){
    res = 0;
    scanf("%d",&n);
    For(i,1,n){
        scanf("%d",&a[i]);
        res+=a[i];
    }
}
void Solve(){
    sort(a+1,a+1+n);
    For(i,1,n/2)
        res+=(a[n-i+1] - a[i]);
}
void Write_Output(){
    printf("%d\n",res);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}

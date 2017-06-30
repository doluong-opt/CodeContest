/***********************************************
* Author - LUONG VAN DO                        *
* AUTION ->AC
* Algorithm Adhoc
* Time Limit 0.03s
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
#define maxN 50001
using namespace std;
int res[maxN];
int m,n,ans,sl;
void Read_Input(){
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;i++)
        scanf("%d",&res[i]);
    sort(res+1,res+m+1);
}
void Solve(){
    ans = sl = 0;
    for (int i=1;i<=m;i++)
        if (res[i]*(m-i+1)>ans && (m-i+1)<=n){
            sl = res[i];
            ans = res[i]*(m-i+1);
        }
}
void Write_Output(){
    printf("%d %d\n",sl,ans);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}

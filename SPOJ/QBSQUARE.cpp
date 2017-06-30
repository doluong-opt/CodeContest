/***********************************************
* Author - LUONG VAN DO                        *
* QBSQUARE ->AC
* Algorithm DP
* Time Limit 1.88s
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
int n,m,rs;
int a[maxN][maxN];
int ans[maxN][maxN];
void Read_Input(){
    scanf("%d %d",&m,&n);
    For(i,1,m)
        For(j,1,n)
            scanf("%d",&a[i][j]);
            
    For(i,1,m) a[i][0] = -1;
    For(j,1,n) a[0][j] = -1;
}
void Solve(){
    rs = -INF;
    For(i,1,m)
        For(j,1,n) {
        if (a[i][j]==a[i][j-1] && a[i][j-1]==a[i-1][j-1] && a[i-1][j-1]==a[i-1][j])
            ans[i][j] = min(ans[i][j-1], min(ans[i-1][j-1],ans[i-1][j])) + 1;
            if (rs < ans[i][j]) rs = ans[i][j];
        }
}
void Write_Output(){
    printf("%d\n",rs + 1);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}

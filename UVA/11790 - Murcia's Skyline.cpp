/***********************************************
* Author - LUONG VAN DO                        *
* 11790 - Murcia's Skyline ->AC
* Algorithm dp
* Time Limit 0.108s
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
#define For(i, a, b) for (int i=a; i<=b; i++)
#define Ford(i,a,b) for (int i=a;i>=b;i--)
#define Rep(i, n) for (int i=0; i<n; i++)
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
int n,rs1,rs2;
int h[maxN], w[maxN];
int dp[maxN];
int lis1(){
    for (int i=1;i<=n;i++) {
        dp[i] = w[i];
        for (int j=1;j<=i-1;j++)
        if ( h[i] > h[j] )
            dp[i] = max(dp[i], dp[j] + w[i]);
    }
    return *max_element(dp+1,dp+n+1);
}
int lis2(){
    memset(dp, 0, sizeof(dp));
    for (int i=1;i<=n;i++) {
        dp[i] = w[i];
        for (int j=1;j<=i-1;j++)
        if ( h[i] < h[j] )
            dp[i] = max(dp[i], dp[j] + w[i]);
    }
    return *max_element(dp+1,dp+n+1);
}
void Read_Input(){
    int test;
    scanf("%d",&test);
    for (int k=1;k<=test;k++) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&h[i]);
        for (int i=1;i<=n;i++) scanf("%d",&w[i]);
        rs1 = lis1();
        rs2 = lis2();
        if (rs1 >= rs2)
            printf("Case %d. Increasing (%d). Decreasing (%d).\n",k,rs1,rs2);
        else
            printf("Case %d. Decreasing (%d). Increasing (%d).\n",k,rs2,rs1);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

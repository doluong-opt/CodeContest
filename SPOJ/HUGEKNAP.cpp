/***********************************************
* Author - LUONG VAN DO                        *
* HUGEKNAP ->AC
* Algorithm dp
* Time Limit 3.8s
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
#define maxN 10001
using namespace std;
int w[10001], v[10001];
int f[10001][1001];
int s[10001];
int n,m,rs;
void Solve(){
    for (int i=1;i<=n;i++)
        for (int j=0;j<=m;j++)
        {
            f[i][j] = f[i-1][j];
            if (j>=w[i] && f[i][j] < f[i-1][j-w[i]] + v[i])
                f[i][j] = f[i-1][j-w[i]] + v[i];
        }
}
void Xuat(){
    int i,j,si;
    printf("%d",f[n][m]);
    i = n; j = m; si = 0;    
    while (i!=0)
    {
        if (f[i][j]!=f[i-1][j])
        {
            s[++si] = i;
            j-=w[i];
        }
        i--;
    }
    printf(" %d\n",si);
    Ford(i,si,1)
    {
        if (i < si) printf(" ");
        printf("%d",s[i]);
    }
    printf("\n");
}
void Read_Input(){
    int t;
    scanf("%d",&t);
    while (t--)
    {
        rs = -INF;
        scanf("%d %d",&n,&m);
        For(i,1,n) scanf("%d",&w[i]);
        For(i,1,n) scanf("%d",&v[i]);
        Solve();
        Xuat();
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    //Write_Output();
}

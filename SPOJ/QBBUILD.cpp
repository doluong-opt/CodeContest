/***********************************************
* Author - LUONG VAN DO                        *
* QBBUILD ->AC
* Algorithm Floyd
* Time Limit 0.09s
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
#define INF 1000000000
#define maxN 101
using namespace std;
int a[maxN][maxN];
int city[maxN],rs,n;
void Read_Input(){
    scanf("%d",&n);    
    for (int i=1;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
            a[i][j] = a[j][i] = INF;
            a[i][i] = 0;    
    }
    Rep(i,4) scanf("%d",&city[i]);
    int u,v,c;
    while ( scanf("%d %d %d",&u,&v,&c)!=EOF )
    {
        if ( a[u][v] > c)
            a[u][v] = a[v][u] = c;
    }
}
void Solve(){
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
    sort(city,city+4);
    rs = INF;
    do
    {
        for (int u=1;u<=n;u++)
            for (int v=1;v<=n;v++)
            if ( a[city[0]][u] + a[city[1]][u] + a[city[2]][v] + a[city[3]][v] + a[u][v] < rs)
                rs = a[city[0]][u] + a[city[1]][u] + a[city[2]][v] + a[city[3]][v] + a[u][v];
    } while ( next_permutation(city,city+4) );
}
void Write_Output(){
    printf("%d\n",rs);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}

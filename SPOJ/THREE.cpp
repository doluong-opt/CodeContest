/***********************************************
* Author - LUONG VAN DO                        *
* THREE ->AC
* Algorithm Floyd
* Time Limit 0.25s
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
#define maxN 101
using namespace std;
int n,m,nm;
int64 res,pos;
int a[maxN][maxN], id[maxN][maxN];
int Trace[maxN][maxN], idx[maxN];
void Read_Input(){
    int u,v,c;
    scanf("%d %d",&n,&m);
    For(i,1,n){
        For(j,1,n) a[i][j] = INF;
        a[i][i] = 0;
    }
    
    For(i,1,m)
    {
        scanf("%d %d %d",&u,&v,&c);
        if ( a[u][v] > c )
        {
            a[u][v] = a[v][u] = c;
            id[u][v] = id[v][u] = i;
        }
    }
}
void Floyd(){
    For(i,1,n)
        For(j,1,n)
            Trace[i][j] = j;
    For(k,1,n)
        For(i,1,n)
            For(j,1,n)
                if ( a[i][j] > a[i][k] + a[k][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                    Trace[i][j] = Trace[i][k];
                }
}
void Solve(){
    Floyd();
    nm = 0;
    int s,f;
    res = INF;
    For(i,1,n)
        if ( a[1][i] + a[2][i] + a[3][i] < res )
        {
            res = a[1][i] + a[2][i] + a[3][i];
            pos = i;
        }
    s = 1; f = pos;
    while ( s!=f )
    {
        idx[nm++] = id[s][Trace[s][f]];
        s = Trace[s][f];
    }
    s = 2; f = pos;
    while ( s!=f )
    {
        idx[nm++] = id[s][Trace[s][f]];
        s = Trace[s][f];
    }
    s = 3; f = pos;
    while ( s!=f )
    {
        idx[nm++] = id[s][Trace[s][f]];
        s = Trace[s][f];
    }
}
void Write_Output(){
    printf("%lld\n",res);
    printf("%d\n",nm);
    Rep(i,nm){
        if (i > 0) printf(" ");
        printf("%d",idx[i]);
    }
    printf("\n");
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}

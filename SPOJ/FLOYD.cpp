/***********************************************
* Author - LUONG VAN DO                        *
* FLOYD ->AC
* Algorithm Floyd
* Time Limit 0.12s
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
int a[maxN][maxN];
int Trace[maxN][maxN];
int n,m,k;
void Read_Input(){
    scanf("%d %d %d",&n,&m,&k);
    For(i,1,n){
        For(j,1,n) a[i][j] = INF;
        a[i][i] = 0;
    }
    Rep(i,m)
    {
        int u,v,c;
        scanf("%d %d %d",&u,&v,&c);
        a[u][v] = a[v][u] = c;
    }
}
void Floyd(){
    For(i,1,n)    
        For(j,1,n) Trace[i][j] = j;
    For(k,1,n)
        For(i,1,n)
            For(j,1,n)
                if ( a[i][j] > a[i][k] + a[k][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                    Trace[i][j] = Trace[i][k];
                }
}
void Xuat(int s, int t){
    vector <int> path;
    while (s!=t)
    {
        path.pb( s );
        s = Trace[s][t];
    }
    path.pb( t );
    printf("%d",path.size());
    Rep(i,path.size())
        printf(" %d",path[i]);
    printf("\n");
}
void Solve(){
    Floyd();
    while (k--)
    {
        int q,u,v;
        scanf("%d %d %d",&q,&u,&v);
        if (q == 0) printf("%d\n",a[u][v]);
        else Xuat(u,v);
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

/***********************************************
* Author - LUONG VAN DO                        *
* IOIBIN ->AC
* Algorithm Kruskal
* Time Limit 0.66s
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
#define maxN 50005
using namespace std;
int n;
int Lab[maxN];
int Get(int v){
    if (Lab[v] < 0) return v;
    else return Lab[v] = Get( Lab[v] );
}
void Union(int r1, int r2){
    int x = Lab[r1] + Lab[r2];
    if ( Lab[r1] > Lab[r2] )
    {
        Lab[r2] = x;
        Lab[r1] = r2;
    }
    else
    {
        Lab[r1] = x;
        Lab[r2] = r1;        
    }
}
void Read_Input(){
    int u,v,q,x,y;
    scanf("%d",&n);
    For(i,1,10000) Lab[i] = -1;
    Rep(i,n)
    {
        scanf("%d %d %d",&u,&v,&q);
        if (q == 1)
        {
            x = Get( u ) ; y = Get( v );
            if (x!=y) Union(x,y);
        }
        else
        {
            x = Get( u );
            y = Get( v );
            if (x == y) puts("1");
            else puts("0");
        }
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
   // Solve();
   // Write_Output();
}

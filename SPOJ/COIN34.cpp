/***********************************************
* Author - LUONG VAN DO                        *
* COIN34 ->AC
* Algorithm Tham Lam
* Time Limit 0.00s
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
int64 a[36],X;
int color[36];
void Init(){
    a[1] = 2; a[2] = 3; a[3] = 5;
    For(i,4,34) a[i] = a[i-1] + a[i-2] + a[i-3];
}
int Solve(){
    int rs;
    For(i,1,34) color[i] = 0;
    Ford(i,34,1)
    {
        if ( X>=a[i] )
        {
            color[i] = 1;
            X-=a[i];
        }
    }
    rs = -1;
    if (X==0)
    {
        if ( color[3] )
        {
            color[1] = color[2] = 1;
            color[3] = 0;
        }
        while ( true )
        {
            int i;
            for (i=4;i<=34;i++)
                if (color[i] && !color[i-1] && !color[i-2] && !color[i-3])
                {
                    color[i] = 0;
                    color[i-1] = color[i-2] = color[i-3] = 1;
                    break;                    
                }
            if (i==35) break;
        }
        For(i,1,34)
            if (color[i]) rs++;
    }    
    if (rs==-1) return rs;
    else return rs + 1;
}
void Read_Input(){
    int t,Case = 0;
    Init();
    scanf("%d",&t);
    while (t--)
    {
        scanf("%lld",&X);
        printf("Case #%d: %d\n",++Case,Solve());
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
//    Solve();
//    Write_Output();
}

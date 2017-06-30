/***********************************************
* Author - LUONG VAN DO                        *
* MDOLLS ->AC
* Algorithm Lis
* Time Limit 0.39s
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
#define maxN 20001
using namespace std;
typedef struct node
{
    int w,h;
    node(){}
    node (int ww, int hh)
    {
        w = ww; h = hh;
    }
    bool operator < (node D) const
    {
        if (h != D.h) return h > D.h;
        return w < D.w;
    }
};
int m;
node a[maxN];
void Solve(){
    sort(a,a+m);
    int mm = 0,u,v;
    int b[maxN];
    b[mm] = 0;
    for (int i=1;i<m;i++)
    {
        if (a[i].w >= a[b[mm]].w)
        {
            b[++mm] = i;
            continue;
        }
        
        for (u = 0, v = mm;u<v;)
        {
            int c = (u + v) >> 1;
            if ( a[i].w >= a[b[c]].w) u = c + 1;
            else v = c;
        }
        
        if (a[i].w <= a[b[u]].w)
        //if (u > 0)
        b[u] = i;
    }
    printf("%d\n",mm + 1);
}
void Read_Input(){
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&m);
        Rep(i,m) scanf("%d %d",&a[i].w,&a[i].h);
        Solve();
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    //Write_Output();
}

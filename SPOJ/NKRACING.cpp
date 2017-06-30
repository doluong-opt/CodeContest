/***********************************************
* Author - LUONG VAN DO                        *
* NKRACING ->AC
* Algorithm Kruskal
* Time Limit 0.87s
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
#define maxN 100001
using namespace std;
struct node
{
    int x,y,c;
    node(){}
    node(int xx, int yy, int cc)
    {
        x = xx; y = yy; c = cc;
    };
    bool operator < (node D) const
    {
        return (c > D.c);
    };
};
node edge[maxN];
int n,m,Sum,rs;
int Lab[maxN];
void Read_Input(){
    Sum = 0;
    scanf("%d %d",&n,&m);
    Rep(i,m)
    {
        int u,v,c;
        scanf("%d %d %d",&u,&v,&c);
        Sum+=c;
        edge[i] = node(u,v,c);
    }
    sort(edge,edge+m);
}
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
void Solve(){
    int Count,u,v;
    For(i,1,n) Lab[i] = -1;
    rs = Count = 0;
    Rep(i,m)
    {
        u = Get( edge[i].x ); v = Get( edge[i].y );
        if (u!=v)
        {
            Union(u,v);
            rs+=edge[i].c;
            if (++Count == n - 1) break;
        }
    }
}
void Write_Output(){
    printf("%d\n",Sum - rs);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}

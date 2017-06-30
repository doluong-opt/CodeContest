/***********************************************
* Author - LUONG VAN DO                        *
* MSE06H ->AC
* Algorithm BIT
* Time Limit 1.21s
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
struct node
{
    int x,y;
};
int n,m,nm,k;
node d[1000001];
int tree[1001];
int64 rs;
bool cmp(node c, node d){
    if (c.y!=d.y) return c.y < d.y;
    return c.x < d.x;
}
void update(int i){
    while ( i <= nm)
    {
        tree[i]++;
        i+=(i&-i);
    }
}
int64 Get(int i){
    int64 sum = 0;
    while ( i )
    {
        sum+=tree[i];
        i-=(i&-i);
    }
    return sum;
}
void Solve(int Case){
    rs = 0;
    sort(d+1,d+k+1,cmp);
    for (int i=k;i>=1;i--)
    {   
        update( d[i].x );
        rs+=Get( d[i].x - 1 );
    }
    printf("Test case %d: %lld\n",Case,rs);
}
void Read_Input(){
    int t,Case = 0;
    scanf("%d",&t);
    while (t--)
    {
        nm = 0;
        scanf("%d %d %d",&n,&m,&k);
        For(i,1,k)
        {
            scanf("%d %d",&d[i].x,&d[i].y);
            nm = max(nm,d[i].x);
        }
        For(i,1,nm) tree[i] = 0;
        Solve(++Case);
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

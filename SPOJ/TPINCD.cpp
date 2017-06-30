/***********************************************
* Author - LUONG VAN DO                        *
* TPINCD ->AC
* Algorithm dp + BIT
* Time Limit 3.32s
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
#define INF 5000000
#define maxN 10005
using namespace std;
struct node
{
    int val,id;
};
int n,k,rs,nm,nmm;
node a[maxN];
int tree[51][maxN];
int b[maxN];
bool cmp(node c, node d){
    return c.val < d.val;
}
void Read_Input(){
    scanf("%d %d",&n,&k);
    For(i,1,n)
    {
        scanf("%d",&a[i].val);
        a[i].id = i;
    }
    sort(a+1,a+1+n,cmp);
}
void update(int i, int j, int value){
    if (!j) return;
    while ( j<=nm )
    {
        tree[i][j] = (tree[i][j] + value) % INF;
        j+=(j&-j);
    }
}
int Get(int i, int j){
    if (!j) return 0;
    int sum = 0;
    while ( j )
    {
        sum = (sum + tree[i][j] ) % INF;
        j-=(j&-j);
    }
    return sum;
}
void Solve(){
    a[0].val = a[1].val - 1;
    nm = 0;
    for (int i=1;i<=n;i++)
    {
        if ( a[i].val!=a[i-1].val) nm++;
        b[a[i].id] = nm;
    }
    for (int j=1;j<=n;j++)
    {
        int inc = 1;
        for (int i=1;i<=k;i++)
        {
            //int am = Get(i,b[j]) - Get(i,b[j]-1);
            //update(i,b[j],-am);
            update(i,b[j],inc);
            inc = Get(i, b[j] - 1 );
        }
    }
}
void Write_Output(){
    printf("%d\n",Get(k,nm));
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}

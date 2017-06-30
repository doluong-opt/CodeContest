/***********************************************
* Author - LUONG VAN DO                        *
* INCVN ->AC
* Algorithm dp + BIT
* Time Limit 0.96s
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
int n,k,rs,nm;
node a[maxN];
int tree[51][maxN];
int f[51][maxN];
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
    while ( j<=nm )
    {
        tree[i][j] = (tree[i][j] + value) % INF;
        j+=(j&-j);
    }
}
int get(int i, int j){
    int sum = 0;
    while ( j )
    {
        sum = (sum + tree[i][j]) % INF;
        j-=(j&-j);
    }
    return sum;
}
void Solve(){
    a[0].val = a[1].val-1;
    nm = 0;
    for (int i=1;i<=n;i++)
    {
        if ( a[i].val > a[i-1].val) nm++;
        b[a[i].id] = nm;
        f[1][i] = 1;
    }
    for (int i=1;i<=int(n/2);i++) swap(b[i],b[n-i+1]);
    for (int j=n;j>=1;j--)
    {
        for (int i=1;i<=k;i++)
        {
            if ( i > 1 ) f[i][j] = get(i-1,b[j]-1);
            if ( i > n - j + 1) f[i][j] = 0;
            update(i,b[j],f[i][j]);
        }
    }
}
void Write_Output(){
    rs = 0;
    for (int i=1;i<=n;i++)
        rs = (rs + f[k][i]) %INF;
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

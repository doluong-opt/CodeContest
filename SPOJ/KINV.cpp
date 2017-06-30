/***********************************************
* Author - LUONG VAN DO                        *
* KINV ->AC
* Algorithm dp + BIT
* Time Limit 0.22s
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
#define INF 1000000000
#define maxN 10005
using namespace std;
int a[maxN];
int f[15][maxN];
int n,k;
int64 rs;
int tree[15][maxN];
void Read_Input(){
    scanf("%d %d",&n,&k);
    For(i,1,n) scanf("%d",&a[i]);
}
void update(int i, int j, int value){
    while ( j<=n )
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
    rs = 0;
    for (int i=1;i<=n;i++) f[1][i] = 1;
        
    for (int j=n;j>=1;j--)
        for (int i=1;i<=k;i++)
        {
            if (i > 1) f[i][j] = get(i-1,a[j]-1);
            if (i > n - j + 1) f[i][j] = 0;
            update(i,a[j],f[i][j]);
        }   
    for (int i=1;i<=n;i++)
        rs = ( rs + f[k][i] ) % INF;
}
void Write_Output(){
    /*For(i,1,k)
    {
        For(j,1,n)
        cout<<tree[i][j]<<" ";
        cout<<endl;
    }
        cout<<endl;
    For(i,1,k)
    {
        For(j,1,n)
        cout<<f[i][j]<<" ";
        cout<<endl;
    }*/
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

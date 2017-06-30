/***********************************************
* Author - LUONG VAN DO                        *
* QMAX ->AC
* Algorithm IT
* Time Limit 0.58s
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
int Sum[8*maxN];
int res,n;
void Init(){
    for (int i=1,nn = 4*n;i<=nn;i++)
        Sum[i] = 0;
}
void update(int pos, int U, int V, int val, int L, int R){
    if (V < L || U > R) return;
    if (U<=L && R<=V)
    {
        Sum[pos]+=val;
        return;
    }
    int mid = ( L + R ) >> 1;
    update(pos << 1, U, V, val, L, mid);
    update((pos << 1) + 1, U, V, val, mid + 1, R);
    
}
void Get(int pos, int U, int V, int L, int  R){
    if ( L > V || R < U) return;
    if ( U<=L && R<=V)
    {
        res = max(res,Sum[pos]);
        return;
    }
    int mid = ( L + R ) >> 1;
    Get(pos << 1, U, V, L, mid);
    Get((pos << 1) + 1, U, V, mid+1, R);
}
int Duyet(int pos, int val, int L, int R){
    if (L==R)
    {
        Sum[pos]+=val;
        return Sum[pos];
    }
    int a,b,mid = ( L + R ) >> 1;
    a = Duyet(pos << 1, Sum[pos] + val, L, mid);
    b = Duyet((pos << 1) + 1, Sum[pos] + val, mid + 1, R);
    Sum[pos] = max(a,b);
    return Sum[pos];
}
void Read_Input(){
    Init();
    int m,q;
    scanf("%d %d",&n,&m,&q);
    For(i,1,m)
    {
        int u,v,k;
        scanf("%d %d %d",&u,&v,&k);
        update(1,u,v,k,1,n);
    }
    Duyet(1,0,1,n);
//    For(i,1,16) cout<<Sum[i]<<" ";
//    cout<<endl;
    scanf("%d",&q);
    while (q--)
    {
        res = -INF;
        int u,v;
        scanf("%d %d",&u,&v);
        Get(1,u,v,1,n);
        printf("%d\n",res);
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

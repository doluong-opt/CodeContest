/***********************************************
* Author - LUONG VAN DO                        *
* QMAX2 ->AC
* Algorithm IT
* Time Limit 0.85s
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
int Max[8*maxN], Inc[8*maxN];
int n,m,res;
void Init(){
    for (int i=1, nn = n*8;i<=nn;i++){
        Max[i] = 0;
        Inc[i] = 0;
    }
}
void update(int pos, int val, int U, int V, int L, int R){
    if (V < L || U > R) return;
    if (U<=L && R<=V)
    {
        Inc[pos]+=val;
        return;
    }
    Inc[2*pos]+=Inc[pos];
    Inc[2*pos+1]+=Inc[pos];
    Inc[pos] = 0;
    int mid = ( L + R ) >> 1;
    update(pos << 1, val, U, V, L, mid);
    update((pos << 1) + 1, val, U, V, mid+1,R);
    Max[pos] = max( Max[2*pos] + Inc[2*pos], Max[2*pos+1] + Inc[2*pos+1] );
}
int Get(int pos, int U, int V, int L, int R){
    if ( V < L || U > R ) return -INF;
    if (U<=L && R<=V)
    {
        Inc[2*pos]+=Inc[pos];
        Inc[2*pos+1]+=Inc[pos];
        Inc[pos] = 0;
        Max[pos] = max(Max[2*pos] + Inc[2*pos], Max[2*pos+1] + Inc[2*pos+1]);
        return Max[pos];
    }
    int mid = ( L + R ) >> 1;
    Inc[2*pos]+=Inc[pos];
    Inc[2*pos+1]+=Inc[pos];
    Inc[pos] = 0;
    Max[pos] = max(Max[2*pos] + Inc[2*pos], Max[2*pos+1] + Inc[2*pos+1]);
    return max( Get(pos << 1, U, V, L, mid), Get((pos << 1) + 1, U, V, mid + 1, R) );
}
void Read_Input(){
    scanf("%d %d",&n,&m);
    Rep(i,m)
    {
        int u,v,q,k;
        scanf("%d %d %d",&q,&u,&v);
        if (!q)
        {
            scanf("%d",&k);
            update(1,k,u,v,1,n);
        }
        else
            printf("%d\n",Get(1,u,v,1,n));
    }
    for (int i=1;i<=4*n;i++) cout<<Inc[i]<<" ";
    cout<<endl;
}
main(){
    /*#ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif*/
    Read_Input();
    system("pause");
//    Solve();
//    Write_Output();
}

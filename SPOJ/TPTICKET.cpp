/***********************************************
* Author - LUONG VAN DO                        *
* TPTICKET ->AC
* Algorithm IT
* Time Limit 6.5s
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
#define maxN 100001
using namespace std;
int n,k,m;
int Max[8*maxN], Inc[8*maxN];
void Init(){
    int nn;
    for (int i=1,nn = 8*n;i<=nn;i++) {
        Max[i] = Inc[i] = 0;
    }
}
void update(int pos, int u, int v, int val, int l, int r){
    if (l>v || r<u) return;
    if (u<=l && r<=v) {
        Inc[pos]+=val;
        return;
    }
    Inc[2*pos]+=Inc[pos];
    Inc[2*pos+1]+=Inc[pos];
    Inc[pos] = 0;
    int mid = ( l + r) >> 1;
    update(2*pos, u, v, val, l, mid);
    update(2*pos+1, u, v, val, mid+1, r);
    Max[pos] = max(Max[2*pos] + Inc[2*pos], Max[2*pos+1]+ Inc[2*pos+1]);
}
int get(int pos, int u, int v, int l, int r){
    if (l>v || r<u) return 0;
    if (u<=l && r<=v) {
        Inc[2*pos]+=Inc[pos];
        Inc[2*pos+1]+=Inc[pos];
        Inc[pos] = 0;
        Max[pos] = max(Max[2*pos] + Inc[2*pos], Max[2*pos+1] + Inc[2*pos+1]);        
        return Max[pos];
    }
    Inc[2*pos]+=Inc[pos];
    Inc[2*pos+1]+=Inc[pos];
    Inc[pos] = 0;
    Max[pos] = max(Max[2*pos] + Inc[2*pos], Max[2*pos+1] + Inc[2*pos+1]);
    int mid = ( l + r) >> 1;
    return max( get(2*pos, u, v, l, mid), get(2*pos+1, u, v, mid+1, r) );
}
void Read_Input(){
    int u,v,kk;
    Init();
    scanf("%d %d %d",&n,&k,&m);
    scanf("%d %d",&u,&v);
    if (k > 0) {
        update(1,u,v-1,1,0,n-1);
        puts("1");
    }
    else puts("0");
    For(i,2,m) {
        scanf("%d %d",&u,&v);
        kk = get(1,u,v-1,0,n-1);
        if (kk>=k) puts("0");
        else {
            update(1,u,v-1,1,0,n-1);
            puts("1");
        }
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

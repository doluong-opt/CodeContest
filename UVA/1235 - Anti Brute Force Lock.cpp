/***********************************************
* Author - LUONG VAN DO                        *
* 1235 - Anti Brute Force Lock ->AC
* Algorithm Kruskal
* Time Limit 0.224s
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
#define maxN 505
using namespace std;
typedef struct node{
    int u,v,x;
    node(){}
    node(int uu, int vv, int xx){
        u = uu; v = vv; x = xx;
    }
    bool operator < (node D) const{
        return x < D.x;
    }
};
int a[maxN];
int rs , m, n ,Min;
node edge[maxN*maxN];
int Lab[maxN];
int Get(int v){
    if (Lab[v] < 0) return v;
    else return Lab[v] = Get( Lab[v] );
}
void Union(int r1, int r2){
    int x = Lab[r1] + Lab[r2];
    if (Lab[r1] > Lab[r2]) {
        Lab[r1] = r2;
        Lab[r2] = x;
    }
    else {
        Lab[r1] = x;
        Lab[r2] = r1;
    }
}
int Calulator(int x, int y){
    int cost = 0;
    int xx, yy;
    Rep(i,4) {
        xx = (x % 10);
        yy = (y % 10);
        if (xx<=yy) cost+=min(xx-yy+10, yy-xx);
        else cost+=min(yy-xx+10,xx-yy);
        x/=10;
        y/=10;
    }
    return cost;
}
void Solve(){
    int u,v,value,cnt;
    rs = m = cnt = 0;
    Min = INF;
    For(i,1,n) {
        Lab[i] = -1;
        int tt = Calulator(0,a[i]);
        if (Min > tt) Min = tt;
        For(j,i+1,n) {
            value = Calulator(a[i],a[j]);
            edge[++m] = node(i,j,value);
            edge[++m] = node(j,i,value);
        }
    }
    sort(edge+1,edge+1+m);
    For(i,1,m) {
        u = Get(edge[i].u); v = Get(edge[i].v);
        if (u!=v) {
            Union(u,v);
            rs+=edge[i].x;
            if (++cnt == n-1) break;
        }
    }
}
void Write_Output(){
    printf("%d\n",rs + Min);
}
void Read_Input(){
    int t;
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        For(i,1,n) scanf("%d",&a[i]);
        Solve();
        Write_Output();
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    //Write_Output();
}

/***********************************************
* Author - LUONG VAN DO                        *
* GPMB ->AC
* Algorithm vector chi phuong
* Time Limit 3.51s
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
#define maxN 1501
using namespace std;
typedef struct point {
    int x,y,w;
    point(){}
    point(int xx, int yy)
    {
        x = xx; y = yy;        
    }
    bool operator < (point D) const
    {
        if (x!=D.x) return x < D.x;
        return y < D.y;
    }
};
typedef struct node{
    double val;
    int id;
    node(){}
    bool operator < (node D) const
    {
        return val < D.val;
    }
};
int64 rs;
point a[maxN];
node dt[maxN];
int n;
int64 Cal(int xx){
    return (xx * xx + 5);
}
void Read_Input(){
    rs = 0;
    scanf("%d",&n);
    For(i,1,n) {
        scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].w);
        rs = max(rs,Cal(a[i].w));
    }
    For(i,1,n-1)
        For(j,i+1,n)
        rs = max(rs, Cal(a[i].w) + Cal(a[j].w));
}
int frx(double x, int l, int r){
    while (l<=r){
        int mid = (l + r) >> 1;
        if (dt[mid].val<=x) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
void Call(int i){
    int xx,l,r,m;
    int64 r1,r2,r3;    
    double u,v;
    m = r1 = r2 = r3 = 0;
    r3 = Cal(a[i].w);
    For(j,i+1,n){
        u = a[j].x - a[i].x;
        v = a[j].y - a[i].y;
        if (u && v) dt[++m].val = v / u, dt[m].id = j;
        if (!u) r1+=Cal(a[j].w);
        if (!v) r2+=Cal(a[j].w);
    }
    rs = max(rs,max(r3 + r1, r3 + r2));
    sort(dt+1,dt+m+1);
    For(i,1,m) {
        l = i;
        r = frx(dt[i].val,l,m);
        if (l<=r){
            xx = r;
            r1 = r3;
            for (int j=l;j<=r;j++)
                r1+=Cal(a[dt[j].id].w);
            rs = max(rs,r1);
            i = r;            
        }
    }
}
void Solve(){
    For(i,1,n-1) Call( i );
}
void Write_Output(){
    printf("%lld\n",rs);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}

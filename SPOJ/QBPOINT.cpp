/***********************************************
* Author - LUONG VAN DO                        *
* QBPOINT ->AC
* Algorithm vector chi phuong
* Time Limit 3.05s
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
#define maxN 2001
using namespace std;
typedef struct point {
    int x, y;
    point (){}
    point (int xx, int yy){
        x = xx; y = yy;
    }
    bool operator < (point D) const
    {
        if (x!=D.x) return x < D.x;
        return y < D.y;
    }
};
point a[maxN];
double dt[maxN];
int64 rs;
int n;
void Read_Input(){    
    scanf("%d",&n);
    For(i,1,n) scanf("%d %d",&a[i].x,&a[i].y);
}
int frx(double x, int l, int r){
    while (l<=r){
        int mid = (l + r) >> 1;
        if (dt[mid]<=x) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
void Cal(int i){
    int64 xx,yy,m,l,r;
    double u,v;
    xx = 0; yy = 0; m = 0;
    For(j,i+1,n) {
        u = a[j].x - a[i].x;
        v = a[j].y - a[i].y;
        if (u && v) dt[++m] = v / u;
        if (!u) xx++;
        if (!v) yy++;
    }
    if (xx) rs+=(xx * (xx - 1) ) / 2;
    if (yy) rs+=(yy * (yy - 1) ) / 2;
    sort(dt+1,dt+1+m);
    For(i,1,m) {
        l = i;
        r = frx(dt[i],l,m);
        if (l<=r) {
            yy = r;
            xx = r - l + 1;
            rs+=(xx * (xx - 1) ) / 2;
            i = yy;
        }
    }
}
void Solve(){
    rs = 0;
    For(i,1,n-1) Cal( i );    
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

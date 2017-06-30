/***********************************************
* Author - LUONG VAN DO                        *
* MRECT1 ->AC
* Algorithm Nhi Phan
* Time Limit 17.58s
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
#define maxN 300001
using namespace std;
typedef struct point
{
    int x,y;
    point(){}
    point(int xx, int yy)
    {
        x = xx; y = yy;
    }
};
int n,q,coner;
point a[maxN];
point b[maxN];
bool cmp1(point p1, point p2){
    if (p1.x!=p2.x) return (p1.x < p2.x);
    return p1.y < p2.y;
}
bool cmp2(point p1, point p2){
    if (p1.y!=p2.y) return (p1.y < p2.y);
    return p1.x < p2.x;
}
int fly(int y, point a[], int l, int r){
    while (l<=r)
    {
        int mid = (l + r) >> 1;
        if (a[mid].y>=y) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int fry(int y, point a[], int l, int r){
    while (l<=r)
    {
        int mid = (l + r) >> 1;
        if (a[mid].y<=y) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
int flx(int x, point a[], int l, int r){
    while (l<=r)
    {
        int mid = (l + r) >> 1;
        if (a[mid].x>=x) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int frx(int x, point a[], int l, int r){
    while (l<=r)
    {
        int mid = (l + r) >> 1;
        if (a[mid].x<=x) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
int64 Canh_AB(int y1, int x1, int x2){
    int ll,rr,l,r;
    int64 rs = 0;
    l = fly(y1,b,1,n);
    r = fry(y1,b,1,n);
    if (l>=1 && l<=n && r>=1 && r<=n)
    if (l<=r)
    {
        ll = flx(x1,b,l,r);
        rr = frx(x2,b,l,r);
        if (ll>=l && ll<=r && rr>=l && rr<=r)
        {
            if (b[ll].x==x1) coner++;
            if (b[rr].x==x2) coner++;
            if (ll<=rr) rs+=(rr-ll+1);
        }
    }
    return rs;
}
int64 Canh_BC(int x2, int y1, int y2){
    int ll,rr,l,r;
    int64 rs = 0;
    l = flx(x2,a,1,n);
    r = frx(x2,a,1,n);
    if (l>=1 && l<=n && r>=1 && r<=n)
    if (l<=r)
    {
        ll = fly(y1,a,l,r);
        rr = fry(y2,a,l,r);
        if (ll>=l && ll<=r && rr>=l && rr<=r)
        {
            if (a[ll].y==y1) coner++;
            if (a[rr].y==y2) coner++;
            if (ll<=rr) rs+=(rr-ll+1);
        }
    }
    return rs;
}
int64 Canh_CD(int y2, int x1, int x2){
    int ll,rr,l,r;
    int64 rs = 0;
    l = fly(y2,b,1,n);
    r = fry(y2,b,1,n);
    if (l>=1 && l<=n && r>=1 && r<=n)
    if (l<=r)
    {
        ll = flx(x1,b,l,r);
        rr = frx(x2,b,l,r);
        if (ll>=l && ll<=r && rr>=l && rr<=r)
        {
            if (b[ll].x==x1) coner++;
            if (b[rr].x==x2) coner++;
            if (ll<=rr) rs+=(rr-ll+1);
        }
    }
    return rs;
}
int64 Canh_DA(int x1, int y1, int y2){
    int ll,rr,l,r;
    int64 rs = 0;
    l = flx(x1,a,1,n);
    r = frx(x1,a,1,n);
    if (l>=1 && l<=n && r>=1 && r<=n)
    if (l<=r)
    {
        ll = fly(y1,a,l,r);
        rr = fry(y2,a,l,r);
        if (ll>=l && ll<=r && rr>=l && rr<=r)
        {
            if (a[ll].y==y1) coner++;
            if (a[rr].y==y2) coner++;
            if (ll<=rr) rs+=(rr-ll+1);
        }
    }
    return rs;
}
void Read_Input(){
    int l,r,ll,rr;
    scanf("%d",&n);
    For(i,1,n)
    {
        scanf("%d %d",&a[i].x,&a[i].y);
        b[i] = a[i];
    }
    sort(a+1,a+1+n,cmp1);
    sort(b+1,b+1+n,cmp2);
    scanf("%d",&q);
    while (q--)
    {
        int x1,y1,x2,y2;
        int64 rs = 0;
        coner = 0;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        
        rs+=Canh_AB(y1, x1, x2);
        //cout<<rs<<endl;
        rs+=Canh_BC(x2, y1, y2);
        //cout<<rs<<endl;
        rs+=Canh_CD(y2, x1, x2);
        //cout<<rs<<endl;
        rs+=Canh_DA(x1, y1, y2);
        //cout<<rs<<endl;
        //cout<<coner<<endl;
        printf("%lld\n",rs - (coner / 2));
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

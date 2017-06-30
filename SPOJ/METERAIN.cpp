/***********************************************
* Author - LUONG VAN DO                        *
* METERAIN
* Algorithm
* Time Limit
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
#define maxN 5001
#define esp 1e-7
using namespace std;
typedef struct point {
    int x, y;
    point (){}
    point (int xx, int yy) {
        x = xx; y = yy;
    }
    bool operator == (const point& D)
    {
        return x==D.x && y==D.y;
    }
};
point a[maxN];
point b[maxN];
int n,m,nm;
int ccw(point p1, point p2, point p3) {
    int a1,a2,b1,b2,t;
    a1 = p2.x - p1.x;
    b1 = p2.y - p1.y;
    a2 = p3.x - p2.x;
    b2 = p3.y - p2.y;
    t = a1 * b2 - a2 * b1;
    if (!t) return 0;
    return (t > 0) ? -1 : 1;
}
int64 area(point p1, point p2, point p3){
    int64 s = (p1.x - p2.x) * (int64)(p1.y + p2.y);
    s+=(p2.x - p3.x) * (int64)(p2.y + p3.y);
    s+=(p3.x - p1.x) * (int64)(p3.y + p1.y);
    return (s > 0) ? s: -s;
}
bool cmp(point p1, point p2){
    return (p1.y < p2.y || (p1.y==p2.y && p1.x < p2.x) );
}
int graham(point a[], int n) {
    nm = 0;
    sort(a,a+n,cmp);
    Rep(i,n) {
        while (nm>=2 && ccw(b[nm-2],b[nm-1],a[i])<=0) --nm;
        b[nm++] = a[i];
    }
    int t = nm + 1;
    for (int i=n-1;i>=0;i--) {
        while (nm>=t && ccw(b[nm-2],b[nm-1],a[i])<=0) --nm;
        b[nm++] = a[i];
    }
    return nm;
}
double D(point p1, point p2){
    double dx,dy;
    dx = p1.x - p2.x;
    dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}
bool Is_on_seg(point p1, point p2, point p3){
    return fabs( D(p1,p3) + D(p3,p2) - D(p1,p2) < esp);
}
bool Check(point p, int l, int r){
    if ( p == a[1] ) return false;
    while (r - l > 2) {
        int mid = (l + r) >> 1;
        int turn = ccw(a[1],a[mid],p);        
            if (turn > 0) l = mid + 1;
        else
            if (turn < 0) r = mid;
        else {
            if ( p == a[mid] ) return false;
            return Is_on_seg(a[1],a[mid],p);
        }
    }
    if ( p==a[r-1] || p==a[r] ) return false;
    int64 s0 = area(a[1],a[r-1],a[r]);
    int64 aa = area(a[1],a[r-1],p);
    int64 bb = area(a[1],a[r],p);
    int64 cc = area(a[r-1],a[r],p);
    if (!aa || !bb | !cc) return false;
    return ( s0==(aa+bb+cc) );
}
void Read_Input() {
    scanf("%d",&n);
    Rep(i,n) scanf("%d %d",&a[i].x,&a[i].y);
    nm = graham(a,n);
    Rep(i,nm-1) a[i+1] = b[i];
    nm--;
    //For(i,1,nm) cout<<a[i].x<<" "<<a[i].y<<endl;
    scanf("%d",&m);
    Rep(i,m) {
        point p;
        scanf("%d %d",&p.x,&p.y);
        if (!ccw(a[1],a[2],p) || !ccw(a[1],a[nm],p) ) puts("NO");
            else {
                if ( Check(p,1,nm) ) puts("YES");
                else puts("NO");
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

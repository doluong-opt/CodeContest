/***********************************************
* Author - LUONG VAN DO                        *
* MTRIAREA ->AC
* Algorithm convel hull
* Time Limit 0.16s
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
#define maxN 50001
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
int n,nm;
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
void Read_Input() {
    while ( scanf("%d",&n) ) {
        if (n==-1) break;
        Rep(i,n) scanf("%d %d",&a[i].x,&a[i].y);
        nm = graham(a,n);
        Rep(i,nm-1) a[i+1] = b[i];
        nm--;
        int i,j,k;
        i = 1;
        j = 2;
        k = 3;        
        int64 rs = -INF;
        if (nm==3){
            rs = area(a[1],a[2],a[3]);
            printf("%.2lf\n",((double)rs)/2.0);
            continue;
        }
        else
        if (nm<3) {
            printf("0.00\n");
            continue;
        }
        while ( 1 ) {
            while ( 1 ) {
                while ( area(a[i],a[j],a[k]) <= area(a[i],a[j],a[(k % nm) + 1]) && k < nm)
                    k = (k % nm) + 1;
                if ( area(a[i],a[j],a[k]) <= area(a[i],a[(j % nm) + 1],a[k]) && j < nm) {
                    j = (j % nm) + 1;
                    continue;
                }
                else break;
            }
            int64 d = area(a[i],a[j],a[k]);
            if (rs < d ) rs = d;
            i = (i % nm) + 1;
            if (i==j) j = (j % nm) + 1;
            if (j==k) k = (k % nm) + 1;
            if (i == 1) break;
        }
        printf("%.2lf\n",((double)rs)/2.0);
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

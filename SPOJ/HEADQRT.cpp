/***********************************************
* Author - LUONG VAN DO                        *
* HEADQRT ->AC
* Algorithm Convel hull
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
#define maxN 30005
using namespace std;
struct point
{
    int64 x,y;
    bool operator == (point D) const
    {
        return x==D.x && y==D.y;
    }
};
point a[maxN], b[maxN];
point rs1[maxN], rs2[maxN];
int m1,m2,na,nb;
double res;
double Dist(point p1, point p2){
    double dx,dy;
    dx = p1.x - p2.x;
    dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);    
}
int64 ccw(point p1, point p2, point p3){
    int64 a1,b1,a2,b2,t;
    a1 = p2.x - p1.x;
    b1 = p2.y - p1.y;
    a2 = p3.x - p2.x;
    b2 = p3.y - p2.y;
    t = a1 * b2 - a2 * b1;
    if (!t) return 0;
    return (t > 0) ? -1 : 1;    
}
bool cmp(point c, point d){
    return ( c.x < d.x || (c.x==d.x && c.y < d.y ));
}
void Solve(){
    m1 = m2 = 0;
    int t1,t2;
    sort(a+1,a+1+na,cmp);
    For(i,1,na){
        while ( m1>=2  && ccw(rs1[m1-2],rs1[m1-1],a[i])<=0) --m1;
        rs1[m1] = a[i];
        m1++;
    }
    t1 = m1 + 1;
    for (int i=na-1;i>=0;i--){
        while ( m1>=t1 && ccw(rs1[m1-2],rs1[m1-1],a[i])<=0) --m1;
        rs1[m1] = a[i];
        m1++;
    }
    sort(b+1,b+1+nb,cmp);
    For(i,1,nb){
        while ( m2>=2  && ccw(rs2[m2-2],rs2[m2-1],b[i])<=0) --m2;
        rs2[m2] = b[i];
        m2++;
    }
    t2 = m2 + 1;
    for (int i=nb-1;i>=0;i--){
        while ( m2>=t2 && ccw(rs2[m2-2],rs2[m2-1],b[i])<=0) --m2;
        rs2[m2] = b[i];
        m2++;
    }
    res = 0.0;
    Rep(i,m1)
        Rep(j,m2)
        {
            double d = Dist(rs1[i],rs2[j]);
            if ( res < d ) res = d;
        }
}
void Write_Output(){
    printf("%lld\n",(int64)res);
}
void Read_Input(){
    int t,q,c;
    scanf("%d",&t);
    while (t--){
        scanf("%d",&q);
        na = nb = 0;
        Rep(i,q)
        {
            point k;
            scanf("%lld %lld %d",&k.x,&k.y,&c);
            if (c == 0) a[++na] = k;
            else b[++nb] = k;
        }
        Solve();
        Write_Output();
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
//    Solve();
//    Write_Output();
}

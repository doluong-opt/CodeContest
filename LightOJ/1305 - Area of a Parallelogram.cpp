/***********************************************
* Author - LUONG VAN DO                        *
* 1305 - Area of a Parallelogram ->AC
* Algorithm Adhoc
* Time Limit 0.003s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 50001

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int ax,ay,bx,by,cx,cy,dx,dy;
void Read(){
    int test;
    double xt, yt, H, T, AD, AB, BD, S;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d %d %d %d %d %d",&ax,&ay,&bx,&by,&cx,&cy);
        xt = (ax + cx) / 2.0;
        yt = (ay + cy) / 2.0;
        dx = (int)(2 * xt) - bx;
        dy = (int)(2 * yt) - by;
        AD = sqrt( (ax - dx) * (ax - dx) + (ay - dy) * (ay - dy) );
        AB = sqrt( (ax - bx) * (ax - bx) + (ay - by) * (ay - by) );
        BD = sqrt( (bx - dx) * (bx - dx) + (by - dy) * (by - dy) );
        T = ((AD * AD + AB * AB) - (BD * BD)) / (2 * AD * AB);
        T = sqrt(1 - T * T);
        H = T * AD;
        S = (H * AB);
        printf("Case %d: %d %d ",t,dx,dy);
        printf("%.0lf\n",S);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

/***********************************************
* Author - LUONG VAN DO                        *
* 1077 - How Many Points ->AC
* Algorithm math + euclid
* Time Limit 0.002s
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
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int64 Ax, Ay, Bx, By;
int64 xx[3], yy[3];
int64 x, y, d;
void extended(int64 a, int64 b) {
    if (b == 0) {
        x = 1; y = 0; d = a;
        return;
    }
    extended(b, a % b);
    int64 x1 = y;
    int64 y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    int64 a, b, A, B, C, k, t1, t2, l1, l2, r1, r2, l, r;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%lld %lld %lld %lld",&Ax,&Ay,&Bx,&By);
        xx[1] = min(Ax, Bx); yy[1] = min(Ay, By);
        xx[2] = max(Ax, Bx); yy[2] = max(Ay, By);
        a = Bx - Ax;
        b = By - Ay;
        A = -b;
        B = a;
        C = b * Ax - a * Ay;
        if (A == 0 && B!=0 ) {
            printf("Case %d: %lld\n",t,xx[2] - xx[1] + 1);
            continue;
        }
        if (B == 0 && A!=0 ) {
            printf("Case %d: %lld\n",t,yy[2] - yy[1] + 1);
            continue;
        }
        if (A == 0 && B == 0) {
            r1 = xx[2] - xx[1] + 1;
            r2 = yy[2] - yy[1] + 1;
            printf("Case %d: %lld\n",t,r1 * r2);
            continue;
        }
        extended(A, B);
        if ( C % d != 0) {
            printf("Case %d: 2\n",t);
            continue;
        }
        k = -(C / d);
        t1 = x * k;
        t2 = y * k;
        A /= d;
        B /= d;
        if (B > 0) {
            l1 = (int64)(ceil((double)(xx[1] - t1) / (double)B));
            r1 = (int64)(floor((double)(xx[2] - t1) / (double)B));
        }
        else {
            B*=-1;
            l1 = (int64)(ceil((double)(t1 - xx[2]) / (double)B));
            r1 = (int64)(floor((double)(t1 - xx[1]) / (double)B));
        }
        if (A > 0) {
            r2 = (int64)(floor((double)(t2 - yy[1]) / (double)A));
            l2 = (int64)(ceil((double)(t2 - yy[2]) / (double)A));
        }
        else {
            A*=-1;
            r2 = (int64)(floor((double)(yy[2] - t2) / (double)A));
            l2 = (int64)(ceil((double)(yy[1] - t2) / (double)A));
        }
        
        l = max(l1, l2);
        r = min(r1, r2);
        
        if (r>=l) printf("Case %d: %lld\n",t,r - l + 1);
        else printf("Case %d: 2\n",t);
    }
    return 0;
}

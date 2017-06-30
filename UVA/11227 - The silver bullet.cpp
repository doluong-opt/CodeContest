/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11227 - The silver bullet. ->AC
* Algorithm Adhoc
* Time Limit 0.008s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
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
#define M 100

#define eps 1e-9
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct Point{
    double x, y;
    Point(){}
    Point(double xx, double yy){
        x = xx; y = yy;
    }
    bool operator < (const Point& other) const{
        if ( fabs(x - other.x) > eps) return x < other.x;
        return y < other.y;
    }
    bool operator == (const Point& other) const{ 
        return (fabs(x - other.x) <= eps && fabs(y - other.y) <= eps);
    }
}P[M + 1];
Point A[M + 1];
double D[M + 1];
int m;
int frx(double x, int l, int r){
    while (l<=r) {
        int mid = (l + r) >> 1;
        if (D[mid]<=x) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
int cal(int u){
    int sz, xi, yi, r, rr;
    double x, y;
    sz = xi = yi = 0; r = 1;
    for (int v = u + 1; v < m; v++) {
        x = A[v].x - A[u].x;
        y = A[v].y - A[u].y;
        if (fabs(x) > eps && fabs(y) > eps) D[sz++] = y / x;
        else
        if (fabs(x) <= eps) xi++;
        else
        if (fabs(y) <= eps) yi++;
    }
    r = max(r, max(xi + 1, yi + 1));
    sort(D, D + sz);
    REP(i, sz) {
        rr = frx(D[i], i, sz - 1);
        if (i<=rr) {
            r = max(r, rr - i + 2);
            i = rr;
        }
    }
    return r;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, n, Ans;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        REP(i, n)
            scanf("%lf %lf",&P[i].x,&P[i].y);
        sort(P, P + n);
        m = 0; P[n] = Point(INF, INF);
        REP(i, n) {
            if (P[i] == P[i + 1]) continue;
            A[m++] = P[i];
        }
        Ans = 1;
        REP(i, m - 1)
            Ans = max(Ans, cal(i));
        if (Ans == 1) printf("Data set #%d contains a single gnu.\n",t);
        else printf("Data set #%d contains %d gnus, out of which a maximum of %d are aligned.\n",t,m,Ans);
    }
}

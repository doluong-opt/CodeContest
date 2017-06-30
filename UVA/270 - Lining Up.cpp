/***********************************************
* Author - LUONG VAN DO                        *
* Problem 270 - Lining Up ->AC
* Algorithm Adhoc
* Time Limit 0.164s
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
#define M 700

#define eps 1e-8
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
    int x, y;
    Point(){}
    Point(int xx, int yy){
        x = xx; y = yy;
    }
}p[M + 1];
int n;
double D[M + 1];
int frx(double x, int l, int r){
    while (l<=r) {
        int mid = (l + r) >> 1;
        if (D[mid] <= x ) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
int cal(int u){
    int xx, yy, sz, xi, yi, r, rr;
    sz = xi = yi = 0; r = 1;
    for (int v = u + 1;v < n;++v) {
        xx = p[v].x - p[u].x;
        yy = p[v].y - p[u].y;
        if (xx && yy) D[sz++] = (double)yy / (double)xx;
        else
        if (!xx) xi++;
        else
        if (!yy) yi++;
    }
    r = max(r, max(yi + 1,xi + 1));
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
    int test, Ans;
    char s[100];
    scanf(" %d ",&test);
    FOR(t, 1, test) {
        n = -1;
        while ( gets(s) && strlen(s)) {
            n++;
            sscanf(s,"%d %d",&p[n].x,&p[n].y);
        }
        n++;
        Ans = 1;
        REP(i, n - 1)
            Ans = max(Ans, cal(i));
        if (t > 1) puts("");
        printf("%d\n",Ans);
    }
}

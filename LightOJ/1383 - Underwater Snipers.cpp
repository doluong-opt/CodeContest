/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1383 - Underwater Snipers 
* Algorithm
* Time Limit
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
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define frr(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i=n - 1; i>=0; i--)
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 100000000000000000LL
#define N 10010

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
struct point{
    int64 x, y;
    point(){}
    point(int64 xx, int64 yy){
        x = xx; y = yy;
    }
    bool operator < (const point& other) const{
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};
point p[N];
int64 k, n, s, d, id;
char ss[N];
double dist(int64 x, int64 y, point a) {
    double dx = x - a.x;
    double dy = y - a.y;
    return sqrt(dx * dx + dy * dy);
}

int64 compute(point a, int64 M, int64 D) {
    double dy = (double)(M + a.y) * (double)(M + a.y);
    double dx = (double)D * (double)D - dy;
    if (dx < 0.0) return -1;
    return (int64)sqrt(dx);
}

bool isOK(int64 M) {
    int64 x, y, lx, rx, llx, rrx, cnt = 0;
    y = -M; rx = -INF;
    for (int i=0; i < n ;i++) {
        x = compute(p[i], M, d);
        if (x == -1) return false;
        llx = p[i].x - x;
        rrx = p[i].x + x;
        if (llx > rx) cnt++, lx = llx, rx = rrx;
        else lx = max(lx, llx),  rx = min(rx, rrx);
    }
    return (cnt <= s);
}
int64 getNext(int l) {
    int64 v = 0, sign = 0;
    while (id < l && ss[id] !=' ') {
        if (ss[id] == '-') {
            sign = 1;
            id++;
        }
        if (ss[id] !=' ') v = v * 10 + ss[id++] - '0';
    }
    ++id;
    if (sign) v = -v;
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, l;
    int64 ans, M, lo, hi;
    gets(ss); l = strlen(ss); id = 0; cases = getNext( l );
    while (cases--) {
        gets(ss);
        gets(ss); l = strlen(ss); id = 0;
        k = getNext(l); n = getNext(l); s = getNext(l); d = getNext(l);
        for (int i=0;i<n;i++) {
            gets(ss); l = strlen(ss); id = 0;
            p[i].x = getNext(l); p[i].y = getNext(l);
            p[i].y-=k;
        }
        sort(p, p + n);
        lo = 0; hi = d; ans = -1;
        while (lo <= hi) {
            M = (lo + hi) >> 1;
            if ( isOK(M) ) {
                ans = M;
                lo = M + 1;
            }
            else hi = M - 1;
        }
        printf("Case %d: ", ++caseno);
        if ( ans == -1 ) puts("impossible");
        else printf("%lld\n", ans);
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* 1333 - Grid Coloring ->AC
* Algorithm math
* Time Limit 0.355s
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
#define INF 1000000000
#define M 500
#define N 1000000
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct point{
    int x, y;
    point(){}
    point(int xx, int yy){
        x = xx; y = yy;
    }
    bool operator < (const point &other) const{
        if (y!=other.y) return y < other.y;
        return x < other.x;
    };
} p[M + 1] ;
int64 m, n, k, b;
int64 inc[N + 1];
int64 power(int64 x, int64 mu) {
    int64 res = 1;
    while ( mu ) {
        if (mu & 1) res = ((res % INF) * (x % INF)) % INF;
        x = ((x % INF) * (x % INF)) % INF;
        mu>>=1;
    }
    return res;
}
int frx(int x, int l, int r){
    while (l<=r) {
        int mid = (l + r) >> 1;
        if (p[mid].y<=x) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    int64 x, y, u, v;
    int64 Ans, r1, r2, i1, i2, xx;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%lld %lld %lld %lld",&m,&n,&k,&b);
        FOR(i, 1, n) inc[i] = 0;
        x = y = 0;
        REP(i, b) {
            scanf("%lld %lld",&u,&v);
            p[i] = point(u, v);
            y++;
        }
        sort(p, p + b);
        REP(i, b) {
            if (!inc[p[i].y]) x++;
            inc[p[i].y]++;
        }
        i1 = 0; x = n - x;
        while (i1 < b) {
            i2 = frx(p[i1].y, i1, b - 1);
            xx = 0;
            if (i1<=i2)
            FOR(i, i1, i2) {
                if (xx + 1!=p[i].x) x++;
                xx = p[i].x;
            }
            if (m > xx) x++;
            i1 = i2 + 1;
        }
        Ans = 1;
        y = m * n - y - x;
        r1 = power(k, x);
        r2 = power(k - 1, y);
        Ans = ((r1 % INF) * (r2 % INF)) % INF;
        printf("Case %d: %lld\n",t,Ans);
    }
    return 0;
}

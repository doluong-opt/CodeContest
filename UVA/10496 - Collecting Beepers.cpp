/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10496 - Collecting Beepers ->AC
* Algorithm dp
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
#define INF 500000000
#define N 25

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
    int x, y;
    point(){}
    point(int xx, int yy){
        x = xx; y = yy;
    }
};
point p[N];
int dp[N][1<<11], lim, n;
int dist(point a, point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}
int run(int cur, int mask) {
    if (mask == lim - 1) return dist(p[cur], p[0]);
    int &res = dp[cur][mask];
    if (res != -1) return res;
    res = INF;
    for (int i=1;i<n;i++)
        if ( !And(mask, i) )
            res = min(res, dist(p[cur], p[i]) + run(i, Or(mask, i)));
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, r, c;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d",&r,&c);
        scanf("%d %d",&p[0].x, &p[0].y);
        scanf("%d",&n); n++;
        lim = (1<<n);
        for (int i=1;i<n;i++)
            scanf("%d %d",&p[i].x,&p[i].y);
        memset(dp, -1, sizeof(dp));
        printf("The shortest path has length %d\n",run(0, 1));
    }
}

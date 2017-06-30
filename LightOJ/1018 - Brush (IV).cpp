/***********************************************
* Author LUONG VAN DO                        *
* Problem 1018 - Brush (IV)
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

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 111222333
#define N 17

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
struct point {
    int x, y;
    point(){}
    point(int xx, int yy){
        x = xx; y = yy;
    }
};
int dp[1<<N], lim, n;
point p[N];

int cross(point a, point b, point o) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

int run(int mask) {
    if (mask == lim - 1) return 0;
    int &res = dp[mask];
    if (res != -1) return res;
    int i, j, k, newmask;
    res = INF;
    for (i = 0; i < n;i++) if ( !And(mask, i) ) break;

        for (j = i + 1;j < n;j++)
            if ( !And(mask, j) ) {
                newmask = Or(Or(mask, i), j);
                for (k = j + 1;k < n; k++)
                    if ( !And(newmask, k) && !cross(p[i], p[j], p[k]) ) newmask = Or(newmask, k);
                res = min(res, 1 + run(newmask));
            }

    if (res == INF) res = 1;
    return res;
}

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    scanf("%d", &cases);
    point a, b, c;
    while (cases--) {
        scanf("%d", &n);
        rep(i, n)
            scanf("%d %d", &p[i].x, &p[i].y);
        fill(dp, -1);
        lim = (1<<n);
        printf("Case %d: %d\n", ++caseno, run(0));
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem C. Looking for Order ->AC
* Algorithm dp
* Time Limit 130ms
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
#define M 100000

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
}p[26];
int dp[1<<24];
int d[25][25];
int n, lim;
int dist(point a, point b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return (dx * dx + dy * dy);
}
int run(int mask) {
    if (mask == lim - 1) return 0;
    int &res = dp[mask];
    if (res !=-1 ) return res;
    res = INF;
    for (int i=0;i<n;i++) {
        if ( !And(mask, i) ) {
            res = 2 * d[n][i] + run( Or(mask, i) );
            for (int j=0;j<n;j++)
                if ( !And(mask, j) && i!=j) {
                    int v = d[i][j] + d[j][n] + d[n][i];
                    res = min(res, v + run(Or(Or(mask, i), j)));
                }
            break;
        }
    }
    return res;
}
void trace(int mask) {
    int res = run(mask);
    if (res == 0) return;
    
    for (int i=0;i<n;i++) {
        if ( !And(mask, i) ) {
            if (res == 2 * d[i][n] + run(Or(mask, i))) {
                printf(" %d 0",i + 1);
                trace(Or(mask, i));
                return;
            }
            for (int j=i + 1;j<n;j++) {
                if ( !And(mask, j) ) {
                    if (res == d[i][j] + d[j][n] + d[n][i] + run(Or(Or(mask, i),j))) {
                        printf(" %d %d 0",i + 1, j + 1);
                        trace(Or(Or(mask, i), j));
                        return;
                    }
                }
            }
            break;
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int xs, ys, Ans;
    scanf("%d %d",&xs,&ys);
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d %d",&p[i].x,&p[i].y);
    p[n] = point(xs, ys);
    lim = (1<<n);
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
            d[i][j] = dist(p[i], p[j]);
    memset(dp, -1, sizeof(dp));
    Ans = run(0);
    printf("%d\n",Ans);
    printf("0");
    trace( 0 );
    printf("\n");
}

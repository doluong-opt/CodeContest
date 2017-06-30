/***********************************************
* Author - LUONG VAN DO                        *
* Problem 216 - Getting in Line ->AC
* Algorithm adhoc
* Time Limit 0.012s
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
#define N 10

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
    point(){};
    point(int xx, int yy){
        x = xx; y = yy;
    }
};
int n;
point p[10];
double dist[N][N];
double dp[1<<9][N];
int next[1<<9][N];
double d(point a, point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy) + 16.0;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int caseno = 0, lim, end, msk, cur;
    double ans;
    while ( scanf("%d",&n) && n) {
        for (int i=0;i<n;i++) scanf("%d %d",&p[i].x,&p[i].y);
        lim = (1<<n);
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                dist[i][j] = d(p[i], p[j]);
        
        for (int i=0;i<lim;i++)
            for (int j=0;j<n;j++) {
                dp[i][j] = INF;
                next[i][j] = -1;
            }
            
        for (int i=0;i<n;i++)
            dp[1<<i][i] = 0;
            
        ans = INF;
        for (int i=1;i<lim;i++) {
            
            for (int j=0;j<n;j++)
                for (int k=0;k<n;k++) {
                    if ( !And(i, k) ) {
                        if ( dp[i | (1<<k)][k] > dp[i][j] + dist[j][k] ) {
                            dp[i | (1<<k)][k] = dp[i][j] + dist[j][k];
                            next[i | (1<<k)][k] = j;
                        }
                    }
                }
        }
        for (int i=0;i<n;i++)
            if (ans > dp[lim - 1][i]) {
                ans = dp[lim - 1][i];
                end = i;
            }
        msk = lim - 1;
        puts("**********************************************************");
        printf("Network #%d\n",++caseno);
        while ( msk ) {
            cur = end;
            end = next[msk][end];
            if (end != -1) printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",p[cur].x,p[cur].y, p[end].x,p[end].y, dist[cur][end]);
            msk = msk ^ (1<<cur);
        }
        printf("Number of feet of cable required is %.2lf.\n",ans);
        
    }
}

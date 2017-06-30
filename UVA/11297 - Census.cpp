/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11297 - Census ->AC
* Algorithm RMQ
* Time Limit 11297
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
#define N 550

#define MAX_LOG 9
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
int64 a[N][N], n;
int iMin[N][N][MAX_LOG];
int iMax[N][N][MAX_LOG];
void initMin() {
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            iMin[i][j][0] = j;
            
    for (int k=0;k<n;k++)
        for (int j=1;(1<<j)<=n;j++)
            for (int i=0;i + (1<<j) - 1 < n;i++)
                if ( a[k][iMin[k][i][j-1]] < a[k][iMin[k][i + (1<<(j-1))][j-1]] )
                    iMin[k][i][j] = iMin[k][i][j-1];
                else
                    iMin[k][i][j] = iMin[k][i + (1<<(j-1))][j-1];
}
void initMax() {
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            iMax[i][j][0] = j;
    
    for (int k=0;k<n;k++)
        for (int j=1;(1<<j)<=n;j++)
            for (int i=0;i + (1<<j) - 1 < n;i++)
                if ( a[k][iMax[k][i][j-1]] > a[k][iMax[k][i + (1<<(j-1))][j-1]] )
                    iMax[k][i][j] = iMax[k][i][j-1];
                else
                    iMax[k][i][j] = iMax[k][i + (1<<(j-1))][j-1];
}
void update(int r) {
    for (int j=0;j<n;j++) {
        iMin[r][j][0] = j;
        iMax[r][j][0] = j;
    }
    for (int j=1;(1<<j)<=n;j++)
        for (int i=0;i + (1<<j) - 1 < n;i++)
            if (a[r][iMin[r][i][j-1]] < a[r][iMin[r][i + (1<<(j-1))][j-1]] )
                iMin[r][i][j] = iMin[r][i][j-1];
            else
                iMin[r][i][j] = iMin[r][i + (1<<(j-1))][j-1];
                
    for (int j=1;(1<<j)<=n;j++)
        for (int i=0;i + (1<<j) - 1 < n;i++)
            if (a[r][iMax[r][i][j-1]] > a[r][iMax[r][i + (1<<(j-1))][j-1]] )
                iMax[r][i][j] = iMax[r][i][j-1];
            else
                iMax[r][i][j] = iMax[r][i + (1<<(j-1))][j-1];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    char type;
    int64 ansMax, ansMin;
    int q, x1, y1, x2, y2, k, v, x, y;
    scanf("%d %d",&n,&n);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++) scanf("%lld",&a[i][j]);
    initMin();
    initMax();
    scanf(" %d ",&q);
    while (q--) {
        scanf(" %c ",&type);
        if (type == 'q') {
            scanf(" %d %d %d %d ",&x1,&y1,&x2,&y2);
            x1--; x2--;
            y1--; y2--;
            ansMin = INF;
            ansMax = -INF;
            k = (int)log2(y2 - y1 + 1);
            for (int i=x1;i<=x2;i++) {
                ansMin = min(ansMin, min(a[i][iMin[i][y1][k]], a[i][iMin[i][y2 - (1<<k) + 1][k]]));
                ansMax = max(ansMax, max(a[i][iMax[i][y1][k]], a[i][iMax[i][y2 - (1<<k) + 1][k]]));
            }
            printf("%lld %lld\n", ansMax, ansMin);
        }
        else {
            scanf(" %d %d %d ",&x, &y, &v);
            x--; y--;
            a[x][y] = v;
            update( x );
        }
    }
}

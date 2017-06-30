/***********************************************
* Author - LUONG VAN DO                        *
* Problem 
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
#define INF 500000000
#define N 510

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, string> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node {
    int f, up;
    node(){}
    node(int ff, int uu){
        f = ff; up = uu;
    }
};
int color[N][7];
int op[10], n;
node dp[N][110];
string mm[] = {"front", "back", "left", "right", "top", "bottom"};
int res[N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int ans, x, y, caseno = 0, i1, i2;
    op[0] = 1; op[1] = 0; op[2] = 3; op[3] = 2; op[4] = 5; op[5] = 4;
    while ( scanf("%d",&n) && n) {
        for (int i=0;i<n;i++) {
            for (int j=0;j<6;j++)
                scanf("%d",&color[i][j]);
        }
        
        for (int j=0;j<=100;j++)
            dp[n + 1][j].f = 0;
            
        for (int i=n;i>=1;i--) {
            for (int j=1;j<=100;j++) {
                dp[i][j].f = dp[i + 1][j].f;
                dp[i][j].up = -1;
            }
            
            for (int j=0;j<6;j++) {
                x = color[i - 1][j];
                y = color[i - 1][op[j]];
                if ( dp[i + 1][y].f + 1 > dp[i][x].f ) {
                    dp[i][x].f = dp[i + 1][y].f + 1;
                    dp[i][x].up = j;
                }
            }
        }
        
        ans = 0;
        for (int i=1;i<=100;i++) {
            if ( ans < dp[1][i].f ) {
                ans = dp[1][i].f;
                i2 = i;
            }
        }
        if ( caseno ) puts("");
        printf("Case #%d\n",++caseno);
        printf("%d\n", ans);

        
        for (int i1=1;i1<=n;i1++) {
            if ( dp[i1][i2].up != -1 ) {
                cout<<i1<<" "<<mm[dp[i1][i2].up]<<endl;
                i2 = color[i1 - 1][op[dp[i1][i2].up]];
            }
        }
    }
}

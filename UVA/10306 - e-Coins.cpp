/***********************************************
* Author - LUONG VAN DO                        *
* 10306 - e-Coins ->AC
* Algorithm dp
* Time Limit 0.036s
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
#define INF 500000000
#define maxN 1001
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int v1[maxN], v2[maxN];
int dp[maxN][maxN];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, m, s;
    int ans;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&m,&s);
        REP(i, m) scanf("%d %d",&v1[i],&v2[i]);
        REP(i, s + 1)
            REP(j, s + 1) dp[i][j] = INF;
        dp[0][0] = 0;
        
        REP(i, m)
            FOR(j, v1[i], s)
                FOR(k, v2[i], s)
                    dp[j][k] = min(dp[j][k], 1 + dp[j-v1[i]][k-v2[i]]);
        ans = INF;
        REP(i, s + 1)
            REP(j, s + 1)
                if (i * i + j * j == s * s) 
                    ans = min(ans, dp[i][j]);
        if ( ans == INF) puts("not possible");
        else printf("%d\n",ans);
    }
    return 0;
}

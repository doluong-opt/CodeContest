/***********************************************
* Author - LUONG VAN DO                        *
* 1231 - Coin Change (I) ->AC
* Algorithm dp
* Time Limit 0.422s
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
#define maxN 1060
#define INF 100000007
using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int a[maxN], c[maxN];
int dp[maxN][maxN];
int N, K;
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&N,&K);
        FOR(i, 1, N) scanf("%d",&c[i]);
        FOR(i, 1, N) scanf("%d",&a[i]);
        
        FOR(i, 1, N)
            FOR(j, 1, K) dp[i][j] = 0;
            
        FOR(i, 0, N) dp[i][0] = 1;
        
        FOR(i, 1, N)
            FOR(j, 1, K)
                FOR(k, 0, a[i])
                    if (j>=k*c[i]) dp[i][j] = (( dp[i][j] % INF) + (dp[i-1][j-k*c[i]] % INF)) % INF;
        
        printf("Case %d: %d\n",t,dp[N][K] % INF);
    }
    return 0;
}

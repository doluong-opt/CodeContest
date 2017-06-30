/***********************************************
* Author - LUONG VAN DO                        *
* 1191 - Bar Codes ->AC
* Algorithm dp
* Time Limit 0.024s
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
#define maxN 50001

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, k, m;
uint64 dp[55][55][55];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    FOR(i, 0, 50)
        FOR(j, 0, 50)
            FOR(h, 0, 50) dp[i][j][h] = 0;
            
    FOR(i, 0, 50) dp[0][0][i] = 1;
    for (int h=1;h<=50;h++)
        for (int i=1;i<=50;i++)
            for (int j=1;j<=50;j++)
                for (int v = 1; v<=i && v<=h; v++)
                    dp[i][j][h]+= dp[i-v][j-1][h];
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d %d",&n,&k,&m);
        printf("Case %d: %lld\n",t,dp[n][k][m]);
    }
    return 0;
}

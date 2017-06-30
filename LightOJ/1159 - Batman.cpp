/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1159 - Batman ->AC
* Algorithm dp
* Time Limit 0.03s
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
#define M 50

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int dp[M + 1][M + 1][M + 1];
char s1[M + 1], s2[M + 1], s3[M + 1];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, l1, l2, l3;
    scanf(" %d ",&test);
    getchar();
    FOR(t, 1, test) {
        getchar();
        gets(s1); l1 = strlen(s1);
        gets(s2); l2 = strlen(s2);
        gets(s3); l3 = strlen(s3);
        FOR(i, 1, l1)
            FOR(j, 1, l2)
                FOR(k, 1, l3) dp[i][j][k] = 0;
        FOR(i, 1, l1)
            FOR(j, 1, l2)
                FOR(k, 1, l3)
                    if (s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k],dp[i][j][k-1]));
        printf("Case %d: %d\n",t,dp[l1][l2][l3]);
    }
}

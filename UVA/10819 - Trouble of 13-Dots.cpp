/***********************************************
* Author - LUONG VAN DO                        *
* 10819 - Trouble of 13-Dots ->AC
* Algorithm dp
* Time Limit 0.144s
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
#define maxN 10501

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int64 dp[maxN];
int p[100 + 5], v[100 + 5];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int m, n;
    while ( scanf("%d %d",&m,&n) != EOF) {
        FOR(i, 1, m + 200) dp[i] = 0;
        FOR(i, 1, n) scanf("%d %d",&p[i],&v[i]);
        
        FOR(i, 1, n) {
            FORD(j, m + 200, p[i])
                    if ( j == p[i] ) dp[j] = max(dp[j], dp[j-p[i]] + v[i]);
                else
                    if ( j > p[i] && dp[j-p[i]]) dp[j] = max(dp[j], dp[j-p[i]] + v[i]);
        }
        int ans = 0;
        FOR(i, 1, m + 200) {
            if (i > 2000 || i<=m)
                ans = max(ans, dp[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}

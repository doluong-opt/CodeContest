/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1157 - LCS Revisited ->AC
* Algorithm dp
* Time Limit 0.73s
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
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1010
#define MOD 1000007
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
int dp[N][N], a[N][N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, m, n, caseno = 0;
    char s1[N], s2[N];
    scanf("%d ",&cases);
    while (cases--) {
        gets(s1); n = strlen(s1);
        gets(s2); m = strlen(s2);
        memset(dp, 0, sizeof(dp));
        memset(a, 0, sizeof(dp));
        for (int i=0;i<=n;i++) dp[i][0] = 1;
        for (int i=0;i<=m;i++) dp[0][i] = 1;
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
            if (s1[i-1] == s2[j-1]) {
                a[i][j] = a[i-1][j-1] + 1;
                dp[i][j] = dp[i-1][j-1];
                if (dp[i][j] > MOD) dp[i][j]-=MOD;
            }
            else {
                a[i][j] = max(a[i-1][j], a[i][j-1]);
                if (a[i][j] == a[i-1][j]) dp[i][j]+=dp[i-1][j];
                if (a[i][j] == a[i][j-1]) dp[i][j]+=dp[i][j-1];
                if (a[i][j] == a[i-1][j-1]) dp[i][j]-=dp[i-1][j-1];
                while (dp[i][j] > MOD) dp[i][j]-=MOD;
                while (dp[i][j] < 0) dp[i][j]+=MOD;
            }
        }
        printf("Case %d: %d\n",++caseno, dp[n][m]);
    }
}

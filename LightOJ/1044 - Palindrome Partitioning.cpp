/***********************************************
* Author LUONG VAN DO                        *
* Problem 1044 - Palindrome Partitioning 
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

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 111222333
#define N 1100

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
int dp[N][N], d[N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, caseno = 0;
    char s[N];
    scanf("%d", &cases);
    while (cases--) {
        scanf("%s", s); n = strlen(s);
        fill(dp, 0);
        fr(i, 1, n - 1) {
            dp[i][i] = 1;
            if (s[i - 1] == s[i]) dp[i][i + 1] = dp[i + 1][i] = 1;
        }
        dp[n][n] = 1;
        for (int k = 1; k <= n; k++)
            for (int i = 1;i <= n - k; i++) {
                int j = i + k;
                dp[i][j] = (dp[i + 1][j - 1] & (s[i - 1] == s[j - 1]));
            }
        fill(d, INF);
        d[0] = 0;
        for (int i = 1;i <= n;i++)
            for (int j = i;j >=1; j--)
                if (dp[j][i]) d[i] = min(d[i], d[j - 1] + 1);
        printf("Case %d: %d\n", ++caseno, d[n]);
    }
}

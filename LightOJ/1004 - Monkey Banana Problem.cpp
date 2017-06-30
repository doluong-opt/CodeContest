/***********************************************
* Author LUONG VAN DO                        *
* Problem 1004 - Monkey Banana Problem 
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
#define N 310

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
int dp[N][N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, c, n, m, ans, t;
    int caseno = 0;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        fill(dp, 0);
        fr(i, 1, n) {
            c = n - i + 1;
            fr(j, 1, i) {
                scanf("%d", &dp[i][c]);
                c+=2;
            }
        }
        m = n - 1; t = c = 2;
        fr(i, n + 1, 2 * n - 1) {
            fr(j, 1, m) {
                scanf("%d", &dp[i][c]);
                c+=2;
            }
            m--; t++; c = t;
        }
        fr(i, 1, 2 * n - 1)
            fr(j, 1, 2 * n - 1) {
                if (!dp[i][j]) continue;
                if (dp[i - 1][j - 1] == 0) dp[i][j] += dp[i - 1][j + 1];
                else
                if (dp[i - 1][j + 1] == 0) dp[i][j] += dp[i - 1][j - 1];
                else
                dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j + 1]);
            }
        ans = 0;
        fr(i, 1, 2 * n - 1)
            ans = max(ans, dp[2 * n - 1][i]);
        printf("Case %d: %d\n", ++caseno, ans);
    }
}

/***********************************************
* Author LUONG VAN DO                        *
* Problem COUNTPL
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
#define N 270

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
int d[N][N], dp[N], n;
char s[N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    gets(s); n = strlen(s);
    fill(d, 0);
    fr(i, 1, n) d[i][i] = 1;
    fr(i, 1, n)
        if (s[i] == s[i - 1]) d[i][i + 1] = d[i + 1][i] = 1;
    for (int k = 1;k <= n;k++)
        for (int i = 1;i <= n - k;i++) {
            int j = i + k;
            d[i][j] = (d[i + 1][j - 1] & (s[i - 1] == s[j - 1]));
        }
    fr(i, 1, n) dp[i] = INF;
    dp[0] = 0;
    fr(i, 1, n)
        for (int j = i;j >= 1;j--)
            if (d[j][i]) dp[i] = min(dp[i], dp[j - 1] + 1);
    printf("%d\n", dp[n]);
}

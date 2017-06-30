/***********************************************
* Author LUONG VAN DO                        *
* Problem 1064 - Throwing Dice 
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
#define N 25
#define X 151

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline uint64 gcd(uint64 a, uint64 b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
uint64 all[N], dp[N][X], total[X];
void init() {
    total[0] = 0;
    fill(dp, 0);
    for (int i = 1;i <= 149;i++) {
        if (i <= 6) dp[1][i] = 1;
        else dp[1][i] = 0;
        if (i) total[i] = total[i - 1] + dp[1][i];
    }
    for (int i = 2;i <= 24;i++) {
        
        for (int j = 0;j <= 149;j++) {
            if (i > j) dp[i][j] = 0;
            if (j <= 6) dp[i][j] = total[j - 1];
            else dp[i][j] = total[j - 1] - total[j - 7];
        }
        total[0] = 0;
        for (int j = 1;j <= 149;j++)
            total[j] = total[j - 1] + dp[i][j];
    }
    for (int i = 0;i <= 24; i++)
        for (int j = 148;j >= 0; j--)
            dp[i][j] += dp[i][j + 1];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    all[0] = 1;
    fr(i, 1, 24) all[i] = all[i - 1] * 6;
    init();
    int cases, n, caseno = 0, k;
    uint64 x, y, d;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d", &n, &k);
        x = dp[n][k]; y = all[n];
        d = gcd(x, y);
        x/=d; y/=d;
        if (y != 1) printf("Case %d: %llu/%llu\n", ++caseno, x, y);
        else printf("Case %d: %llu\n", ++caseno, x);
    }
}

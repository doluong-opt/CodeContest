/***********************************************
* Author LUONG VAN DO                        *
* Problem
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
#define N 22

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, a[N][N], lim, x;
int64 result[1<<21], dp[1<<21];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    scanf("%d", &n);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) scanf("%d", &a[i][j]);
    lim = (1<<n);
    for (int i = 0;i < lim;i++) result[i] = -1, dp[i] = 0;
    dp[0] = 1; result[0] = 0;
    
    for (int mask = 0;mask < lim;mask++) {
        x = 0;
        for (int k = 0;k < n;k++)
            if ( And(mask, k) ) x++;
            
        for (int k = 1;k <= n;k++)
            if ( And(mask, k - 1) )
                if (result[mask] < result[Xor(mask, k - 1)] + a[x][k] ) {
                    result[mask] = result[Xor(mask, k - 1)] + a[x][k];
                    dp[mask] = dp[Xor(mask, k - 1)];
                }
                else
                if ( result[mask] == result[Xor(mask, k - 1)] + a[x][k])
                    dp[mask] += dp[Xor(mask, k - 1)];
                    
    }
    printf("%lld %lld\n", result[lim - 1], dp[lim - 1]);
}

/***********************************************
* Author LUONG VAN DO                        *
* Problem 1030 - Discovering Gold 
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
#define N 110

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
double dp[N], a[N], sum[N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, caseno = 0;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        fr(i, 1, n)
            scanf("%lf", &a[i]);
        dp[n] = a[n]; dp[n - 1] = a[n] + a[n - 1];
        sum[n] = a[n]; sum[n - 1] = dp[n] + dp[n - 1];
        for (int i = n - 2;i >= 1;i--) {
            if ( n - i > 6 ) dp[i] = a[i] + (sum[i + 1] - sum[i + 7]) / 6.0;
            else dp[i] = a[i] + sum[i + 1] / (double)(n - i);
            sum[i] = sum[i + 1] + dp[i];
        }
        printf("Case %d: %.10lf\n", ++caseno, dp[1]);
    }
}

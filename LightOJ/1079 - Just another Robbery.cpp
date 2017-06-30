/***********************************************
* Author LUONG VAN DO                        *
* Problem 1079 - Just another Robbery 
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
#define S 10010
using namespace std;

inline double max(double a, double b) { return a > b ? a : b; }
inline double min(double a, double b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int m[N], mark[S];
double dp[S], a[N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, total, n, ans;
    double p;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%lf %d", &p, &n);
        total = 0;
        fr(i, 1, n) {
            scanf("%d %lf", &m[i], &a[i]);
            total+=m[i];
        }
        rep(i, total + 1) dp[i] = 1.0 * INF, mark[i] = 0;
        dp[0] = 0.0; mark[0] = 1;
        for (int i = 1;i <= n;i++) {
            
            for (int j = total - m[i]; j >= 0;j--)
                if ( mark[j] ) {
                    double xx = (1.0 - dp[j]) * a[i];
                    dp[j + m[i]] = min(dp[j + m[i]], dp[j] + xx);
                    mark[j + m[i]] = 1;
                }
        }
        frr(i, 0, total)
            if (dp[i] <= p) {
                ans = i;
                break;
            }
        printf("Case %d: %d\n", ++caseno, ans);
    }
}

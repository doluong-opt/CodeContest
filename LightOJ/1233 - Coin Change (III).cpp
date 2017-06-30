/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1233 - Coin Change (III) ->AC
* Algorithm dp
* Time Limit 0.332s
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
#define M 100010

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
int n, m;
int dp[M], need[M];
int a[110], c[110];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, k, Ans, caseno = 0;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d",&n,&m);
        memset(dp, 0, sizeof(dp));
        memset(need, 0, sizeof(need));
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        for (int i=0;i<n;i++) scanf("%d",&c[i]);
        dp[0] = 1;
        for (int i=0;i<n;i++) {
            
            for (int j=0;j<=m;j++)
                if (dp[j]) need[j] = 0;
                else need[j] = INF;
            
            for (int j=0;j<=m;j++) {
                k = j + a[i];
                if (k > m) continue;
                if (!dp[k] && need[k] > need[j] + 1 && need[j] < c[i]) {
                    need[k] = need[j] + 1;
                    dp[k] = 1;
                }
            }
        }
        Ans = 0;
        for (int i=1;i<=m;i++) Ans+=dp[i];
        printf("Case %d: %d\n",++caseno, Ans);
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10130 - SuperSale ->AC
* Algorithm dp
* Time Limit 0.056s
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
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define frr(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i=n - 1; i>=0; i--)
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1010

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
int n, S;
int V[N], W[N];
int dp[N][35];
int run(int id, int remW) {
    if (remW == 0 || id == n + 1) return 0;
    int &res = dp[id][remW];
    if (res != -1) return res;
    res = 0;
    if ( W[id] > remW ) res+=run(id + 1, remW);
    else
    res+=max( run(id + 1, remW), V[id] + run(id + 1, remW - W[id]));
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, ans, m;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d %d",&V[i], &W[i]);
        scanf("%d",&m);
        ans = 0;
        memset(dp, -1, sizeof(dp));
        for (int i=1;i<=30;i++) run(1, i);
        while (m--) {
            scanf("%d",&S);
            ans+=dp[1][S];
        }
        printf("%d\n",ans);
    }
}

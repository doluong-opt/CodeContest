/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1422 - Halloween Costumes ->AC
* Algorithm dp
* Time Limit 0.126s
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
#define M 100

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
int n, dp[M + 1][M + 1];
int a[M + 1];
int run(int cur, int end){
    if (cur > end || cur == n) return 0;
    int &res = dp[cur][end];
    if (res!=-1) return res;
    res = 1 + run(cur + 1, end);
    for (int i=cur + 1;i < n;i++) {
        if (a[i] == a[cur])
            res = min(res, run(cur + 1, i - 1) + run(i, end));
    }
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, Ans;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        REP(i, n) scanf("%d",&a[i]);
        memset(dp, -1, sizeof(dp));
        Ans = run(0, n - 1);
        printf("Case %d: %d\n",t,Ans);
    }
}

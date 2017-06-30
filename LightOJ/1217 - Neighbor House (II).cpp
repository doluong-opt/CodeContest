/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1217 - Neighbor House (II) ->AC
* Algorithm dp
* Time Limit 0.011s
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
#define M 1000

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
int n;
int sell[M + 1];
int dp[M + 1][2], color[M + 1];
int mod(int x){
    if (x<0) x+=n;
    return x % n;
}
int run(int cur, int p) {
    if (cur == n) return 0;
    int &res = dp[cur][p];
    if (res!=-1) return res;
    res = 0;
    if (!color[cur]) {
        color[cur]++;
        color[mod(cur - 1)]++;
        color[mod(cur + 1)]++;
        int t1 = sell[cur] + run(cur + 1, 1);
        res = max(res, t1);
        color[cur]--;
        color[mod(cur - 1)]--;
        color[mod(cur + 1)]--;
        
        int t2 = run(cur + 1, 0);
        res = max(res, t2);
    }
    else {
        int t1 = run(cur + 1, 0);
        res = max(res, t1);
    }
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, R1, R2;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        REP(i, n) scanf("%d",&sell[i]);
        memset(dp, -1, sizeof(dp));
        memset(color, 0, sizeof(color));
        R1 = run(1, 0);
        memset(dp, -1, sizeof(dp));
        memset(color, 0, sizeof(color));
        color[0] = color[1] = color[n - 1] = 1;
        R2 = sell[0] + run(1, 1);
        printf("Case %d: %d\n",t,max(R1, R2));
    }
}

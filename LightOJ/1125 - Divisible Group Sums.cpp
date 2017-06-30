/***********************************************
* Author - LUONG VAN DO                        *
* 1125 - Divisible Group Sums ->AC
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
#define maxN 205
#define MOD 1000000000
using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int64 a[maxN];
int64 dp[maxN][15][25];
int64 d, m;
int n, q;
int64 mod(int64 x) {
    x+=d * MOD;
    return x;
}
int64 run(int cur, int s, int r){
    if ( s == m ) return (r == 0);
    else
    if ( cur == n ) return 0;
    int64 &res = dp[cur][s][r];
    if (res != -1) return res;
    res = 0;
    res+=run(cur + 1, s, r);
    res+=run(cur + 1, s + 1, mod(r + a[cur]) % d);
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    scanf("%d",&cases);
    while ( cases--) {
        scanf("%d %d",&n,&q);
        for (int i=0;i<n;i++) scanf("%lld",&a[i]);
        printf("Case %d:\n",++caseno);
        while (q--) {
            scanf("%lld %lld",&d, &m);
            memset(dp, -1, sizeof(dp));
            printf("%lld\n",run(0, 0, 0));
        }
    }
    return 0;
}

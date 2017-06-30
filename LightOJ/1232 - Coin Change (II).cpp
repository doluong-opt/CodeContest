/***********************************************
* Author - LUONG VAN DO                        *
* 1232 - Coin Change (II) ->AC
* Algorithm dp
* Time Limit 0.322s
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
#define INF 100000007
#define maxN 10001
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, k;
int dp[maxN], a[maxN];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&n,&k);
        FOR(i, 1, n) scanf("%d",&a[i]);
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i=1;i<=n;i++)
            for (int j=a[i];j<=k;j++) {
                dp[j]+=dp[j-a[i]];
                dp[j]%=INF;
            }
        printf("Case %d: %d\n",t,dp[k]);
    }
    return 0;
}

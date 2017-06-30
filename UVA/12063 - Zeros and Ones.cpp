/***********************************************
* Author - LUONG VAN DO                        *
* Problem 12063 - Zeros and Ones ->AC
* Algorithm dp
* Time Limit 0.124s
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
#define M 100000

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
int64 dp[65][65][101];
int n, k;
int64 run(int zeros, int ones, int mod){
    if (zeros + ones > n) return 0;
    if (dp[zeros][ones][mod]!=-1) return dp[zeros][ones][mod];
    return dp[zeros][ones][mod] = run(zeros + 1, ones, (mod << 1) % k) + run(zeros, ones + 1, ((mod << 1) % k + 1) % k);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases;
    int64 Ans;
    scanf("%d",&cases);
    for (int t=1;t<=cases;t++) {
        scanf("%d %d",&n,&k);
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++)
                for (int h=0;h<=k;h++) dp[i][j][h] = -1;
        Ans = 0;
        dp[n>>1][n>>1][0] = 1;
        if (k > 0 && n % 2 == 0)
            Ans = run(0, 1, 1 % k);
        printf("Case %d: %lld\n",t,Ans);
    }
}

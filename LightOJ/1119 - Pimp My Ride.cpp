/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1119 - Pimp My Ride  ->AC
* Algorithm dp
* Time Limit 0.446s
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
int n;
int val[15][15];
int dp[1<<16], lim;
int run(int mask){
    if (mask == lim) return 0;
    int &res = dp[mask];
    if (res!=-1) return res;
    res = INF;
    REP(i, n) {
        if (!And(mask, i)) {
            int S = 0;
            REP(j, n)
                if (!And(mask, j))
                    S+=val[i][j];
                res = min(res, S + run(Or(mask, i)));
        }
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
        REP(i, n)
            REP(j, n) scanf("%d",&val[i][j]);
        lim = (1<<n) - 1;
        memset(dp, -1, sizeof(dp));
        Ans = run( 0 );
        printf("Case %d: %d\n",t,Ans);
    }
}

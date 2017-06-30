/***********************************************
* Author - LUONG VAN DO                        *
* 10759 - Dice Throwing ->AC
* Algorithm probability
* Time Limit 0.016s
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
#define maxN 155
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline uint64 gcd(uint64 a, uint64 b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int64 dp[maxN][maxN];
uint64 all[maxN];
uint64 Recur(int n, int x){
    if (!n && !x) return dp[n][x] = 1;
    else
    if (n <=0 || x<=0) {
        if (n>=0 && x>=0) dp[n][x] = 0;
        return 0;
    }
    else
    if (dp[n][x] !=-1) return dp[n][x];
    uint64 res = 0, j;
    for(j = 1; j <= 6; j++)
        res+=Recur(n - 1, x - j);
    return dp[n][x] = res;
}
void init() {
    all[0] = 1;
    FOR(i, 1, 24)
        all[i] = all[i-1] * 6;
    
    FOR(i, 1, 24)
        FOR(j, 0, 150) dp[i][j] = -1;
    
    FOR(i, 1, 24)
        FOR(j, 0, 150)
            Recur(i, j);
    FOR(i, 1, 25)
        FORD(j, 149, 0)
            dp[i][j]+=dp[i][j+1];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, x;
    init();
    while ( scanf("%d %d",&n,&x) && ( n + x) ){
        if ( dp[n][x] % all[n] == 0 )
            printf("%lld\n",dp[n][x] / all[n]);
        else {
            uint64 d = gcd(dp[n][x], all[n]);
            printf("%lld/%lld\n",dp[n][x] / d, all[n] / d);
        }
    }
    return 0;
}

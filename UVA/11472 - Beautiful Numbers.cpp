/***********************************************
* Author - LUONG VAN DO                        *
* 11472 - Beautiful Numbers ->AC
* Algorithm dp
* Time Limit 0.064s
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
#define INF 1000000007
#define maxN 50001
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int64 dp[1025][11][101];
int m, n;
int64 recur(int last, int i, int state) {
    if (dp[state][last][i]!=-1)
        return dp[state][last][i];
        
    int64 res = ( (state == (1<<n)-1) && i>=n);
    if (i < m) {
        int a = last + 1;
        int b = last - 1;
        if (a < n)
            res = (res + (recur(a, i + 1, state | (1<<a)) % INF)) % INF;
        if (b>=0)
            res = (res + (recur(b, i + 1, state | (1<<b)) % INF)) % INF;
    }
    return dp[state][last][i] = res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, nn;
    int64 res;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&n,&m);
        nn = (1<<n);
        FOR(i, 0, nn)
            FOR(j, 0, n)
                FOR(k, 0, m + 1)
                    dp[i][j][k] = -1;
        res = 0;
        FOR(i, 1, n - 1)
            res = (res + recur(i, 1, (1<<i)) % INF) % INF;
        printf("%lld\n",res);
    }
    return 0;
}

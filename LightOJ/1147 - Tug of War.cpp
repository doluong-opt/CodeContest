/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1147 - Tug of War 
* Algorithm
* Time Limit
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

inline int64 And(int64 mask, int64 bit) { return mask & (1LL << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int val[M + 1], n;
int64 dp[M + 1];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, S, SS, team1, team2, bit;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        S = 0;
        REP(i, n) {
            scanf("%d",&val[i]);
            S+=val[i];
        }
        SS = S;
        S>>=1;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        REP(i, n)
            FORD(j, S - val[i], 0)
                if (dp[j]) dp[j + val[i]] |= (dp[j] << 1);
        bit = (n >> 1) + (n & 1 ? 1 : 0);
        FORD(x, S, 0)
            if (And(dp[x], bit)) {
                team1 = x;
                team2 = SS - x;
                break;
            }
        if (team1 > team2) swap(team1, team2);
        printf("Case %d: %d %d\n",t,team1,team2);
    }
}

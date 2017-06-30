/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1037 - Agent 47 ->AC
* Algorithm dp bitmask
* Time Limit 0.102s
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
int health[16], lim;
int dp[1<<16], n;
char s[16][16];
int cal(int msk, int target){
    int temp = 1;
    REP(i, n) {
        if (And(msk, i)) {
            temp = max(temp, s[i][target] - '0');
        }
    }
    int r = health[target] / temp;
    if (health[target] % temp) r++;
    return r;
}
int run(int mask) {
    if (mask == lim - 1) return 0;
    int &res = dp[mask];
    if (res!=-1) return res;
    res = INF;
    REP(i, n) {
        if (!And(mask, i)) {
            int temp = cal(mask, i) + run(Or(mask, i));
            res = min(res, temp);
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
        REP(i, n) scanf("%d ",&health[i]);
        REP(i, n) gets(s[i]);
        lim = (1<<n);
        REP(i, lim) dp[i] = -1;
        Ans = run( 0 );
        printf("Case %d: %d\n",t,Ans);
    }
}

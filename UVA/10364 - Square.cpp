/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10364 - Square ->AC
* Algorithm dp bitmask
* Time Limit 1.668s
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
int dp[1<<21][5];
int len[21], n, pivot;
int cal(int mask, int k) {
    int S = 0;
    REP(i, n)
        if (And(mask, i)) S+=len[i];
    return S - k * pivot;
}
int run(int mask, int k) {
    int x = cal(mask, k);
    if (x == pivot) return run(mask, k + 1);
    if (k == 4) return 1;
    int &res = dp[mask][k];
    if (res!=-1) return res;
    
        res = 0;
        for (int i=0;i<n && !res;++i) {
            if (!And(mask, i) && x + len[i]<=pivot)
                res|=run(Or(mask, i), k);
        }
    
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, S, lim, Ans;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        S = 0;
        REP(i, n) {
            scanf("%d",&len[i]);
            S+=len[i];
        }
        if (S % 4) puts("no");
        else {
            pivot = S / 4;
            lim = (1<<n);
            REP(i, lim) dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = -1;
            Ans = run(0, 0);
            if (Ans) puts("yes");
            else puts("no");
        }
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* 1122 - Digit Count ->AC
* Algorithm dp bitmask
* Time Limit 0.002s
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
#define maxN 50001

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, m;
int mask;
int dp[11][11];
int Or(int mask, int bit){
    return mask | (1<<bit);
}
int And(int mask, int bit){
    return mask & (1<<bit);
}
int run(int N, int Pre){
    int &res = dp[N][Pre];
    if (res!=-1) return res;
    if (!N) return 1;
    res = 0;
    FOR(i, 1, 9) {
        if (And(mask, i)) {
            if (!Pre || abs(Pre - i) <= 2)
                res+=run(N - 1, i);
        }
    }
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, x, Ans;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&m,&n);
        mask = 0; memset(dp, -1, sizeof(dp));
        REP(i, m) {
            scanf("%d",&x);
            mask = Or(mask, x);
        }
        Ans = run(n, 0);
        printf("Case %d: %d\n",t,Ans);
    }
    return 0;
}

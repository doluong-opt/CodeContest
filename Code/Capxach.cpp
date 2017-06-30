/***********************************************
* Author - LUONG VAN DO
*
* Algorithm
* Time Limit 0.003s
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
#define N 1000005
#define C 1000000
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int cases, n;
int dp[N];
int x[] = {1, 3, 5, 10, 15, 19};
int y[] = {1, 1,2,1, 2, 3};
void init() {
        for (int i = 0;i <= C;i++) dp[i] = INF;
        dp[0] = 0;
        for (int i = 1;i <= C;i++) {
                for (int j = 0;j < 6;j++)
                        if (i >= x[j])
                                dp[i] = min(dp[i], dp[i - x[j]] + y[j]);
        }
}
int main() {
        //freopen("exam.inp","r", stdin);
        //freopen("exam.out","w", stdout);
        init();
        scanf("%d", &cases);
        while (cases--) {
                scanf("%d", &n);
                printf("%d\n", dp[n]);
        }
        return 0;
}

// =============================================================================
// Author LUONG VAN DO
// Problem
// Algorithm
// Time Limit
// =============================================================================
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
#define fillarr(arr, c) memset(arr, c, sizeof(arr))
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1111

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, m, k;
char sn[N];
char sm[N];
int sum[N][N][11][2];
int main() {
        //freopen("exam.inp","r", stdin);
        //freopen("exam.out","w", stdout);
        scanf("%d %d %d ", &n, &m, &k);
        gets(sn); gets(sm);
        fillarr(sum, 0);
        for (int i = 1;i <= k;i++)
                for (int j = 1;j <= n;j++) for (int t = 1;t <= m;t++) {
                        if (sn[j - 1] == sm[t - 1])
                                sum[j][t][i][1] = max(sum[j - 1][t - 1][i - 1][0], sum[j - 1][t - 1][i][1]) + 1;
                        sum[j][t][i][0] = max(sum[j][t][i][1], max(sum[j - 1][t][i][0], sum[j][t - 1][i][0]));
                }
        printf("%d\n", sum[n][m][k][0]);
        return 0;
}

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
#define N 1005

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, k, ans;
int a[N], f[N][55];
int getMod(int x, int y, int md) {
        return (x + y) % md;
}
int main() {
        //freopen("exam.inp","r", stdin);
        //freopen("exam.out","w", stdout);
        scanf("%d %d", &n, &k);
        for (int i = 1;i <= n;i++) {
                scanf("%d", &a[i]);
                a[i] %= k;
        }
        f[0][0] = ans = 0;
        for (int i = 1;i < k;i++) f[0][i] = -INF;
        for (int i = 1;i <= n;i++)
                for (int j = 0;j < k;j++) {
                        f[i][j] = max(f[i - 1][j], f[i - 1][getMod(j, a[i], k)] + 1);
                        if (j == 0) ans = max(ans, f[i][j]);
                }
         printf("%d\n", ans);
}

/***********************************************
* Author LUONG VAN DO                        *
* Problem 10667 - Largest Block
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

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 111222333
#define N 110

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int sum[N][N], d[N][N];
bool check(int r1, int c1, int r2, int c2) {
    int total = d[r2][c2] - d[r1 - 1][c2] - d[r2][c1 - 1] + d[r1 - 1][c1 - 1];
    return (total == 0);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, r1, c1, r2, c2;
    int n, q, ans;
    scanf("%d", &cases);
    while (cases--) {
        fill(sum, 0); fill(d, 0);
        scanf("%d", &n);
        scanf("%d", &q);
        while (q--) {
            scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
            for (int i = r1;i <= r2;i++)
                for (int j = c1; j <= c2;j++)
                    sum[i][j] = 1;
        }
        for (int i = 1;i <= n;i++) d[1][i] = d[1][i - 1] + sum[1][i];
        
        for (int i = 2;i <= n;i++) {
            for (int j = 1;j <= n;j++) d[i][j] = d[i][j - 1] + sum[i][j];
            for (int j = 1;j <= n;j++) d[i][j] += d[i - 1][j];
        }
        ans = 0;
        for (int i = 1;i <= n;i++)
            for (int j = i;j <= n;j++)
                for (int i1 = 1;i1 <= n;i1++)
                    for (int j1 = i1;j1 <= n;j1++)
                        if ( check(i, i1, j, j1) ) ans = max(ans, (j - i + 1) * (j1 - i1 + 1));
        printf("%d\n", ans);
    }
}

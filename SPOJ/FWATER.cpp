/***********************************************
* Author LUONG VAN DO                        *
* Problem FWATER
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
#define N 310

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
int a[N][N], n, mark[N], d[N], trace[N];
int solve() {
    int Min, ans, u;
    for (int i = 0;i <= n;i++) {
        d[i] = INF;
        trace[i] = 0;
        mark[i] = 1;
    }
    d[0] = 0;
    for (int i = 0;i <= n;i++) {
        Min = INF;
        for (int j = 0;j <= n;j++)
            if (mark[j] && d[j] < Min) {
                Min = d[j];
                u = j;
            }
        mark[u] = 0;
        for (int v = 0; v<=n;v++) {
            if (mark[v] && d[v] > a[u][v]) {
                d[v] = a[u][v];
                trace[v] = u;
            }
        }
    }
    ans = 0;
    for (int i = 1;i <= n;i++)
        ans+=a[trace[i]][i];
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int x;
    scanf("%d", &n);
    for (int i = 1;i <= n;i++) {
        scanf("%d", &x);
        a[i][0] = x;
        a[0][i] = x;
    }
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) scanf("%d", &a[i][j]);
    printf("%d\n", solve());
}

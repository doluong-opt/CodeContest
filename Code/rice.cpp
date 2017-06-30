/***********************************************
* Author - LUONG VAN DO                        *
* Problem
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
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i = b;i >= a;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define pb push_back
#define ff first
#define ss second
#define fill(arr, val) memset(arr, val, sizeof(arr))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint32 unsigned int
#define INF 1000000000
#define N 5000100
#define MAX_LOG 16
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
int n, t, a[N], ans, lf, rt, curMin, curMax;
int posMin[N][MAX_LOG];
int posMax[N][MAX_LOG];
int getMin(int u, int v) {
    int k = log2(v - u + 1);
    if ( a[posMin[u][k]] <= a[posMin[v - (1 << k) + 1][k]] ) return a[posMin[u][k]];
    return a[posMin[v - (1 << k) + 1][k]];
}
int getMax(int u, int v) {
    int k = log2(v - u + 1);
    if ( a[posMax[u][k]] >= a[posMax[v - (1 << k) + 1][k]] ) return a[posMax[u][k]];
    return a[posMax[v - (1 << k) + 1][k]];
}
int main() {
	freopen("rice.inp","r", stdin); freopen("exam.out","w", stdout);
    scanf("%d %d", &n, &t);
    for (int i = 0;i < n;i++) scanf("%d", &a[i]);
    for (int i = 0;i < n;i++) posMin[i][0] = posMax[i][0] = i;
    for (int j = 1;(1 << j) <= n;j++)
        for (int i = 0;(i + (1 << j) - 1) < n;i++) {
            if ( a[posMin[i][j - 1]] < a[posMin[i + (1 << (j - 1))][j - 1]])
                posMin[i][j] = posMin[i][j - 1];
            else
                posMin[i][j] = posMin[i + (1 << (j - 1))][j - 1];

            if ( a[posMax[i][j - 1]] > a[posMax[i + (1 << (j - 1))][j - 1]])
                posMax[i][j] = posMax[i][j - 1];
            else
                posMax[i][j] = posMax[i + (1 << (j - 1))][j - 1];
        }
    ans = 0;
    for (int i = 0;i < n;i++) {
        lf = i; rt = n - 1;
        while (lf <= rt) {
            int mid = (lf + rt) >> 1;
            curMin = getMin(i, mid);
            curMax = getMax(i, mid);
            if ( curMax - curMin <= t ) {
                ans = max(ans, mid - i + 1);
                lf = mid + 1;
            }
            else rt = mid - 1;
        }
    }
    printf("%d\n", ans);
	return 0;
}

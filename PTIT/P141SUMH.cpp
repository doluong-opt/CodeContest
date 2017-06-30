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
#define INF 2000000000
#define N 1111

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
int n, a[N][7], ans;
bool isOk(int x, int y) {
    int x1, y1, z1, x2, y2, z2;
    x1 = y1 = z1 = -INF;
    x2 = y2 = z2 = INF;
    x1 = max(x1, a[x][1]); y1 = max(y1, a[x][2]); z1 = max(z1, a[x][3]);
    x2 = min(x2, a[x][4]); y2 = min(y2, a[x][5]); z2 = min(z2, a[x][6]);
    
    x1 = max(x1, a[y][1]);
    y1 = max(y1, a[y][2]);
    z1 = max(z1, a[y][3]);
    x2 = min(x2, a[y][4]);
    y2 = min(y2, a[y][5]);
    z2 = min(z2, a[y][6]);
    int64 dx, dy, dz;
    dx = x2 - x1; dy = y2 - y1; dz = z2 - z1;
    int64 ans = dx * dy * dz;
    return (ans > 0);
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n);
	fr(i, 1, n) fr(j, 1, 6) scanf("%d", &a[i][j]);
	ans = 0;
	fr(i, 1, n)
        fr(j, i + 1, n)
            if (isOk(i, j)) ans++;
    printf("%d\n", ans);
	return 0;
}

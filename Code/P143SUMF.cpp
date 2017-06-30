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
#define N 55
#define limit 2500000
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
int n, a[N][N];
int sum[N][N], cnt[limit + limit];
int64 ans;
int getVal(int x1, int y1, int x2, int y2) {
    if (x1 <= x2 && y1 <= y2)
        return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
    else
        return 0;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n);
	fr(i, 1, n) fr(j, 1, n) scanf("%d", &a[i][j]);
	sum[1][0] = 0;
	fr(i, 1, n) sum[1][i] = sum[1][i - 1] + a[1][i];
	fr(i, 2, n) {
        fr(j, 1, n)
            sum[i][j] = sum[i][j - 1] + a[i][j];
        fr(j, 1, n)
            sum[i][j] += sum[i - 1][j];
	}
	ans = 0LL; fill(cnt, 0);
	fr(i, 1, n) fr(j, 1, n) {
	    for (int x = 1;x <= i;x++)
            for (int y = 1;y <= j;y++)
                cnt[getVal(x, y, i, j) + limit]++;
                
        for (int x = i + 1;x <= n;x++)
            for (int y = j + 1;y <= n;y++)
                ans += cnt[getVal(i + 1, j + 1, x, y) + limit];
            
        for (int x = 1;x <= i;x++)
            for (int y = 1;y <= j;y++)
                cnt[getVal(x, y, i, j) + limit]--;
        
        for (int x = 1;x <= i;x++)
            for (int y = j;y <= n;y++)
                cnt[getVal(x, j, i, y) + limit]++;
                
        for (int x = i + 1;x <= n;x++)
            for (int y = 1;y <= j - 1;y++)
                ans += cnt[getVal(i + 1, y, x, j - 1) + limit];
        
        for (int x = 1;x <= i;x++)
            for (int y = j;y <= n;y++)
                cnt[getVal(x, j, i, y) + limit]--;
	}
	printf("%lld\n", ans);
	return 0;
}

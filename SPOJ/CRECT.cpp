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
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 444

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
int n, m, x[6], y, a[N][N];
int64 ans, dp[N], posLeft[N], f[N][N];
char s[N][N];
int64 calc(int rowCur) {
    dp[0] = 0LL; fill(posLeft, 0);
    f[rowCur][0] = -1;
    for (int i = 1;i <= n;i++) {
        posLeft[i] = i - 1;
        while ( f[rowCur][i] <= f[rowCur][posLeft[i]] ) posLeft[i] = posLeft[ posLeft[i] ];
    }
    int64 res = 0;
    for (int i = 1;i <= n;i++) {
        dp[i] = f[rowCur][i] * (i - posLeft[i]) + dp[posLeft[i]];
        res += dp[i];
    }
    return res;
}
int64 solve(int c1, int c2, int c3) {
    fill(f, 0);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            if ( a[j][i] == c1 || a[j][i] == c2 || a[j][i] == c3 )
                f[j][i] = f[j - 1][i] + 1;
    /*for (int i = 1;i <= m;i++) {
        for (int j = 1;j <= n;j++)
            printf("%lld ", f[i][j]);
            printf("\n");
    }*/
    int64 res = 0;
    for (int i = 1;i <= m;i++)
        res += calc(i);
    return res;
}
int64 solveMain(int c1, int c2, int c3) {
    int64 res = solve(c1, c2, c3);    
    res -= solve(c1, c1, c2);
    //res -= solve(c1, c1, c3);
    //res -= solve(c2, c2, c1);
    res -= solve(c2, c2, c3);    
    res -= solve(c3, c3, c1);
    //res -= solve(c3, c3, c2);
    res += solve(c1, c1, c1);
    res += solve(c2, c2, c2);
    res += solve(c3, c3, c3);
    return res;
}
int main() {
	//freopen("DDD.INP","r", stdin); freopen("DDD.OUT","w", stdout);
	scanf(" %d %d ", &m, &n);
	rep(i, m) gets(s[i]);	
	rep(i, m)
        rep(j, n) a[i + 1][j + 1] = s[i][j] - 'A';
	for (int i = 1;i <= 3;i++) x[i] = i;
	ans = 0LL;
	do {
	    ans += solveMain(x[1] - 1, x[2] - 1, x[3] - 1);	    
	    //for (int i = 1;i <= 3;i++) printf("%d ", x[i]);
	    //puts("");
	    y = 3;
	    while (y >= 1 && x[y] == y + 2) --y;
	    if (y > 0) {
	        x[y]++;
	        for (int j = y + 1;j <= 3;j++)
                x[j] = x[j - 1] + 1;
	    }
	}while (y != 0);
	printf("%lld\n", ans);
	return 0;
}


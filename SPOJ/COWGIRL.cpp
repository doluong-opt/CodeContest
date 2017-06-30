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
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 32

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
int64 dp[N][1<<6], res;
int m, n, lim;
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, x, y;
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d %d", &m, &n);
	    if (m > n) swap(m, n);
	    lim = (1<<m);
	    for (int i = 0;i < n;i++)
            for (int j = 0;j < lim;j++) dp[i][j] = 0;
        for (int i = 0;i < lim;i++) dp[0][i] = 1LL;
        
        for (int i = 1;i < n;i++)
            for (int mask1 = 0;mask1 < lim;mask1++) {
                for (int mask2 = 0;mask2 < lim; mask2++) {
                    x = mask1 & mask2;
                    y = mask1 | mask2;
                    int flag = 1;
                    
                    for (int j = 0;j < m - 1 && flag;j++) {
                        if ( And(x, j) && And(x, j + 1) ) flag = 0;
                        if ( !And(y, j) && !And(y, j + 1) ) flag = 0;
                    }
                    if (flag) dp[i][mask2] += dp[i - 1][mask1];
                }
            }
        res = 0LL;
        for (int i = 0;i < lim;i++) res += dp[n - 1][i];
        printf("%lld\n", res);
	}
	return 0;
}


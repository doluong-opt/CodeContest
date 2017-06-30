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
#define N 111
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
int w, h, n, x, y;
int64 dp[N][N], ans;
int mark[N][N];
int64 run(int x, int y) {
    if (mark[x][y]) return 0LL;
    if (x == w && y == h) return 1LL;    
    int64 &res = dp[x][y];
    if (res != -1) return res;
    res = 0LL;
    if (x + 1 <= w && !mark[x + 1][y])
        res += run(x + 1, y);
    if (y + 1 <= h && !mark[x][y + 1])
        res += run(x, y + 1);
    return res;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while ( scanf("%d %d", &w, &h) && (w + h)) {
	    for (int i = 0;i <= w;i++)
            for (int j = 0;j <= h;j++) dp[i][j] = -1, mark[i][j] = 0;
	    scanf("%d", &n);
	    fr(i, 1, n) {
	        scanf("%d %d", &x, &y);
	        mark[x][y] = 1;
	    }
	    ans = run(0, 0);
	    if (!ans)
            printf("There is no path.\n");
        else 
        if (ans == 1)
            printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
        else 
            printf("There are %lld paths from Little Red Riding Hood's house to her grandmother's house.\n", ans);
	}
	return 0;
}

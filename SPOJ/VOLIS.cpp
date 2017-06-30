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
#define N 2222

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
struct node{
    int x, y;
    node(){}
    node(int _x, int _y) {
        x = _x; y = _y;
    }
};
int n, d, val, curN, curM, ans;
int tempA[N], dp[N][N], maxCur[N][N];
node a[N], b[N];
bool cmp(node a, node b) {
    return a.x < b.x;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d", &n, &d);
	curN = curM = 0;
	fr(i, 1, n) {
	    scanf("%d", &val);
	    ++curN;
	    b[curN] = node(val - d, curN);
	    ++curN;
	    b[curN] = node(val + d, curN);
	}
	sort(b + 1, b + curN + 1, cmp);
    b[0].x = b[1].x - 1;
    fr(i, 1, curN) {
        if (b[i].x > b[i - 1].x) curM++;
        tempA[b[i].y] = curM;
    }
    for (int i = 1;i <= curN;i += 2) a[i / 2 + 1] = node(tempA[i], tempA[i + 1]);
    fill(dp, 0); fill(maxCur, 0);
    fr(v, a[1].x, a[1].y) {
        dp[1][v] = 1;
        maxCur[1][v] = 1;
    }
    fr(i, 1, curM) maxCur[1][i] = max(maxCur[1][i - 1], dp[1][i]);
    for (int i = 2;i <= n;i++) {
        for (int j = a[i].x;j <= a[i].y;j++)
            dp[i][j] = max(dp[i][j], maxCur[i - 1][j] + 1);
        for (int j = 1;j <= curM;j++)
            maxCur[i][j] = max(dp[i][j], max(maxCur[i - 1][j], maxCur[i][j - 1]));
    }
    ans = 0;
    fr(i, 1, n) fr(j, 1, curM) ans = max(ans, dp[i][j]);
    printf("%d\n", ans);
	return 0;
}

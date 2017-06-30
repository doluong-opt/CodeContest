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
#define N 100100

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
int64 dp[55][55][555], ans;
int a[55][55], n, s, posStart;
string path;
int64 solve(int row, int col, int sum) {
    if (row == 2 * n - 1) {
        if (sum == a[row][col]) return 1LL;
        return 0LL;
    }
    int64 &res = dp[row][col][sum];
    if (res != -1) return res;
    res = 0LL;
    if (row <= n - 1) {
        if (col - 1 >= 1 && col - 1 <= a[row + 1][0] && sum >= a[row][col]) res += solve(row + 1, col - 1, sum - a[row][col]);
        if (col <= a[row + 1][0] && sum >= a[row][col]) res += solve(row + 1, col, sum - a[row][col]);
    }
    else {
        if (col <= a[row + 1][0] && sum >= a[row][col]) res += solve(row + 1, col, sum - a[row][col]);
        if (col + 1 <= a[row + 1][0] && sum >= a[row][col]) res += solve(row + 1, col + 1, sum - a[row][col]);
    }
    return res;
}
void findPath(int row, int col, int sum) {
    if (row == 2 * n) return;
    int64 total;
    if (row <= n - 1) {
        if (col - 1 >= 1 && col - 1 <= a[row + 1][0]) {
            total = solve(row + 1, col - 1, sum - a[row][col]);
            if (total > 0) {
                path += "L";
                findPath(row + 1, col - 1, sum - a[row][col]);
                return;
            }
        }
        if (col <= a[row + 1][0]) {
            total = solve(row + 1, col, sum - a[row][col]);
            if (total > 0) {
                path += "R";
                findPath(row + 1, col, sum - a[row][col]);
                return;
            }
        }
    }
    else {
        if (col <= a[row + 1][0]) {
            total = solve(row + 1, col, sum - a[row][col]);
            if (total > 0) {
                path += "L";
                findPath(row + 1, col, sum - a[row][col]);
                return;
            }
        }
        if (col + 1 <= a[row + 1][0]) {
            total = solve(row + 1, col + 1, sum - a[row][col]);
            if (total > 0) {
                path += "R";
                findPath(row + 1, col + 1, sum - a[row][col]);
                return;
            }
        }
    }
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while ( scanf("%d %d",&n, &s) && (n + s)) {
	    for (int i = 1;i <= n;i++) {
	        a[i][0] = n - i + 1;
	        for (int j = 1;j <= a[i][0];j++) scanf("%d", &a[i][j]);
	    }
	    for (int i = n + 1;i <= 2 * n - 1;i++) {
	        a[i][0] = i - n + 1;
	        for (int j = 1;j <= a[i][0];j++) scanf("%d", &a[i][j]);
	    }
	    fill(dp, -1); ans = 0LL; path = "";
	    posStart = 0;
	    for (int i = 1;i <= n;i++) {
            if (s >= a[1][i]) {
                ans += solve(1, i, s);
                if ( !posStart && ans > 0 ) {
                    posStart = i;
                    findPath(1, i, s);
                }
            }
	    }
	    printf("%lld\n", ans);
	    if (ans > 0) cout << posStart - 1 <<" "<<path<<endl;
	    else puts("");
	}
	return 0;
}

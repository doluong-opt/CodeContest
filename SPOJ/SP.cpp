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
#define N 222

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
    int x, y, z;
    node(){}
    node(int _x, int _y, int _z){
        x = _x; y = _y; z = _z;
    }
};
int dp[N][N][N], ans;
vector<node> d;
int a, b, c, s;
bool isOk(int x, int y, int z) {
    return (x >= 0 && y >= 0 && z >= 0);
}
int run(int a, int b, int c) {
    int &res = dp[a][b][c];
    if (res != -1) return res;
    res = 0;
    int sum = a + 2 * b + 3 * c;
    rep(i, d.size()) {
        int nx = a - d[i].x;
        int ny = b - d[i].y;
        int nz = c - d[i].z;
        if ( isOk(nx, ny, nz) ) res = max(res, run(nx, ny, nz) + 1);
        if ( res >= sum / s ) break;
    }
    return res;
}
int main() {
	freopen("exam.INP","r", stdin); freopen("exam.OUT","w", stdout);
	scanf("%d %d %d %d", &a, &b, &c, &s);
	if (s == 1) {
	    printf("%d\n", a + b + c);
	    return 0;
	}
	if (s == 2) {
	    printf("%d\n", (a / 2) + b + c);
	    return 0;
	}
	if (s == 3) {
	    int x = min(a, b);
	    printf("%d\n", x + c);
	    return 0;
	}
	fill(dp, -1);
	for (int i = 0;i <= a && i <= s;i++)
        for (int j = 0;j <= b && i + 2 * j <= s;j++) {
            for (int k = 0;k <= c;k++) {                
                if (i + 2 * j + 3 * k >= s) {
                    dp[i][j][k] = 1;
                    d.pb(node(i, j, k));
                    break;
                }
            }
        }
	printf("%d\n", run(a, b, c));
	return 0;
}

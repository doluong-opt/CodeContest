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
#define N 111
#define M 10011

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
    int w, v, a;
    node(){}
    node(int ww, int vv, int aa){
        w = ww; v = vv; a = aa;
    }
};
node gold[N];
int n, m, ans;
int dp[N][M][10];
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d", &n, &m);
	fr(i, 1, n) scanf("%d %d %d", &gold[i].w, &gold[i].v, &gold[i].a);
	fill(dp, 0);
	fr(i, 1, n) fr(j, 1, m) {
        for (int k = 0; (1 << k) <= gold[i].a; k++) {
            int w = (1 << k) * gold[i].w;
            if (j >= w) dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - w][k] + (1 << k) * gold[i].v);
        }
	}
	ans = 0;
	/*for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            for (int k = 0;k < 10;k++)
                cout <<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;	*/
    rep(i, 10) cout << dp[n][m][i] << endl;
	printf("%d\n", ans);
	return 0;
}

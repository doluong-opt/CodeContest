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
#define M 1000007
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
int n, nx, ny, res;
char s[N][N];
int dp[N][N];
ii st;
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
	scanf("%d", &cases);
	while (cases--) {
	    scanf(" %d ", &n);
	    rep(i, n) gets(s[i]);
	    rep(i, n) rep(j, n) {
	        dp[i][j] = 0;
	        if (s[i][j] == 'W') dp[i][j] = 1, st = ii(i, j);
	    }
	    for (int i = st.ff - 1;i >= 0;i--) for (int j = 0;j < n;j++) {
            if (i + 1 < n && j + 1 < n && s[i][j] == '.' && s[i + 1][j + 1] == 'W' || s[i + 1][j + 1] == '.') {
                dp[i][j] += dp[i + 1][j + 1];
                if (dp[i][j] > M) dp[i][j] -= M;
            }
            if (i + 1 < n && j - 1 >= 0 && s[i][j] == '.' && s[i + 1][j - 1] == 'W' || s[i + 1][j - 1] == '.') {
                dp[i][j] += dp[i + 1][j - 1];
                if (dp[i][j] > M) dp[i][j] -= M;
            }
            if (i - 1 >= 0 && j - 1 >= 0 && s[i][j] == 'B' && s[i - 1][j - 1] == '.' && (s[i + 1][j + 1] == '.' || s[i + 1][j + 1] == 'W')) {
                dp[i - 1][j - 1] += dp[i + 1][j + 1];
                if (dp[i - 1][j - 1] > M) dp[i - 1][j - 1] -= M;
            }
            if (i - 1 >= 0 && j + 1 < n && s[i][j] == 'B' && s[i - 1][j + 1] == '.' && (s[i + 1][j - 1] == '.' || s[i + 1][j - 1] == 'W')) {
                dp[i - 1][j + 1] += dp[i + 1][j - 1];
                if (dp[i - 1][j + 1] > M) dp[i - 1][j + 1] -= M;
            }
	    }
	    /*rep(i, n) cout << s[i] << endl;
	    cout << endl;
	    rep(i, n) {
	        rep(j, n)
                cout << dp[i][j]<<" ";
            cout<<endl;
	    }*/
	    res = 0;
	    rep(i, n) {
            if (s[0][i] == '.') res += dp[0][i];
            if (res > M) res -= M;
        }
        printf("Case %d: %d\n", ++caseno, res);
	}
	return 0;
}

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
#define N 360

using namespace std;

inline uint64 max(uint64 a, uint64 b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
uint64 dp[N][N], ans;
int p[N], m, n;
vector <int> prime;
void sieve() {
    for (int i = 0;i < N;i++) p[i] = 1; p[0] = p[1] = 0;
    for (int i = 3;i * i < N;i += 2)
        if (p[i])
            for (int j = i * i;j < N;j += 2 * i) p[j] = 0;
    prime.pb(2);
    for (int i = 3;i < N;i += 2)
        if (p[i]) prime.pb(i);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
	sieve(); m = prime.size();
	fill(dp, 0);
    for (int i = 0;i <= m;i++) dp[0][i] = dp[1][i] = 1LL;            
	for (int i = 1;i <= 350;i++) {
        for (int j = 1;j <= m;j++) {
            dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
            int temp = prime[j - 1];
            while (temp <= i) {
                dp[i][j] = max(dp[i][j], max(dp[i - prime[j - 1]][j - 1] * prime[j - 1], dp[i - temp][j - 1] * temp));
                temp *= prime[j - 1];
            }
        }
    }
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d", &n);
        ans = 0LL;
        for (int i = 1;i <= m;i++)
            if (ans < dp[n][i]) ans = dp[n][i];
        cout << ans << endl;
	}
	return 0;
}

/***********************************************
* Author LUONG VAN DO                        *
* Problem 1036 - A Refining Company 
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

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 111222333
#define N 510

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
int dp[N][N], a[N][N], b[N][N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, m, n, caseno = 0;
    int up, right;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d", &m, &n);
        fr(i, 1, m)
            fr(j, 1, n) scanf("%d", &a[i][j]);
        fr(i, 1, m)
            fr(j, 1, n) scanf("%d", &b[i][j]);
        fr(i, 1, m) dp[i][0] = 0;
        fr(i, 1, n) dp[0][i] = 0;
        
        fr(i, 1, m)
            fr(j, 1, n) {
                up = right = 0;
                fr(k, 1, i)
                    up += b[k][j];
                fr(k, 1, j)
                    right += a[i][k];
                
                up += dp[i][j - 1];
                right += dp[i - 1][j];
                dp[i][j] = max(up, right);
                
            }
        printf("Case %d: %d\n", ++caseno, dp[m][n]);
    }
}

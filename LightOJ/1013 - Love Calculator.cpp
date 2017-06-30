/***********************************************
* Author LUONG VAN DO                        *
* Problem 1013 - Love Calculator 
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
#define N 40

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
int64 dp[2 * N][N][N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, m, caseno = 0, minLen;
    char s1[N], s2[N];
    string A, B;
    scanf(" %d ", &cases);
    while (cases--) {
        gets(s1); n = strlen(s1);
        gets(s2); m = strlen(s2);
        A = B = " ";
        A += s1; B += s2;
        fill(dp, 0);
        dp[0][0][0] = 1;
        fr(i, 1, n + m)
            fr(j, 0, n)
                fr(k, 0, m)
                    if (j && k) {
                        if (A[j] == B[k]) dp[i][j][k]+=dp[i - 1][j - 1][k - 1];
                        else dp[i][j][k]+=dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1];
                    }
                    else
                    if (!j || !k) {
                        if (j) dp[i][j][k]+=dp[i - 1][j - 1][k];
                        if (k) dp[i][j][k]+=dp[i - 1][j][k - 1];
                    }
        fr(i, 0, n + m)
            if (dp[i][n][m] > 0) {
                minLen = i;
                break;
            }
        printf("Case %d: %d %lld\n", ++caseno, minLen, dp[minLen][n][m]);
    }
}

/***********************************************
* Author LUONG VAN DO                        *
* Problem 526 - String Distance and Transform Process
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
#define N 110

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
int dp[N][N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    char s1[N], s2[N];
    int n, m, flag = 0, run, i1, i2, cnt;
    string a, b;
    while ( gets(s1) ) {
        gets(s2);
        n = strlen(s1); m = strlen(s2);
        a =  " "; b = "*";
        a += s1; b += s2;
        fr(i, 1, n)
            dp[i][0] = i;
        fr(i, 1, m)
            dp[0][i] = i;
        fr(i, 1, n)
            fr(j, 1, m)
                if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
        
        if (flag) puts("");
        flag = 1;
        printf("%d\n", dp[n][m]);
        i1 = n; i2 = m; run = dp[n][m]; cnt = 0;
        while (run) {
            if (a[i1] == b[i2]) {
                i1--;
                i2--;
            }
            else {
                if (i1 - 1 >= 0 && dp[i1][i2] == dp[i1 - 1][i2] + 1) {
                    printf("%d", ++cnt);
                    printf(" Delete %d\n", i1);                    
                    i1--;
                }
                else
                if (i1 - 1 >= 0 && i2 - 1 >= 0 && dp[i1][i2] == dp[i1 - 1][i2 - 1] + 1) {
                    printf("%d", ++cnt);
                    printf(" Replace %d,%c\n", i1, s2[i2 - 1]);
                    i1--;
                    i2--;
                }
                else
                if (i2 - 1 >= 0 && dp[i1][i2] == dp[i1][i2 - 1] + 1) {
                    printf("%d", ++cnt);
                    printf(" Insert %d,%c\n", i1 + 1, s2[i2 - 1]);
                    i2--;
                }
                run--;
            }
        }
    }
}

/***********************************************
* Author LUONG VAN DO                        *
* Problem 164 - String Computer
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
#define N 101

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
int dp[N][N], n, m;
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    char s1[N], s2[N];
    string a, b;
    int steps, x, y;
    while ( scanf("%s", s1) && strcmp(s1, "#")) {
        scanf("%s", s2);
        n = strlen(s1); m = strlen(s2);
        a = " "; b = "*";
        a += s1; b += s2;
        fr(i, 1, n) dp[i][0] = i;
        fr(i, 1, m) dp[0][i] = i;
        
        fr(i, 1, n)
            fr(j, 1, m)
                if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                
        steps = dp[n][m]; x = n; y = m;
        while ( steps ) {
            if (a[x] == b[y]) {
                x--;
                y--;
            }
            else {
                if (y - 1 >= 0 && dp[x][y] == dp[x][y - 1] + 1) {
                    printf("I%c", b[y]);
                    y--;
                    printf("%02d", x + 1);
                }
                else
                if (x - 1 >= 0 && dp[x][y] == dp[x - 1][y] + 1) {
                    printf("D%c", a[x]);
                    printf("%02d", x);
                    x--;
                }
                else
                if (x - 1 >= 0 && y - 1 >= 0 && dp[x][y] == dp[x - 1][y - 1] + 1) {
                    printf("C%c", b[y]);
                    printf("%02d", x);
                    x--;
                    y--;
                }
                steps--;
            }
        }
        puts("E");
    }
}

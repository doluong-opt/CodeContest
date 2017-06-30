/***********************************************
* Author LUONG VAN DO                        *
* Problem 1051 - Good or Bad 
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
#define N 55

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
int dp[N][4][6], n;
char s[N];
int check(char c) {
    if (c == '?') return 2;
    return (c == 'A' || c == 'E' || c == 'O' || c == 'U' || c == 'I');
}
int run(int cur, int x, int y) {
    if (x >= 3 || y >= 5) return 0;
    if (cur == n) return 1;
    int &res = dp[cur][x][y];
    if (res != -1) return res;
    if ( check(s[cur]) == 2) {
        int xx = run(cur + 1, x + 1, 0);
        int yy = run(cur + 1, 0, y + 1);
        if (xx == 1 && yy == 1) return res = 1;
        else
        if (xx == 0 && yy == 0) return res = 0;
        else return res = 2;
    }
    else {
        if ( check(s[cur]) == 1) res = run(cur + 1, x + 1, 0);
        else res = run(cur + 1, 0, y + 1);
    }
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, ans, caseno = 0;
    scanf(" %d ", &cases);
    while (cases--) {
        gets(s); n = strlen(s);
        fill(dp, -1);
        ans = run(0, 0, 0);
        printf("Case %d: ", ++caseno);
        if (ans == 0) puts("BAD");
        else
        if (ans == 1) puts("GOOD");
        else puts("MIXED");
    }
}

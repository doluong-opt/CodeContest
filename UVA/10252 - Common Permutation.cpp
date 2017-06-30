/***********************************************
* Author LUONG VAN DO                        *
* Problem 10252 - Common Permutation
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
#define N 1100

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
string dp[N][N];
string Smin(string a, string b) {
    if ( a.length() != b.length() ) return (a.length() > b.length() ? a : b);
    return a < b ? a : b;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    char s1[N], s2[N];
    string a, b;
    int n, m;
    while (gets(s1)) {
        gets(s2);
        sort(s1, s1 + strlen(s1));
        sort(s2, s2 + strlen(s2));
        n = strlen(s1); m = strlen(s2);
        a = b = " ";
        a += s1; b += s2;
        fr(i, 0, n)
            fr(j, 0, m) dp[i][j] = "";
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= m;j++)
                if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + a[i];
            else
                dp[i][j] = Smin(dp[i][j], Smin(dp[i - 1][j], dp[i][j - 1]));
        cout << dp[n][m] << endl;
    }
}

/***********************************************
* Author LUONG VAN DO                        *
* Problem 1021 - Painful Bases 
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
#define N 17

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
int64 dp[1<<N][25];
int num[N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, n, d, base, lim;
    char s[N];
    scanf("%d", &cases);
    while (cases--) {
        scanf(" %d %d ",&base, &d);
        gets(s); n = strlen(s);
        fill(dp, 0); dp[0][0] = 1;
        rep(i, n)
            if (s[i] >= 'A' && s[i] <= 'Z') num[i] = s[i] - 'A' + 10;
            else num[i] = s[i] - '0';
        lim = (1<<n);
        rep(i, lim)
            rep(j, d) {
                if (!dp[i][j]) continue;
                rep(k, n) {
                    if ( And(i, k) ) continue;
                    dp[Or(i, k)][(j * base + num[k]) % d]+=dp[i][j];
                }
            }
        printf("Case %d: %lld\n", ++caseno, dp[lim - 1][0]);
    }
}

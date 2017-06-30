 /***********************************************
* Author LUONG VAN DO                        *
* Problem 11218 - KTV
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
#define N 85
#define M 1100
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
int n, lim, id, m;
int a[N], b[N], c[N], w[N];
int dp[1<<10];
char s[M];
int run(int mask) {
    if ( mask == lim - 1 ) return 0;
    int &res = dp[mask];
    if (res != -1) return res;
    res = -INF;
    int x, y, z;
    for (int i = 1;i <= n;i++) {
        x = a[i] - 1; y = b[i] - 1; z = c[i] - 1;
        if ( !And(mask, x) && !And(mask, y) && !And(mask, z) ) {
            int nextmask = Or(Or(Or(mask, x), y), z);
            int Cost = w[i] + run(nextmask);
            res = max(res, Cost);
        }
    }
    return res;
}
int getInt() {
    int v = 0;
    while (id < m && s[id] != ' ') v = v * 10 + s[id++] - '0';
    ++id;
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int ans, caseno = 0;
    while ( gets(s) && strcmp(s, "0")) {
        id = 0; m = strlen(s); n = getInt();
        fr(i, 1, n) {
            gets(s); id = 0; m = strlen(s);
            a[i] = getInt(); b[i] = getInt(); c[i] = getInt(); w[i] = getInt();
        }
        fill(dp, -1); lim = (1<<9);
        ans = run( 0 );
        if ( ans >= 0 ) printf("Case %d: %d\n", ++caseno, ans);
        else printf("Case %d: -1\n", ++caseno);
    }
}

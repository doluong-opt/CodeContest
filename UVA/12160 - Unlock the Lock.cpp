/***********************************************
* Author LUONG VAN DO                        *
* Problem 12160 - Unlock the Lock
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
#define N 100000
#define C 10000
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int dp[N], a[N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int u, l, r, flag, x, y;
    int caseno = 0;
    while (scanf("%d %d %d", &l, &u, &r) && (u + l + r)) {
        for (int i = 0;i < r;i++) scanf("%d", &a[i]);
        for (int i = 0;i < 10000;i++) dp[i] = INF;
        queue <int> q; 
        q.push(l); dp[l] = 0;
        while ( !q.empty() ) {
            x = q.front(); q.pop();
            for (int i = 0; i < r;i++) {
                y = (x + a[i]) % C;
                if (dp[y] > dp[x] + 1) {
                    dp[y] = dp[x] + 1;
                    q.push(y);
                }
            }
        }
        if (dp[u] != INF) printf("Case %d: %d\n", ++caseno, dp[u]);
        else printf("Case %d: Permanently Locked\n", ++caseno);
    }
}

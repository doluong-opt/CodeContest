/***********************************************
* Author LUONG VAN DO                        *
* Problem 11003 - Boxes
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
#define N 1010

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
int n, dp[N];
ii a[N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int total, i, j, cnt;
    while ( scanf("%d", &n) && n) {
        for (i = 1;i <= n;i++) scanf("%d %d", &a[i].ff, &a[i].ss);
        fill(dp, 0);
        a[0].ss = -1;
        dp[1] = dp[0] = 1;
        for (i = 2;i <= n;i++) {
            total = 0;
            for (j = i;j >= 1;j--) {
                total+=a[j].ff;
                if (total > a[j - 1].ss) {
                    if (dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
                    total = a[j].ff;
                }
            }
        }
        
        fr(i, 1, n) cout<<dp[i]<<endl;
        printf("%d\n", dp[n]);
    }
}

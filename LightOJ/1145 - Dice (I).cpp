/***********************************************
* Author LUONG VAN DO                        *
* Problem 1145 - Dice (I) ->AC
* Algorithm dp
* Time Limit 0.469s
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
#define S 15100

#define MOD 100000007
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
int64 dp[S], f[S];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, n, k, s;
    int64 xx;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d %d",&n, &k, &s);
        f[0] = 0;
        
        fr(i, 1, s) {
            f[i] = f[i - 1] + (i <= k ? 1 : 0);
            dp[i] = (i <= k ? 1 : 0);
        }
        
        fr(i, 2, n) {
            fr(j, 1, s) {
                xx = (j > k ? f[j - 1] - f[j - k - 1] : f[j - 1]);
                while (xx < 0) xx+=MOD;
                xx%=MOD;
                dp[j] = xx;
            }
            fr(j, 1, s) {
                f[j] = f[j - 1] + dp[j];
                f[j]%=MOD;
            }
        }
        printf("Case %d: %lld\n", ++caseno, dp[s]);
    }
}

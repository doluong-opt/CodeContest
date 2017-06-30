/***********************************************
* Author LUONG VAN DO                        *
* Problem 1193 - Dice (II) ->AC
* Algorithm dp
* Time Limit 0.135s
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
#define S 15010
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

int64 dp[S], f[S], g[S];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, k, s, caseno = 0;
    int64 sumCur, sumIn;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d %d",&n, &k, &s);
        fill(f, 0); fill(dp, 0);
        fr(i, 1, n) {
            f[0] = (i == 1 ? 1 : 0);
            sumCur = sumIn = 0;
            fr(j, 1, s) {
                sumCur+=f[j - 1];
                if (j > k) {
                    sumCur-=f[j - k - 1];
                    sumIn -=(k * f[j - k - 1]);
                }
                sumIn = sumIn + sumCur;
                dp[j] = (sumIn % MOD);
            }
            
            fr(j, 1, s)
                f[j] = dp[j];
        }
        
        printf("Case %d: %lld\n",++caseno, dp[s]);
    }
}

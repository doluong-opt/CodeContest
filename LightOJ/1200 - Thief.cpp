/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1200 - Thief ->AC
* Algorithm dp
* Time Limit 0.14s
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

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define M 100000

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
struct items{
    int p, c, w;
    items(){}
    items(int pp, int cc, int ww){
        p = pp; c = cc; w = ww;
    }
};
items a[105];
bool use[M];
int dp[M], n;
int run(int m) {
    memset(use, false, sizeof(use));
    memset(dp, 0, sizeof(dp));
    use[0] = 1;
    for (int i=0;i<n;i++)
        for (int j=0;j<=m - a[i].w;j++)
            if (use[j]) {
                use[j + a[i].w] = true;
                dp[j + a[i].w] = max(dp[j + a[i].w], dp[j] + a[i].p);
            }
    int Ans = 0;
    for (int j=0;j<=m;j++)
        Ans = max(Ans, dp[j]);
    return Ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    int W, w;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d",&n,&W);
        w = 0;
        for (int i=0;i<n;i++) {
            scanf("%d %d %d",&a[i].p,&a[i].c,&a[i].w);
            w+=(a[i].c * a[i].w);
        }
        printf("Case %d: ",++caseno);
        if (w > W) printf("Impossible\n");
        else printf("%d\n",run(W - w));
    }
}

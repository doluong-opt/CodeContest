/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10502 - Counting Rectangles ->AC
* Algorithm dp
* Time Limit 0.008s
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
#define M 105

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
int r, c;
char s[M + 1][M + 1];
int Left[M + 1];
int f[M + 1][M + 1], a[M + 1][M + 1];
int64 dp[M + 1], Ans;
void cal(int u) {
    for (int i=1;i<=c;i++) Left[i] = 0;
    f[u][0] = -1;
    for (int i=1;i<=c;i++) {
        Left[i] = i - 1;
        while ( f[u][i] <= f[u][ Left[i] ] ) Left[i] = Left[ Left[i] ];
    }
    dp[0] = 0;
    for (int i=1;i<=c;i++) {
        dp[i] = f[u][i] * (i - Left[i]) + dp[ Left[i] ];
        Ans+=dp[i];
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    while ( scanf(" %d ",&r) && r) {
        scanf(" %d ",&c);
        for (int i=0;i<r;i++) gets(s[i]);
        
        for (int i=0;i<r;i++)
            for (int j=0;j<c;j++) {
                a[i+1][j+1] = s[i][j] - '0';
                f[i+1][j+1] = 0;
            }
        Ans = 0;
        for (int i=1;i<=c;i++)
            for (int j=1;j<=r;j++)
                if ( a[j][i] ) f[j][i] = f[j-1][i] + 1;
        for (int i=1;i<=r;i++) cal( i );
        printf("%lld\n",Ans);
    }
}

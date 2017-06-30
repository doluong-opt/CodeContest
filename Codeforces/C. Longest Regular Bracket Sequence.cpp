/***********************************************
* Author - LUONG VAN DO                        *
* Problem C. Longest Regular Bracket Sequence ->AC
* Algorithm dp
* Time Limit 50ms
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
#define M 1000010

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
int dp[M];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    char s[M];
    stack <int> S;
    int ans, amount, nx, n;
    gets(s); n = strlen(s);
    ans = 0; amount = 1;
    memset(dp, 0, sizeof(dp));
    for (int i=0;i<n;i++) {
        if (s[i] =='(') S.push( i );
        else {
            if (S.empty()) continue;
            nx = i - S.top() + 1;
            if (S.top() > 0) nx+=dp[S.top()-1];
            if (nx > ans) {
                ans = nx;
                amount = 1;
            }
            else
            if (nx == ans) amount++;
            dp[i] = nx;
            S.pop();
        }
    }
    printf("%d %d\n",ans, amount);
}

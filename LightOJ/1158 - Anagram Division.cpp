/***********************************************
* Author - LUONG VAN DO                        *
* 1158 - Anagram Division 
* Algorithm dp bitmask
* Time Limit 0.651s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
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
#define maxN 50001
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int dp[(1<<11)][1005];
int n, d;
char s[11];
int Cal(int mu){
    int res = 1;
    FOR(i, 2, mu) res*=i;
    return res;
}
int get(){
    int inc = 0;
    int res = 1;
    sort(s, s + n);
    REP(i, n) {
        if (i && s[i] == s[i-1]) inc++;
        else {
            res*=Cal(inc);
            inc = 1;
        }
    }
    res*=Cal(inc);
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, lim;
    scanf(" %d ",&test);
    FOR(t, 1, test) {
        scanf("%s %d",s,&d);
        n = strlen(s);
        
        lim = (1<<n);
        for (int i=0;i<lim;i++)
            for (int j=0;j<d;j++) dp[i][j] = 0;
            
        dp[0][0] = 1;
        
        for (int i=0;i<lim;i++)
            for (int j=0;j<d;j++) {
                if (!dp[i][j]) continue;
                for (int k=0;k<n;k++) {
                    if (i & (1<<k)) continue;
                    dp[i|(1<<k)][(j * 10 + (s[k]-'0')) % d]+=dp[i][j];
                }
            }
        printf("Case %d: %d\n",t,dp[lim-1][0] / get());
    }
    return 0;
}

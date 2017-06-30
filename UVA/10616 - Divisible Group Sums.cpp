/***********************************************
* Author - LUONG VAN DO                        *
* 10616 - Divisible Group Sums ->AC
* Algorithm dp
* Time Limit 0.032s
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
#define maxN 201

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, q, r, d;
int a[maxN];
int dp[maxN][15][25];
int mod(int x, int y){
    if (x < 0) x+=y;
    return (x % y);
}
int Answer(int n, int r, int v) {
    if ( !n && r ) return 0;
    else
    if ( !r )
        return dp[n][r][v] = (v == 0);
    else
        if (dp[n][r][v] != -1) return dp[n][r][v];
    else return dp[n][r][v] = Answer(n-1,r-1,mod(v - mod(a[n], d), d)) + Answer(n-1,r,v);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int Case = 0;
    while ( scanf("%d %d",&n,&q) && (n + q) ) {
        printf("SET %d:\n",++Case);
        FOR(i, 1, n) scanf("%d",&a[i]);
        
        FOR(c, 1, q) {
            scanf("%d %d",&d,&r);
            FOR(i, 0, n)
                FOR(j, 0, r)
                    FOR(k, 0, d)
                        dp[i][j][k] = -1;
            printf("QUERY %d: %d\n",c, Answer(n,r,d) );
        }
    }
    return 0;
}

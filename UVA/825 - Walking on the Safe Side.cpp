/***********************************************
* Author - LUONG VAN DO                        *
* Problem 825 - Walking on the Safe Side ->AC
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
#define M 1000

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int color[M + 1][M + 1];
int64 dp[M + 1][M + 1];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, u, v, blank = 0;
    int r, c, idx, n;
    char s[M + 1];
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf(" %d %d ",&r,&c);
        FOR(i, 1, r)
            FOR(j, 1, c) {
                color[i][j] = 0;
                dp[i][j] = 0;
            }
        FOR(i, 1, r) {
            gets(s); n = strlen(s); idx = 0;
            u = 0;
            while (idx < n && s[idx]!=' ') {
                u = u * 10 + (s[idx]-'0');
                idx++;
            }
            while (idx < n) {
                while (idx < n && s[idx] == ' ') idx++;
                v = 0;
                while (idx < n && s[idx]!=' ') {
                    v = v * 10 + (s[idx] - '0');
                    ++idx;
                }
                if (v) color[u][v] = 1;
            }
        }
        if (blank) puts("");
        blank = 1;
        
        FOR(i, 1, c)
            if (!color[1][i]) dp[1][i] = 1;
            else break;
        FOR(i, 1, r)
            if (!color[i][1]) dp[i][1] = 1;
            else break;
            
        FOR(i, 2, r)
            FOR(j, 2, c)
                if (!color[i][j])
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    
        printf("%d\n",dp[r][c]);
    }
}

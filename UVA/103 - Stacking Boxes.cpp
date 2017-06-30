/***********************************************
* Author - LUONG VAN DO                        *
* 103 - Stacking Boxes ->AC
* Algorithm DAG
* Time Limit 0.008s
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
int m[40][40], n, l;
int dp[maxN], pre[maxN];
int a[40][40], idx[40];
bool check(int x, int y){
    REP(i, l)
        if (m[x][i] <= m[y][i]) return true;
    return false;
}
void Swap(int x, int y){
    REP(i, l)
        swap(m[x][i], m[y][i]);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int x;
    bool found;
    while ( scanf("%d %d",&n,&l)!=EOF){
        REP(i, n) {
            dp[i] = 0;
            pre[i] = -1;
        }
        REP(i, n)
            REP(j, n) a[i][j] = 0;
        REP(i, n) {
            REP(j, l)
                scanf("%d",&m[i][j]);
            sort(m[i], m[i] + l);
            idx[i] = i + 1;
        }
        
        REP(i, n)
            REP(j, n) {
                if (i == j) continue;
                if ( check( i, j ) ) {
                    swap(idx[i], idx[j]);
                    Swap(i, j);
                }
            }
        
        REP(i, n) {
            REP(j, n) {
                found = true;
                REP(k, l)
                    if (m[i][k]>=m[j][k]) {
                        found = false;
                        break;
                    }
                if ( found ) a[i][j] = 1;
            }
        }
                
        REP(i, n)
            REP(j, n) {
                if (i == j) continue;
                if (a[i][j] && dp[i] + 1 > dp[j]) {
                    dp[j] = dp[i] + 1;
                    pre[j] = i;
                }
            }
            
        int maxbox = 0;
        REP(i, n)
            if (dp[i] > dp[maxbox]) maxbox = i;
        printf("%d\n",dp[maxbox] + 1);
        int ans[40], index;
        index = maxbox;
        for (int i=dp[maxbox];i>=0;i--) {
            ans[i] = index;
            index = pre[index];
        }
        
        REP(i, dp[maxbox] + 1) {
            if (i > 0) printf(" ");
            printf("%d",idx[ans[i]]);
        }
        printf("\n");
    }
    return 0;
}

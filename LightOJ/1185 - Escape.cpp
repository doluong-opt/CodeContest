/***********************************************
* Author - LUONG VAN DO                        *
* 1185 - Escape ->AC
* Algorithm dfs
* Time Limit 0.18s
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
#define maxN 103
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int a[maxN][maxN], deg[maxN];
int mark[maxN][3];
int n, m;
void dfs(int u, int s){
    if (mark[u][s]) return;
    FOR(v, 1, n)
        if (a[u][v]) {
            mark[u][s] = s ^ 1;
            dfs(v, s ^ 1);
        }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, u, v, ans;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&n,&m);
        FOR(i, 1, n)
            FOR(j, 1, n) a[i][j] = 0;
        REP(i, m) {
            scanf("%d %d",&u,&v);
            a[u][v] = a[v][u] = 1;
        }
        ans = 0;
        FOR(i, 1, n)
            FOR(j, 0, 1) mark[i][j] = 0;
        dfs(1, 0);
        FOR(i, 1, n)
            ans+=mark[i][0];
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}

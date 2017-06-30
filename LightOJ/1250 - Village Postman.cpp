/***********************************************
* Author - LUONG VAN DO                        *
* 1250 - Village Postman ->AC 
* Algorithm Euler
* Time Limit 0.033s
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
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector <int> adj[maxN];
int n, m, cnt, ans, sz;
int w[maxN], color[maxN];
int a[maxN][maxN], path[maxN];
void dfs(int u) {
    if (!color[u]) {
        ++cnt;
        ans+=(w[u] - cnt);
    }
    color[u] = 1;
    FOR(v, 1, n)
        if (a[u][v]) {
            a[u][v]--;
            a[v][u]--;
            dfs( v );
            path[sz++] = v;
        }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, u, v;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&n,&m);
        FOR(i, 1, n) {
            scanf("%d",&w[i]);
            color[i] = 0;
        }
        FOR(i, 1, n)
            FOR(j, 1, n)
                a[i][j] = 0;
        REP(i, m) {
            scanf("%d %d",&u,&v);
            a[u][v]++;
            a[v][u]++;
        }
        ans = 0; cnt = sz = 0;
        dfs( 1 );
        printf("Case %d: %d\n",t,ans - sz);
        REP(i, sz)
            printf("%d ",path[i]);
        printf("1\n");
    }
    return 0;
}

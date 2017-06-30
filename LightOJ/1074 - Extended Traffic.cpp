/***********************************************
* Author - LUONG VAN DO                        *
* 1074 - Extended Traffic ->AC
* Algorithm ford bellman
* Time Limit 0.025s
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
#define INF 10000000000LL
#define maxN 301
#define EM 0.5772156649015328606065120900824
using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int busyness[maxN];
vector <ii> adj[maxN];
int64 d[maxN];
int Q[maxN], inQ[maxN], n, m;
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, q, u, v, x, y, w, t;
    scanf("%d",&test);
    FOR(tt, 1, test) {
        scanf("%d",&n);
        FOR(i, 1, n)
            adj[i].clear();
        FOR(i, 1, n) scanf("%d",&busyness[i]);
        scanf("%d",&m);
        REP(i, m) {
            scanf("%d %d",&u,&v);
            x = busyness[v] - busyness[u];
            adj[u].pb(ii(v, x * x * x));
        }
        FOR(i, 1, n) {
            d[i] = INF;
            inQ[i] = false;
            Q[i] = 0;
        }
        d[1] = 0; Q[0] = 1;
        x = 0; y = 0; inQ[1] = true;
        int cnt = 0;
        while ( x !=(y + 1) % n ) {
            cnt++;
            if (cnt == 2000) break;
            u = Q[x];
            inQ[u] = false;
            x = (x + 1) % n;
            REP(i, adj[u].size()) {
                v = adj[u][i].A;
                w = adj[u][i].B;
                if ( d[v] > d[u] + w ) {
                    d[v] = d[u] + w;
                    if ( !inQ[v] ) {
                        y = (y + 1) % n;
                        Q[y] = v;
                        inQ[v] = true;
                    }
                }
            }
        }
        printf("Case %d:\n",tt);
        scanf("%d",&q);
        REP(i, q) {
            scanf("%d",&t);
            if (d[t] < 3 || d[t] == INF) printf("?\n");
            else printf("%d\n",d[t]);
        }
    }
    return 0;
}

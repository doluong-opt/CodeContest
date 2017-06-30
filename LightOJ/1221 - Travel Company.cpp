/***********************************************
* Author - LUONG VAN DO                        *
* 1221 - Travel Company ->AC
* Algorithm ford bellman
* Time Limit 0.311s
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
#define maxN 101
#define EM 0.5772156649015328606065120900824
using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, r, p;
vector <ii> adj[maxN];
int d[maxN];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, u, v, in, ex, w;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d %d",&n,&r,&p);
        REP(i, n) adj[i].clear();
        REP(i, r) {
            scanf("%d %d %d %d",&u,&v,&in,&ex);
            adj[u].pb(ii(v, ex * p - in));
        }
        REP(i, n) d[i] = INF;
        d[0] = 0;
        for (int i=0;i<n-1;i++) {
            for (int j=0;j<n;j++)
                for (int k = 0;k<adj[j].size();k++) {
                    v = adj[j][k].A;
                    w = adj[j][k].B;
                    if (d[v] > d[j] + w) d[v] = d[j] + w;
                }
        }
        
        bool neg_cycle = false;
        for (int i=0; !neg_cycle && i<n;i++)
            for (int j=0; !neg_cycle && j<adj[i].size();j++) {
                v = adj[i][j].A;
                w = adj[i][j].B;
                if (d[v] > d[i] + w) neg_cycle = true;
            }
        if ( neg_cycle ) printf("Case %d: YES\n",t);
        else printf("Case %d: NO\n",t);
    }
    return 0;
}

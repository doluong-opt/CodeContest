/***********************************************
* Author - LUONG VAN DO                        *
* 1108 - Instant View of Big Bang ->AC
* Algorithm tajan + ford bellman
* Time Limit 0.201s
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
#define maxN 1005
#define EM 0.5772156649015328606065120900824
using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node{
    int x, y, c;
    node(){}
    node(int xx, int yy, int cc){
        x = xx; y = yy; c = cc;
    }
};
node edge[maxN];
int n, m, cnt, sc;
int low[maxN], num[maxN];
int mark[maxN], d[maxN], color[maxN];
int q[maxN], cc[maxN];
vector <ii> adj[maxN], radj[maxN];
set <int> ans;
set <int> :: iterator it;
stack <int> S;
void dfs(int u){
    int v;
    if ( cc[u] ) return;
    ans.insert( u );
    cc[u] = 1;
    REP(i, radj[u].size()) {
        v = radj[u][i].A;
        if ( !cc[v] ) dfs( v );
    }
}
void tajan(int u){
    int v, i, j, k, w, x;
    num[u] = ++cnt;
    low[u] = num[u];
    S.push( u );
    REP(i, adj[u].size()) {
        v = adj[u][i].A;
        if (!color[v])
        if ( num[v] ) low[u] = min(low[u], num[v]);
        else {
            tajan( v );
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == num[u]) {
        sc = 0; v = -1;
        while ( v!=u ) {
            v = S.top(); S.pop();
            color[v] = 1;
            q[++sc] = v;
            d[v] = INF;
            mark[v] = 1;
        }
        d[u] = 0;
        for (i = 1;i<sc;i++) {
            
            for (j=1;j<=sc;j++) {
                x = q[j];
                for (k=0;k<adj[x].size();k++) {
                    v = adj[x][k].A;
                    w = adj[x][k].B;
                    if ( !mark[v] ) continue;
                    if ( d[v] > d[x] + w) d[v] = d[x] + w;
                }
                
            }
        }
        
        bool neg_cycle = false;
        for (i = 1; !neg_cycle && i < sc;i++) {
            x = q[i];
            for (j = 0; !neg_cycle && j<adj[x].size();j++) {
                v = adj[x][j].A;
                w = adj[x][j].B;
                if ( !mark[v] ) continue;
                if ( d[v] > d[x] + w) {
                    neg_cycle = true;
                    break;
                }
            }
        }
        
        for (i = 0; i < n;i++) cc[i] = 0;

        if ( neg_cycle )
            for (i = 1;i <=sc;i++)
                if ( mark[ q[i] ] ) dfs( q[i] );
                
        for (i = 1;i <= sc;i++) {
            d[ q[i] ] = 0;
            mark[ q[i] ] = 0;
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, u, v, c;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&n,&m);
        ans.clear();
        REP(i, n) {
            adj[i].clear();
            radj[i].clear();
        }
        REP(i, m) {
            scanf("%d %d %d",&u,&v,&c);
            adj[u].pb(ii(v, c));
            radj[v].pb(ii(u, c));
        }
        cnt = 0;
        REP(i, n) {
            low[i] = num[i] = 0;
            mark[i] = color[i] = 0;
        }
        REP(i, n)
            if ( !color[i] ) tajan( i );
        printf("Case %d:",t);
        if (!ans.size()) printf(" impossible\n");
        else {
            for (it = ans.begin(); it!=ans.end(); it++)
                printf(" %d",(*it));
            printf("\n");
        }
    }
    return 0;
}

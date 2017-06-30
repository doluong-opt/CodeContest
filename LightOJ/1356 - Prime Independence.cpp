/***********************************************
* Author - LUONG VAN DO                        *
* 1356 - Prime Independence ->AC
* Algorithm Bipartite matching
* Time Limit 0.427s
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
#define M 500001
using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node{
    int x, pos;
    node(){}
    node(int xx, int pp){
        x = xx; pos = pp;
    }
};
int a[M + 5], n, Size;
int color[M + 5];
vector <int> adj[M + 5];
vector <int64> prime;
node m[M + 5];
int distx[M + 5], disty[M + 5];
int matchx[M + 5], matchy[M + 5];
void sieve(){
    FOR(i, 1, M - 1) color[i] = 1;
    color[1] = 0;
    for (int i=4;i<M;i+=2) color[i] = 0;
    for (int i=3;i*i<M;i+=2)
        if (color[i])
            for (int j=i*i;j<M;j+=2*i) color[j] = 0;
    prime.pb( 2 );
    for (int i=3;i<M;i+=2)
        if (color[i]) prime.pb(i);
    Size = prime.size();
}
void init() {
    FOR(i, 1, n) {
        int ind = 0;
        while (ind < Size && (int64)a[i] * (int64)prime[ind]<= 500000 ) {
            if ( m[ a[i] * prime[ind] ].x ) {
                adj[i].pb( m[ a[i] * prime[ind] ].pos );
                adj[ m[ a[i] * prime[ind] ].pos ].pb( i );
            }
            ++ind;
        }
    }
}
bool bfs() {
    int u;
    bool found = false;
    queue <int> Q;
    FOR(i, 1, n) {
        disty[i] = 0;
        distx[i] = 0;
        if ( !matchx[i] ) Q.push( i );
    }
    while ( !Q.empty() ) {
        u = Q.front(); Q.pop();
        REP(i, adj[u].size()) {
            int v = adj[u][i];
            if ( !disty[v] ) {
                disty[v] = distx[u] + 1;
                if ( !matchy[v] ) found = true;
                else {
                    distx[ matchy[v] ] = disty[v] + 1;
                    Q.push( matchy[v] );
                }
            }
        }
    }
    return found;
}
bool dfs(int u){
    REP(i, adj[u].size()) {
        int v = adj[u][i];
        if ( disty[v] == distx[u] + 1 ) {
            disty[v] = 0;
            if ( !matchy[v] || dfs( matchy[v] ) ) {
                matchx[u] = v;
                matchy[v] = u;
                return true;
            }
        }
    }
    return false;
}
int solve() {
    int res = 0;
    FOR(i, 1, n) matchx[i] = matchy[i] = 0;
    while ( bfs() ) {
        FOR(i, 1, n)
            if ( !matchx[i] && dfs(i) ) res++;
    }
    return n - (res / 2);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    sieve();
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        FOR(i, 1, n) adj[i].clear();
        FOR(i, 1, M - 1) m[i].x = m[i].pos = 0;
        FOR(i, 1, n) {
            scanf("%d",&a[i]);
            m[a[i]].x = 1;
            m[a[i]].pos = i;
        }
        init();
        printf("Case %d: %d\n",t,solve());
    }    
    return 0;
}

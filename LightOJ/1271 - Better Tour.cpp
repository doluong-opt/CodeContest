/***********************************************
* Author - LUONG VAN DO                        *
* 1271 - Better Tour ->AC
* Algorithm bfs
* Time Limit 0.151s
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
#define maxN 50010
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
vector <int> ans, tmp;
int color[maxN], parent[maxN];
int s, t, id;
char ss[8 * maxN];
void update(int t) {
    tmp.clear();
    tmp.pb( t );
    while (t!=s) {
        t = parent[t];
        tmp.pb(t);
    }
    if ( !ans.size() ) ans = tmp;
    else
    if ( ans.size() > tmp.size() ) {
        ans.clear();
        ans = tmp;
    }
}
void bfs(){
    queue <int> Q;
    Q.push( s ); color[s] = 1;
    while ( !Q.empty() ) {
        int u = Q.front(); Q.pop();
        REP(i, adj[u].size()) {
            int v = adj[u][i];
            if ( v == t ) {
                parent[v] = u;
                update( v );
                continue;
            }
            else
            if ( !color[v] ) {
                color[v] = 1;
                parent[v] = u;
                Q.push( v );
            }
        }
    }
}
int getInt(int n) {
    int v = 0;
    while (id < n && ss[id] !=' ') v = v * 10 + ss[id++] - '0';
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, u, v, n, l, maxi, caseno = 0;
    gets(ss); id = 0;
    test = getInt(strlen(ss));
    while (test--) {
        gets(ss); id = 0; n = getInt(strlen(ss));
        ans.clear();
        gets(ss); id = 0; l = strlen(ss);
        t = getInt(l); ++id;
        s = t; maxi = s;
        for (int i=1;i<n;i++) {
            u = getInt(l); ++id;
            adj[t].pb(u);
            adj[u].pb(t);
            t = u;
            maxi = max(maxi, u);
        }
        for (int i = 1; i<=maxi; i++)
            sort(adj[i].begin(), adj[i].end());
        bfs();
        printf("Case %d:\n",++caseno);
        printf("%d",ans[ans.size()-1]);
        for (int i=ans.size()-2;i>=0;i--) printf(" %d",ans[i]);
        printf("\n");
        for (int i=0;i<=maxi;i++) {
            adj[i].clear();
            color[i] = 0; parent[i] = 0;
        }
    }
}

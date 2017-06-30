/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1242 - Similar Trees (II) 
* Algorithm
* Time Limit
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
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define frr(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i=n - 1; i>=0; i--)
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 110

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, m, root;
vector <int> adj[N], adjj[N];
vector <int> tom[N], jerry[N];
vector <int> adjjj[N];
int out_tom[N], out_jerry[N], mark[N], level[N], parent[N];
int matchx[N], matchy[N], par1[N];
int distx[N], disty[N], par2[N];
void dfs(int p[], int out[], vector <int> a[], int u, vector <int> b[]) {
    if (mark[u]) return;
    mark[u] = 1;
    for (int i=0;i<a[u].size();i++) {
        int v = a[u][i];
        if (!mark[v]) {
            level[v] = level[u] + 1;
            out[u]++;
            p[v] = u;
            b[level[v]].pb( v );
            dfs(p, out, a, v, b);
        }
    }
}
void init(int p[], int out[], vector <int> a[], vector <int> b[]) {
    b[0].pb(1);
    for (int i=1;i<=n;i++) {
        mark[i] = 0;
        level[i] = 0;
    }
    p[1] = 1;
    dfs(p, out, a, root, b);
}
bool bfs() {
    bool found = false;
    int u, v;
    queue <int> q;
    for (int i=1;i<=n;i++) {
        if (!matchx[i]) q.push( i );
        distx[i] = disty[i] = 0;
    }
    while ( !q.empty()){
        u = q.front(); q.pop();
        for (int i=0;i<adjjj[u].size();i++) {
            v = adjjj[u][i];
            if (!disty[v]) {
                disty[v] = distx[u] + 1;
                if (!matchy[v]) found = true;
                else {
                    distx[ matchy[v] ] = disty[v] + 1;
                    q.push( matchy[v] );
                }
            }
        }
    }
    return found;
}
bool dfs1(int u) {
    for (int i=0;i<adjjj[u].size();i++) {
        int v = adjjj[u][i];
        if ( disty[v] == distx[u] + 1) {
            disty[v] = 0;
            if ( !matchy[v] || dfs1( matchy[v]) ) {
                matchx[u] = v;
                matchy[v] = u;
                return true;
            }
        }
    }
    return false;
}
int hop() {
    int ans = 0;
    for (int i=1;i<=n;i++) matchx[i] = matchy[i] = 0;
    while ( bfs() ) {
        for (int i=1;i<=n;i++)
            if (!matchx[i] && dfs1(i) ) ans++;
    }
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, u, v, p1, p2, p3, q1, q2, q3, caseno = 0;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d",&n);
        root = 1;
        for (int i=0;i<=n;i++) {
            adjjj[i].clear();
            adj[i].clear();
            adjj[i].clear();
            tom[i].clear();
            jerry[i].clear();
            out_tom[i] = out_jerry[i] = 0;
            par1[i] = par2[i] = 0;
        }
        for (int i=0;i<n-1;i++) {
            scanf("%d %d",&u,&v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        init(par1, out_jerry, adj, jerry);
        scanf("%d",&m);
        for (int i=0;i<m-1;i++) {
            scanf("%d %d",&u,&v);
            adjj[u].pb(v);
            adjj[v].pb(u);
        }
        init(par2, out_tom, adjj, tom);
        
        /*for (int i=1;i<=n;i++) cout<<out_jerry[i]<<endl;
        cout<<endl;
        for (int i=1;i<=m;i++) cout<<out_tom[i]<<endl;*/
        //for (int i=1;i<=m;i++) cout<<i<<" "<<par2[i]<<endl;
        for (int i=0;i<=n;i++) {
            
            for (int j=0;j<tom[i].size();j++) {
                p1 = tom[i][j];
                p2 = out_tom[p1];
                p3 = out_tom[par2[p1]];
                for (int k=0;k<jerry[i].size();k++)  {
                    q1 = jerry[i][k];
                    q2 = out_jerry[q1];
                    q3 = out_jerry[par1[q1]];
                    if (p2 <= q2 && p3 <= q3) adjjj[p1].pb(q1);
                }
            }
        }
        /*for (int i=1;i<=n;i++) {
            cout<<i<<":"<<endl;
            for (int j=0;j<adjjj[i].size();j++)
                cout<<adjjj[i][j]<<" ";
                cout<<endl;
        }*/
        printf("Case %d: ",++caseno);
        if ( hop() == m ) puts("Yes");
        else puts("No");
    }
}

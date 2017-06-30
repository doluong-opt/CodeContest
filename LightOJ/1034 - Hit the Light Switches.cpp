/***********************************************
* Author - LUONG VAN DO                        *
* 1034 - Hit the Light Switches ->AC
* Algorithm Strongly Connected Component
* Time Limit 0.135s
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
#define maxN 10005

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vi adj[maxN], radj[maxN];
vi Node;
int n,m;
int in[maxN], comp[maxN];
bool visit[maxN];
void reset(){
    for (int i=1;i<=n;i++) {
        adj[i].clear();
        radj[i].clear();
        visit[i] = false;
        in[i] = comp[i] = 0;
    }
    Node.clear();
}
void dfs1(int x) {
    visit[x] = true;
    for (int i=0;i<adj[x].size();i++)
        if ( !visit[ adj[x][i] ] ) dfs1( adj[x][i] );
    Node.pb( x );
}
void dfs2(int x, int c){
    visit[x] = false;
    comp[x] = c;
    for (int i=0;i<radj[x].size();i++)
        if ( visit[ radj[x][i] ] ) dfs2(radj[x][i], c);
}
int solve() {
    int res = 0;
    for (int i=1;i<=n;i++)
        if ( !visit[i] ) dfs1( i );
    int s = Node.size()-1;
    int c = 0;
    for (int i=s;i>=0;i--)
        if ( visit[Node[i]] ) dfs2(Node[i], ++c);
    for (int i=1;i<=n;i++)
        for (int j=0;j<adj[i].size();j++)
            if ( comp[i] != comp[ adj[i][j] ] ) in[ comp[ adj[i][j] ] ]++;
    for (int i=1;i<=c;i++)
        if ( !in[i] ) res++;
    return res;
}
void Read(){
    int test,a,b;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d %d",&n,&m);
        reset();
        for (int i=1;i<=m;i++) {
            scanf("%d %d",&a,&b);
            adj[a].pb(b);
            radj[b].pb(a);
        }
        printf("Case %d: %d\n",t,solve());
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

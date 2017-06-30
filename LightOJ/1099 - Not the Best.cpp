/***********************************************
* Author - LUONG VAN DO                        *
* 1099 - Not the Best ->AC
* Algorithm dijkstra
* Time Limit 0.442s
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
#define maxN 5001

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector <ii> adj[maxN];
struct node{
    int x, y, z;
    node(){}
    node(int xx, int yy, int zz){
        x = xx; y = yy; z = zz;
    }
};
int n, nheap;
int inc[maxN], d[maxN][3];
int pos[maxN], heap[maxN];
int solve() {
    FOR(i, 1, n) inc[i] = 0;
    set <ii> S;
    S.insert(ii(0, 1));
    while (!S.empty()) {
        int w = S.begin() -> first;
        int u = S.begin() -> second;
        S.erase(S.begin());
        inc[u]++;
        if (inc[u] > 2) continue;
        if (inc[u] == 2 && u == n) return w;
        REP(i, adj[u].size()) {
            int v = adj[u][i].A;
            int cost = adj[u][i].B;
            S.insert(ii(cost + w, v));
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, R;
    int u, v, c;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&n,&R);
        FOR(i, 1, n)
            adj[i].clear();
        REP(i, R) {
            scanf("%d %d %d",&u,&v,&c);
            adj[u].pb(ii(v, c));
            adj[v].pb(ii(u, c));
        }
        printf("Case %d: %d\n",t,solve());
    }
    return 0;
}

/***********************************************
* Author - LUONG VAN DO                        *
* 11080 - Place the Guards ->AC
* Algorithm Biartite Maching Check
* Time Limit 0.012s
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

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector <int> adj[maxN];
int color[maxN], d[maxN];
int r1, r2, v, found;
void dfs(int x, int p){
    if ( !found ) return;
    if ( color[x] ) return;
    color[x] = 1;
    d[x] = p;
    if ( p ) r1++;
    else r2++;
    REP(i, adj[x].size()) {
        int y = adj[x][i];
            if ( !color[y] ) dfs(y, 1 - p);
        else
            if ( d[x] == d[y] ) found = 0;
    }
}
int solve() {
    int res = 0;
    found = 1;
    REP(i, v)
        if (found && !color[i]) {
            r1 = r2 = 0;
            dfs(i, 0);
                if (!r1) res+=r2;
            else
                if (!r2) res+=r1;
            else
                res+=min(r1,r2);
        }
    if ( found ) return res;
    return -1;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, e, x ,y;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&v,&e);
        REP(i, v) adj[i].clear();
        REP(i, e) {
            scanf("%d %d",&x,&y);
            adj[x].pb(y);
            adj[y].pb(x);
        }
        REP(i, v) color[i] = 0, d[i] = -1;
        printf("%d\n",solve());
    }    
    return 0;
}

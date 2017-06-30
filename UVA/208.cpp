 /***********************************************
* Author - LUONG VAN DO                        *
* Problem 208 - Firetruck ->AC
* Algorithm dfs
* Time Limit 0.008s
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
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 22

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
vector <int> adj[N];
int color[N], cnt;
vector <int> node;
void dfs(int u) {
    if (color[u]) return;
    color[u] = 1;
    for (int i=0;i<adj[u].size();i++) dfs(adj[u][i]);
}
void find_path(int sta, int des, int mask) {
    if (color[sta]) {
        if (sta == des) {
            cnt++;
            for (int i=0;i<node.size()-1;i++)
                printf("%d ",node[i]);
            printf("%d\n",node[node.size()-1]);
            return;
        }
        for (int i=0;i<adj[sta].size();i++) {
            int v = adj[sta][i];
            if ( !And(mask, v - 1) ) {
                node.pb(v);
                find_path(v, des, Or(mask, v - 1));
                node.pop_back();
            }
        }
    }
    return;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, x, y, n, caseno = 0;
    while (scanf("%d",&n) != EOF) {
        for (int i=1;i<N;i++) {
            adj[i].clear();
            color[i] = 0;
        }
        node.clear();
        scanf("%d %d",&x,&y);
        while (x!=0 && y!=0) {
            adj[x].pb(y);
            adj[y].pb(x);
            scanf("%d %d",&x,&y);
        }
       dfs( n ); cnt = 0;
       for (int i=1;i<N;i++) sort(adj[i].begin(), adj[i].end());
       node.pb( 1 );
       printf("CASE %d:\n",++caseno);
       find_path(1, n, 1);
       printf("There are %d routes from the firestation to streetcorner %d.\n",cnt, n);
    }
}

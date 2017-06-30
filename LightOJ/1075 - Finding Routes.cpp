/***********************************************
* Author - LUONG VAN DO                        *
* 1075 - Finding Routes ->AC
* Algorithm topo
* Time Limit 0.077s
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
#define maxN 50001
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
vector <int> topo;
map <string, int> Name;
string ans[maxN];
bool color[maxN];
void dfs(int x){
    if (color[x]) return;
    color[x] = true;
    REP(i, adj[x].size()) {
        int v = adj[x][i];
        if ( !color[v] ) dfs(v);
    }
    topo.pb( x );
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, cnt, m, u, v;
    string x, y;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&m);
        FOR(i, 1, m) {
            adj[i].clear();
            color[i] = false;
        }
        Name.clear(); cnt = 0;
        topo.clear();
        REP(i, m - 1) {
            cin >> x >> y;
            if ( !Name[x] ) Name[x] = ++cnt;
            if ( !Name[y] ) Name[y] = ++cnt;
            u = Name[x]; v = Name[y];
            ans[u] = x;
            ans[v] = y;
            adj[u].pb(v);
        }
        FOR(i, 1, m)
            if (!color[i]) dfs( i );
        printf("Case %d:\n",t);
        FORD(i, m - 1, 0)
            cout<<ans[ topo[i] ] <<endl;
        cout<<endl;
    }
    return 0;
}

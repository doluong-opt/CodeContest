/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11686 - Pick up sticks ->AC
* Algorithm topo
* Time Limit 0.756s
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
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define M 100000

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
vector <int> adj[M + 1];
vector <int> topo;
int inc[M + 1], n, m;
int color[M + 1];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int u, v, sz;
    while ( scanf("%d %d",&n,&m) && (m + n)) {
        FOR(i, 1, n) {
            adj[i].clear();
            inc[i] = color[i] = 0;
        }
        FOR(i, 1, m) {
            scanf("%d %d",&u,&v);
            adj[u].pb(v);
            inc[v]++;
        }
        topo.clear(); bool ok = true;
        int x = -1;
        while ( x != n ) {
            x = topo.size();
            if (x == n) break;
            FOR(i, 1, n) {
                if (!color[i] && !inc[i]) {
                    color[i] = 1;
                    topo.pb( i );
                    REP(j, adj[i].size())
                        inc[adj[i][j]]--;
                }
            }
            if (x == topo.size()) {
                ok = false;
                break;
            }
        }
        if (!ok) puts("IMPOSSIBLE");
        else
        REP(i, n)
            printf("%d\n",topo[i]);
    }
}

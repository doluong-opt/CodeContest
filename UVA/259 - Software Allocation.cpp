/***********************************************
* Author - LUONG VAN DO                        *
* Problem 259 - Software Allocation ->AC
* Algorithm max_flow
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
#define N 100000

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
char str[N];
int f, s, t;
vector <int> adj[40];
int dist[40], p[40];
int c[40][40];
void findPath(int v, int minEdge) {
    if (v == s) {
        f = minEdge;
        return;
    }
    else 
    if (p[v] != -1) {
        findPath(p[v], min(minEdge, c[p[v]][v]));
        c[p[v]][v]-=f;
        c[v][p[v]]+=f;
    }
}
int max_flow() {
    int mf = 0, u, v;
    while ( true ) {
        f = 0;
        for (int i=0;i<=t;i++) dist[i] = p[i] = -1;
        queue <int> q; q.push(s); dist[s] = 0;
        while ( !q.empty() ) {
            u = q.front(); q.pop();
            if (u == t) break;
            for (int i=0;i<adj[u].size();i++) {
                v = adj[u][i];
                if (dist[v] == -1 && c[u][v] > 0) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    p[v] = u;
                }
            }
        }
        findPath(t, INF);
        if (!f) break;
        mf+=f;
    }
    return mf;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int total, flag;
    while ( gets(str) ) {
        s = 0; t = 37; total = 0;
        for (int i=0;i<=t;i++) {
            adj[i].clear();
            for (int j=0;j<=t;j++)
                c[i][j] = 0;
        }
        c[s][ str[0] - 'A' + 1] = str[1] - '0';
        total+=str[1] - '0';
        adj[ s ].pb(str[0] - 'A' + 1);
        adj[str[0] - 'A' + 1].pb( s );
        for (int j=3;j<strlen(str) - 1;j++) {
            c[str[0] - 'A' + 1][str[j] - '0' + 27] = 1;
            adj[str[0] - 'A' + 1].pb(str[j] - '0' + 27);
            adj[str[j] - '0' + 27].pb(str[0] - 'A' + 1);
        }
        while ( gets(str) ) {
            if ( strlen(str) == 0 ) break;
            c[s][ str[0] - 'A' + 1] = str[1] - '0';
            total+=str[1] - '0';
            adj[ s ].pb(str[0] - 'A' + 1);
            adj[str[0] - 'A' + 1].pb( s );
            for (int j=3;j<strlen(str) - 1;j++) {
                c[str[0] - 'A' + 1][str[j] - '0' + 27] = 1;
                adj[str[0] - 'A' + 1].pb(str[j] - '0' + 27);
                adj[str[j] - '0' + 27].pb(str[0] - 'A' + 1);
            }
        }
        for (int i=27;i<=t;i++) {
            c[i][t] = 1;
            adj[i].pb(t);
            adj[t].pb(i);
        }
        if ( max_flow() != total ) printf("!");
        else
        for (int i=27;i<=36;i++) {
            flag = 0;
            for (int j=1;j<=26;j++) {
                if (c[i][j] > 0) {
                    flag = 1;
                    printf("%c", j + 'A' - 1);
                    break;
                }
            }
            if (!flag) printf("_");
        }
        puts("");
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1405 - The Great Escape ->AC
* Algorithm dinic + adj
* Time Limit 1.347s
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
#define maxN 400010
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
struct node {
    int x, y, w, und;
    node(){}
    node(int xx, int yy, int ww, int in){
        x = xx; y = yy; w = ww; und = in;
    }
} edge[maxN];

char s[N][N];
int r, c, n, f, numEdge, source, sink, p[maxN], total;
vector <int> adj[maxN];
vector <ii> conectoEnd;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool isInside(int u, int v) {
    return (u >= 0 && u < r && v >=0 && v < c);
}
int convert(int u, int v) {
    return (u * c + v);
}
void addEdge(int u, int v, int w) {
    edge[numEdge] = node(u, v, w, numEdge + 1);
    adj[u].pb(numEdge);
    edge[numEdge + 1] = node(v, u, 0, numEdge);
    adj[v].pb(numEdge + 1);
    numEdge += 2;
}
void findPath(int v, int minEdge) {
    if (v == source) {
        f = minEdge;
        return;
    }
    else
    if (p[v] != -1) {
        findPath( edge[p[v]].x, min(minEdge, edge[p[v]].w));
        edge[p[v]].w-=f;
        edge[edge[p[v]].und].w+=f;
    }
}
int dinic(int n, int s, int t) {
    int mf = 0, u, v, w;
    while ( true ) {
        for (int i=0;i<n;i++) p[i] = -1;
        p[s] = -2;
        queue <int> q; q.push(s);
        while ( !q.empty() && p[t] == -1) {
            u = q.front(); q.pop();
            for (int i=0;i<adj[u].size();i++) {
                v = edge[ adj[u][i] ].y;
                w = edge[ adj[u][i] ].w;
                if ( p[v] == -1 && w > 0)
                    p[v] = adj[u][i], q.push( v );
            }
        }
        if (p[t] == -1) break;
        for (int i=0;i < conectoEnd.size();i++) {
            u = conectoEnd[i].ff; v = conectoEnd[i].ss;
            if ( p[u] != -1 && edge[v].w > 0) {
                f = edge[v].w;
                findPath(u, INF);
                mf+=f;
                if (mf >= total) break;
            }
        }
        if (mf >= total) break;
    }
    return mf;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, x, y;
    scanf(" %d ",&cases);
    while (cases--) {
        scanf(" %d %d ", &r, &c);
        n = r * c; numEdge = 0;
        total = 0; source = 2 * r * c; sink = source + 1;
        
        conectoEnd.clear();
        for (int i=0;i<=sink;i++) adj[i].clear();
        
        for (int i=0;i<r;i++) gets(s[i]);
        for (int i=0;i<r;i++)
            for (int j=0;j<c;j++) {
                x = convert(i, j);
                addEdge(x, x + n, 1);
                if (s[i][j] == '*') {
                    total++;
                    addEdge(source, x, 1);
                }
                for (int k=0;k<4;k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if ( isInside(nx, ny) ) {
                        y = convert(nx, ny);
                        addEdge(x + n, y, 1);
                    }
                    else {
                        y = convert(i, j);
                        conectoEnd.pb(ii(y + n, numEdge - 2));
                        addEdge(y + n, sink, 1);
                    }
                }
            }
        printf("Case %d: ", ++caseno);
        if ( total == dinic(sink + 1, source, sink) ) puts("yes");
        else puts("no");
    }
}

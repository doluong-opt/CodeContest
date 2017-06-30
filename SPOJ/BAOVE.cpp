/***********************************************
* Author - LUONG VAN DO                        *
* Problem BAOVE
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
#define repr(i, n) for (int i=n-1;i>=0;i--)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define frr(i,a,b) for (int i=a;i>=b;i--)
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
inline int64 min(int64 a, int64 b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct node{
    int x, y, c, rev;
    node(){}
    node(int xx, int yy, int cc, int revv){
        x = xx; y = yy; c = cc; rev = revv;
    }
} edge[N];

int numEdge, source, sink;
vector <int> adj[N];
vector <ii> conect;
int p[N];
int64 f;
 
void addEdge(int u, int v, int w) {
    edge[numEdge] = node(u, v, w, numEdge + 1);
    adj[u].pb( numEdge );
    edge[numEdge + 1] = node(v, u, 0, numEdge);
    adj[v].pb( numEdge + 1 );
    numEdge+=2;
}

void findPath(int v, int64 minEdge) {
    if (v == source) {
        f = minEdge;
        return;
    }
    else
    if (p[v] != -1) {
        findPath( edge[ p[v] ].x, min( edge[ p[v] ].c, minEdge) );
        edge[p[v]].c-=f;
        edge[ edge[p[v]].rev ].c+=f;
    }
}

int64 dinic(int n, int s, int t) {
    int64 mf = 0;
    int64 u, v, w;
    while ( true ) {
        for (int i=0;i<n;i++) p[i] = -1;
        p[s] = -2;
        queue <int> q; q.push( s );
        
        while ( !q.empty() && p[t] == -1) {
            u = q.front(); q.pop();
            for (int i=0;i<adj[u].size();i++) {
                v = edge[ adj[u][i] ].y;
                w = edge[ adj[u][i] ].c;
                if (p[v] == -1 && w > 0)
                    p[v] = adj[u][i], q.push( v );
            }
        }
        if (p[t] == -1) break;
        for (int i=0;i<conect.size();i++) {
            u = conect[i].ff; v = conect[i].ss;
            if ( p[u] != -1 && edge[v].c > 0 ) {
                findPath(t, INF);
                mf+=f;
            }
        }
    }
    return mf;
}

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int u, v, w, n, m;
    scanf("%d",&n);
    numEdge = 0; source = n; sink = 1;
    while (scanf("%d %d %d",&u, &v, &w) != EOF) {
        addEdge(u, v, w);
        if (v == 1) conect.pb(ii(u, numEdge - 2));
    }
    printf("%lld\n", dinic(n + 1, source, sink));
}

/***********************************************
* Author LUONG VAN DO                        *
* Problem NKFLOW
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

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 111222333
#define N 1100
#define M 100010
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
struct node {
    int x, y, c, rev;
    node(){}
    node(int xx, int yy, int cc, int revv){
        x = xx; y = yy; c = cc; rev = revv;
    }
} edge[M];
int n, m, s, t, numEdge, f;
int p[N];
vector <int> adj[N];
vector <ii> connect;
void add_edge(int u, int v, int w) {
    edge[numEdge] = node(u, v, w, numEdge + 1);
    adj[u].pb( numEdge );
    edge[numEdge + 1] = node(v, u, 0, numEdge);
    adj[v].pb( numEdge + 1 );
    numEdge+=2;
}

void findPath(int v, int minEdge) {
    if (v == s) {
        f = minEdge;
        return;
    }
    else
    if (p[v] != -1) {
        findPath( edge[p[v]].x, min( edge[p[v]].c, minEdge) );
        edge[p[v]].c-=f;
        edge[ edge[p[v]].rev].c+=f;
    }
}

int dinic(int n, int s, int t) {
    int u, v, w;
    int mf = 0;
    while ( true ) {
        for (int i = 1;i <= n;i++) p[i] = -1;
        p[s] = -2;
        queue <int> q; q.push(s);
        while ( !q.empty() && p[t] == -1 ) {
            u = q.front(); q.pop();
            for (int i = 0;i < adj[u].size();i++) {
                v = edge[ adj[u][i] ].y;
                w = edge[ adj[u][i] ].c;
                if ( w > 0 && p[v] == -1)
                    p[v] = adj[u][i], q.push( v );
            }
        }
        if (p[t] == -1) break;
        for (int i = 0;i < connect.size(); i++) {
            u = connect[i].ff; v = connect[i].ss;
            if (p[u] != -1 && edge[v].c > 0) {
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
    int u, v, c;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    numEdge = 0; connect.clear();
    rep(i, m) {
        scanf("%d %d %d",&u, &v, &c);
        add_edge(u, v, c);
        if (v == t) connect.pb(ii(u, numEdge - 2));
    }
    printf("%d\n", dinic(n, s, t));
}

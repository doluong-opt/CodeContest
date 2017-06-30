/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1330 - Binary Matrix 
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
#define N 200

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
int source, sink, m, n;
int cap[N][N], deg[N], adj[N][N], res[N][N], p[N], flow[N][N], d[N];
int row[N], col[N], id;
char ss[N];
int findPath(int n, int s, int t) {
    int u, v, f;
    for (int i = 0;i < n;i++) d[i] = INF;
    d[s] = 0;
    p[s] = -1;
    queue <int> q; q.push(s);
    while ( !q.empty() ) {
        u = q.front(); q.pop();
        if (u == t) break;
        for (int i=0;i < deg[u];i++) {
            v = adj[u][i];
            if (d[v] < INF) continue;
            if (u == source || u == sink || v == source || v == sink) {
                if (cap[u][v]  > flow[u][v] )
                    d[v] = d[u] + 1, p[v] = u, q.push(v);
                if (v == t) break;
            }
            else {
                if (flow[u][v] < 1 && cap[u][v] > flow[u][v])
                    d[v] = d[u] + 1, p[v] = u, q.push(v);
                if (v == t) break;
            }
        }
    }
    if (d[t] == INF) return 0;
    f = INF;
    for (v = t; p[v] != -1; v = p[v]) f = min(f, cap[p[v]][v] - flow[p[v]][v]);
    for (v = t; p[v] != -1; v = p[v]) {
        flow[p[v]][v]+=f;
        flow[v][p[v]]-=f;
    }
    return f;
}

int maxflow(int n, int s, int t) {
    int mf = 0, f, u, v;
    memset(deg, 0, sizeof(deg));
    for (u = 0; u < n; u++) for (v = 0; v < n; v++) if ( cap[u][v] || cap[v][u] )
        adj[u][ deg[u]++ ] = v;
    while ( true ) {
        f = findPath(n, s, t);
        if (!f) break;
        mf+=f;
    }
    return mf;
}
void lexico() {
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            if ( flow[i][j + n] == 0 ) {
                res[i][j] = 0;
                flow[i][j + n]++;
                flow[j + n][i]--;
            }
            else {
                res[i][j] = 1;
                flow[j + n][i]++;
                
                flow[source][i]--;
                flow[i][source]++;
                flow[j + n][sink]--;
                flow[sink][j + n]++;
                
                if ( findPath(sink + 1, source, sink) ) res[i][j] = 0;
                else {
                    flow[source][i]++;
                    flow[i][source]--;
                    flow[j + n][sink]++;
                    flow[sink][j + n]--;
                }
            }
}
int getNext(int m) {
    int v = 0;
    while (id < m && ss[id] != ' ') v = v * 10 + ss[id++] - '0';
    ++id;
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, mf, total, r, c, caseno = 0, l;
    gets(ss); id = 0; l = strlen(ss); cases = getNext(l);
    while (cases--) {
        gets(ss); id = 0; l = strlen(ss);
        m = getNext(l); n = getNext(l);
        r = c = 0;
        gets(ss); id = 0; l = strlen(ss);
        for (int i=1;i<=m;i++) {
            row[i] = getNext(l);
            r+=row[i];
        }
        gets(ss); id = 0; l = strlen(ss);
        for (int i=1;i<=n;i++) {
            col[i] = getNext(l);
            c+=col[i];
        }
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        source = 0; sink = 2 * n + 1;
        for (int i=1;i<=m;i++) {
            cap[source][i] = row[i];
            for (int j=1;j<=n;j++)
                cap[i][j + n] = 1;
        }
        for (int i=1;i<=n;i++)
            cap[i + n][sink] = col[i];
            
        printf("Case %d:",++caseno);
        if (r != c) puts(" impossible");
        else {
            mf = maxflow(sink + 1, source, sink);
            //cout<<mf<<endl;
            if (mf != r) puts(" impossible");
            else {
                puts("");
                lexico();
                for (int i=1;i<=m;i++) {
                    for (int j=1;j<=n;j++)
                        printf("%d",res[i][j]);
                        puts("");
                }
            }
        }
    }
}

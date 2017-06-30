/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11045 - My T-shirt suits me ->AC
* Algorithm maxflow
* Time Limit 0.04s
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
#define N 100

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
string sz[] = {"XXL", "XL", "L", "M", "S", "XS"};
int source, sink, n, m;
int cap[N][N], deg[N], d[N], p[N], adj[N][N];
int convert(string x) {
    for (int i=0;i < 6;i++)
        if (sz[i] == x) return i;
}
int maxflow(int n, int s, int t) {
    int mf = 0, u, v, f;
    memset(deg, 0, sizeof(deg));
    for (u = 0; u < n; u++) for (v = 0; v < n; v++) if ( cap[u][v] || cap[v][u] )
        adj[u][ deg[u]++] = v;
    do{
        f = INF;
        for (int i=0;i < n; i++) d[i] = -1;
        d[s] = 0; p[s] = -1;
        queue <int> q; q.push(s);
        while ( !q.empty() ) {
            u = q.front(); q.pop();
            if (u == t) break;
            for (int i=0;i<deg[u];i++) {
                v = adj[u][i];
                if (d[v] == -1 && cap[u][v] > 0)
                    d[v] = d[u] + 1, p[v] = u, q.push(v);
            }
        }
        for (v = t; p[v] != -1; v = p[v]) f = min(f, cap[p[v]][v]);
        for (v = t; p[v] != -1; v = p[v]) {
            cap[p[v]][v]-=f;
            cap[v][p[v]]+=f;
        }
        mf+=f;
    }while (f);
    return mf;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, u, v, caseno = 0;
    string a, b;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d",&n,&m);
        source = m + 6; sink = source + 1;
        memset(cap, 0, sizeof(cap));
        for (int i=0;i<m;i++) {
            cin >> a >> b;
            u = convert(a); v = convert(b);
            if (u == v) cap[u][i + 6] = 1;
            else {
                cap[u][i + 6] = 1;
                cap[v][i + 6] = 1;
            }
        }
        for (int i=0;i<6;i++)
            cap[source][i] = n / 6;
        for (int i=0;i<m;i++)
            cap[i + 6][sink] = 1;
        //printf("Case %d: ",++caseno);
        if ( maxflow(sink + 1, source, sink) == m ) puts("YES");
        else puts("NO");
    }
}

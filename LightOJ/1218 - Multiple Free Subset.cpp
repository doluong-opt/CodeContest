/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1218 - Multiple Free Subset ->AC
* Algorithm max_flow
* Time Limit 0.984s
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
int mark[N];
set <int> s;
int n, m, a[N];
int ss, tt, f;
int p[N], dist[N], c[210][210], cc[210][210];
vector <int> adj[N];
void init() {
    ss = 2 * m; tt = ss + 1;
    for (int i=0;i<=tt;i++) {
        adj[i].clear();
        for (int j=0;j<=tt;j++) c[i][j] = 0;
    }
    
    for (int i=0;i<m;i++)
        for (int j=i + 1;j<m;j++)
            if (a[j] % a[i] == 0) {
                c[2 * i + 1][2 * j] = 1;
                adj[2 * i + 1].pb(2 * j);
                adj[2 * j].pb(2 * i + 1);
            }
    for (int i=0;i<m;i++) {
        c[ss][2 * i + 1] = 1;
        adj[2 * i + 1].pb(ss);
        adj[ss].pb(2 * i + 1);
        
        c[2 * i][tt] = 1;
        adj[2 * i].pb(tt);
        adj[tt].pb(2 * i);
    }
}
void findPath(int v, int minEdge) {
    if (v == ss) {
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
        for (int i=0;i<=tt;i++) dist[i] = p[i] = -1;
        queue <int> q; q.push(ss); dist[ss] = 0;
        while ( !q.empty() ) {
            u = q.front(); q.pop();
            if (u == tt) break;
            for (int i=0;i<adj[u].size();i++) {
                v = adj[u][i];
                if (dist[v] == -1 && c[u][v] > 0) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    p[v] = u;
                }
            }
        }
        findPath(tt, INF);
        if (!f) break;
        mf+=f;
    }
    return mf;
}
void copy(int a[210][210], int b[210][210]) {
    for (int i=0;i<=tt;i++)
        for (int j=0;j<=tt;j++) b[i][j] = a[i][j];
}
void reset() {
    for (int i=0;i<=tt;i++) {
        for (int j=0;j<=tt;j++)
            if (c[i][j]) printf("%d %d - > %d\n", i, j, c[i][j]);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, x, maxf, temp, caseno = 0;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d",&n);
        s.clear(); m = 0;
        for (int i=0;i<n;i++) {
            scanf("%d",&x);
            s.insert(x);
        }
        for (set<int> :: iterator it = s.begin(); it!= s.end(); it++) a[m++] = *it;
        sort(a, a + m);
        for (int i=0;i<m;i++) mark[i] = 1;
        init();
        copy(c, cc);
        maxf = max_flow();
        for (int i=m-1;i>=0;i--) {
            copy(cc, c);
            c[ss][2 * i + 1] = 0;
            c[2 * i][tt] = 0;
            temp = max_flow();
            if (temp < maxf) {
                mark[i]^=1;
                maxf = temp;
                cc[ss][2 * i + 1] = 0;
                cc[2 * i][tt] = 0;
            }
            else {
                cc[ss][2 * i + 1] = 1;
                cc[2 * i][tt] = 1;
            }
        }
        printf("Case %d:",++caseno);
        for (int i=0;i<m;i++)
            if (mark[i]) printf(" %d",a[i]);
        puts("");
    }
}

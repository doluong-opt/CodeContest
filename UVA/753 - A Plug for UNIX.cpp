/***********************************************
* Author - LUONG VAN DO                        *
* Problem 753 - A Plug for UNIX -> AC
* Algorithm maxflow
* Time Limit 0.02s
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
#define N 500

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
string s1, s2;
int cap[N][N], source, sink;
int deg[N], adj[N][N], d[N], p[N];
map <string, int> rec;
int n, m, k;
int max_flow(int n, int s, int t) {
    int mf = 0, u, v, f;
    memset(deg, 0, sizeof(deg));
    for (u = 0; u < n; u++) for (v = 0; v < n; v++) if ( cap[u][v] || cap[v][u] )
        adj[u][ deg[u]++ ] = v;
    do{
        f = INF;
        for (int i=0; i < n;i++) d[i] = -1;
        p[s] = -1; d[s] = 0;
        queue <int> q; q.push(s);
        while ( !q.empty() ) {
            u = q.front(); q.pop();
            for (int i=0;i<deg[u];i++) {
                v = adj[u][i];
                if ( d[v] == -1 && cap[u][v] > 0) {
                    d[v] = d[u] + 1;
                    p[v] = u;
                    q.push( v );
                }
            }
        }
        for (v = t; p[v] != -1; v = p[v]) f = min(f, cap[p[v]][v]);
        for (v = t; p[v] != -1; v = p[v]) {
            cap[p[v]][v]-=f;
            cap[v][p[v]]+=f;
        }
        mf+=f;
    }while ( f );
    return mf;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, cnt, u, v, caseno = 0, ans;
    scanf("%d",&cases);
    while (cases--) {
        rec.clear();
        scanf("%d",&n);
        cnt = 1; source = 0; sink = 1;
        memset(cap, 0, sizeof(cap));
        for (int i=0;i<n;i++) {
            cin >> s1;
            if ( !rec[s1] ) rec[s1] =  ++cnt;
            u = rec[s1];
            cap[source][u]++;
        }
        scanf("%d",&m);
        for (int i=0;i<m;i++) {
            cin >> s1 >> s2;
            if ( !rec[s2] ) rec[s2] = ++cnt;
            u = rec[s2];
            cap[u][sink]++;
        }
        scanf(" %d ",&k);
        for (int i=0;i<k;i++) {
            cin >> s1 >> s2;
            if ( !rec[s1] ) rec[s1] = ++cnt;
            if ( !rec[s2] ) rec[s2] = ++cnt;
            v = rec[s1]; u = rec[s2];
            cap[u][v] = INF;
        }
        ans = max_flow(cnt + 1, source, sink);
        if ( caseno ) puts("");
        caseno++;
        printf("%d\n", m - ans);
    }
}

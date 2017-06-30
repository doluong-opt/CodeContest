/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1412 - Visiting Islands ->AC
* Algorithm bfs
* Time Limit 0.572s
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
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 100010
 
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
vector <int> adj[N];
vector <ii> v;
int color[N], mark[N];
int use[N];
int n, m, node, nm, id;
char s[N];
int bfs1(int u) {
    queue <ii> q; use[u] = 1;
    q.push(ii(u, 0));
    int v, maxi = 0;
    while (!q.empty()) {
        ii a = q.front(); q.pop();
        if (a.ss > maxi) maxi = a.ss;
        for (int i=0;i<adj[a.ff].size();i++) {
            v = adj[a.ff][i];
            if (!use[v]) {
                use[v] = 1;
                q.push(ii(v, a.ss + 1));
            }
        }
    }
    return maxi;
}
int bfs(int u) {
    color[u] = 1;
    queue <ii> q;
    q.push(ii(u, 0));
    int no, v, maxi = 0;
    while ( !q.empty() ) {
        ii a = q.front(); q.pop();
        if (a.ss > maxi) {
            maxi = a.ss;
            no = a.ff;
        }
        for (int i=0;i<adj[a.ff].size();i++) {
            v = adj[a.ff][i];
            if (!color[v]) {
                color[v] = 1;
                node++;
                q.push(ii(v, a.ss + 1));
            }
        }
    }
    return bfs1(no);
}
bool cmp(ii a, ii b) {
    if (a.ss != b.ss) return a.ss > b.ss;
    return a.ff > b.ff;
}
int getInt(int m) {
    int v = 0;
    while (id < m && s[id] !=' ') v = v * 10 + s[id++] - '0';
    id++;
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, x, y, caseno = 0;
    int k, q, ans, f;
    gets(s); id = 0; cases = getInt(strlen(s));
    while (cases--) {
        gets(s); id = 0;
        n = getInt(strlen(s));
        m = getInt(strlen(s));
        v.clear();
        for (int i=1;i<=n;i++) {
            adj[i].clear();
            color[i] = use[i] = 0;
            mark[i] = -1;
        }
       
        for (int i=1;i<=m;i++) {
            gets(s); id = 0;
            x = getInt(strlen(s));
            y = getInt(strlen(s));
            adj[x].pb(y);
            adj[y].pb(x);
        }
        nm = 0;
        for (int i=1;i<=n;i++)
            if (!color[i]) {
                node = 1;
                ans = bfs(i);
                if ( mark[node] == -1) {
                    v.pb(ii(node, ans));
                    mark[node] = nm++;
                }
                else v[ mark[node] ].ss = max(v[mark[node]].ss, ans);
            }
        sort(v.begin(), v.end(), cmp);
        printf("Case %d:\n",++caseno);
        gets(s); id = 0; q = getInt(strlen(s));
        while (q--) {
            gets(s); id = 0; k = getInt(strlen(s));
            f = 0;
            for (int i=0;i<nm && !f;i++) {
                if (v[i].ff < k) continue;
                f = 1;
                if (v[i].ss + 1 >= k) printf("%d\n",k - 1);
                else printf("%d\n",v[i].ss + ((k - v[i].ss - 1) << 1));
                break;
            }
            if (!f) puts("impossible");
        }
    }
}

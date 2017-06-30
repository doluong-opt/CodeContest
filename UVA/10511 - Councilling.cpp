/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10511 - Councilling ->AC
* Algorithm maxflow
* Time Limit 0.180s
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
#define N 2000

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
char s[N];
int id, source, sink;
map <string, int> person;
map <string, int> party;
map <string, int> clubs;
map <string, int> :: iterator it, it1, it2;
int deg[N], adj[N][N], d[N], cap[N][N], p[N];
string X[N], Y[N];
string getString(int n) {
    string str = "";
    while (id < n && s[id] !=' ') str+=s[id++];
    ++id;
    return str;
}
int maxflow(int n, int s, int t) {
    int mf = 0, u, v, f;
    memset(deg, 0, sizeof(deg));
    for (u = 0; u < n; u++) for (v = 0; v < n; v++) if ( cap[u][v] || cap[v][u] )
        adj[u][ deg[u]++] = v;
    do{
        f = INF;
        for (int i=0;i < n;i++) d[i] = -1;
        d[s] = 0; p[s] = -1;
        queue <int> q; q.push(s);
        while ( !q.empty() ) {
            u = q.front(); q.pop();
            if (u == t) break;
            for (int i=0;i<deg[u];i++) {
                v = adj[u][i];
                if ( d[v] == -1 && cap[u][v] > 0) {
                    d[v] = d[u] + 1;
                    p[v] = u;
                    q.push(v);
                }
            }
        }
        for (v = t; p[v] != -1; v = p[v]) f = min(f, cap[p[v]][v]);
        for (v = t; p[v] != -1; v = p[v]) {
            cap[p[v]][v]-=f;
            cap[v][p[v]]+=f;
        }
        mf+=f;
    } while (f);
    return mf;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, cnt, u, v, con, mf, n, caseno = 0;
    string name, par, club;
    scanf(" %d ",&cases);
    while ( cases--) {
        person.clear(); party.clear(); clubs.clear();
        memset(cap, 0, sizeof(cap));
        cnt = 1; source = 0; sink = 1;
        
        while ( gets(s) && strlen(s) ) {
            n = strlen(s); id = 0;
            name = getString( n );
            par = getString( n );
            if ( !party[par] ) party[par] = ++cnt;
            v = party[par];
            if ( !person[name] ) person[name] = ++cnt;
            u = person[name]; X[u] = name;
            cap[u][v] = 1;
            while (id < n) {
                club = getString( n );
                if ( !clubs[club] ) clubs[club] = ++cnt;
                v = clubs[club]; Y[v] = club;
                cap[v][u] = 1;
            }
        }
        con = (clubs.size() - 1) >> 1;
        for (it = clubs.begin(); it != clubs.end(); it++)
            cap[source][it->second] = 1;
        for (it = party.begin(); it != party.end(); it++)
            cap[it->second][sink] = con;
        
        mf = maxflow(cnt + 1, source, sink);
        if ( caseno ) puts(""); caseno++;
        if ( mf != clubs.size() ) puts("Impossible.");
        else {
            for (it1 = person.begin(); it1 != person.end(); it1++)
                for (it2 = clubs.begin(); it2 != clubs.end(); it2++) {
                    u = it1->second;
                    v = it2->second;
                    if ( !cap[v][u] && cap[u][v] + cap[v][u] == 1 ) cout<<X[u]<<" "<<Y[v]<<endl;
                }
        }
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1308 - Ant Network ->AC
* Algorithm articulation
* Time Limit 0.439s
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
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 50010

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
int low[N], num[N], lab[N];
int child[N], parent[N], color[N];
bool isCut[N];
int n, m, cnt;

void dfs(int u) {
    low[u] = num[u] = ++cnt;
    for (int i=0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if ( !parent[v] ) {
            parent[v] = u;
            child[u]++;
            dfs( v );
            low[u] = min(low[u], low[v]);
            if (parent[u] == -1)
                isCut[u] = isCut[u] || (low[v] >= num[u] && child[u] > 1);
            else
                isCut[u] = isCut[u] || (low[v] >= num[u]);
        }
        else
        if (parent[u] != v && low[u] > num[v]) low[u] = num[v];
    }
}

void reset() {
    cnt = 0;
    for (int i=1;i<=n;i++) {
        num[i] = low[i] = 0;
        parent[i] = child[i] = 0;
        isCut[i] = false;
    }
}
void init() {
    for (int i=1;i<=n;i++) lab[i] = i;
}
int findSet(int v) {
    return v == lab[v] ? v : lab[v] = findSet(lab[v] );
}
void Union(int r1, int r2) {
    lab[findSet(r1)] = findSet(r2);
}

vector<vector<int> > com, Adj;
map <int,int> Sizes;
map <int,int> in;
int nm, l, ind;
char s[N];

void getCom(int u) {
    if ( color[u] ) return;
    color[u] = 1;
    com.back().pb(u);
    for (int i=0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if (color[v] || isCut[v]) continue;
        Union(u, v);
        getCom(v);
    }
}

void build() {
    
    init();
    memset(color, 0, sizeof(color));
    map <int, int> mm;
    int no = 0;
    
    com.clear(); Sizes.clear();
    in.clear(); Adj.clear();
    
    for (int i=1;i<=n;i++)
        if (isCut[i]) {
            vector <int> c;
            c.pb(i);
            com.pb(c);
        }
        else
        if ( !color[i] ) {
            vector <int> c;
            com.pb(c);
            getCom(i);
        }
    
    for (int i=1;i<=n;i++) findSet(i);
    
    //for (int i=1;i<=n;i++)
        //cout<<i-1<<" "<<lab[i]-1<<endl;
        
    for (int i=1;i<=n;i++) {
        if (Sizes.count(lab[i]) == 0) Sizes[lab[i]] = 0;
        Sizes[lab[i]]++;
    }

    nm = com.size();
    
//    for (int i=0;i<nm;i++)
//        cout<<com[i].size()<<endl;
        
    for (int i=0;i<nm;i++) {
        vector <int> c;
        Adj.pb(c);
    }
    
    for (int i=0;i<nm;i++) if ( com[i].size() == 1) {
        int arc = com[i][0];
        if ( !isCut[arc] ) continue;
        int par = findSet(arc);
        
        if ( mm.count(par) == 0 ) {
            in[no] = par;
            mm[par] = no++;
        }
        
        int x = mm[par];
        
        for (int j=0;j<adj[arc].size();j++) {
            int v = adj[arc][j];
            int par = findSet(v);
            if ( mm.count(par) == 0 ) {
                in[no] = par;
                mm[par] = no++;
            }
            int y = mm[par];
            Adj[x].pb(y);
            Adj[y].pb(x);
        }
    }
    
    for (int i=0;i<Adj.size();i++) {
        sort(Adj[i].begin(), Adj[i].end());
        Adj[i].erase(unique(Adj[i].begin(), Adj[i].end()), Adj[i].end());
    }
}
int getInt(int m) {
    int v = 0;
    while (ind < m && s[ind] !=' ') v = v * 10 + s[ind++] - '0';
    ++ind;
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, x, y, caseno = 0;
    uint64 r1, r2;
    gets(s); ind = 0; cases = getInt(strlen(s));
    while (cases--) {
        gets(s);
        gets(s); ind = 0; l = strlen(s);
        n = getInt(l); m = getInt(l);
        
        for (int i=1;i<=n;i++) adj[i].clear();
        for (int i=0;i<m;i++) {
            gets(s); ind = 0; l = strlen(s);
            x = getInt(l); y = getInt(l);
            ++x; ++y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        reset();
        for (int i=1;i<=n;i++) {
            if (!parent[i]) {
                parent[i] = -1;
                dfs( i );
            }
        }
        r1 = 0; r2 = 1LL;
        int cc = 0;
        
        for (int i=1;i<=n;i++)
            if (isCut[i]) cc++;
        if (cc == 0) {
            cout << "Case "<<++caseno<<": 2 "<<((n * (n - 1)) >> 1)<<endl;
            continue;
        }
        build();
        for (int i=0;i<nm;i++) if ( Adj[i].size() == 1 ) {
            r1++;
            r2*=(uint64)(Sizes[in[i]]);
        }
        cout << "Case "<<++caseno<<": "<<r1<<" "<<r2<<endl;
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 
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
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 2000000000
#define N 100111

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
vector <ii> adj[N];
int d[N][3], pos[N][3], color[N][3], nheap;
int num[N], low[N], parent[N];
int n, m, s, t, cnt;
ii heap[N * 3];
void update(int v, int k) {
    int child, parent;
    child = pos[v][k];
    if (!child) child = ++nheap;
    parent = child >> 1;
    while (parent > 0 && d[heap[parent].ff][heap[parent].ss] > d[v][k]) {
        heap[child] = heap[parent];
        pos[heap[child].ff][heap[child].ss] = child;
        child = parent;
        parent = child >> 1;
    }
    heap[child] = ii(v, k);
    pos[v][k] = child;
}
ii popHeap() {
    ii u, v;
    u = heap[1]; v = heap[nheap--];
    int r = 1;
    while (2 * r <= nheap) {
        int c = 2 * r;
        if (c < nheap && d[heap[c + 1].ff][heap[c + 1].ss] < d[heap[c].ff][heap[c].ss]) ++c;
        if (d[v.ff][v.ss] <= d[heap[c].ff][heap[c].ss]) break;
        heap[r] = heap[c];
        pos[heap[r].ff][heap[r].ss] = r;
        r = c;
    }
    heap[r] = v;
    pos[v.ff][v.ss] = r;
    return u;
}
int solve(int s, int t) {
    nheap = 0;
    for (int i = 1;i <= n;i++) {
        d[i][0] = d[i][1] = INF;
        color[i][0] = color[i][1] = pos[i][0] = pos[i][1] = 0;
    }
    d[s][1] = 0; update(s, 1);
    while ( nheap ) {
        ii u = popHeap();
        color[u.ff][u.ss] = 1;
        for (int i = 0;i < adj[u.ff].size();i++) {
            int v = adj[u.ff][i].ff;
            int w = adj[u.ff][i].ss;
            int k = u.ss;
            if ( color[v][k ^ 1] ) continue;
            cout <<num[v] <<" "<<low[u.ff]<<endl;
            //if (u.ff == 1 && v == 3 && k == 0) cout <<"ds"<<d[v][k ^ 1] <<" "<< d[u.ff][k] + w << endl;
            if (num[v] > low[u.ff] && d[v][k ^ 1] > d[u.ff][k] + w ) {
                //cout <<"Ds"<<v<<" "<<(k^1)<<endl;
                d[v][k ^ 1] = d[u.ff][k] + w;
                update(v, k ^ 1);
            }
        }
    }
    return (d[t][1] == INF ? -1 : d[t][1]);
}
void dfs(int u) {
    num[u] = low[u] = ++cnt;
    for (int i = 0;i < adj[u].size();i++) {
        int v = adj[u][i].ff;
        if (parent[v] == 0) {
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else
        if (parent[u] != v) low[u] = min(low[u], num[v]);
    }
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int u, v, w;
	scanf("%d %d %d %d", &n, &m, &s, &t);	
	fr(i, 1, n) {
        adj[i].clear();
        num[i] = low[i] = parent[i] = 0;
	}
	fr(i, 1, m) {
	    scanf("%d %d %d", &u, &v, &w);
	    adj[u].pb(ii(v, w));
	    adj[v].pb(ii(u, w));
	}
	cnt = 0;
	dfs(s);
	printf("%d\n", solve(s, t));
	/*for (int i = 1;i <= n;i++)
        cout <<i<<" "<<low[i]<<" "<<num[i]<<" "<<parent[i]<<endl;*/
	return 0;
}

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
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i = b;i >= a;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define pb push_back
#define ff first
#define ss second
#define fill(arr, val) memset(arr, val, sizeof(arr))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint32 unsigned int
#define INF 2000000001
#define N 1111
#define E 1000001
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
struct node{
    int x, y, w, und;
    node(){}
    node(int _x, int _y, int _w, int _und) {
        x = _x; y = _y; w = _w; und = _und;
    }
}edge[E];
int n, m, f, minV, maxV, numEdge, source, sink, ans;
int b[N], val[N], p[N];
ii a[N];
vector <int> adj[N];
vector <ii> conectoEnd;
void addEdge(int u, int v, int w) {
    edge[numEdge] = node(u, v, w, numEdge + 1);
    adj[u].pb(numEdge);
    edge[numEdge + 1] = node(v, u, w, numEdge);
    adj[v].pb(numEdge + 1);
    numEdge += 2;
}
bool cmp(ii x, ii y) {
    return (x.ss < y.ss);
}
void build() {
    numEdge = 0;
    fr(i, 1, m)
        fr(j, i + 1, m) {
            int d = gcd(val[i], val[j]);
            if (d > 1) {
                addEdge(i, j, d);
                //cout<<i<<" "<<j<<" "<<d<<endl;
                if (j == sink) conectoEnd.pb(ii(i, numEdge - 2));
            }
        }
    //rep(i, conectoEnd.size()) cout<<conectoEnd[i].ff<<" "<<conectoEnd[i].ss<<endl;
}
void findPath(int v, int minEdge) {
    if (v == source) {
        f = minEdge;
        return;
    }
    else
    if (p[v] != -1) {
        findPath(edge[p[v]].x, min(minEdge, edge[p[v]].w));
        edge[p[v]].w -= f;
        edge[edge[p[v]].und].w += f;
    }
}
int dinic(int n, int s, int t) {
    int mf = 0, u, v, w;
    while ( true ) {
        for (int i = 0;i < n;i++) p[i] = -1;
        p[s] = -2;
        queue <int> q; q.push(s);
        while ( !q.empty() && p[t] == -1 ) {
            u = q.front(); q.pop();
            for (int i = 0;i < adj[u].size();i++) {
                v = edge[adj[u][i]].y;
                w = edge[adj[u][i]].w;
                if (p[v] == -1 && w > 0)
                    p[v] = adj[u][i], q.push(v);
            }
        }
        if (p[t] == -1) break;
        for (int i = 0;i < conectoEnd.size();i++) {
            u = conectoEnd[i].ff; v = conectoEnd[i].ss;
            if (p[u] != -1 && edge[v].w > 0) {
                f = edge[v].w;
                findPath(u, f);
                edge[v].w -= f;
                edge[edge[v].und].w += f;
                mf += f;
            }
        }
    }
    return mf;
}
inline int getInt(int &res) {
    res = 0; char c;
    do { c = getchar(); } while (c < '0' || c > '9');
    do { res = res * 10 + c - '0'; c = getchar();} while (c >= '0' && c <= '9');
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	getInt(n);
	maxV = 0; minV = INF;
	fr(i, 1, n) {
	    a[i].ff = i;
	    getInt(a[i].ss);
	    if (minV > a[i].ss) minV = a[i].ss;
	    if (maxV < a[i].ss) maxV = a[i].ss;
	}
	sort(a + 1, a + n + 1, cmp);
	a[0].ss = a[1].ss - 1; m = 0;
	fr(i, 1, n) {
	    if (a[i].ss > a[i - 1].ss) m++;
	    b[a[i].ff] = m; val[m] = a[i].ss;
	    if (minV == a[i].ss) source = m;
	    if (maxV == a[i].ss) sink = m;
	}
	build();
	ans = dinic(m + 1, source, sink);
	printf("%d\n", ans);
	return 0;
}

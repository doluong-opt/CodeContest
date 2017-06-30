/***********************************************
* Author LUONG VAN DO                        *
* Problem CENTRE28
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
int n, m, nheap;
int heap[N], pos[N], color[N], d1[N], d2[N];
int64 s1[N], s2[N];
vector <int> res, adj[N], cost[N];
void update(int v, int d[]) {
    int child, parent;
    child = pos[v];
    if (!child) child = ++nheap;
    parent = child >> 1;
    while ( parent > 0 && d[heap[parent]] > d[v] ) {
        heap[child] = heap[parent];
        pos[heap[child]] = child;
        child = parent;
        parent = child >> 1;
    }
    heap[child] = v;
    pos[v] = child;
}
int popHeap(int d[]) {
    int u = heap[1], v = heap[nheap--];
    int r = 1;
    while (2 * r <= nheap) {
        int c = 2 * r;
        if (c < nheap && d[heap[c + 1]] < d[heap[c]]) ++c;
        if (d[v] <= d[heap[c]]) break;
        heap[r] = heap[c];
        pos[heap[r]] = r;
        r = c;
    }
    heap[r] = v;
    pos[v] = r;
    return u;
}

void dijk(int source, int d[], int64 s[]) {
    int u, v, w;
    nheap = 0;
    fr(i, 1, n) {
        color[i] = pos[i] = heap[i] = s[i] = 0;
        d[i] = INF;
    }
    d[source] = 0; s[source] = 1;
    update(source, d);
    while ( nheap ) {
        u = popHeap( d );
        color[u] = 1;
        rep(i, adj[u].size()) {
            v = adj[u][i];
            w = cost[u][i];
            if ( color[v] ) continue;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                s[v] = s[u];
                update(v, d);
            }
            else
            if (d[v] == d[u] + w) s[v]+=s[u];
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int u, v, c;
    scanf("%d %d",&n,&m);
    fr(i, 1, m) {
        scanf("%d %d %d",&u, &v, &c);
        adj[u].pb(v);
        adj[v].pb(u);
        cost[u].pb(c);
        cost[v].pb(c);
    }
    dijk(1, d1, s1);
    dijk(n, d2, s2);
    fr(i, 2, n - 1) {
        if (d1[i] + d2[i] == d1[n] && s1[i] * s2[i] == s1[n]) continue;
        res.pb(i);
    }
    printf("%d\n", res.size());
    rep(i, res.size())
        printf("%d\n",res[i]);
}

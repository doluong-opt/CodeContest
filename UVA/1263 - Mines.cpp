/***********************************************
* Author LUONG VAN DO                        *
* Problem 1263 - Mines
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
#define N 2010

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct point {
    double x, y;
    point(){}
    point(double xx, double yy) {
        x = xx; y = yy;
    }
};
point p1[N], p2[N], I[N];
double x, y, d;
vector <int> adj[N];
int mark[N], n, m;
stack <int> S;
list <int> topo;
bool confi(int i, int j) {
    return (I[j].x >= p1[i].x && I[j].x <= p2[i].x && I[j].y >= p1[i].y && I[j].y <= p2[i].y);
}
void call(int u) {
    if (mark[u]) return;
    mark[u] = 1;
    for (int i = 0;i < adj[u].size();i++) {
        int v = adj[u][i];
        if (!mark[v]) call(v);
    }
    topo.push_front(u);
}
void dfs(int u) {
    if (mark[u]) return;
    mark[u] = 1;
    for (int i = 0;i < adj[u].size();i++) {
        int v = adj[u][i];
        if (!mark[v]) dfs(v);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, ans, u, v;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        for (int i = 1;i <= n;i++) {
            scanf("%lf %lf %lf", &x, &y, &d);
            p1[i] = point(x - d / 2.0, y - d / 2.0);
            p2[i] = point(x + d / 2.0, y + d / 2.0);
            I[i] = point(x, y);
            adj[i].clear();
        }
        topo.clear();
        for (int i = 1;i <= n;i++)
            for (int j = i + 1;j <= n;j++) {
                if (i == j) continue;
                if ( confi(i, j) ) adj[i].pb(j);
                if ( confi(j, i) ) adj[j].pb(i);
            }
        fill(mark, 0);
        for (int i = 1;i <= n;i++)
            if (!mark[i]) call( i );
        fill(mark, 0);
        ans = 0;
        for (list <int> :: iterator it = topo.begin(); it != topo.end(); it++)
            if ( !mark[*it] ) {
                dfs(*it);
                ans++;
            }
        printf("%d\n", ans);
    }
}

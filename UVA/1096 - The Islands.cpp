/***********************************************
* Author LUONG VAN DO                        *
* Problem 1096 - The Islands
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
#define N 110

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<double, double> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node {
    int y;
    double w;
    node(){}
    node(int yy, double ww){
        y = yy; w = ww;
    }
};
ii p[N];
vector <node> adj[N];
int nheap, pos[N], heap[N];
double d[N];
double dist(ii a, ii b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return (dx * dx + dy * dy);
}
double run() {
    for (int i = 1;i <= n;i++) {
        d[i] = INF;
        for (int j = 1;j <= n;j++)
            mark[i][j] = 0;
    }
        d[1] = 0.0;
    update(1); 
    while ( nheap ) {
        u = popHeap();
        for (int i = 0;i < adj[u].size();i++) {
            int v = adj[u][i].y;
            double w = adj[u][i].w;
            if (mark[u][v]) continue;
            if ((u == a && v == b) || (u == b && v == a)) continue;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                update(v);
            }
        }
    }
    
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int caseno = 0;
    while ( scanf("%d %d %d", &n, &a, &b,) && (n + a + b)) {
        fr(i, 1, n) scanf("%lf %lf", &p[i].ff, &p[i].ss);
        fr(i, 1, n - 1)
            fr(j, i + 1, n) {
                adj[i].pb(node(j, dist(p[i], p[j])));
                adj[j].pb(node(i, dist(p[i], p[j])));
            }
        printf("Case %d: %.2lf\n", ++caseno, run());
    }
}

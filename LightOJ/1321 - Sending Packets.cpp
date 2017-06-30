/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1321 - Sending Packets ->AC
* Algorithm dijkstra
* Time Limit 0.112s
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
#define M 100

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

typedef pair<int, double> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct Node{
    int x;
    double w;
    Node(){}
    Node(int xx, double ww){
        x = xx; w = ww;
    }
    bool operator < (const Node& other) const{
        return w < other.w;
    }
} a ;
vector <Node> adj[M + 1];
int n, m, s, k;
int color[M + 1];
double d[M + 1];
double solve() {
    priority_queue <Node> Q;
    REP(i, n) {
        d[i] = 0.0;
        color[i] = 0;
    }
    Q.push(Node(0, 1));
    while ( !Q.empty() ) {
        a = Q.top(); Q.pop();
        int nx = a.x;
        double nw = a.w;
        if (color[nx]) continue;
        REP(i, adj[nx].size()) {
            int v = adj[nx][i].x;
            double w = adj[nx][i].w * nw;
            if (!color[v] && w > d[v]) {
                d[v] = w;
                Q.push(Node(v, w));
            }
        }
        color[nx] = 1;
    }
    return d[n - 1];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, u, v, p;
    double Ans;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d %d %d",&n,&m,&s,&k);
        REP(i, n) adj[i].clear();
        REP(i, m) {
            scanf("%d %d %d",&u,&v,&p);
            adj[u].pb(Node(v, (double)p / 100.0));
            adj[v].pb(Node(u, (double)p / 100.0));
        }
        Ans = solve();
        printf("Case %d: %.10lf\n", t,(double( (double)(k * 2) * s) / Ans));
    }
}


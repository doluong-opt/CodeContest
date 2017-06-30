/***********************************************
* Author - LUONG VAN DO                        *
* 1086 - Jogging Trails ->AC
* Algorithm Euler
* Time Limit 0.015s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
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
#define maxN 50001
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node{
    int x, y;
    int w;
    node(){}
    node(int xx, int yy, int cc){
        x = xx; y = yy; w = cc;
    }
    bool operator <(const node &other) const{
        return w < other.w;
    }
} Edge[maxN];
int cost[16][16], deg[16];
int color[16], n, m;
int edge, sumcost, Mincost;
void reset() {
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cost[i][j] = INF;
        }
        deg[i] = color[i] = 0;
    }
}
void floyd() {
    FOR(k, 1, n)
        FOR(i, 1, n)
            FOR(j, 1, n)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
}
void add_edge(){
    edge = 0;
    FOR(i, 1, n) {
        if (deg[i] % 2 == 0) continue;
        FOR(j, i + 1, n) {
            if (deg[j] % 2 == 0) continue;
            Edge[edge].x = i;
            Edge[edge].y = j;
            Edge[edge++].w = cost[i][j];
        }
    }
}
void Recur(int n, int level, int taget, int ww){
    if (ww >= Mincost) return;
    if (level == taget) {
        if (ww < Mincost) Mincost = ww;
        return;
    }
    color[Edge[n].x] = color[Edge[n].y] = 1;
    for (int i=n+1;i<edge;i++) {
        if (color[Edge[i].x] || color[Edge[i].y]) continue;
        Recur(i, level + 1, taget, ww + Edge[i].w);
    }
    color[Edge[n].x] = color[Edge[n].y] = 0;
}
int solve() {
    int cnt = 0;
    FOR(i, 1, n)
        if (deg[i] % 2) cnt++;
    if (cnt == 0) return sumcost;
    if (edge == 1) return Edge[0].w + sumcost;
    sort(Edge, Edge + edge);
    Mincost = INF;
    for (int i = 0;i + 1 < edge;i++)
        Recur(i, 1, cnt / 2, Edge[i].w);
    return Mincost + sumcost;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, u, v, c;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&n,&m);
        reset(); sumcost = 0;
        REP(i, m) {
            scanf("%d %d %d",&u,&v,&c);
            sumcost+=c;
            deg[u]++; deg[v]++;
            if (cost[u][v] > c)
                cost[u][v] = cost[v][u] = c;
        }
        floyd();
        add_edge();
        printf("Case %d: %d\n",t,solve());
    }
    return 0;
}

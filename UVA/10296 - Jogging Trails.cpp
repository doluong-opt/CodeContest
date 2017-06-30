/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10296 - Jogging Trails -> AC
* Algorithm dp
* Time Limit 0.104s
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
#define M 15

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
struct Node{
    int x, y, w;
    Node(){}
    Node(int xx, int yy, int ww){
        x = xx; y = yy; w = ww;
    }
    bool operator <(const Node& other) const{
        return (w < other.w);
    }
} Edge[M * M + 5];
int cost[M + 1][M + 1];
int deg[M + 1], color[M + 1];
int sumcost, n, m, edge, Ans;
void floy(){
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++) cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
}
void add_edge(){
    for (int i=1;i<=n-1;i++) {
        if (deg[i] % 2 ==  0) continue;
        for (int j=i+1;j<=n;j++) {
            if (deg[j] % 2 == 0) continue;
            Edge[edge++] = Node(i, j, cost[i][j]);
        }
    }
}
void recur(int n, int level, int taget, int ww){
    if (ww >= Ans) return;
    if (level == taget) {
        if (ww < Ans) Ans = ww;
        return;
    }
    color[Edge[n].x] = color[Edge[n].y] = 1;
    for (int i=n + 1;i<edge;i++) {
        if (color[Edge[i].x] || color[Edge[i].y]) continue;
        recur(i, level + 1, taget, ww + Edge[i].w);
    }
    color[Edge[n].x] = color[Edge[n].y] = 0;
}
int answer(){
    int cnt;
    cnt = 0;
    for (int i=1;i<=n;i++)
        if (deg[i] % 2) cnt++;
    if (cnt == 0) return sumcost;
    if (edge == 1) return Edge[0].w + sumcost;
    sort(Edge, Edge + edge);
    Ans = INF;
    for (int i=0;i<edge;i++)
        recur(i, 1, cnt / 2, Edge[i].w);
    return Ans + sumcost;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int u, v, w;
    while ( scanf("%d",&n) && n){
        for (int i=1;i<=n;i++) {
            cost[i][i] = color[i] = deg[i] = 0;
            for (int j=1;j<=n;j++)
                if (i!=j) cost[i][j] = INF;
        }
        sumcost = edge = 0;
        scanf("%d",&m);
        for (int i=0;i<m;i++) {
            scanf("%d %d %d",&u,&v,&w);
            sumcost+=w; deg[u]++; deg[v]++;
            if (cost[u][v] > w)
                cost[u][v] = cost[v][u] = w;
        }
        floy();
        add_edge();
        printf("%d\n",answer());
    }
}

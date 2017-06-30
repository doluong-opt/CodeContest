// =============================================================================
// Author LUONG VAN DO
// Problem 1208 - Dangerous Bull! Who Wants to Pull
// Algorithm
// Time Limit
// =============================================================================
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
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint unsigned int

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, double> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 111222333
#define N 222
#define eps 1e-7
struct point{
    int x, y, id;
    point(){}
    point(int _x, int _y, int _id){
        x = _x; y = _y; id = _id;
    }    
}p[N];

struct node{
    int u, v, s;
    double w;
    node(){}
    node(int _u, int _v, int _s, double _w){
        u = _u; v = _v; s = _s; w = _w;
    }
    bool operator < (const node& other) const{
        if (w != other.w) return w < other.w;
        if (s != other.s) return s < other.s;
        if (u != other.u) return u < other.u;
        return v < other.v;
    }
};

point bull, fence[N], pnew[N];
int n, m, mark[N][N];
vector <ii> adj[N];

bool cmp(point a, point b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
double dist(point a, point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int cross(point o, point a, point b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

double solve(int start) {
    int u, v, s;
    double w;
    fr(i, 1, m)
        fr(j, 1, m) mark[i][j] = 0;
    set <node> se;
    for (int i = 0;i < adj[start].size();i++) {
        v = adj[start][i].ff;
        w = adj[start][i].ss;
        se.insert(node(start, v, v, w));
    }
    while ( !se.empty() ) {
        node a = *(se.begin());
        se.erase(a);
        u = a.u; v = a.v; s = a.s; w = a.w;
        if ( mark[u][v] ) continue;
        mark[u][v] = 1;
        if (v == start) {
            if ( cross(pnew[u], pnew[v], pnew[s]) > 0 ) return w;
            else continue;
        }
        
        for (int i = 0;i < adj[v].size();i++)
            if ( cross(pnew[u], pnew[v], pnew[adj[v][i].ff]) > 0 )
                se.insert(node(v, adj[v][i].ff, s, w + adj[v][i].ss));
    }
    return INF;
}
int main(){
	freopen("exam.inp","r",stdin);
	freopen("exam.out","w",stdout);
	int cases, caseno = 0, u, v;
	double d, ans;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d %d", &n, &bull.x, &bull.y);
        fr(i, 1, 2 * n) {
            scanf("%d %d", &p[i].x, &p[i].y);
            p[i].id = i;
            pnew[i].x = INF;
            adj[i].clear();
        }
        sort(p + 1, p + 2 * n + 1, cmp);
        p[0] = point(INF, INF, 0); m = 0;
        fr(i, 1, 2 * n) {
            if (p[i].x != p[i - 1].x || p[i].y != p[i - 1].y) m++;
            fence[p[i].id] = point(p[i].x, p[i].y, m);
            if (pnew[m].x == INF) pnew[m] = point(p[i].x, p[i].y, 0);
        }
        for (int i = 1;i <= 2 * n;i += 2){
            u = fence[i].id; v = fence[i + 1].id;
            d = dist(pnew[u], pnew[v]);
            if ( cross(pnew[u], pnew[v], bull) > 0 )
                adj[u].pb(ii(v, d));
            else
                adj[v].pb(ii(u, d));
        }
        ans = INF;
        for (int i = 1;i <= m;i++) {
            d = solve(i);
            if (ans > d) ans = d;
        }
        if ( ans == INF ) printf("Case %d: -1.000\n", ++caseno);
        else printf("Case %d: %.10lf\n", ++caseno, ans * 2.0);
    }
}

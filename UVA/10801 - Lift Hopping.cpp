/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10801 - Lift Hopping ->AC
* Algorithm dijkstra + heap
* Time Limit 0.012s
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
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define frr(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i=n - 1; i>=0; i--)
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1010

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
struct node {
    int x, y;
    node(){}
    node(int xx, int yy){
        x = xx; y = yy;
    }
};

int n, k, a[N], id, m;
int nheap;
char s[N];
int f[N][N], d[N][N], pos[N][N], color[N][N];
node heap[N];

int getNext(int m) {
    int v = 0;
    while (id < m && s[id] != ' ') v = v * 10 + s[id++] - '0';
    ++id;
    return v;
}

void reset() {
    nheap = 0;
    for (int i=0;i<n;i++) {
        heap[i].x = heap[i].y = 0;
        for (int j=0;j<=99;j++) {
            color[i][j] = 0;
            pos[i][j] = 0;
            d[i][j] = INF;
        }
    }
}

void update(int x, int y) {
    int parent, child;
    child = pos[x][y];
    if (!child) child = ++nheap;
    parent = child >> 1;
    while ( parent > 0 && d[ heap[parent].x ][ heap[parent].y ] > d[x][y] ) {
        heap[child] = heap[parent];
        pos[ heap[child].x ][ heap[child].y ] = child;
        child = parent;
        parent = child >> 1;
    }
    heap[child] = node(x, y);
    pos[x][y] = child;
}
node popHeap() {
    node u = heap[1], v = heap[nheap--];
    int r = 1, c;
    while (r * 2 <= nheap) {
        c = 2 * r;
        if ( c < nheap && d[ heap[c + 1].x ][ heap[c + 1].y ] < d[ heap[c].x ][ heap[c].y ] ) ++c;
        if ( d[v.x][v.y] <= d[ heap[c].x ][ heap[c].y ] ) break;
        heap[r] = heap[c];
        pos[ heap[r].x ][ heap[r].y ] = r;
        r = c;
    }
    heap[r] = v;
    pos[v.x][v.y] = r;
    return u;
}

int run(int t) {
    reset();
    node u;
    for (int i=0;i<n;i++)
        if ( f[i][0] ) {
            d[i][0] = 0;
            update(i, 0);
        }
    while ( nheap ) {
        u = popHeap();
        color[u.x][u.y] = 1;
        for (int i=0;i<=99;i++)
            if ( f[u.x][i] ) {
                if ( !color[u.x][i] && d[u.x][i] > d[u.x][u.y] + abs(i - u.y) * a[u.x] ) {
                    d[u.x][i] = d[u.x][u.y] + abs(i - u.y) * a[u.x];
                    update(u.x, i);
                }
            }
        for (int i=0;i<n;i++)
            if (u.x != i)
                for (int j=0;j<=99;j++)
                    if ( j == u.y && f[i][j] ) {
                        if ( !color[i][j] && d[i][j] > d[u.x][u.y] + 60 ) {
                            d[i][j] = d[u.x][u.y] + 60;
                            update(i, j);
                        }
                    }
    }
    int res = INF;
    for (int i=0;i<n;i++)
        res = min(res, d[i][k]);
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int ans;
    while ( scanf(" %d %d ",&n,&k) != EOF) {
        for (int i=0;i<n;i++)
            for (int j=0;j<=99;j++) f[i][j] = 0;
            
        for (int i=0;i<n;i++) scanf(" %d ",&a[i]);
        for (int i=0;i<n;i++) {
            gets(s); m = strlen(s); id = 0;
            while (id < m) f[i][getNext(m)] = 1;
        }
        ans = run( k );
        if ( ans != INF ) printf("%d\n", ans);
        else puts("IMPOSSIBLE");
    }
}

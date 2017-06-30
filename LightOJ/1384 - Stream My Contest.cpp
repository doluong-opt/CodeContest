/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1384 - Stream My Contest ->AC
* Algorithm DMST + BS
* Time Limit 0.070s
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
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 10010
#define M 10010
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
    int x, y, b, c;
    node(){}
    node(int xx, int yy, int bb, int cc){
        x = xx; y = yy; b = bb; c = cc;
    }
};
int n, m, C, root, n0, id;
node e[M], ee[M];
int pre[N], color[N], ind[N], w[N];
char s[N];
void reset() {
    for (int i=0;i<n;i++) {
        color[i] = -1;
        ind[i] = -1;
    }
}
bool check(int B) {
    int m0 = 0, res = 0, nn;
    int u, v, cost;
    for (int i=0;i<m;i++)
        if ( e[i].b >= B ) ee[m0++] = e[i];

    root = 0; n = n0;
    
    while ( true ) {
        for (int i=0;i<n;i++) w[i] = INF;
        
        for (int i=0;i<m0;i++) {
            u = ee[i].x;
            v = ee[i].y;
            cost = ee[i].c;
            if (u != v && cost < w[v]) {
                w[v] = cost;
                pre[v] = u;
            }
        }
        for (int i=0;i<n;i++)
            if (i == root) continue;
        else
            if (w[i] == INF) return false;
            
        nn = 0;
        reset();
        w[root] = 0;
        for (int i=0;i<n;i++) {
            res+=w[i];
            u = i;
            while (u != root && color[u] != i && ind[u] == -1) {
                color[u] = i;
                u = pre[u];
            }
            
            if (u != root && ind[u] == -1) {
                for (int v = pre[u]; u != v; v = pre[v]) ind[v] = nn;
                ind[u] = nn++;
            }
        }
        
        if (!nn) break;
        for (int i=0;i<n;i++)
            if (ind[i] == -1) ind[i] = nn++;
            
        for (int i=0;i<m0;i++) {
            u = ee[i].x;
            v = ee[i].y;
            ee[i].x = ind[u];
            ee[i].y = ind[v];
            if (ee[i].x != ee[i].y) ee[i].c-=w[v];
        }
        n = nn; root = ind[root];
    }
    return (res <= C);
}
int solve() {
    int lo, hi, res;
    res = -1;
    lo = 0; hi = 1000000;
    while ( lo <= hi ) {
        int mid = (lo + hi) >> 1;
        if ( check(mid) ) {
            res = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return res;
}
int getInt(int m) {
    int v = 0;
    while (id < m && s[id] != ' ') v = v * 10 + s[id++] - '0';
    ++id;
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, ans, l;
    gets(s); id = 0; l = strlen(s); cases = getInt(l);
    while ( cases--) {
        gets(s);
        gets(s); id = 0; l = strlen(s);
        n = getInt(l); m = getInt(l); C = getInt(l);
        n0 = n;
        for (int i=0;i<m;i++) {
            gets(s); id = 0; l = strlen(s);
            e[i].x = getInt(l); e[i].y = getInt(l); e[i].b = getInt(l); e[i].c = getInt(l);
        }
        ans = solve();
        if (ans != -1) printf("Case %d: %d kbps\n",++caseno, ans);
        else printf("Case %d: impossible\n",++caseno);
    }
}

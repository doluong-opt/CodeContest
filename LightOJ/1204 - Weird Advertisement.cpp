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
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 100111

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
struct edge{
    int x, ymin, ymax;
    int begin;
    edge(){}
    edge(int _x, int _ymin, int _ymax, int _begin){
        x = _x;
        ymin = _ymin; 
        ymax = _ymax;
        begin = _begin;
    }
};
struct node{
    int value;
    int ymin, ymax;
    int p[12];
    node(){}
    node(int _v, int _ymin, int _ymax){
        value = _v;
        ymin = _ymin; ymax = _ymax;
    }
};

int n, k;
int xa, xb, ya, yb;

node tree[8 * N];
vector <int> ySet;
vector <edge> edges;
bool cmp(edge a, edge b) {
    return (a.x < b.x);
}
void build(int pos, int l, int r) {
    if (l == r) {
        for (int i = 0;i <= k;i++) tree[pos].p[i] = 0;
        tree[pos].value = 0;
        tree[pos].ymin = ySet[l];
        tree[pos].ymax = ySet[l + 1];
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    build(c, l, mid); build(c + 1, mid + 1, r);
    tree[pos].value = 0;
    tree[pos].ymin = min(tree[c].ymin, tree[c + 1].ymin);
    tree[pos].ymax = max(tree[c].ymax, tree[c + 1].ymax);
    for (int i = 0;i <= k;i++) tree[pos].p[i] = 0;
}
void update(int nodeCur, int l, int r) {
    int tempK = tree[nodeCur].value;
    for (int i = 0;i <= k;i++)
        if (tempK >= i) tree[nodeCur].p[i] = tree[nodeCur].ymax - tree[nodeCur].ymin;
        else
            tree[nodeCur].p[i] = tree[2 * nodeCur].p[i - tempK] + tree[2 * nodeCur + 1].p[i - tempK];
}
void inc(int pos, int u, int v, int l, int r) {
    cout<<tree[pos].ymin<<" "<<tree[pos].ymax<<endl;
    if (r < u || l > v) return;
    if (l == r) {
        tree[pos].value++;
        update(pos, l, r);
        return;
    }
    if (u <= l && r <= v) {
        tree[pos].value++;
        update(pos, l, r);
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    inc(c, u, v, l, mid);
    inc(c + 1, u, v, mid + 1, r);
    update(pos, l, r);
}
void dec(int pos, int u, int v, int l, int r) {
    cout<<tree[pos].ymin<<" "<<tree[pos].ymax<<endl;
    if (r < u || l > v) return;
    if (l == r) {
        tree[pos].value--;
        update(pos, l, r);
        return;
    }
    if (u <= l && r <= v) {
        tree[pos].value--;
        update(pos, l, r);
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    dec(c, u, v, l, mid);
    dec(c + 1, u, v, mid + 1, r);
    update(pos, l, r);
}
int solve() {
    int ans = 0, n = ySet.size() - 2, m = edges.size();
    build(1, 0, n);
    inc(1, edges[0].ymin, edges[0].ymax, 0, n);
    for (int i = 1;i < m;i++) {
        //cout<<tree[1].p[k]<<" "<<edges[i].x - edges[i - 1].x<<endl;
        ans += tree[1].p[k] * (edges[i].x - edges[i - 1].x);
        if ( edges[i].begin )
            inc(1, edges[i].ymin, edges[i].ymax, 0, n);
        else
            dec(1, edges[i].ymin, edges[i].ymax, 0, n);
    }
    return ans;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d %d", &n, &k);
	    set <int> y_points;
	    edges.clear(); ySet.clear();
	    rep(i, n) {
	        scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
	        xb++; yb++;
	        edges.pb(edge(xa, ya, yb, 1));
	        edges.pb(edge(xb, ya, yb, 0));
	        y_points.insert(ya);
	        y_points.insert(yb);
	    }
	    sort(edges.begin(), edges.end(), cmp);
	    for (set <int> :: iterator it = y_points.begin(); it != y_points.end();it++)
            ySet.pb(*it);
        /*cout<<ySet.size()<<endl;
        for (int i = 0;i < ySet.size();i++)
            printf("%d ", ySet[i]);*/
        printf("Case %d: %d\n", ++caseno, solve());
	}
	return 0;
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1120 - Rectangle Union ->AC
* Algorithm IT
* Time Limit 0.385s
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
#define N 30010

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
    int x;
    int ymin, ymax;
    int begin;
    edge(){}
    edge(int xx, int ymi, int yma, int be){
        x = xx; ymin = ymi; ymax = yma; begin = be;
    }
};
struct Node{
    int left, right;
    int64 sum, value;
    int ymin, ymax;
};
set <int> points;
vector <edge> edges;
vector <int> y_points;
Node tree[8 * N];
int64 S;
char s[50];
int ix;
bool cmp(edge a, edge b) {
    return a.x < b.x;
}
void build_tree(int pos, int l, int r) {
    tree[pos].left = l;
    tree[pos].right = r;
    tree[pos].value = tree[pos].sum = 0;
    if (l == r) {
        tree[pos].ymin = y_points[l];
        tree[pos].ymax = y_points[l + 1];
        return;
    }
    int mid = (l + r) >> 1;
    build_tree(pos<<1, l, mid);
    build_tree((pos<<1) + 1, mid + 1, r);
    tree[pos].ymin = min(tree[pos<<1].ymin, tree[(pos<<1) + 1].ymin);
    tree[pos].ymax = max(tree[pos<<1].ymax, tree[(pos<<1) + 1].ymax);
}
void inc(int pos, int a, int b) {
    if (b<=tree[pos].ymin || a>=tree[pos].ymax) return;    
    /*if (tree[pos].left == tree[pos].right) {
        tree[pos].value++;
        tree[pos].sum = tree[pos].ymax - tree[pos].ymin;
        return;
    }*/
    if (a<=tree[pos].ymin && tree[pos].ymax <= b) {
        tree[pos].value++;
        tree[pos].sum = tree[pos].ymax - tree[pos].ymin;
        return;
    }
    inc(pos<<1, a, b);
    inc((pos<<1) + 1, a, b);
    if (!tree[pos].value)
        tree[pos].sum = tree[pos<<1].sum + tree[(pos<<1) + 1].sum;    
}
void dec(int pos, int a, int b) {
    if (b<=tree[pos].ymin || a>=tree[pos].ymax) return;
    /*if (tree[pos].left == tree[pos].right) {
        tree[pos].value--;
        if (!tree[pos].value) tree[pos].sum = 0;
        return;
    }*/
    if (a<=tree[pos].ymin && tree[pos].ymax <= b) {
        tree[pos].value--;
        if (!tree[pos].value)
            tree[pos].sum = tree[pos<<1].sum + tree[(pos<<1) + 1].sum;
        return;
    }
    dec(pos<<1, a, b);
    dec((pos<<1) + 1, a, b);
    if (!tree[pos].value)
        tree[pos].sum = tree[pos<<1].sum + tree[(pos<<1) + 1].sum;
}
void solve() {
    build_tree(1, 1, y_points.size() - 2);
    inc(1, edges[0].ymin, edges[0].ymax);    
    for (int i=1;i<edges.size();i++) {
        S+=tree[1].sum * (edges[i].x - edges[i-1].x);        
        if (edges[i].begin)
            inc(1, edges[i].ymin, edges[i].ymax);
        else
            dec(1, edges[i].ymin, edges[i].ymax);
    }
}
int main(){
    //freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
    int x1, y1, x2, y2, l, n;
    scanf("%d", &n);
        points.clear(); edges.clear();
        y_points.clear();
        S = 0;
        for (int i=0;i<n;i++) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            points.insert(y1);
            points.insert(y2);
            edges.pb(edge(x1, y1, y2, 1));
            edges.pb(edge(x2, y1, y2, 0));
        }
        sort(edges.begin(), edges.end(), cmp);
        set<int> :: iterator it = points.begin();
        y_points.resize(points.size() + 1);
        int i = 1;
        while (it!=points.end()) {
            y_points[i] = *it;
            ++i; ++it;
        }
        solve();
        printf("%lld\n", S);
}

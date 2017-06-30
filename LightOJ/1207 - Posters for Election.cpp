/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1207 - Posters for Election ->AC
* Algorithm IT
* Time Limit 0.565s
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
#define N 100010

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
    int x, y;
    node(){}
    node(int xx, int yy){
        x = xx; y = yy;
    }
    bool operator <(const node &other) const{
        return x < other.x;
    }
};
node d[2 * N], a[N];
int n, Ans, b[2 * N];
int color[N];
int tree[8 * N];
void build_tree(int pos, int l, int r) {
    if (l == r) {
        tree[pos] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build_tree(pos<<1, l, mid);
    build_tree((pos<<1) | 1, mid + 1, r);
}
void update(int pos, int x, int y, int l, int r, int v) {
    if (y < l || x > r) return;
    if (x<=l && r<=y) {
        tree[pos] = v;
        return;
    }
    if (tree[pos]) {
        tree[pos<<1] = tree[pos];
        tree[(pos<<1) | 1] = tree[pos];
        tree[pos] = 0;
    }
    int mid = (l + r) >> 1;
    update(pos<<1, x, y, l, mid, v);
    update((pos<<1) | 1, x, y, mid + 1, r, v);
}
void get(int pos, int l, int r) {
    if (l > r) return;
    if (tree[pos] && color[tree[pos]]) {
        color[tree[pos]] = 0;
        Ans++;
        return;
    }
    if (tree[pos]) return;
    int mid = (l + r) >> 1;
    get(pos<<1, l, mid);
    get((pos<<1) | 1, mid + 1, r);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    int v, m;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) color[i] = 1;
        build_tree(1, 1, 2 * n);
        for (int i=1;i<=2 * n;i++) {
            scanf("%d",&v);
            d[i] = node(v, i);
        }
        m = 0;
        d[0].x = d[1].x - 1;
        sort(d + 1, d + 2 * n + 1);
        for (int i=1;i<=2 * n;i++) {
            if (d[i].x > d[i-1].x) m++;
            b[d[i].y] = m;
        }
        for (int i=1;i<=2 * n;i+=2) {
            a[i/2 + 1].x = b[i];
            a[i/2 + 1].y = b[i+1];
        }
        for (int i=1;i<=n;i++) update(1, a[i].x, a[i].y, 1, m, i);
        Ans = 0;
        get(1, 1, m);
        printf("Case %d: %d\n",++caseno, Ans);
    }
}

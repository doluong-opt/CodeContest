// =============================================================================
// Author LUONG VAN DO
// Problem 1348 - Aladdin and the Return Journey
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
#define N 30010

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

// optimization input / output
int m, ind;
char buff[N * 20];

int nextInt() {
    int v = 0;
    while (ind < m && buff[ind] != ' ') v = v * 10 + buff[ind++] - '0';
    while (ind < m && buff[ind] == ' ') ++ind;
    return v;
}

int readLine() {
    gets(buff); m = strlen(buff); ind = 0;
    return (m == 0);
}

void prinln(int n) {
    if (!n) {
        puts("0");
        return;
    }
    m = 0;
    while ( n ) {
        buff[m++] = (n % 10 + 48);
        n/=10;
    }
    repr(i, m) putchar(buff[i]);
    puts("");
}

// End-----


struct bitTree {
    vi tree, amount;
    void clear() {
        tree.clear(); amount.clear();
    }
    void updateBit(int i, int val) {
        if (!i) return;
        while (i < tree.size()) {
            tree[i] += val;
            i += (i&-i);
        }
    }
    int getBit(int i) {
        int res = 0;
        while ( i ) {
            res += tree[i];
            i -= (i&-i);
        }
        return res;
    }
    void build() {
        tree.resize(amount.size() + 1, 0);
        rep(i, amount.size()) updateBit(i + 1, amount[i]);
        amount.clear();
    }
    void add(int val) {
        amount.pb(val);
    }
} tree[N];

vi adj[N];
int n, a[N];
int depth[N], head[N], number[N], parent[N], size[N];
bool heavy[N];

int dfs(int u, int p, int lvl) {
    size[u] = 1;
    parent[u] = p;
    depth[u] = lvl;
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        if (v != p) size[u] += dfs(v, u, lvl + 1);
    }
    return size[u];
}

// Build tree heavy - light - decomposition

void buildHLD(int u, int first, int ind) {
    number[u] = ind;
    head[u] = first;
    for (int i = 0;i < adj[u].size();i++) {
        int v = adj[u][i];
        if (parent[u] == v) continue;
        if (size[v] > size[u] / 2) heavy[v] = true, tree[head[u]].add(a[v]), buildHLD(v, first, ind + 1);
        else buildHLD(v, v, 0);
    }
}

int getLCA(int u, int v) {
    while ( head[u] != head[v] ) {
        if ( depth[head[u]] < depth[head[v]] ) swap(u, v);
        // u = (heavy[u] ? head[u] : parent[u]);
        u = parent[head[u]];
    }
    return (depth[u] < depth[v] ? u : v);
}

int getSum(int u) {
    int res = 0;
    while ( u != -1 ) {
        if (heavy[u]) res += tree[head[u]].getBit(number[u]);
        else res += a[u];
        u = (heavy[u] ? head[u] : parent[u]);
    }
    return res;
}

void update(int u, int val) {
    if (heavy[u]) tree[head[u]].updateBit(number[u], val - a[u]);
    a[u] = val;
}

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, u, v, root, c, q;
    readLine();
    cases = nextInt();
    while (cases--) {
        while (readLine());
        n = nextInt();
        readLine();
        rep(i, n) {
            a[i] = nextInt();
            adj[i].clear(); heavy[i] = false;
        }
        rep(i, n - 1) {
            readLine();
            u = nextInt(); v = nextInt();
            adj[u].pb(v); adj[v].pb(u);
            tree[i].clear();
        }
        dfs(0, -1, 0);
        buildHLD(0, 0, 0);
        rep(i, n) tree[i].build();
        printf("Case %d:\n", ++caseno);
        readLine();
        q = nextInt();
        while (q--) {
            readLine();
            c = nextInt(); u = nextInt(); v = nextInt();
            if (c) update(u, v);
            else {
                root = getLCA(u, v);
                prinln(getSum(u) + getSum(v) - 2 * getSum(root) + a[root]);
            }
        }
    }
}

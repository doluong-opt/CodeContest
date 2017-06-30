// =============================================================================
// Author LUONG VAN DO
// Problem 12424 - Answering Queries on a Tree
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
#define N 100001

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

struct bitTree {
    int n;
    vi amount;
    vector <vi> tree;
    void clear() { tree.clear(); amount.clear(); };
    void updateBit(int i, int c, int val) {
        if (!i) return;
        while ( i <= n ) {
            tree[i][c] += val;
            i += (i & -i);
        }
    }
    int getBit(int i, int c) {
        int res = 0;
        while ( i ) {
            res += tree[i][c];
            i -= (i & -i);
        }
        return res;
    }
    void build() {
        n = amount.size();
        tree.resize(n + 1);
        fr(i, 1, n) tree[i].resize(10, 0);
        rep(i, amount.size()) updateBit(i + 1, amount[i], 1);
        amount.clear();
    }
    void add(int val) { amount.pb(val); }
} tree[N];


vi adj[N];
int a[N], depth[N], head[N], parent[N], size[N], ind[N];
int n, q, x, m, v;
char s[N * 20], buff[20];
bool heavy[N];

// optimization input / output

int nextInt() {
    v = 0;
    while (x < m && s[x] != ' ') v = v * 10 + s[x++] - '0';
    ++x;
    return v;
}

void readLine() {
    gets(s); m = strlen(s); x = 0;
}

// End optimi........

int dfs(int u, int p, int lvl) {
    parent[u] = p;
    depth[u] = lvl;
    size[u] = 1;
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        if (v != p) size[u] += dfs(v, u, lvl + 1);
    }
    return size[u];
}


void buildHLD(int u, int first, int num) {
    ind[u] = num;
    head[u] = first;
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        if (parent[u] == v) continue;
        if (size[v] > size[u] / 2) heavy[v] = true, tree[head[u]].add(a[v]), buildHLD(v, first, num + 1);
        else buildHLD(v, v, 0);
    }
}

int getLCA(int u, int v) {
    while ( head[u] != head[v] ) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        if (heavy[u]) u = head[u];
        else u = parent[u];
    }
    return (depth[u] < depth[v] ? u : v);
}


int getSum(int u, int color) {
    int res = 0;
    while ( u != -1 ) {
        if (heavy[u]) {
            res += tree[head[u]].getBit(ind[u], color);
            u = head[u];
        }
        else {
            res += (a[u] == color);
            u = parent[u];
        }
    }
    return res;
}

void update(int u, int color) {
    if (heavy[u]) {
        tree[head[u]].updateBit(ind[u], a[u], -1);
        tree[head[u]].updateBit(ind[u], color, 1);
    }
    a[u] = color;
}

void prinln(int n) {
    m = 0;
    while ( n ) {
        buff[m++] = (n % 10 + 48);
        n/=10;
    }
    repr(i, m) putchar(buff[i]);
    puts("");
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, c, u, v, ans, k;
    readLine();
    cases = nextInt();
    while (cases--) {
        readLine();
        n = nextInt(); q = nextInt();
        readLine();
        rep(i, n) {
            a[i] = nextInt() - 1;
            adj[i].clear();
            tree[i].clear();
            heavy[i] = false;
        }
        
        rep(i, n - 1) {
            readLine();
            u = nextInt() - 1; v = nextInt() - 1;
            adj[u].pb(v); adj[v].pb(u);
        }
        dfs(0, -1, 0);
        buildHLD(0, 0, 0);
        rep(i, n) tree[i].build();
        rep(i, q) {
            readLine();
            c = nextInt(); u = nextInt() - 1; v = nextInt() - 1;
            if (c) {
                ans = 0;
                k = getLCA(u, v);
                rep(i, 10)
                    ans = max(ans, getSum(u, i) + getSum(v, i) - 2 * getSum(k, i) + ((a[k] == i) ? 1 : 0));
                prinln(ans);
            }
            else update(u, v);
        }
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* 1164 - Horrible Queries ->AC
* Algorithm IT
* Time Limit 0.282s
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
#define N 100010

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node {
    int64 sum, value;
};
node tree[8 * N];
int ix;
char s[110];
void build_tree(int pos, int l, int r) {
    tree[pos].value = 0;
    tree[pos].sum = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build_tree(pos<<1, l, mid);
    build_tree((pos<<1)|1, mid + 1, r);
}
void update(int pos, int x, int y, int l, int r, int v) {
    if (y<l || x > r) return;
    if (x<=l && r<=y) {
        tree[pos].value += v;
        tree[pos].sum += (int64)v * (r - l + 1);
        return;
    }
    int mid = (l + r) >> 1;
    if (tree[pos].value != 0) {
        tree[pos<<1].sum += (mid - l + 1) * tree[pos].value;
        tree[(pos<<1)|1].sum += (r - mid) * tree[pos].value;
        tree[pos].sum = 0;
        tree[pos<<1].value+=tree[pos].value;
        tree[(pos<<1)|1].value+= tree[pos].value;
        tree[pos].value = 0;
    }
    update(pos<<1, x, y, l, mid, v);
    update((pos<<1)|1, x, y, mid + 1, r, v);
    tree[pos].sum = tree[pos<<1].sum + tree[(pos<<1)|1].sum;
}
int64 get(int pos, int x, int y, int l, int r) {
    if (y < l || x > r) return 0;
    if (x<=l && r<=y) return tree[pos].sum;
    int mid = (l + r) >> 1;
    if (tree[pos].value != 0) {
        tree[pos<<1].sum += (mid - l + 1) * tree[pos].value;
        tree[(pos<<1)|1].sum += (r - mid) * tree[pos].value;
        tree[pos<<1].value+=tree[pos].value;
        tree[(pos<<1)|1].value+= tree[pos].value;
        tree[pos].value = 0;
    }
    return get(pos<<1, x, y, l, mid) + get((pos<<1)|1, x, y, mid + 1, r);
}
int getInt(int n) {
    int val = 0;
    while (ix < n && s[ix]!=' ') val = val * 10 + s[ix++] - '0';
    return val;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    int x, y, c, n, q, l;
    gets(s); ix = 0; cases = getInt(strlen(s));
    while (cases--) {
        gets(s); ix = 0;
        n = getInt(strlen(s)); ++ix;
        q = getInt(strlen(s));
        build_tree(1, 1, n);
        printf("Case %d:\n",++caseno);
        while (q--) {
            gets(s); l = strlen(s); ix = 0;
            c = getInt(l); ++ix;
            if (!c) {
                x = getInt(l); ++ix;
                y = getInt(l); ++ix;
                c = getInt(l);
                ++x; ++y;
                update(1, x, y, 1, n, c);
            }
            else {
                x = getInt(l); ++ix;
                y = getInt(l);
                ++x; ++y;
                printf("%lld\n",get(1, x, y, 1, n));
            }
        }
    }
    return 0;
}

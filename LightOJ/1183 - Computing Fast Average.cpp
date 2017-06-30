/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1183 - Computing Fast Average ->AC
* Algorithm IT
* Time Limit 0.241s
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
    int no, sum;
};
node tree[8 * N];
char s[100];
int ix;
void build_tree(int pos, int l, int r) {
    tree[pos].no = -1;
    tree[pos].sum = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build_tree(pos<<1, l, mid);
    build_tree((pos<<1)|1, mid + 1, r);
}
void update(int pos, int x, int y, int l, int r, int v) {
    if (y < l || x > r) return;
    if (x<=l && r<=y) {
        tree[pos].no = v;
        tree[pos].sum = v * (r - l + 1);
        return;
    }
    int mid = (l + r) >> 1;
    if (tree[pos].no != -1) {
        tree[pos<<1].sum = (mid - l + 1) * tree[pos].no;
        tree[(pos<<1)|1].sum = (r - mid) * tree[pos].no;
        tree[pos<<1].no = tree[(pos<<1)|1].no = tree[pos].no;
        tree[pos].no = -1;
    }
    update(pos<<1, x, y, l, mid, v);
    update((pos<<1)|1, x, y, mid + 1, r, v);
    tree[pos].sum = tree[pos<<1].sum + tree[(pos<<1)|1].sum;
}
int get(int pos, int x, int y, int l, int r) {
    if (y < l || x > r) return 0;
    if (x<=l && r<=y) return tree[pos].sum;
    int mid = (l + r) >> 1;
    if (tree[pos].no != -1) {
        tree[pos<<1].sum = (mid - l + 1) * tree[pos].no;
        tree[(pos<<1)|1].sum = (r - mid) * tree[pos].no;
        tree[pos<<1].no = tree[(pos<<1)|1].no = tree[pos].no;
        tree[pos].no = -1;
    }
    return get(pos<<1, x, y, l, mid) + get((pos<<1)|1, x, y, mid + 1, r);
}
int getInt(int n) {
    int val = 0;
    while (ix < n && s[ix] !=' ') val = val * 10 + s[ix++] - '0';
    return val;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, q, caseno = 0;
    int c, x, y, v, l;
    int r1, r2, d;
    gets(s); ix = 0; cases = getInt(strlen(s));
    while (cases--) {
        gets(s); n = q = ix = 0;
        n = getInt(strlen(s)); ++ix;
        q = getInt(strlen(s));
        build_tree(1, 1, n);
        printf("Case %d:\n",++caseno);
        while (q--) {
            gets(s); c = ix = 0; l = strlen(s);
            c = getInt(l); ++ix;
            if (c == 1) {
                x = y = v = 0;
                x = getInt(l); ++ix;
                y = getInt(l); ++ix;
                v = getInt(l);
                ++x; ++y;
                update(1, x, y, 1, n, v);
            }
            else {
                x = y = 0;
                x = getInt(l); ++ix;
                y = getInt(l);
                ++x; ++y;
                r1 = get(1, x, y, 1, n);
                r2 = y - x + 1;
                d = gcd(r1, r2);
                r1/=d; r2/=d;
                if (r2 == 1) printf("%d\n",r1);
                else
                if (r1 == 0) printf("0\n");
                else printf("%d/%d\n",r1,r2);
            }
        }
    }
}

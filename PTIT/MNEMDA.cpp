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
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i = b;i >= a;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define pb push_back
#define ff first
#define ss second
#define fill(arr, val) memset(arr, val, sizeof(arr))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint32 unsigned int
#define INF 1000000000
#define N 1000100

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
    int val, sum;
    node(){}
    node(int _val, int _sum){
        val = _val; sum = _sum;
    }
};
int m, n, k, last, len, x, y, a, b, lf, rt, sign;
node tree[8 * 8 * N];
int val[8 * 8 * N], st[8];
void build(int pos, int l, int r) {
    if (l == r) {
        tree[pos].val = val[l];
        tree[pos].sum = val[l];
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    build(c, l, mid);
    build(c + 1, mid + 1, r);
    tree[pos].sum = tree[c].sum + tree[c + 1].sum;
}
void update(int pos, int l, int r, int u, int v) {
    if (r < u || l > v) return;
    if (u <= l && r <= v) {
        tree[pos].val = 0;
        tree[pos].sum = 0;
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    if ( !tree[pos].val ) {
        tree[c].val = tree[c + 1].val = 0;
    }
    if ( !tree[pos].sum ) {
        tree[c].sum = tree[c + 1].sum = 0;
    }
    update(c, l, mid, u, v);
    update(c + 1, mid + 1, r, u, v);
    tree[pos].sum = tree[c].sum + tree[c + 1].sum;
}
int getSum(int pos, int l, int r, int u, int v) {
    if (r < u || l > v) return 0;
    if (u <= l && r <= v) return tree[pos].sum;
    int mid = (l + r) >> 1, c = 2 * pos;
    if ( !tree[pos].val ) {
        tree[c].val = tree[c + 1].val = 0;
    }
    if ( !tree[pos].sum ) {
        tree[c].sum = tree[c + 1].sum = 0;
    }
    int a = getSum(c, l, mid, u, v);
    int b = getSum(c + 1, mid + 1, r, u, v);
    return a + b;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
    scanf("%d %d %d", &m, &n, &k);
    len = 0;
    for (int i = 1;i <= m;i++) {
        scanf("%d", &x); last = 0;
        while (x) st[last++] = x % 2, x /= 2;
        while (last < 8) st[last++] = 0;
        for (int j = last - 1;j >= 0;j--) val[++len] = st[j];
    }
    build(1, 1, len);
    //cout << tree[1].sum << endl;
    for (int i = 1;i <= n;i++) {
        scanf("%d %d %d %d", &x, &a, &y, &b);
        lf = x * 8 + (8 - a);
        rt = y * 8 + (8 - b);
        update(1, 1, len, lf, rt);
    }
    //cout << tree[1].sum << endl;
    for (int i = 1;i <= k;i++) {
        scanf("%d %d %d %d", &x, &a, &y, &b);
        lf = x * 8 + (8 - a);
        rt = y * 8 + (8 - b);
        sign = getSum(1, 1, len, lf, rt);
        //cout << sign << endl;
        update(1, 1, len, lf, rt);
        if (sign > 0) puts("YES");
        else puts("PASS");
    }
	return 0;
}

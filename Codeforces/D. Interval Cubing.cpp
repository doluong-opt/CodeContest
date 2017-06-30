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
#define mod 95542721
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
int a[N];
int n, q, x, y, c;
int inc[8 * N], temp[50], tree[8 * N][50];
int getCube(int x) {
    return (x * (int64)((x * (int64)x) % mod)) % mod;
}
void pushDown(int x) {
    if ( !inc[x] ) return;
    inc[x + x] = (inc[x + x] + inc[x]) % 48;
    inc[x + x + 1] = (inc[x + x + 1] + inc[x]) % 48;
    rep(i, 48) temp[i] = tree[x + x][i];    
    rep(i, 48) tree[x + x][i] = temp[(i + inc[x]) % 48];
    rep(i, 48) temp[i] = tree[x + x + 1][i];
    rep(i, 48) tree[x + x + 1][i] = temp[(i + inc[x]) % 48];
    inc[x] = 0;
}
void buildTree(int pos, int l, int r) {
    if (l == r) {
        tree[pos][0] = a[l];
        for (int i = 1;i < 48;i++) tree[pos][i] = getCube(tree[pos][i - 1]);
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    buildTree(c, l, mid); buildTree(c + 1, mid + 1, r);
    inc[pos] = 0;
    for (int i = 0;i < 48;i++) tree[pos][i] = (tree[c][i] + tree[c + 1][i]) % mod;
}
void update(int pos, int l, int r, int x, int y) {
    if (r < x || l > y) return;
    if (x <= l && r <= y) {
        inc[pos] = (inc[pos] + 1) % 48;
        rep(i, 48) temp[i] = tree[pos][i];
        rep(i, 48) tree[pos][i] = temp[(i + 1) % 48];
        return;
    }
    pushDown(pos);
    int mid = (l + r) >> 1, c = 2 * pos;
    update(c, l, mid, x, y); update(c + 1, mid + 1, r, x, y);
    rep(i, 48) tree[pos][i] = (tree[c][i] + tree[c + 1][i]) % mod;
}
int getSum(int pos, int l, int r, int x, int y) {
    if (r < x || l > y) return 0LL;
    if (x <= l && r <= y) return tree[pos][0];
    pushDown(pos);
    int mid = (l + r) >> 1, c = 2 * pos;
    int64 a = getSum(c, l, mid, x, y);
    int64 b = getSum(c + 1, mid + 1, r, x, y);
    rep(i, 48) tree[pos][i] = (tree[c][i] + tree[c + 1][i]) % mod;
    return (a + b) % mod;
}
int main() {
    //freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n);
	fr(i, 1, n) scanf("%d", &a[i]);
	buildTree(1, 1, n);
	scanf("%d", &q);
	rep(i, q) {
	    scanf("%d %d %d", &c, &x, &y);
	    if (c == 2) update(1, 1, n, x, y);
	    else printf("%d\n", getSum(1, 1, n, x, y));
	}
	return 0;
}

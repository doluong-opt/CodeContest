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
int a[N], tree[8 * N], n;
int64 ans;
void build(int pos, int l, int r) {
    if (l == r) {
        tree[pos] = a[l];
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    build(c, l, mid);
    build(c + 1, mid + 1, r);
    tree[pos] = max(tree[c], tree[c + 1]);
}
int getMax(int pos, int u, int v, int l, int r) {
    if (u > v) return 0;
    if (r < u || l > v) return 0;
    if (u <= l && r <= v) return tree[pos];
    int mid = (l + r) >> 1, c = 2 * pos;
    int a = getMax(c, u, v, l, mid);
    int b = getMax(c + 1, u, v, mid + 1, r);
    return max(a, b);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int l, r;
	scanf("%d", &n);
	fr(i, 1, n) scanf("%d", &a[i]);
	build(1, 1, n);
	ans = 0LL;
	fr(i, 1, n) {
	    l = getMax(1, 1, i - 1, 1, n);
	    r = getMax(1, i + 1, n, 1, n);
	    if (a[i] < l && a[i] < r) ans += min(l, r) - a[i];
	}
	printf("%lld\n", ans);
	return 0;
}

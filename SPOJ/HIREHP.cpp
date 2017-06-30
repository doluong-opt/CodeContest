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
#define INF 2000000000000LL
#define N 500111

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int64, int64> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
ii d[N];
int n;
int64 f[N], tree[8 * N];
void update(int pos, int u, int v, int l, int r, int64 val) {
    if (r < u || l > v) return;
    if (u <= l && r <= v) {
        tree[pos] += val;
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    update(c, u, v, l, mid, val);
    update(c + 1, u, v, mid + 1, r, val);
    tree[pos] = min(tree[c], tree[c + 1]);
}
int64 getMin(int pos, int u, int v, int l, int r) {
    if (r < u || l > v) return INF;
    if (u <= l && r <= v) return tree[pos];
    int mid = (l + r) >> 1, c = 2 * pos;
    int64 a = getMin(c, u, v, l, mid);
    int64 b = getMin(c + 1, u, v, mid + 1, r);
    tree[pos] = min(tree[c], tree[c + 1]);
    return min(a, b);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n);
	fr(i, 1, n) scanf("%lld %lld", &d[i].ff, &d[i].ss);
	f[n] = d[n].ss;
	update(1, n, n, 1, n + 1, d[n].ss);	
	for (int i = n - 1;i >= 1;i--) {
	    int64 nextSmall = getMin(1, i + 1, d[i].ff + 1, 1, n + 1);
        f[i] = nextSmall + d[i].ss;
        update(1, i, i, 1, n + 1, f[i]);
	}
	printf("%lld\n", f[1]);
	return 0;
}

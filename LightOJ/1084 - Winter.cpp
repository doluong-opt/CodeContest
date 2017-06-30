/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1084 - Winter
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
int n, k, a[N];
int dp[N], j_min;
int tree[8 * N];
void build(int pos, int l, int r) {
    tree[pos] = INF;
    if (l == r) return;    
    int mid = (l + r) >> 1, c = 2 * pos;
    build(c, l, mid); build(c + 1, mid + 1, r);
}
void update(int pos, int x, int l, int r, int val) {
    if (r < x || l > x) return;
    if (x <= l && r <= x) {
        tree[pos] = min(tree[pos], val);
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    update(c, x, l, mid, val);
    update(c + 1, x, mid + 1, r, val);
    tree[pos] = min(tree[c], tree[c + 1]);
}
int getMin(int pos, int u, int v, int l, int r) {
    if (r < u || l > v) return INF;
    if (u <= l && r <= v) return tree[pos];
    int mid = (l + r) >> 1, c = 2 * pos;
    int a = getMin(c, u, v, l, mid);
    int b = getMin(c + 1, u, v, mid + 1, r);
    return min(a, b);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
	scanf("%d", &cases);
	while (cases--) {
        scanf("%d %d", &n, &k);
        fr(i, 1, n) {
            scanf("%d", &a[i]);
            dp[i] = INF;
        }
        build(1, 0, n); update(1, 0, 0, n, 0);
        sort(a + 1, a + n + 1);
        j_min = 1;
        for (int i = 1;i <= n;i++) {
            while (j_min <= i - 2 && a[i] - a[j_min] > 2 * k) j_min++;
            if (j_min <= i - 2) {
                dp[i] = getMin(1, j_min - 1, i - 3, 0, n) + 1;
                update(1, i, 0, n, dp[i]);
            }
        }
        if (dp[n] < INF) printf("Case %d: %d\n", ++caseno, dp[n]);
        else printf("Case %d: -1\n", ++caseno);
	}
	return 0;
}

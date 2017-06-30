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
#define N 50005

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
int n, q, x, y;
int a[N], treeMin[8 * N], treeMax[8 * N];
void build(int pos, int l, int r) {
    if (l == r) {
        treeMin[pos] = a[l];
        treeMax[pos] = a[l];
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    build(c, l, mid); build(c + 1, mid + 1, r);
    treeMin[pos] = min(treeMin[c], treeMin[c + 1]);
    treeMax[pos] = max(treeMax[c], treeMax[c + 1]);
}
int getMax(int pos, int x, int y, int l, int r) {
    if (r < x || l > y) return 0;
    if (x <= l && r <= y) return treeMax[pos];
    int mid = (l + r) >> 1, c = 2 * pos;
    int a = getMax(c, x, y, l, mid);
    int b = getMax(c + 1, x, y, mid + 1, r);
    return max(a, b);
}
int getMin(int pos, int x, int y, int l, int r) {
    if (r < x || l > y) return INF;
    if (x <= l && r <= y) return treeMin[pos];
    int mid = (l + r) >> 1, c = 2 * pos;
    int a = getMin(c, x, y, l, mid);
    int b = getMin(c + 1, x, y, mid + 1, r);
    return min(a, b);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d", &n, &q);
	fr(i, 1, n) scanf("%d", &a[i]);
	build(1, 1, n);
	rep(i, q) {
	    scanf("%d %d", &x, &y);
	    printf("%d\n", getMax(1, x, y, 1, n) - getMin(1, x, y, 1, n));
	}
	return 0;
}

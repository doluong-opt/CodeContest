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
#define INF 1000000000
#define N 140100
#define maxN 5000000
#define M 1114716
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
struct seg{
    int value, total;
}tree[maxN + 5];
int f[N + 5], n;
int mark[maxN];
void build(int pos, int l, int r) {
    if (l == r) {
        tree[pos].value = 2 * l - 1;
        tree[pos].total = 1;
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    build(c, l, mid); build(c + 1, mid + 1, r);
    tree[pos].total = tree[c].total + tree[c + 1].total;
}
void update(int pos, int l, int r, int val) {
    tree[pos].total--;
    if (l == r) return;
    int mid = (l + r) >> 1, c = 2 * pos;
    if (tree[c].total >= val) update(c, l, mid, val);
    else update(c + 1, mid + 1, r, val - tree[c].total);
}
int get(int pos, int l, int r, int val) {
    if (l == r) return tree[pos].value;
    int mid = (l + r) >> 1, c = 2 * pos;
    if (tree[c].total >= val) return get(c, l, mid, val);
    else return get(c + 1, mid + 1, r, val - tree[c].total);
}
void init() {
    int k, val;
    f[1] = 1;
    build(1, 1, M);
    for (int i = 2;i<=140000;i++) {
        f[i] = get(1, 1, M, i);
        k = 1;
        val = f[i] * k;
        if (val > tree[1].total) continue;
        do{
            ++k;
            update(1, 1, M, val);
            val = (f[i] * k) - k + 1;
        }while ( val <= tree[1].total );
    }
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	init();
	for (int i = 1;i <= 140000;i++) mark[i] = 0;
	for (int i = 1;i <= 140000;i++) mark[f[i]] = 1;
	while ( scanf("%d", &n) != EOF) {
	    if (n & 1) {
	        printf("%d is not the sum of two luckies!\n", n);
	        continue;
	    }
	    int x = n / 2;
	    while (x >= 1 && !mark[x] ) x--;
	    while ( x > 0 ) {
	        if (n >= x && mark[x] && mark[n - x] ) break;
	        x -= 2;
	    }
        if (x > 0) printf("%d is the sum of %d and %d.\n", n, x, n - x);
        else printf("%d is not the sum of two luckies!\n", n);
	}
	return 0;
}

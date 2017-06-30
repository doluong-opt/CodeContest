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
#define N 250001

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
    int a, b, d, x;
    bool flag;
    int64 sum;
};
seg tree[8 * N];
char op[5];
int st, nd, x;
int64 total[N + 5];
void build_tree(int pos, int l, int r) {
    tree[pos].a = tree[pos].b = tree[pos].d = tree[pos].x = tree[pos].sum = 0;
    tree[pos].flag = false;
    if (l == r) return;
    int mid = (l + r) >> 1, c = 2 * pos;
    build_tree(c, l, mid);
    build_tree(c + 1, mid + 1, r);
}
void updateLeft(int pos, int x, int y, int l, int r) {
    if (y < l || r < x) return;
    int mid = (l + r) >> 1, c = 2 * pos;
    if (x <= l && r <= y) {
        tree[pos].sum += total[r - x + 1] - total[l - x];
        tree[c].a++; tree[c + 1].a++;
        tree[c].d += (l - x); tree[c + 1].d += (mid + 1 - x);
        return;
    }
    updateLeft(c, x, y, l, mid);
    updateLeft(c + 1, x, y, mid + 1, r);
    tree[pos].sum = tree[c].sum + tree[c + 1].sum;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
	total[0] = 0;
	fr(i, 1, N) total[i] = total[i - 1] + i;
	scanf(" %d ", &cases);
	while (cases--) {
	    build_tree(1, 1, N - 1);
	    scanf(" %s ", &op);
	    if (op[0] == 'A') {
	        scanf("%d %d", &st, &nd);
	        updateLeft(1, st, nd, 1, N - 1);
	    }
	    else 
	    if (op[0] == 'B') {
	        scanf("%d %d", &st, &nd);
	    }
	    else
	    if (op[0] == 'C') {
	        scanf("%d %d %d", &st, &nd, &x);
	    }
	    else {
	        scanf("%d %d", &st, &nd);
	        printf("%lld\n", getSum(1, st, nd, 1, N - 1));
	    }
	}
	return 0;
}

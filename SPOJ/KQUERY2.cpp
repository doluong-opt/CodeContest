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

#define N 30111
#define V 10111
#define M 200

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
int n, m, nBit, q, e;
int a[N], l[N], r[N], pos[N];
int tree[M][V];
void update(int i, int x, int val) {
    while ( x ) {
        tree[i][x] += val;
        x -= (x & -x);
    }
}
int get(int i, int x) {
    int ans = 0;
    while ( x <= V ) {
        ans += tree[i][x];
        x += (x & -x);
    }
    return ans;
}
int run(int u, int v, int k) {
    int res = 0;
    if (pos[u] == pos[v]) {
        fr(i, u, v)
            if (a[i] > k) res++;
        return res;
    }
    fr(i, u, r[pos[u]])
        if (a[i] > k) res++;
    fr(i, l[pos[v]], v)
        if (a[i] > k) res++;
    fr(i, pos[u] + 1, pos[v] - 1)
        res += get(i, k + 1);
    return res;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int u, v, k;
	scanf("%d", &n);
	fr(i, 1, n) scanf("%d", &a[i]);
	nBit = 1; m = (int)sqrt(n);
	l[nBit] = 1;
	fr(i, 1, n) {
	    pos[i] = nBit;
	    if (i % m == 0) {
	        r[nBit++] = i;
	        l[nBit] = i + 1;
	    }
	}
	r[nBit] = n; fill(tree, 0);
	fr(i, 1, n)
        fr(j, l[i], r[i])
            update(i, a[j], 1);
	scanf("%d", &q);
	fr(i, 1, q) {
	    scanf("%d", &e);
	    if (e == 0) {
	        scanf("%d %d", &u, &v);
	        update(pos[u], a[u], -1);
	        update(pos[u], v, 1);
	        a[u] = v;
	    }
	    if (e == 1) {
	        scanf("%d %d %d", &u, &v, &k);
	        printf("%d\n", run(u, v, k));
        }
	}
	return 0;
}

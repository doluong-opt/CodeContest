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
int bitGroup[N], bitAmount[N], a[N], ans;
int tree[8 * N], n, m, x, y;
char q;
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
void updateBIT(int tree[], int x, int val){
    while ( x <= n ) {
        tree[x] += val;
        x += (x & -x);
    }
}
void updateIT(int pos, int u, int v, int l, int r) {
    //cout<<pos<<" "<<u<<" "<<v<<" "<<l<<" "<<r<<endl;
    if (r < u || l > v) return;
    if (u <= l && r <= v) {
        tree[pos] = -1;
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    updateIT(c, u, v, l, mid);
    updateIT(c + 1, u, v, mid + 1, r);
    tree[pos] = max(tree[c], tree[c + 1]);
}
int get(int tree[], int x) {
    int total = 0;
    while ( x ) {
        total += tree[x];
        x -= (x & -x);
    }
    return total;
}
int fleft(int tree[], int key, int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if ( get(tree, mid) >= key ) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int fright(int tree[], int key, int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if ( get(tree, mid) <= key ) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
int getMax(int pos, int u, int v, int l, int r) {
    if (r < u || l > v) return -1;
    if (u <= l && r <= v) return tree[pos];
    int mid = (l + r) >> 1, c = 2 * pos;
    int a = getMax(c, u, v, l, mid);
    int b = getMax(c + 1, u, v, mid + 1, r);
    return max(a, b);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) bitAmount[i] = bitGroup[i] = 0;
	for (int i = 1;i <= n;i++) {
	    scanf("%d", &a[i]);
	    updateBIT(bitAmount, i, 1);
	}
	build(1, 1, n);
	scanf(" %d ", &m);
	for (int i = 1;i <= m;i++) {
	    scanf(" %c ", &q);
	    if (q == 'S') {
	        scanf(" %d ", &x);
	        x = fleft(bitAmount, x, 1, n);
	        updateBIT(bitAmount, x, -1);
	        updateBIT(bitGroup, x, 1);
	        updateIT(1, x, x, 1, n);
	    }
	    else {
	        scanf(" %d %d ", &x, &y);
	        x = max(x, 0); y = min(y, n);
	        x = fleft(bitGroup, x, 1, n);
	        y = fright(bitGroup, y, 1, n);
	        ans = getMax(1, x, y, 1, n);
	        if (ans == -1) puts("NONE");
	        else printf("%d\n", ans);
	    }
	}
	//cout << tree[3] << endl;
}

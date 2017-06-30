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
#define M 1000000007

struct node{
    int64 size;
    int64 val[7];
};

int n, m, q;
node IT[8 * N];
int BIT[N], x, k;
int64 v, a[N];
void updateBIT(int x, int val) {
    while ( x <= n ) {
        BIT[x]+=val;
        x += (x & -x);
    }
}
int get(int x) {
    int total = 0;
    while ( x ) {
        total += BIT[x];
        x -= (x & -x);
    }
    return total;
}
void build(int pos, int l, int r) {
    if (l == r) {
        IT[pos].size = 1;
        IT[pos].val[0] = a[l];
        fr(i, 1, 6) IT[pos].val[i] = 1;
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    build(c, l, mid);
    build(c + 1, mid + 1, r);
    for (int k = 0;k <= 6;k++) {
        int x = ((k - (IT[c].size % 7)) + 7) % 7;
        IT[pos].val[k] = IT[c].val[k] * IT[c + 1].val[x];
        IT[pos].val[k] %= M;
    }
    IT[pos].size = IT[c].size + IT[c + 1].size;
}
int binary(int key, int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (get(mid) >= key) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
void update1(int pos, int key, int l, int r) {
    if (key < l || key > r) return;
    if (key <= l && r <= key) {
        IT[pos].size = 0;
        IT[pos].val[0] = 1LL;
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    update1(c, key, l, mid);
    update1(c + 1, key, mid + 1, r);    
    for (int k = 0;k <= 6;k++) {
        int x = ((k - (IT[c].size % 7)) + 7) % 7;
        IT[pos].val[k] = IT[c].val[k] * IT[c + 1].val[x];
        IT[pos].val[k] %= M;
    }
    IT[pos].size = IT[c].size + IT[c + 1].size;
}
void update2(int pos, int key, int l, int r, int64 v) {
    if (key < l || key > r) return;
    if (key <= l && r <= key) {
        IT[pos].val[0] = v;        
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    update2(c, key, l, mid, v);
    update2(c + 1, key, mid + 1, r, v);
    for (int k = 0;k <= 6;k++) {
        int x = ((k - (IT[c].size % 7)) + 7) % 7;
        IT[pos].val[k] = IT[c].val[k] * IT[c + 1].val[x];
        IT[pos].val[k] %= M;
    }
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 0;i < n;i++) {
	    scanf("%lld", &a[i]);
	    updateBIT(i + 1, 1);
	}
	build(1, 0, n - 1);
	for (int i = 0;i < m;i++) {
	    scanf("%d", &q);
	    if (q == 3) {
	        scanf("%d", &k);
	        printf("%lld\n", IT[1].val[k]);
	    }
	    else
	    if (q == 1) {
	        scanf("%d", &x);
	        int pos = binary(x + 1, 1, n);
	        updateBIT(pos, -1);
	        update1(1, pos - 1, 0, n - 1);
	    }
	    else 
	    if (q == 2) {
	        scanf("%d %lld", &x, &v);
	        int pos = binary(x + 1, 1, n);
	        update2(1, pos - 1, 0, n - 1, v);
	    }
	}
}

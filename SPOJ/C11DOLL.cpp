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
struct node{
    int minVal;
    int inc;
};
node IT[8 * N];
int n, m, a[N], l[N], r[N], d[N], ans, pivot;
void build(int pos, int l, int r) {
    if (l == r) {
        IT[pos].inc = 0;
        IT[pos].minVal = d[l];
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    build(c, l, mid);
    build(c + 1, mid + 1, r);
    IT[pos].inc = IT[c].inc + IT[c + 1].inc;
    IT[pos].minVal = min(IT[c].minVal, IT[c + 1].minVal);
}
void update(int pos, int u, int v, int l, int r, int val) {
    if (r < u || l > v) return;
    if (u <= l && r <= v) {
        IT[pos].inc += val;
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    IT[c].inc += IT[pos].inc;
    IT[c + 1].inc += IT[pos].inc;
    IT[pos].inc = 0;
    update(c, u, v, l, mid, val);
    update(c + 1, u, v, mid + 1, r, val);
    IT[pos].minVal = min(IT[c].minVal + IT[c].inc, IT[c + 1].minVal + IT[c + 1].inc);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1;i <= m;i++) l[i] = r[i] = d[i] = 0;
	for (int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for (int i = 1;i <= n / 2;i++) l[a[i]]++;
	for (int i = n / 2 + 1;i <= n;i++) r[a[i]]++;
    d[m] = -l[m];
    for (int i = m - 1;i >= 1;i--) d[i] = d[i + 1] + r[i + 1] - l[i];
    build(1, 1, m);
    ans = -1;
    for (int k = n / 2;k >= 1;k--) {
        if ( IT[1].minVal >= 0 ) {
            ans = k;
            break;
        }
        update(1, 1, a[k], 1, m, 1);
        update(1, 1, a[k] - 1, 1, m, 1);        
        pivot = 2 * k;
        update(1, 1, a[pivot] - 1, 1, m, -1);
        update(1, 1, a[pivot - 1] - 1, 1, m, -1);
    }
    printf("%d\n", ans);
}

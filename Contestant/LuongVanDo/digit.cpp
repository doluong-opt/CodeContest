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
#define C 100000
#define MAX_LOG 20
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
int n, a[N][6];
struct node {
    int64 val[6];
};
node tree[8 * N];
int cnt[8 * N];
int q, x, y;
char s[111];
int get(int x) {
    int firstDigit = x / C;
    int sub = firstDigit * C * 10;
    return x * 10 - sub + firstDigit;
}
void build(int pos, int l, int r) {
    if (l == r) {
        for (int i = 0;i < 6;i++)
            tree[pos].val[i] = a[l][i];
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    build(c, l, mid);
    build(c + 1, mid + 1, r);
    for (int i = 0;i < 6;i++)
        tree[pos].val[i] = tree[c].val[i] + tree[c + 1].val[i];
    cnt[pos] = 0;
}
node shift(node x) {
    int64 sumCur = x.val[0];
    for (int i = 0;i < 5;i++)
        x.val[i] = x.val[i + 1];
    x.val[5] = sumCur;
    return x;
}
void update(int pos, int x, int y, int l, int r) {
    if (y < l || r < x) return;
    if (x <= l && r <= y) {
        cnt[pos]++;
        if (cnt[pos] > 5) cnt[pos] -= 6;
        tree[pos] = shift(tree[pos]);
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    if ( cnt[pos] ) {
        cnt[c] += cnt[pos];
        cnt[c + 1] += cnt[pos];
        for (int i = 0;i < cnt[pos] % 6;i++) {
            tree[c] = shift(tree[c]);
            tree[c + 1] = shift(tree[c + 1]);
        }
        cnt[pos] = 0;
    }
    update(c, x, y, l, mid);
    update(c + 1, x, y, mid + 1, r);
    for (int i = 0;i < 6;i++)
        tree[pos].val[i] = tree[c].val[i] + tree[c + 1].val[i];
}
int64 getSum(int pos, int x, int y, int l, int r) {
    if (y < l || r < x) return 0;
    if (x <= l && r <= y) return tree[pos].val[0];
    int mid = (l + r) >> 1, c = 2 * pos;
    if ( cnt[pos] ) {
        cnt[c] += cnt[pos];
        cnt[c + 1] += cnt[pos];
        for (int i = 0;i < cnt[pos] % 6;i++) {
            tree[c] = shift(tree[c]);
            tree[c + 1] = shift(tree[c + 1]);
        }
        cnt[pos] = 0;
    }
    return getSum(c, x, y, l, mid) + getSum(c + 1, x, y, mid + 1, r);
}
int main() {
	freopen("digit.inp","r", stdin); freopen("digit.out","w", stdout);
    scanf("%d", &n);
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i][0]);
        for (int j = 1;j <= 5;j++)
            a[i][j] = get(a[i][j - 1]);
    }
    build(1, 1, n);
    //cout << tree[1].val[1] << endl;
    scanf(" %d ", &q);
    for (int i = 1;i <= q;i++) {
        scanf(" %s %d %d ", &s, &x, &y);
        if (s[0] == 'S')
        printf("%lld\n", getSum(1, x, y, 1, n));
        else update(1, x, y, 1, n);
    }
	return 0;
}

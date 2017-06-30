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
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 200010

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
      int isOff;
      int maxLeft, maxRight, maxPar;
};
node tree[8 * N];
int n, q, c;
void build(int pos, int l, int r) {
      if (l == r) {
            tree[pos].maxLeft = 1;
            tree[pos].maxRight = 1;
            tree[pos].maxPar = 1;
            tree[pos].isOff = 1;
            return;
      }
      int mid = (l + r) >> 1, c = 2 * pos;
      build(c, l, mid);
      build(c + 1, mid + 1, r);
}
void update(int pos, int l, int r, int u) {
      if (r < u || l > u) return;
      int mid = (l + r) >> 1, c = 2 * pos;
      update(c, l, mid, u); update(c + 1, mid + 1, r, u);
      tree[pos].maxPar = max(tree[c].maxPar, tree[c + 1].maxPar);
      tree[pos].maxLeft = tree[c].maxLeft;
      tree[pos].maxRight = tree[c + 1].maxRight;
      if ( tree[mid].isOff != tree[mid + 1].isOff ) {
            if ( tree[c].maxLeft == mid - l + 1)
                  tree[pos].maxLeft = tree[c].maxLeft + tree[c + 1].maxLeft;
            else
                  tree[pos].maxLeft = tree[c].maxLeft;
             if ( tree[c + 1].maxRight == r - mid)
                  tree[pos].maxRight = tree[c + 1].maxRight + tree[c].maxRight;
            else
                  tree[pos].maxRight = tree[c + 1].maxRight;
            tree[pos].maxPar = max(tree[pos].maxPar, tree[c].maxRight + tree[c + 1].maxLeft);
      }
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
      scanf("%d %d", &n, &q);
      build(1, 1, n);
      while (q--) {
            scanf("%d", &c);
            update(1, 1, n, c);
            tree[c].isOff ^= 1;
            printf("%d\n", tree[1].maxPar);
      }
	return 0;
}

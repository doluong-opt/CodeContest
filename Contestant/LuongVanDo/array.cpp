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
#define N 1000100

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
int64 sum;
int n, k, tree[N], a[N], curPos;
void update(int x, int val) {
    while (x <= n) {
        tree[x] += val;
        x += (x & -x);
    }
}
int get(int x) {
    int res = 0;
    while (x) {
        res += tree[x];
        x -= (x & -x);
    }
    return res;
}
int getPos(int pos, int lf, int rt) {
    while (lf <= rt) {
        int mid = (lf + rt) >> 1;
        if ( get(mid) >= pos ) rt = mid - 1;
        else lf = mid + 1;
    }
    return lf;
}
int main() {
    freopen("array.inp","r", stdin); freopen("array.out","w", stdout);
    scanf("%d %d", &n, &k);
    sum = 0;
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        sum += a[i]; update(i, 1);
    }
    for (int i = 1;i <= k;i++) {
        scanf("%d", &curPos);
        curPos = getPos(curPos, 1, n);
        sum -= a[curPos];
        update(curPos, -1);
    }
    printf("%lld\n", sum);
	return 0;
}

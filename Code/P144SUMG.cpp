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
#define N 1000000

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
char s[N];
int tree[N + 5];
int n, m, ans;
void update(int x, int val) {
    while (x <= N) {
        tree[x] += val;
        x += (x & -x);
    }
}
int get(int x) {
    int total = 0;
    while (x) {
        total += tree[x];
        x -= (x & -x);
    }
    return total;
}
int fl(int key, int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if ( get(mid) >= key ) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while ( gets(s) ) {
	    n = 0;
	    if ( isdigit(s[0]) ) {
	        rep(i, strlen(s)) n = n * 10 + s[i] - '0';
	        update(n, 1);
	    }
	    else {
	        m = get(N);
	        if (m & 1) m = (m + 1) >> 1;
	        else m = (m >> 1) + 1;
	        ans = fl(m, 1, N);
	        printf("%d\n", ans);
	        update(ans, -1);
	    }
	}
	return 0;
}

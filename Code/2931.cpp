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
#define N 100100

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
int a[N], r1, r2, n;
int calc() {
    int pos[N], u, v, m;
    m = pos[0] = 0;
    for (int i = 1;i < n;i++) {
        if (a[i] > a[pos[m]]) {
            pos[++m] = i;
            continue;
        }
        for (u = 0, v = m; u < v;) {
            int c = (u + v) >> 1;
            if ( a[i] > a[pos[c]]) u = c + 1;
            else v = c;
        }
        if ( a[i] < a[pos[u]]) pos[u] = i;
    }
    return m + 1;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while ( scanf("%d", &n) != EOF) {
	    rep(i, n) scanf("%d", &a[i]);
	    r1 = calc();
	    reverse(a, a + n);
	    r2 = calc();
	    if (r1 < r2 || r1 > r2) puts("Don't worry. I must intervene.");
	    else if (r1 >= r2) puts("Caution. I will not intervene.");
	}
	return 0;
}

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
#define N 10100

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
int n, x, maxV;
int64 ans[N], c[N];
inline int getInt(int &res) {
    res = 0; char c;
    do { c = getchar(); }while (c < '0' || c > '9');
    do { res = res * 10 + c - '0'; c = getchar();
    }while (c >= '0' && c <= '9');
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	c[4] = 1;
	fr(i, 5, 10000) c[i] = (c[i - 1] * i) / (i - 4);
	while ( scanf("%d", &n) != EOF ) {
	    maxV = 0;
	    fr(i, 1, N - 1) ans[i] = 0;
	    rep(i, n) {
	        getInt(x);
	        maxV = max(maxV, x);
	        for (int j = 1;j * j <= x;j++)
                if (x % j == 0) {
                    ans[j]++;
                    if (j * j != x) ans[x / j]++;
                }
	    }
	    frr(i, 1, maxV) {
	        ans[i] = c[ans[i]];
	        for (int j = i + i;j <= maxV;j += i) ans[i] -= ans[j];
	    }
	    printf("%lld\n", ans[1]);
	}
	return 0;
}

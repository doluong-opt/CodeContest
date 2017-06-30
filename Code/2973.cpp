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
int n, x, y, lim;
int64 nx, ny, ans;
int a[N], k1[15], k2[15];
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while ( scanf("%d", &n) && n) {
	    rep(i, n) scanf("%d", &a[i]);
	    lim = (1 << n);
	    ans = -1;
	    rep(i, lim) {
	        x = y = nx = ny = 0;
	        rep(j, n) if ( And(i, j) ) k1[x++] = a[j];
	        else k2[y++] = a[j];
	        if (x == 0 || y == 0) continue;
	        sort(k1, k1 + x); sort(k2, k2 + y);
	        if (k1[0] == 0) {
                rep(j, x) if (k1[j] != 0) {
                    swap(k1[j], k1[0]);
                    break;
                }
	        }
	        if (k2[0] == 0) {
                rep(j, y) if (k2[j] != 0) {
                    swap(k2[j], k2[0]);
                    break;
                }
	        }
	        if (k1[0] != 0 && k2[0] != 0) {
                rep(j, x) nx = nx * 10 + k1[j];
                rep(j, y) ny = ny * 10 + k2[j];
                if (ans == -1) ans = nx + ny;
                else if ( ans > nx + ny ) ans = nx + ny;
	        }
	    }
	    printf("%lld\n", ans);
	}
	return 0;
}

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
int k, a[10][10];
int64 res, best, cost;
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int u, v, c;
	scanf("%d", &k);
	rep(i, 8)
        rep(j, 8) a[i][j] = mark[i][j] = 0;
        
	rep(i, k) {
	    scanf("%d %d %d",&u, &v, &c);
	    a[u][v] = c;
	}
	res = 0;
	best = -1;
	rep(i, 8)
        rep(j, 8)
            if (a[i][j] == 0 && !mark[i][j]) {
                cost = f1(i, j);
                if (cost > best) {
                    best = cost;
                    u = i; v = j;
                }
            }
    mark[u][v] = 1;
    res += best;
    best = -1;
    rep(i, 8)
        rep(j, 8)
            if (a[i][j] == 0 && !mark[i][j]) {
                cost = f2(i, j);
                if (cost > best) {
                    best = cost;
                    u = i; v = j;
                }
            }
    res += 
	return 0;
}

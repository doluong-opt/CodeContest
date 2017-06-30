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
#define N 1010

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<double, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define N 111
#define INF 100111222
vi adj[N];
int s[N], x[N], y[N], mark[N], u, v, n, minDist, cnt;
double res[N];
double dist(int x1, int y1, int x2, int y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n);
	fr(i, 1, n) {
	    mark[i] = 0;
	    adj[i].clear();
	    scanf("%d %d %d", &x[i], &y[i], &s[i]);
	    fr(j, 1, n - 1) {
	        scanf("%d", &v);
	        adj[i].pb(v);
	    }
	}
	for (int i = 1;i <= n;i++) res[i] = INF;
	res[1] = 0;
	while ( true ) {
	    minDist = INF;
	    u = 0;
	    for (int i = 1;i <= n;i++)
            if (!mark[i] && minDist > res[i]) {
                minDist = res[i];
                u = i;
            }
        mark[u] = 1;
        if (u == 0) break;
        cnt = 0;
        for (int j = 0;j < adj[u].size();j++) {
            v = adj[u][j];
            if (!mark[v] && cnt < s[u] && res[u] < res[v]) {
                if (res[v] > res[u] + dist(x[u], y[u], x[v], y[v]))
                    res[v] = res[u] + dist(x[u], y[u], x[v], y[v]);
                cnt++;
            }
        }
    }
    fr(i, 1, n)
        printf("%.6lf\n", res[i]);
}

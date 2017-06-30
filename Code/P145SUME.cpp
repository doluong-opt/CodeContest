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
#define N 200111

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
int n, x, y, uoc, ans;
int l, r, m;
vector <int> pos[N];
bool solve(int l, int r, int uoc) {
    if (y == 0) return true;
    if (l > r) return false;
    int lo = 0, hi = pos[uoc].size() - 1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (l <= pos[uoc][mid] && pos[uoc][mid] <= r) return false;
        if (pos[uoc][mid] < l) lo = mid + 1;
        else
        if (pos[uoc][mid] > r) hi = mid - 1;
    }
    return true;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n);
	fr(i, 1, 100000) pos[i].clear();
	fr(i, 1, n) {
	    scanf("%d %d", &x, &y);
	    m = sqrt(x); ans = 0;
	    l = i - y; r = i - 1;
	    for (int k = 1;k <= m;k++) {
	        if (x % k == 0) {
	            if (solve(l, r, k)) ans++;
                if (k * k != x)
                    if (solve(l, r, x / k)) ans++;
	        }
	    }
	    for (int k = 1;k <= m;k++)
	        if (x % k == 0) {
	            pos[k].pb(i);
                if (k * k != x) pos[x / k].pb(i);
	        }
        printf("%d\n", ans);
	}
	return 0;
}

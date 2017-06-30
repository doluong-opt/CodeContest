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
#define N 100010

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
ii d[N];
int n, m, q, lf, rg;
int a[N], b[N], c[N], key[N];
int markB[N], ans;
vector <ii> iter;
set <int> sA;
set <int> :: iterator it;
bool search(int x, int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if ( c[mid] == x ) return true;
        if ( c[mid] > x ) r = mid - 1;
        else l = mid + 1;
    }
    return false;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d %d", &n, &m, &q);
	fill(markB, 0);
	sA.clear();
	fr(i, 1, n) {
	    scanf("%d", &a[i]);
	    sA.insert(a[i]);
	}
	n = 0;
	for (it=sA.begin(); it!= sA.end(); it++) key[n++] = *it;
	fr(i, 1, m) {
	    scanf("%d", &b[i]);
	    markB[b[i]] = 1;
	}
	m = 0;
	fr(i, 1, q) scanf("%d", &c[i]);
	fr(i, 1, q)
        if (!markB[c[i]]) d[++m] = ii(i, c[i]);
    ans = 0;
    if (m > 0) {
        lf = rg = d[1].ff;
    }
    else {
        printf("0\n");
        return 0;
    }
    fr(i, 2, m)
        if (rg + 1 != d[i].ff) {
            iter.pb(ii(lf, rg));
            lf = rg = d[i].ff;
        }
        else rg = d[i].ff;
    iter.pb(ii(lf, rg));
    rep(i, iter.size()) sort(c + iter[i].ff, c + iter[i].ss + 1);
    rep(i, iter.size()) {
        if (iter[i].ss - iter[i].ff + 1 < sA.size()) continue;
        int cnt = 0;
        rep(j, n)
            if ( search(key[j], iter[i].ff, iter[i].ss) ) cnt++;
            else break;
        if (cnt == n) ans = max(ans, iter[i].ss - iter[i].ff + 1);
    }
    printf("%d\n", ans);
	return 0;
}

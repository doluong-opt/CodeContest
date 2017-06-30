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
int n, j, d;
ii a[N];
vector <ii> ans;
bool cmp(ii x, ii y) {
    if (x.ff != y.ff) return x.ff < y.ff;
    return x.ss < y.ss;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n);
	fr(i, 1, n) {
	    scanf("%d", &a[i].ff);
	    a[i].ss = i;
	}
	sort(a + 1, a + n + 1, cmp);
	j = 1;
    fr(i, 1, n) {
        while (j <= n && a[j].ff == a[i].ff) j++;
        j--;
        if (i == j) ans.pb(ii(a[i].ff, 0));
        else {
            d = a[i + 1].ss - a[i].ss;
            bool found = true;
            fr(k, i + 1, j) if (a[k].ss - a[k - 1].ss != d) {
                found = false;
                break;
            }
            if (found) ans.pb(ii(a[i].ff, d));
        }
        i = j;
        j += 2;
    }
    printf("%d\n", ans.size());
    rep(i, ans.size())
        printf("%d %d\n", ans[i].ff, ans[i].ss);
	return 0;
}

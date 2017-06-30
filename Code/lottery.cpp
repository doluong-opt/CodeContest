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
#define N 300111
#define MAX_LOG 20
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
int n, a[N], b[N], c[N], posB[N], posC[N];
int ans, cnt, x, y;
vector <ii> p;
bool cmp(ii x, ii y) {
    if (x.ff != y.ff) return x.ff < y.ff;
    return x.ss < y.ss;
}
int main() {
	freopen("lottery.inp","r", stdin); freopen("lottery.out","w", stdout);
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for (int i = 1;i <= n;i++) {
	    scanf("%d", &b[i]);
	    posB[b[i]] = i;
	}
	for (int i = 1;i <= n;i++) {
	    scanf("%d", &c[i]);
	    posC[c[i]] = i;
	}
	for (int i = 1;i <= n;i++) {
	    x = posB[a[i]]; y = posC[a[i]];
	    if (x <= i) x = (i - x);
	    else x = (n - x + i);
	    if (y <= i) y = (i - y);
	    else y = (n - y + i);
	    p.pb(ii(x, y));
	}
	//for (int i = 0;i < n;i++) cout<<p[i].ff<<" "<<p[i].ss<<endl;
	sort(p.begin(), p.end(), cmp);
	ans = 0; cnt = 1;
	//for (int i = 0;i < n;i++) cout<<p[i].ff<<" "<<p[i].ss<<endl;
	for (int i = 1;i < n;i++) {
        if (p[i].ff == p[i - 1].ff && p[i].ss == p[i - 1].ss) cnt++;
        else {
            ans = max(ans, cnt);
            cnt = 1;
        }
	}
	ans = max(ans, cnt);
	printf("%d\n", ans);
	return 0;
}

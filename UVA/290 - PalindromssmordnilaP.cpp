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
char s[N];
int n, m, f;
vector <int> a, b, c;
bool isPalind(vector <int> a) {
    int lo = 0, hi = a.size() - 1;
    while (lo <= hi) {
        if (a[lo] != a[hi]) return false;
        lo++; hi--;
    }
    return true;
}
int solve(int base) {
    int x, res = 0;
    a.clear(); b.clear(); c.clear();
    rep(i, n) {
        if (s[i] >= 'A' && s[i] <= 'Z') x = s[i] - 'A' + 10;
        else x = s[i] - '0';
        if (x >= base) return -1;
        a.pb(x);
    }
    if (isPalind(a)) return 0;
    rep(i, n) b.pb(a[n - i - 1]);
    m = n;
    while ( true ) {
        res++; x = 0;
        for (int i = m - 1;i >= 0;i--) {
            x += (a[i] + b[i]);
            c.pb(x % base);
            x /= base;
        }
        while ( x ) c.pb(x % base), x /= base;
        m = c.size();
        //rep(i, m) cout<<c[i]<<" ";
        //cout<<endl;
        if ( isPalind(c) ) break;
        a.clear(); b.clear(); c.clear();
        rep(i, m) a.pb(c[i]), b.pb(c[m - i - 1]);
    }
    return res;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while ( gets(s) ) {
	    n = strlen(s);
	    printf("%d", solve(15));
	    for (int base = 14;base >= 2;base--) {
	        f = solve(base);
	        if (f == -1) printf(" ?");
	        else printf(" %d", f);
	    }
	    puts("");
	}
	return 0;
}

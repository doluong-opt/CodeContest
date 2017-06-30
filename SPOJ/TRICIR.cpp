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
#define N 1000111

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
char s[100];
int n, p, pos;
int64 a, b, c, ans;
int next[N], red[N];
int findPos(int u) {
    if ( !red[u] ) return u;
    int v = findPos(next[u]);
    next[u] = v;
    return v;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while ( true ) {
	    scanf("%s", s);
	    if ( s[1] == 'E' ) break;
	    scanf("%d %d %lld %lld %lld", &n, &p, &a, &b, &c);
	    rep(i, n) {
	        next[i] = (i + 1) % n;
	        red[i] = 0;
	    }
	    rep(i, p) {
	        pos = ((a * i) % n * i + (b * i) % n + c) % n;
	        pos = findPos(pos);
	        red[pos] = 1;
	    }
	    ans = 0LL;
	    if (n & 1) {
	        puts("0");
	        getchar(); getchar();
	        continue;
	    }
	    rep(i, n / 2)
            if (red[i] && red[i + n / 2]) ans += (p - 2);
        printf("%lld\n", ans);
	    getchar(); getchar();
	}
	return 0;
}

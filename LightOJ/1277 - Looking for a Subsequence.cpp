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
#define M 1000111
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
int a[N], val[N], lenMax[N], n, q, id, lenS;
char s[M];
void init() {
    int l, r, k = 0;
    for (int i = 1;i <= n;i++) {
        l = 1; r = k;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (val[mid] > a[i]) l = mid + 1;
            else r = mid - 1;
        }
        val[l] = a[i];
        lenMax[i] = l;
        if (k < l) k = l;
    }
}
void solve(int len) {
    vector <int> res;
    int temp = -INF;
    for (int i = n;i >= 1 && len;i--) {
        if (lenMax[i] >= len && a[i] > temp) {
            res.pb(a[i]);
            len--;
            temp = a[i];
        }
    }
    if (!res.size()) puts("Impossible");
    else {
        rep(i, res.size()) {
            if (i) printf(" ");
            printf("%d", res[i]);
        }
        puts("");
    }
}
int nextInt() {
    int v = 0, sign = 1;
    while (id < lenS && s[id] != ' ') {
        if (s[id] == '-') {
            sign = -1;
            ++id;
        }
        else v = v * 10 + s[id++] - '0';
    }
    ++id;
    return v * sign;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
	lenS = (int)strlen(gets(s)); id = 0;
	cases = nextInt();
	while (cases--) {
	    lenS = (int)strlen(gets(s)); id = 0;
	    n = nextInt(); q = nextInt();
	    lenS = (int)strlen(gets(s)); id = 0;
	    fr(i, 1, n) {
	        a[i] = nextInt();
	        val[i] = lenMax[i] = 0;
	    }
	    reverse(a + 1, a + n + 1);
	    init();
	    printf("Case %d:\n", ++caseno);
	    fr(i, 1, q) {
            lenS = (int)strlen(gets(s)); id = 0;            
            solve(nextInt());
	    }
	}
	return 0;
}

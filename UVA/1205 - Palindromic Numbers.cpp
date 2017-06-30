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
#define INF 1000000000
#define N 19

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
int64 f1[N], f2[N];
int64 x, y;
int n, a[N];
void init() {
    f1[0] = 1; f1[1] = 10;
    f2[0] = 0; f2[1] = 10;
    for (int i = 2;i <= 18;i++) {
        f1[i] = 10 * f1[i - 2];
        f2[i] = f2[i - 1] + 9 * f1[i - 2];
    }
}
int64 calc(int lf, int rt) {
    int len = rt + 1;
    if (rt == 0) return 1;
    if (rt == 1) return a[0] + 1;
    
    int64 res = (a[0] - 1) * f1[len - 2];
    len -= 2; lf++; rt--;
    //cout << res << endl;
    while (lf <= rt) {
        if (len == 1) {
            res += (a[lf] + 1);
            break;
        }
        if (a[rt] < a[lf]) {
            int k;
            for (k = rt - 1;k >= lf;k--)
                if (a[k] > 0) break;
                else a[k] = 9;
            if (k < lf) break;
            a[k]--;
        }
        //rep(i, 4) cout << a[i] <<" ";
        //cout<<endl;
        if (len == 2) res += (a[lf] + 1) * f1[len - 2];
        else res += a[lf] * f1[len - 2];
        len -= 2;
        lf++; rt--;
    }
    return res;
}
int64 solve(int64 x) {
    n = 0;
    if (!x) a[n++] = 0;
    while ( x ) {
        a[n++] = x % 10;
        x /= 10;
    }
    reverse(a, a + n);
    return f2[n - 1] + calc(0, n - 1);
}
bool isPalind(int x) {
    char s[111];
    sprintf(s,"%d", x);
    int l = 0, r = strlen(s) - 1;
    while (l <= r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseNo = 0;
	for (int i = 0;i <= 1001;i++)
        if ( isPalind(i) ) cout <<i << endl;
	init();
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%lld %lld", &x, &y);
	    if (x > y) swap(x, y);
	    if (x == 0) printf("Case %d: %lld\n", ++caseNo, solve(y));
	    else printf("Case %d: %lld\n", ++caseNo, solve(y) - solve(x - 1));
	}
}

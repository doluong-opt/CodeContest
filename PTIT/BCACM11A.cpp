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
#define N 1000100

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
int n, m, k, x, cnt, sz, sum;
int a[N], ok[3];
bool solve(int n, int m, int k) {
    ok[0] = ok[1] = ok[2] = 0;
    for (int i = 100000;i <= 999999;i++) {
        x = i; cnt = sz = sum = 0;
        while (x) {
            a[sz++] = x % 10;
            x /= 10;
            if (a[sz - 1] == 0) cnt++;
            sum += a[sz - 1];
        }
        if (a[0] != a[5] || a[1] != a[4] || a[2] != a[3]) continue;
        if (sum % 10 == 0 && cnt == 0) ok[0]++;
        else 
        if (sum % 10 == 0) ok[1]++;
        else ok[2]++;
    }
    if (ok[0] >= n) ok[1] += (ok[0] - n);
    else return false;
    if (ok[1] >= m) ok[2] += (ok[1] - m);
    else return false;
    if (ok[2] >= k) return true;
    return false;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d %d %d", &n, &m, &k);
	    if ( solve(n, m, k) ) puts("YES");
	    else puts("NO");
    }
	return 0;
}

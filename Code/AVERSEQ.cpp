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
#define N 1000001

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
int n, k;
int a[N], lo, hi, ans;
int64 sum[N];
inline int getInt(int &res) {
    res = 0; char c; int sign = 0;
    do {
        c = getchar(); 
        if (c == '-') break;
    } while (c < '0' || c > '9');
    do {
        if (c == '-') sign = 1, c = getchar();
        res = res * 10 + c - '0';
        c = getchar();
    }while (c >= '0' && c <= '9');
    if (sign) res = -res;
}
bool check(int len) {
    int x, y;
    for (int i = 1;i + len - 1<= n;i++) {
        x = i; y = i + len - 1;
        if (len == 4) cout<<x<<" "<<y<<" "<<sum[y] - sum[x - 1]<<endl;
        if ( sum[y] - sum[x - 1] >= len * (int64)k ) return true;
    }
    return false;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	getInt(n); getInt(k);
	sum[0] = 0;
	fr(i, 1, n) {
	    getInt(a[i]);
	    sum[i] = sum[i - 1] + a[i];
	}
	//fr(i, 1, n) cout<<sum[i]<<" "<<endl;
	lo = 1; hi = n;
	while (lo <= hi) {
	    int mid = (lo + hi) >> 1;
	    if ( check(mid) ) ans = mid, lo = mid + 1;
	    else hi = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}

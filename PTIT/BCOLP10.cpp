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
char a[N], b[N];
int f1[26], f2[26];
int n, m, ans;
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	gets(a); n = strlen(a);
	gets(b); m = strlen(b);
	rep(i, 26) f1[i] = f2[i] = 0;
	rep(i, n) f1[a[i] - 'a']++;
	rep(i, m) f2[b[i] - 'a']++;
	ans = 0;
	rep(i, 26) {
	    if (f1[i] == 0 && f2[i] == 0) continue;
	    if (f1[i] && f2[i] == 0) ans += f1[i];
	    if (f1[i] == 0 && f2[i]) ans += f2[i];
	    if (f1[i] && f2[i]) ans += abs(f1[i] - f2[i]);
	}
	printf("%d\n", ans);
	return 0;
}

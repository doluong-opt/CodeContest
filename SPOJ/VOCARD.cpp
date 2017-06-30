/***********************************************
* Author - LUONG VAN DO                        *
* Problem
* Algorithm
* Time Limit
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <deque>
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
#define N 2000100

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
int n, k, dp[N], total[N], a[N];
char s[N];
deque <int> q;
void push(int x) {
    while ( !q.empty() && dp[q.back()] >= dp[x] ) q.pop_back();
    q.push_back(x);
}
void pop(int x) {
    while ( !q.empty() && q.front() <= x ) q.pop_front();
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf(" %d %d ", &n, &k);
	gets(s); total[0] = 0;
	rep(i, n) a[i + 1] = s[i] - '0';
	fr(i, 1, n) total[i] = total[i - 1] + a[i];
	fr(i, 1, k) {
	    dp[i] = total[i];
	    push(i);
	}
	fr(i, k + 1, n) {
	    dp[i] = total[i] - dp[q.front()];
	    push(i); pop(i - k);
	}
	if (total[n] - dp[n] < dp[n]) {
	    puts("YES");
	    printf("%d\n", total[n] - dp[n]);
	}
	else
	if (total[n] - dp[n] > dp[n]) {
	    puts("YES");
	    printf("%d\n", dp[n]);
	}
	else puts("NO");
	return 0;
}

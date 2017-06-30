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
int n, k, j, mini, maxi, ans;
int a[N], f1[N], f2[N];
deque <int> qMin, qMax;
void pushMin(int pos) {
    while ( !qMin.empty() && a[qMin.back()] >= a[pos] ) qMin.pop_back();
    qMin.push_back(pos);
}
void pushMax(int pos) {
    while ( !qMax.empty() && a[qMax.back()] <= a[pos] ) qMax.pop_back();
    qMax.push_back(pos);
}
void popMin(int pos) {
    while ( !qMin.empty() && qMin.front() <= pos ) qMin.pop_front();
}
void popMax(int pos) {
    while ( !qMax.empty() && qMax.front() <= pos ) qMax.pop_front();
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d", &n, &k);
	fr(i, 1, n) scanf("%d", &a[i]);
	j = 1; f1[1] = 1;
	pushMin(j); pushMax(j);
	for (int i = 2;i <= n;i++) {
	    pushMin(i); pushMax(i);
	    while (j <= i) {
	        mini = a[qMin.front()];
	        maxi = a[qMax.front()];
	        if (maxi - mini <= k) break;
	        popMin(j); popMax(j);
	        j++;
	    }
	    f1[i] = max(f1[i - 1], i - j + 1);
	}
	reverse(a + 1, a + n + 1);
	qMin.clear(); qMax.clear();
	j = 1; f2[1] = 1;
	pushMin(j); pushMax(j);
	for (int i = 2;i <= n;i++) {
	    pushMin(i); pushMax(i);
	    while (j <= i) {
	        mini = a[qMin.front()];
	        maxi = a[qMax.front()];
	        if (maxi - mini <= k) break;
	        popMin(j); popMax(j);
	        j++;
	    }
	    f2[i] = max(f2[i - 1], i - j + 1);
	}
	ans = 0;
	fr(i, 1, n - 1)
        ans = max(ans, f1[i] + f2[n - i]);
    printf("%d\n", ans);
	return 0;
}

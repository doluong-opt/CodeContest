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
#define N 111

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
int l, n, cnt, total;
int a[N], res[N], mark[N];
void run(int id, int k, int cur) {
    if (id <= 0) return;
    if ( mark[id] || a[id] <= 0) run(id - 1, k, cur);
    if (cur == total) {
        printf("%d", res[1]);
        for (int i = 2;i <= l;i++)
            printf(" %d", res[i]);
        puts("");
        ++cnt;
        return;
    }
    
    for (int i = 1;i <= a[id];i++)
        res[k--] = id;
    run(id - 1, k, cur + a[id]);
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d", &l, &n);
	total = 0;
	fr(i, 1, n) {
	    scanf("%d", &a[i]);
	    total += a[i];
	}
	cnt = 0; fill(res, 0); fill(mark, 0);
	for (int i = 1;i <= n && cnt < 1000;i++) {
	    mark[i] = 1; fill(res, 0);
	    total -= a[i];
	    for (int j = 1;j <= a[i];j++) res[j] = i;
	    
            run(n, l, 0);
            
        mark[i] = 0;
        total += a[i];
	}
	return 0;
}

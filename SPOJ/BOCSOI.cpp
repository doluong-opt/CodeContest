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
#define N 30
#define M 111539786
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
int n, val[N];
int64 res[N][N][N][N][N];
int id[N][N], a, b, c, d, e;
int64 run(int x[]) {    
    a = id[0][x[0]];
	b = id[1][x[1]];
	c = id[2][x[2]];
	d = id[3][x[3]];
	e = id[4][x[4]];
    int64 &ans = res[a][b][c][d][e];
    if (ans != -1) return ans;
    ans = 0LL;
    for (int i = 0;i < n;i++) {
        int j = (i + 1) % n;
        if ((x[i] % 2) && (x[j] % 2)) {
            x[i]--; x[j]--;
            ans += run(x);
            x[i]++; x[j]++;
        }
        if (x[i] > 0 && x[j] > 0) {
            int tempA = x[i], tempB = x[j];
            x[i] /= 2; x[j] /= 2;
            ans += run(x);
            x[i] = tempA; x[j] = tempB;
        }
    }
    return ans % M;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	rep(i, 4) val[i] = 0;
	fill(id, 0);
	scanf("%d", &n);
	rep(i, n) {
	    scanf("%d", &val[i]);
	    int x = val[i], sz = 0;
	    while ( x ) {
	        id[i][x] = sz++;
	        if (x & 1) x--;
	        else x /= 2;
	    }
	    id[i][x] = sz++;
	}
	fill(res, -1);
	a = id[0][0];
	b = id[1][0];
	c = id[2][0];
	d = id[3][0];
	e = id[4][0];
	res[a][b][c][d][e] = 1LL;
	printf("%lld\n", run(val));
	return 0;
}

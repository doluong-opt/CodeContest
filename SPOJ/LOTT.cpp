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
#define N 555

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
int64 c[N][6];
char s[100];
int n;
double total, res, x, y, z;
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	c[0][0] = 1;
	fr(i, 1, 500) {
	    c[i][0] = 1;
	    fr(j, 1, min(5, i))
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
	while ( true ) {
        scanf("%s", s);
        if ( s[1] == 'E' ) break;
        scanf("%d", &n);
        total = c[5 * n][5];
        x = (double)c[5][3] * (double)c[5 * (n - 1)][2] * 1.0;
        y = (double)c[5][4] * (double)c[5 * (n - 1)][1] * 1.0;
        z = (double)c[5][5] * (double)c[5 * (n - 1)][0] * 1.0;
        res = ((x + y + z) / total) * (double)n;
        printf("%.10lf\n", res);
	}
	return 0;
}

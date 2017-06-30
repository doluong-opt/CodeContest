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
int n, a[N][N], ans, minVal;
int curPos, pos, mark[N];
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n);
	fr(i, 1, n) fr(j, 1, n) {
	    scanf("%d", &a[i][j]);
	    if (a[i][j] == 0) a[i][j] = INF;
	    //if (i == j) a[i][j] = 0;
	}
	fr(k, 1, n) fr(i, 1, n) fr(j, 1, n) a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
	ans = 0;
	fr(i, 1, n) mark[i] = 1;
	mark[1] = 0; pos = 1;
	fr(i, 2, n - 1) {
	    minVal = INF;
        fr(j, 2, n - 1)
            if (mark[j] && a[pos][j] < minVal) {
                minVal = a[pos][j];
                curPos = j;
            }
        //cout<<curPos<<" "<<minVal<<endl;
        ans += minVal;
        mark[curPos] = 0;
        pos = curPos;
	}
	printf("%d\n", ans + a[pos][n]);
	return 0;
}

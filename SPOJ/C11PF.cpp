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
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 100111
#define M 1000000000
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
int n, b, maxVal, cnt, a[N], f[N];
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);	
	scanf("%d %d", &n, &b); maxVal = -INF;
	f[1] = 1; f[2] = 2; cnt = 0;
	fr(i, 3, 100001) {
	    f[i] = f[i - 1] + f[i - 2];
	    f[i] %= M;
	}
	fr(i, 1, n) {
	    scanf("%d", &a[i]);
	    if (b > a[i]) cnt++;
	    if (maxVal < a[i]) maxVal = a[i];
	}
	if (cnt == n) {
        if (maxVal == a[1]) printf("2\n");
        else printf("1\n");
        cout << f[n + 1] << endl;
	}
	else {
	    printf("0\n");
	    printf("0\n");
	}
	return 0;
}

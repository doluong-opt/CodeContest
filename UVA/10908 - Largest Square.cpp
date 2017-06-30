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
#define INF 1000000000
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
int n, m, q, r, c, ans, len;
char s[N][N];
bool isOk(int a, int x, int y) {
    set <char> st;
    int x1, y1, x2, y2;
    x1 = x - a; y1 = y - a;
    x2 = x + a; y2 = y + a;
    if (x1 < 0 || y1 < 0 || x2 >= m || y2 >= n) return false;
    for (int i = x1;i <= x2;i++)
        for (int j = y1;j <= y2;j++) st.insert(s[i][j]);
    return (st.size() == 1);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
	scanf("%d", &cases);
	while (cases--) {
	    scanf(" %d %d %d ", &m, &n, &q);
	    rep(i, m) gets(s[i]);
	    printf("%d %d %d\n", m, n, q);
	    rep(i, q) {
	        scanf(" %d %d ", &r, &c);
	        len = 0;
	        while ( true ) {
	            if (isOk(len, r, c) ) {
	                ans = len;
	                len++;
	            }
	            else break;
	        }
	        printf("%d\n", 2 * ans + 1);
	    }
	}
	return 0;
}

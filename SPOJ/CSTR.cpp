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
int n, best;
char s1[N], s2[N], s3[N];
int f[N][70][70][70];
char ans[N], T[N];
void run(int cur, int d1, int d2, int d3) {    
    if ( f[cur][d1][d2][d3] ) return;
    f[cur][d1][d2][d3] = 1;
    int res = max(d1, max(d2, d3));
    if (res >= best) return;
    if (cur >= n) {
        best = res;
        rep(i, n) T[i] = ans[i];
        return;
    }
    char ch[5];
    ch[0] = 'A'; ch[1] = s1[cur]; ch[2] = s2[cur]; ch[3] = s3[cur];
    sort(ch, ch + 4);
    rep(i, 4) {
        ans[cur] = ch[i];
        int tempD1, tempD2, tempD3;
        tempD1 = d1; tempD2 = d2; tempD3 = d3;
        if (ch[i] != s1[cur]) d1++;
        if (ch[i] != s2[cur]) d2++;
        if (ch[i] != s3[cur]) d3++;
        run(cur + 1, d1, d2, d3);
        d1 = tempD1; d2 = tempD2; d3 = tempD3;
    }
    return;
}
int main() {
	freopen("CSTR.INP","r", stdin); freopen("CSTR.OUT","w", stdout);
	gets(s1); gets(s2); gets(s3); n = strlen(s1);
	best = (2 * n) / 3 + 2;
	fill(f, 0);
	run(0, 0, 0, 0);
	rep(i, n) putchar(T[i]);
	cout<<endl;
	return 0;
}

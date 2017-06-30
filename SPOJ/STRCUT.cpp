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
#define N 2222

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
char s1[N], s2[N];
int n, f[N][N], m, ans;
ii inter[4];
bool isEqual(int i, int j, int u, int v) {
    return (f[j][v] >= j - i + 1);
}
int solve(int p1, int p2) {
    if (p2 >= n) return 0;
    inter[0] = ii(0, p1);
    inter[1] = ii(p1 + 1, p2);
    inter[2] = ii(p2 + 1, n - 1);
    do{
        int cnt = 0, len = 0;
        for (int i = 0;i < 3;i++) {
            if ( isEqual(inter[i].ff, inter[i].ss, len, len + inter[i].ss - inter[i].ff) ) cnt++;
            len += inter[i].ss - inter[i].ff + 1;
        }
        if (cnt == 3) return 1;
    }while (next_permutation(inter, inter + 3));
    return 0;
}
int main() {
	freopen("STRCUT.INP","r", stdin); freopen("STRCUT.OUT","w", stdout);
	gets(s1); gets(s2);
	n = strlen(s1);
	for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++) {
            if (!i || !j) f[i][j] = (s1[i] == s2[j]);
            else if (s1[i] == s2[j]) f[i][j] = f[i - 1][j - 1] + 1;
            else f[i][j] = 0;
        }
    ans = 0;
    for (int i = 0;i < n;i++)
        for (int j = i + 1;j < n - 1;j++)
            ans += solve(i, j);
    printf("%d\n", ans);
	return 0;
}

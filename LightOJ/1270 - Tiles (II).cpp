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
#define M 9
#define LMT (1 << 8)
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
int m, n, lim, a[N][N];
char s[N][N];
uint64 dp[N][LMT + 5];
vector <int> broken[LMT + 5];
void gen(int cur, int mask, int cover) {
    if (cur == n) {
        broken[mask].pb(cover);
        return;
    }
    if ( And(mask, cur) ) {
        gen(cur + 1, mask, cover);
        return;
    }
    int tempMask;
    if ( !And(cover, cur) ) {
        tempMask = Or(cover, cur);
        gen(cur + 1, mask, tempMask);
    }
    if (cur + 1 < n && !And(mask, cur + 1)) {
        tempMask = cover;
        gen(cur + 2, mask, tempMask);
    }
    if (cur + 1 < n && !And(cover, cur) && !And(cover, cur + 1)) {
        tempMask = Or(Or(cover, cur), cur + 1);
        gen(cur + 1, mask, tempMask);
    }
    if (cur + 1 < n && !And(mask, cur + 1) && !And(cover, cur)) {
        tempMask = Or(cover, cur);
        gen(cur + 2, mask, tempMask);
    }
    if (cur - 1 >= 0 && !And(cover, cur) && !And(cover, cur - 1)) {
        tempMask = Or(Or(cover, cur), cur - 1);
        gen(cur + 1, mask, tempMask);
    }
    if (cur + 1 < n && !And(mask, cur + 1) && !And(cover, cur + 1)) {
        tempMask = Or(cover, cur + 1);
        gen(cur + 2, mask, tempMask);
    }
}
void init() {
    rep(i, lim) broken[i].clear();
    rep(i, lim) gen(0, i, 0);
}
int getBroken(int row) {
    int mask = 0;
    for (int i = 0;i < n;i++) mask = (mask << 1) + a[row][i];
    return mask;
}
void solve() {
    int rowCur, rowNext, rowNexts;
    rowCur = getBroken(0); rowNext = getBroken(1);
    for (int i = 0;i < broken[rowCur].size();i++) {
        rowNexts = broken[rowCur][i];
        if (!( rowNexts & rowNext ))
            dp[1][rowNexts | rowNext]++;
    }
    for (int i = 1;i < m;i++) {
        rowNext = getBroken(i + 1);
        for (int j = 0;j < lim;j++) {
            for (int k = 0;k < broken[j].size();k++) {
                rowNexts = broken[j][k];
                if (i == m - 1) {
                    if ( !rowNexts && j != lim - 1) dp[i][lim - 1] += dp[i][j];
                }
                else
                if (!(rowNexts & rowNext))
                    dp[i + 1][rowNexts | rowNext] += dp[i][j];
            }
        }
    }
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseNo = 0;
	scanf(" %d ", &cases);
	while (cases--) {
        scanf(" %d %d ", &m, &n);
        rep(i, m) gets(s[i]);
        rep(i, m) rep(j, n) a[i][j] = (s[i][j] == '#');
        if (m < n) {
            rep(i, n) rep(j, m) a[i][j] = (s[j][i] == '#');
            swap(m, n);
        }
        lim = (1 << n); fill(dp, 0);
        init(); solve();
        printf("Case %d: %llu\n", ++caseNo, dp[m - 1][lim - 1]);
	}
}

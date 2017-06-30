// =============================================================================
// Author LUONG VAN DO
// Problem
// Algorithm
// Time Limit
// =============================================================================
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

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint unsigned int

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 111222333
#define N 16
#define P 999983
struct node{
    char s[111];
    int len;
}a[N];
int dp[N][1<<N], posEnd[N][N], n;
int best, ans, tmp, lim;
bool isSubString(string x, string y, int i1, int i2) {
    if (a[i1].len == 0 || a[i2].len == 0) return false;
    if (y.length() > x.length()) return false;
    int n = x.length(), m = y.length();
    uint64 ha = 0, hb = 0, mul = 1, f = 1;
    rep(i, m) {
        ha += x[i] * mul;
        hb += y[i] * mul;
        mul *= P;
    }
    if (ha == hb) return true;
    fr(i, m, n - 1) {
        ha += x[i] * mul;
        ha -= x[i - m] * f;
        f *= P; mul *= P;
        if (ha == hb * f) return true;
    }
    return false;
}
int preProcessPos(string x, string y) {
    int n = x.length(), m = y.length();
    uint64 ha = 0, hb = 0, mul = 1, pos = 0;
    for (int i = n - 1, j = 0;i >= 0 && j < m;i--, j++) {
        ha = ha * P + x[i];
        hb = hb + y[j] * mul;
        mul *= P;
        if (ha == hb) pos = j + 1;
    }
    return pos;
}
int run(int cur, int mask) {
    if (mask == lim - 1) return a[cur].len;
    int &res = dp[cur][mask];
    if (res != -1) return res;
    res = INF;
    rep(i, n)
        if ( !And(mask, i) ) {
            int newMask = Or(mask, i);
            res = min(res, a[cur].len - posEnd[cur][i] + run(i, newMask));
        }
    return res;
}
void solve(int cur, int mask) {
    if (mask == lim - 1) {
        printf("%s", a[cur].s);
        return;
    }
    int ans = INF, best = 0, newMask;
    rep(i, n)
        if ( !And(mask, i) ) {
            newMask = Or(mask, i);
            int tmp = a[cur].len - posEnd[cur][i] + dp[i][newMask];
            if (tmp < ans || (tmp == ans && strcmp(&a[i].s[posEnd[cur][i]], &a[best].s[posEnd[cur][best]]) < 0)) {
                ans = tmp;
                best = i;
            }
        }
    for (int i = 0;i < a[cur].len - posEnd[cur][best];i++) putchar(a[cur].s[i]);
    solve(best, Or(mask, best));
}
bool cmp1(node a, node b) {
    return (a.len > b.len);
}
bool cmp2(node a, node b) {
    return (strcmp(a.s, b.s) < 0);
}
int main(){
	//freopen("exam.inp","r",stdin);
    //freopen("exam.out","w",stdout);
	int cases, caseno = 0;	
    scanf(" %d ", &cases);
    while (cases--) {
        scanf(" %d ", &n);
        rep(i, n) {
            scanf(" %s ", &a[i].s);
            a[i].len = strlen(a[i].s);
        }
        rep(i, n) rep(j, n) {
            if (i != j && isSubString(a[i].s, a[j].s, i, j)) a[j].len = 0;
            posEnd[i][j] = 0;
        }
        sort(a, a + n, cmp1);
        rep(i, n)
            if (a[i].len == 0) {
                n = i;
                break;
            }
        sort(a, a + n, cmp2);
        rep(i, n) rep(j, n)
            if (i != j)
                posEnd[i][j] = preProcessPos(a[i].s, a[j].s);
        ans = INF;
        lim = (1<<n);
        rep(i, n)
            rep(j, lim) dp[i][j] = -1;
        rep(i, n) {
            tmp = run(i, 1<<i);
            if (tmp < ans) {
                ans = tmp;
                best = i;
            }
        }
        printf("Case %d: ", ++caseno);
        solve(best, 1<<best);
        puts("");
    }
}

// =============================================================================
// Author LUONG VAN DO
// Problem 1334 - Genes in DNA 
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
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long

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
#define N 50010
char a[N], b[N], s[2 * N];
int next[2 * N], cnt[2 * N], prefixCnt[2 * N], suffixCnt[2 * N];
int n, m, nm;
void preKmp() {
    int i, j, k;
    fill(next, 0);
    i = 0; j = next[0] = -1;
    while (i < nm) {
        while (j >= 0 && s[i] != s[j]) j = next[j];
        ++i; ++j;
        next[i] = j;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, k;
    int64 ans;
    scanf(" %d ", &cases);
    while (cases--) {
        scanf(" %s %s ", &a, &b);
        n = strlen(a); m = strlen(b);
        nm = 0;
        for (int i = 0;i < m;i++)
            s[nm++] = b[i];
        s[nm++] = '*';
        for (int i = 0;i <= n;i++)
            s[nm++] = a[i];
        preKmp();
        for (int i = 0;i < m;i++) {
            cnt[i] = 1;
            if (next[i + 1] >= 1) cnt[i] += cnt[next[i + 1] - 1];
        }
        cnt[m - 1]--;
        for (int i = 0;i < n;i++) {
            prefixCnt[i] = 0; k = m + i + 1;
            if (next[k + 1] >= 1) prefixCnt[i] = cnt[next[k + 1] - 1];
        }
        nm = 0;
        for (int i = m - 1;i >= 0;i--)
            s[nm++] = b[i];
        s[nm++] = '*';
        for (int i = n - 1;i >= 0;i--)
            s[nm++] = a[i];
        preKmp();
        for (int i = 0;i < m;i++) {
            cnt[i] = 1;
            if (next[i + 1] >= 1) cnt[i] += cnt[next[i + 1] - 1];
        }
        cnt[m - 1]--;
        for (int i = 0;i < n;i++) {
            suffixCnt[i] = 0; k = n + m - i;
            if (next[k + 1] >= 1) suffixCnt[i] = cnt[next[k + 1] - 1];
        }
        ans = 0LL;
        for (int i = 0;i + 1 < n;i++)
            ans += (prefixCnt[i] * suffixCnt[i + 1]);
        printf("Case %d: %lld\n", ++caseno, ans);
    }
}

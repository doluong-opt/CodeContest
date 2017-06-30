// =============================================================================
// Author LUONG VAN DO
// Problem E. Test
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
#define N 100010
#define P 999983
string s[4];
int id[4];
uint64 ha, hb, mul, f;
string solve(string x, string y) {
    int n = x.length(), m = y.length();
    int i, j, pos = 0;
    ha = hb = 0;
    mul = 1;
    for (i = n - 1, j = 0;i >= 0 && j < m;i--, j++) {
        ha = ha * P + x[i];
        hb = hb + y[j] * mul;
        if (ha == hb) pos = j + 1;
        mul *= P;
    }
    return x + y.substr(pos);
}
bool preProcess(string x, string y) {
    if (!x.length() || !y.length()) return false;
    if (y.length() > x.length()) return false;
    int n = x.length(), m = y.length();
    ha = hb = 0; mul = f = 1;
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
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int res;
    cin >> s[0] >> s[1] >> s[2];
    rep(i, 3)
        rep(j, 3) if (i != j && preProcess(s[i], s[j])) s[j] = "";
    res = INF;
    rep(i, 3) id[i] = i;
    do{
        res = min(res, solve(s[id[2]], solve(s[id[0]], s[id[1]])).length());
    }while (next_permutation(id, id + 3));
    printf("%d\n", res);
}

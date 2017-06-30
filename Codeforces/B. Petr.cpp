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

typedef pair<int, uint64> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 111222333
#define N 2222
#define P 999983

uint64 hashPow[N], hash[N], head, tail, ans[N * N];
char s[N], a[N], b[N];
int n, m, l1, l2, res;
vector <int> isStart, isEnd;
uint64 get(int l, int r) {
    return (hash[r + 1] - hash[l]) * hashPow[n - r];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    scanf(" %s ", s); n = strlen(s);
    scanf(" %s ", a); l1 = strlen(a);
    scanf(" %s ", b); l2 = strlen(b);
    hashPow[0] = 1; hash[0] = 0;
    fr(i, 1, n) {
        hashPow[i] = hashPow[i - 1] * P;
        hash[i] = hash[i - 1] + s[i - 1] * hashPow[i - 1];
    }
    head = tail = 0;
    rep(i, l1)
        head += a[i] * hashPow[i];
    head *= hashPow[n - l1 + 1];
    rep(i, l2)
        tail += b[i] * hashPow[i];
    tail *= hashPow[n - l2 + 1];
    isStart.clear(); isEnd.clear();
    for (int i = 0;i < n;i++) {
        if (i + l1 - 1 < n && get(i, i + l1 - 1) == head ) isStart.pb(i);
        if (i + l2 - 1 < n && get(i, i + l2 - 1) == tail ) isEnd.pb(i + l2 - 1);
    }
    m = 0;
    for (int i = 0;i < isStart.size();i++) {
        for (int j = 0; j < isEnd.size();j++)
            if (isEnd[j] >= isStart[i] && isEnd[j] - isStart[i] + 1 >= max(l1, l2) ) ans[m++] = get(isStart[i], isEnd[j]);
    }
    sort(ans, ans + m);
    res = 0;
    for (int i = 0;i < m;i++) {
        if (i && ans[i] == ans[i - 1]) continue;
        res++;
    }
    printf("%d\n", res);
}

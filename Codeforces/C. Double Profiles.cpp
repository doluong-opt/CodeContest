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

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 111222333
#define N 1000010
#define P 999983

int n, m, posA, posB;
uint64 ha[N], hb[N], hashPow[N];
int64 res;
vi adj[N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int u, v;
    scanf("%d %d", &n, &m);
    fr(i, 1, n) adj[i].clear();
    rep(i, m) {
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    hashPow[0] = 1;
    fr(i, 1, n) hashPow[i] = hashPow[i - 1] * P;
    fr(i, 1, n) {
        ha[i] = 0;
        sort(adj[i].begin(), adj[i].end());
        rep(j, adj[i].size()) ha[i] += hashPow[j] * adj[i][j];
        hb[i] = 0;
        adj[i].pb(i);
        sort(adj[i].begin(), adj[i].end());
        rep(j, adj[i].size()) hb[i] += hashPow[j] * adj[i][j];
    }
    sort(ha + 1, ha + n + 1); sort(hb + 1, hb + n + 1);
    posA = posB = 1; res = 0;
    ha[n + 1] = ha[n] + 1;
    hb[n + 1] = hb[n] + 1;
    fr(i, 2, n + 1) {
        if (ha[i] != ha[i - 1]) {
            res += ((i - posA) * (int64)(i - posA - 1)) / 2;
            posA = i;
        }
        if (hb[i] != hb[i - 1]) {
            res += ((i - posB) * (int64)(i - posB - 1)) / 2;
            posB = i;
        }
    }
    printf("%I64d\n", res);
}

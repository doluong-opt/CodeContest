// =============================================================================
// Author LUONG VAN DO
// Problem 12430 - Grand Wedding
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
#define INF 111222333444555LL
#define N 100010

using namespace std;

inline int64 max(int64 a, int64 b) { return a > b ? a : b; }
inline int64 min(int64 a, int64 b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector <int64> adj[N], w[N];
int mark[N], d[N], n, m;
int64 xMin, xMax;
bool isOk(int64 x = -1) {
    int u;
    fr(i, 1, n) d[i] = -1;
    fr(i, 1, n)
        if (d[i] == -1) {
            d[i] = 0;
            queue <int> q; q.push( i );
            while ( !q.empty() ) {
                u = q.front(); q.pop();
                for (int i = 0;i < adj[u].size();i++) {
                    int v = adj[u][i];
                    int64 cost = w[u][i];
                    if (x != -1 && cost >= x) continue;
                    if (d[v] == d[u]) return false;
                    if (d[v] == -1) {
                        d[v] = 1 - d[u];
                        q.push( v );
                    }
                }
            }
        }
    return true;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, u, v;
    int64 c, ans, lo, hi;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d", &n, &m);
        fr(i, 1, n) {
            adj[i].clear();
            w[i].clear();
        }
        xMin = INF; xMax = -INF;
        rep(i, m) {
            scanf("%d %d %lld", &u, &v, &c);
            adj[u].pb(v); w[u].pb(c);
            adj[v].pb(u); w[v].pb(c);
            xMin = min(xMin, c);
            xMax = max(xMax, c);
        }
        if ( isOk() ) {
            puts("0");
            continue;
        }
        lo = xMin + 1; hi = xMax; ans = -1;
        while (lo <= hi) {
            int64 mid = (lo + hi) >> 1;
            if ( isOk(mid) ) {
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        printf("%lld\n", ans);
    }
}

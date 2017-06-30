/***********************************************
* Author LUONG VAN DO                        *
* Problem ASSIGN1
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
#define INF 111222333
#define N 210

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
int n, c[N][N];
int matchx[N], matchy[N];
int distx[N], disty[N];

bool bfs(int64 X) {
    bool found = false;
    queue <int> q;
    fr(i, 1, n) {
        if (!matchx[i]) q.push( i );
        distx[i] = disty[i] = 0;
    }
    while ( !q.empty() ) {
        int u = q.front(); q.pop();
        for (int v=1;v<=n;v++)
            if (c[u][v] <= X) {
                if ( !disty[v] ) {
                    disty[v] = distx[u] + 1;
                    if ( !matchy[v] ) found = true;
                    else {
                        distx[ matchy[v] ] = disty[v] + 1;
                        q.push( matchy[v] );
                    }
                }
            }
    }
    return found;
}

bool dfs(int u, int64 X) {
    for (int v=1;v<=n;v++)
        if (c[u][v] <= X) {
            if (disty[v] == distx[u] + 1) {
                disty[v] = 0;
                if ( !matchy[v] || dfs(matchy[v], X) ) {
                    matchx[u] = v;
                    matchy[v] = u;
                    return true;
                }
            }
        }
    return false;
}
bool check(int64 X) {
    int k = 0;
    fr(i, 1, n) matchx[i] = matchy[i] = 0;
    while ( bfs(X) ) {
        fr(i, 1, n)
            if ( !matchx[i] && dfs(i, X) ) k++;
    }
    return (k == n);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int64 lo, hi, ans;
    scanf("%d",&n);
    fr(i, 1, n) fr(j, 1, n)
        scanf("%d", &c[i][j]);
    lo = 0; hi = (1<<31) - 1;
    while ( lo <= hi ) {
        int64 mid = (lo + hi) >> 1;
        if ( check(mid) ) {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    printf("%lld\n", ans);
}

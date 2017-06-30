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
#define N 1111
#define MAX_LOG 20
#define eps 1e-6
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
vector <int> adj[N];
int visit[N], st[N];
double volCur[N], vol[N], total, minVal;
int n, k, x, flag, ans, top, y, sl[N];
char s[N];
void dfs(int u) {
    if ( visit[u] ) return;
    visit[u] = 1;
    if (minVal > vol[u]) minVal = vol[u];
    total += volCur[u];
    st[top++] = u;
    for (int i = 0;i < adj[u].size();i++)
        dfs(adj[u][i]);
}
void solve(int u, int pos) {
    for (int i = 1;i <= n;i++) visit[i] = 0;
    minVal = INF; top = 0; total = 0.0;
    dfs(u);
    double xx = (double)total / (double)top;
    if ( xx  - eps > minVal ) flag = 0;
    while ( top > 0 ) {
        top--;
        volCur[ st[top] ] = xx;
    }
}
void findAdj(int x, int y) {
    sort(adj[x].begin(), adj[x].end());
    int lo = 0, hi = adj[x].size() - 1;
    int pos = -1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if ( adj[x][mid] == y ) {
            pos = mid;
            break;
        }
        if ( adj[x][mid] > y ) hi = mid - 1;
        else lo = mid + 1;
    }
    if (pos == -1) {
        adj[x].pb(y);
        sl[x]++;
    }
    else {
        int last = adj[x].size() - 1;
        sl[x]--;
        swap(adj[x][pos], adj[x][last]);
        adj[x].pop_back();
    }
}
int main() {
	freopen("pot.inp","r", stdin); freopen("pot.out","w", stdout);
    scanf(" %d %d ", &n, &k);
    for (int i = 1;i <= n;i++) {
        scanf(" %lf ", &vol[i]);
        volCur[i] = 0.0;
        adj[i].clear();
        sl[i] = 1;
    }
    flag = 1;
    for (int i = 1;i <= k && flag;i++) {
        scanf(" %s %d %d ", &s, &x, &y);
            if (s[0] == 'V') {
                findAdj(x, y);
                findAdj(y, x);
                solve(x, i);
                solve(y, i);
            }
            else {
                volCur[x] += y;
                if (sl[x] > 1) solve(x, i);
                else
                if (volCur[x] > vol[x]) flag = 0;
            }
            if (flag == 0) ans = i;
       }
    printf("%d\n", ans);
	return 0;
}

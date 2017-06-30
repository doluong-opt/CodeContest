/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1429 - Assassin`s Creed (II) 
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
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1010

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
int my[N], cx[N], cy[N];
int low[N], num[N], color[N], cnt, scc;
int a[N][N], h[N], mark[N];
int n, m;
stack <int> s;
bool match(int x) {
    for (int y = 1;y <= n;y++)
        if (a[x][y] && !my[y]) {
            my[y] = 1;
            if (cy[y] == -1 || match(cy[y])) {
                cy[y] = x;
                cx[x] = y;
                return true;
            }
        }
    return false;
}
void tajan(int u) {
    low[u] = num[u] = ++cnt;
    s.push(u);
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        if (!color[v])
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            tajan(v);
            low[u] = min(low[u], low[v]);
        }    
    }
    if (low[u] == num[u]) {
        int x = -1;
        ++scc;
        do
        {
            x = s.top(); s.pop();
            h[x] = scc;
            color[x] = 1;
        }while (x != u);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, u, v, ans;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d",&n, &m);
        fr(i, 1, n) {
            adj[i].clear();
            h[i] = 0;
            fr(j, 1, n) a[i][j] = 0;
        }
        fr(i, 1, m) {
            scanf("%d %d",&u, &v);
            adj[u].pb(v);
        }
        scc = cnt = 0;
        fr(i, 1, n) low[i] = num[i] = color[i] = 0;
        fr(i, 1, n)
            if ( !color[i] ) tajan(i);
        
        fr(i, 1, n)
            rep(j, adj[i].size()) {
                v = adj[i][j];
                if (h[i] != h[v]) a[h[i]][h[v]] = 1;
            }
        ans = 0;
        for (int i = 1;i <= scc;i++)
            cx[i] = cy[i] = -1;
            
        for (int i = 1;i <= scc;i++) {
            for (int j = 1;j <= scc;j++) my[j] = 0;
            if ( match(i) ) ans++;
        }
        printf("Case %d: %d\n",++caseno, ans);
    }
}

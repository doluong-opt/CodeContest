/***********************************************
* Author LUONG VAN DO                        *
* Problem 11324 - The Largest Clique
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
vector <int> adj[N], adjj[N];
int cnt, scc, n, m, id, len;
int low[N], num[N], mark[N], w[N], com[N], dp[N];
char s[N];
stack <int> S;
void tajan(int u) {
    num[u] = low[u] = ++cnt;
    S.push(u);
    for (int i = 0;i < adj[u].size();i++) {
        int v = adj[u][i];
        if (!mark[v])
        if ( num[v] ) low[u] = min(low[u], num[v]);
        else {
            tajan( v );
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == num[u]) {
        int x = -1, s = 0;
        scc++;
        do{
            x = S.top(); S.pop();
            com[x] = scc;
            mark[x] = 1;
            s++;
        }while (x != u);
        w[scc] = s;
    }
}

int run(int u) {
    int v, cost;
    int &res = dp[u];
    if (res != -1) return res;
    res = cost = 0;
    for (int i = 0;i < adjj[u].size();i++) {
        v = adjj[u][i];
        cost = max(cost, run(v));
    }
    res = cost + w[u];
    return res;
}
int getNext() {
    int v = 0;
    while (id < len && s[id] !=' ') v = v * 10 + s[id++] - '0';
    ++id;
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, ans, u, v;
    gets(s); len = strlen(s); id = 0;
    cases = getNext();
    while (cases--) {
        gets(s); len = strlen(s); id = 0;
        n = getNext(); m = getNext();
        fr(i, 1, n) {
            adj[i].clear();
            adjj[i].clear();
            dp[i] = -1;
        }
        rep(i, m) {
            gets(s); len = strlen(s); id = 0;
            u = getNext(); v = getNext();
            adj[u].pb(v);
        }
        cnt = scc = 0;
        fr(i, 1, n) {
            low[i] = num[i] = 0;
            mark[i] = 0;
        }
        fr(i, 1, n)
            if (!mark[i]) tajan(i);
        fr(i, 1, n)
            rep(j, adj[i].size()) {
                v = adj[i][j];
                if (com[i] != com[v]) adjj[com[i]].pb(com[v]);
            }
        ans = 0;
        for (int i = 1;i<=scc;i++)
            ans = max(ans, run(i));
        printf("%d\n", ans);
    }
}

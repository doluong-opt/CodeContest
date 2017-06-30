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
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i = b;i >= a;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define pb push_back
#define ff first
#define ss second
#define fill(arr, val) memset(arr, val, sizeof(arr))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint32 unsigned int
#define INF 1000000000
#define N 100100

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
int n, m, x, y, at, f[N];
vector <int> adj[N];
bool recheck, missing;
int low[N], num[N], color[N], scc, cnt;
stack <int> st;
vector <int> ans;
void dfs(int u) {
    int v;
    low[u] = num[u] = ++cnt;
    st.push(u);
    rep(i, adj[u].size()) {
        v = adj[u][i];
        if (!color[v])
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == num[u]) {
        scc++; int x;
        do{
            x = st.top(); st.pop();
            color[x] = 1;
        }while (x != u);
    }
}
bool isRecheck() {
    scc = cnt = 0;
    fr(i, 1, n) {
        low[i] = num[i] = 0;
        color[i] = 0;
    }
    fr(i, 1, n) if ( !color[i] ) dfs(i);
    return (scc < n);
}
bool isMissing() {
    at = -1;
    for (int i = 1;i <= n;i++)
        if ( f[i] == 0 ) {
            if (at == -1) at = i;
            else return true;
        }
    if (at == -1) recheck = true;
    return false;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d %d", &n, &m);
	    fr(i, 1, n) {
	        f[i] = 0;
	        adj[i].clear();
	    }
	    rep(i, m) {
	        scanf("%d %d", &x, &y);
	        adj[x].pb(y);
	        f[y]++;
	    }
	    recheck = missing = false;
	    if ( isRecheck() ) recheck = true;
	    if ( isMissing() ) missing = true;
	    //cout<<recheck<<" "<<missing<<endl;
	    ans.clear(); ans.pb(at);
	    for (int i = 0;i < n - 1 && !recheck && !missing;i++) {
	        int nextNode = -1;
	        for (int j = 0;j < adj[at].size();j++) {
	            int v = adj[at][j];
	            int k = --f[v];
	            if (k == 0) {
	                if (nextNode == -1) nextNode = v;
	                else {
	                    missing = true;
	                    break;
	                }
	            }
	        }
	        if (nextNode == -1) recheck = true;
	        ans.pb(nextNode); at = nextNode;
	    }
	    if (recheck) puts("recheck hints");
	    else
	    if (missing) puts("missing hints");
	    else {
	        rep(i, ans.size())
                if (i) printf(" %d", ans[i]);
                else printf("%d", ans[i]);
            puts("");
	    }
	}
	return 0;
}

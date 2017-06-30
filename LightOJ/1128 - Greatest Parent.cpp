/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1128 - Greatest Parent
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
#define N 100111

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
char s[N];
int m, id;
int nextInt() {
    int v = 0;
    while (id < m && s[id] != ' ') v = v * 10 + s[id++] - '0';
    ++id;
    return v;
}
int n, q, x, y;
vector <ii> node, adj[N], qu[N];
int mark[N], res[N];
void dfs(int cur) {
    if ( mark[cur] ) return;
    mark[cur] = 1;
    for (int i = 0;i < qu[cur].size();i++) {
        int x = qu[cur][i].ff;
        int y = qu[cur][i].ss;
        int lo = 0, hi = node.size() - 1;
        if ( res[x] == -1 ) {            
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (node[mid].ss >= y) hi = mid - 1;
                else lo = mid + 1;
            }
            res[x] = node[lo].ff;
        }
    }
    for (int i = 0;i < adj[cur].size();i++) {
        node.pb(adj[cur][i]);
        dfs(adj[cur][i].ff);
    }
    node.pop_back();
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
	m = (int)strlen(gets(s)); id = 0;
	cases = nextInt();
	while (cases--) {
	    gets(s);
	    m = (int)strlen(gets(s)); id = 0;
	    n = nextInt(); q = nextInt();
	    node.clear();
	    for (int i = 0;i < n;i++) {
	        mark[i] = 0;
	        adj[i].clear();
	        qu[i].clear();
	    }
	    for (int i = 1;i < n;i++) {
	        m = (int)strlen(gets(s)); id = 0;
	        x = nextInt(); y = nextInt();
	        adj[x].pb(ii(i, y));	        
	    }
	    for (int i = 0;i < q;i++) {
	        m = (int)strlen(gets(s)); id = 0;
	        x = nextInt(); y = nextInt();
	        qu[x].pb(ii(i, y));
	        res[i] = -1;
	    }
	    node.pb(ii(0, 1)); dfs(0);
	    printf("Case %d:\n", ++caseno);
	    for (int i = 0;i < q;i++)
            printf("%d\n", res[i]);
	}
	return 0;
}

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
struct node{
    int y, a, b;
    node(){}
    node(int _y, int _a, int _b){
        y = _y; a = _a; b = _b;
    }
};
int n, k, x, y, a, b, lo, hi, ans;
vector <node> adj[N];
int valMin[N], valMax[N];
void dfs(int u, int dad) {
    valMax[u] = 0;
    valMin[u] = 0;
    rep(i, adj[u].size()) {
        int v = adj[u][i].y;
        if (v == dad) continue;
        dfs(v, u);
        valMax[u] = max(valMax[u], valMax[v] + adj[u][i].a);
        valMin[u] = max(valMin[u], valMin[v] + adj[u][i].b);
    }
}
int cost(int u, int dad, int euros) {
    int res = 0;
    rep(i, adj[u].size()) {
        int v = adj[u][i].y;
        if (v == dad) continue;
        int x = euros - valMax[v];
        x = min(x, adj[u][i].a);
        x = max(x, adj[u][i].b);
        res += (adj[u][i].a - x) + cost(v, u, euros - x);
    }
    return res;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d", &n, &k);
	rep(i, n - 1) {
	    scanf("%d %d %d %d", &x, &y, &a, &b);
	    x--; y--;
	    adj[x].pb(node(y, a, b));
	    adj[y].pb(node(x, a, b));
	}
	dfs(0, -1);
	/*rep(i, n) cout <<i<<" "<< valMax[i] << endl;
	cout<<endl;
	rep(i, n) cout <<i<<" "<< valMin[i] << endl;*/
	lo = valMin[0]; hi = valMax[0];
	while (lo <= hi) {
	    int mid = (lo + hi) >> 1;
	    if ( cost(0, -1, mid) <= k ) {
	        ans = mid;
	        hi = mid - 1;
	    }
	    else lo = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}

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
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 222

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
int lf[N], ri[N], m, n;
int x[N], y[N], mark[N], match[N];
vector <int> adj[N];
int dfs(int u) {
    if (mark[u]) return 0;
    mark[u] = 1;
    for (int i = 0;i < adj[u].size();i++) {
        int v = adj[u][i];
        if (match[v] == -1 || dfs(match[v]) ) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int t, u, v, pos;
	scanf("%d %d", &n, &m);
	for (int i = 0;i < n;i++) {
	    x[i] = lf[i] = 0;
	    y[i] = ri[i] = n - 1;
	}
	for (int i = 0;i < m;i++) {
	    scanf("%d %d %d %d",&t, &u, &v, &pos);
	    u--; v--; pos--;
	    lf[pos] = max(lf[pos], u);
	    ri[pos] = min(ri[pos], v);
	    for (int j = u;j <= v;j++)
            if (t == 1) y[j] = min(y[j], pos);
            else x[j] = max(x[j], pos);
	}
	
	for (int i = 0;i < n;i++) {
	    match[i] = -1;
	    for (int j = lf[i];j <= ri[i];j++)
            if (x[j] <= i && i <= y[j]) adj[i].pb(j);
	}
	int flag = 1;
	for (int i = 0;i < n && flag;i++) {
	    for (int j = 0;j < n;j++) mark[j] = 0;
	    flag = dfs(i);
	}
	if (flag) {
	    for (int i = 0;i < n;i++) {
            if (i) printf(" ");
            printf("%d", match[i] + 1);
	    }
	    puts("");
	}
	else puts("-1");
	return 0;
	/*for (int i = 0;i < n;i++)
        printf("%d %d\n", lf[i], ri[i]);
    cout<<endl;
    for (int i = 0;i < n;i++)
        printf("%d %d\n", x[i], y[i]);
    cout<<endl;
    return 0;*/
}

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
#define N 100111
int parent[N], mark[N], qu[N], check[N];
ii edge[N];
int n, m, q, res[N];
int findSet(int v) {
    return (v == parent[v] ? v : parent[v] = findSet(parent[v]));
}
void unionSet(int u, int v) {
    parent[findSet(u)] = findSet(v);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int u, v, x;
	scanf("%d %d %d",&n, &m, &q);
	fr(i, 1, n) parent[i] = i;
	fr(i, 1, m) {
	    scanf("%d %d", &u, &v);
	    edge[i] = ii(u, v);
	    mark[i] = check[i] = 0;
	}
	fr(i, 1, q) {
	    scanf("%d", &x);
	    qu[i] = x;
	    mark[x] = 1;
	    res[i] = 0;
	}
	fr(i, 1, m)
        if (!mark[i]) unionSet(edge[i].ff, edge[i].ss);
    fr(i, 1, n) findSet(i);
    fr(i, 1, n) check[parent[i]] = 1;
    fr(i, 1, n) if (check[i]) res[q]++;
    for (int i = q;i>=1;i--) {
        u = findSet(edge[qu[i]].ff);
        v = findSet(edge[qu[i]].ss);
        if (u == v) res[i - 1] = res[i];
        else {
            res[i - 1] = res[i] - 1;
            unionSet(u, v);
        }
    }
    fr(i, 1, q)
        printf("%d\n", res[i]);
}

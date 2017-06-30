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
#define N 3333

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
vi adj[N];
int n, m, u, v, nheap, sz;
int month[N][N];
int f[N], minPath[N][N];
void findMin(int s) {
    queue <int> q;
    q.push(s);
    for (int i = 1;i <= n;i++) minPath[s][i] = INF;
    minPath[s][s] = 0;
    while ( !q.empty() ) {
        u = q.front(); q.pop();
        for (int i = 0;i < adj[u].size();i++) {
            v = adj[u][i];
            if (minPath[s][v] > minPath[s][u] + 1) {
                minPath[s][v] = minPath[s][u] + 1;
                q.push(v);
            }
        }
    }
}
int getInt(int &res) {
    res = 0; char c;
    do { c = getchar();
    }while (c < '0' || c > '9');
    do {
        res = res * 10 + c - '0';
        c = getchar();
    }while (c >= '0' && c <= '9');
    return res;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
    getInt(n); getInt(m);
    for (int i = 1;i <= m;i++) {
        getInt(u); getInt(v);
        adj[u].pb(v); adj[v].pb(u);
    }

    for (int i = 1;i <= n;i++) findMin(i);

    for (int i = 1;i <= n;i++) {
        for (int j = i + 1;j <= n;j++) {
            if (minPath[i][j] == INF) continue;
            u = log2(minPath[i][j]);
            if (u == log2(minPath[i][j])) {
                month[i][j] = u;
                month[j][i] = u;
            }
            else {
                month[i][j] = u + 1;
                month[j][i] = u + 1;
            }
        }
    }
    sz = 0;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) {
            if (i == j || month[i][j] == 0) continue;
            f[month[i][j]]++;
            sz = max(sz, month[i][j]);
        }
    for (int i = 1;i <= sz;i++) {
        if (i == 1) printf("%d", f[i] / 2);
        else printf(" %d", f[i] / 2);
    }
    puts(" 0");
	return 0;
}

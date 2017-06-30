/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10608 - Friends ->AC
* Algorithm adhoc
* Time Limit 0.036s
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
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define frr(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i=n - 1; i>=0; i--)
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 30010

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
int parent[N], f[N];
int n, m;
int findSet(int v) {
    return (v == parent[v] ? v : parent[v] = findSet( parent[v] ));
}
void unionSet(int x, int y) {
    parent[findSet(x)] = findSet(y);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, x, y, ans;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d",&n,&m);
        for (int i=1;i<=n;i++) {
            parent[i] = i;
            f[i] = 0;
        }
        for (int i=0;i<m;i++) {
            scanf("%d %d",&x,&y);
            unionSet(x, y);
        }
        for (int i=1;i<=n;i++) findSet(i);
        ans = 0;
        for (int i=1;i<=n;i++) {
            f[parent[i]]++;
            ans = max(ans, f[parent[i]]);
        }
        printf("%d\n", ans);
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10685 - Nature ->AC
* Algorithm joinSet
* Time Limit 0.372s
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
#define N 5100

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
int lab[N], n, q;
map <string, int> h;
char s[N], s1[N];
int f[N];
int findSet(int x) {
    return (x == lab[x] ? x : lab[x] = findSet(lab[x]));
}
void unionSet(int u, int v) {
    lab[findSet(u)] = findSet(v);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int m, u, v, ans;
    while ( scanf(" %d %d ",&n,&q) && (n + q)) {
        m = 0; h.clear();
        for (int i=0;i<n;i++) {
            scanf(" %s ",s);
            if (!h[s]) h[s] = ++m;
        }
        for (int i=1;i<=n;i++) {
            lab[i] = i;
            f[i] = 0;
        }
        for (int i=0;i<q;i++) {
            scanf(" %s %s ", s1, s);
            u = h[s1]; v = h[s];
            unionSet(u, v);
        }
        for (int i=1;i<=n;i++)
            findSet( i );
        ans = 0;
        for (int i=1;i<=n;i++) {
            f[lab[i]]++;
            ans = max(ans, f[lab[i]]);
        }
        printf("%d\n", ans);
    }
}

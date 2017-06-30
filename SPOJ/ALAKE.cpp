/***********************************************
* Author LUONG VAN DO                        *
* Problem ALAKE ->AC
* Algorithm linked
* Time Limit 1.46
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
#define INF 111222333444LL
#define N 100010

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
int n, next[N], pre[N], ind;
int64 w[N], h[N], res[N], total;
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    scanf("%d",&n);
    total = ind = 0;
    h[0] = h[n + 1] = INF;
    fr(i, 1, n) {
        scanf("%lld %lld",&w[i], &h[i]);
        next[i] = i + 1;
        pre[i] = i - 1;
        if (h[i] < h[ind]) ind = i;
    }
    while (h[ind] < INF) {
        res[ind] = total + w[ind];
        next[ pre[ind] ] = next[ind];
        pre[ next[ind] ] = pre[ind];
        if ( h[ pre[ind] ] < h[ next[ind] ] ) {
            total+=w[ind] * ( h[ pre[ind] ] - h[ind] );
            w[pre[ind]]+=w[ind];
            ind = pre[ind];
            while (ind > 0 && h[pre[ind] ] < h[ind] ) ind = pre[ind];
        }
        else {
            total+=w[ind] * ( h[next[ind]] - h[ind] );
            w[next[ind]]+=w[ind];
            ind = next[ind];
            while (ind <= n && h[next[ind]] < h[ind] ) ind = next[ind];
        }
    }
    fr(i, 1, n)
        printf("%lld\n", res[i]);
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11235 - Frequent values ->AC
* Algorithm IT
* Time Limit 0.508s
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
#define N 200010
#define c 100000
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
int n, q;
int fre[N], a[N];
int tree[16 * N], in[N];
void build(int pos, int l, int r) {
    if (l == r) {
        tree[pos] = fre[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * pos, l, mid);
    build(2 * pos + 1, mid + 1, r);
    tree[pos] = max(tree[2 * pos], tree[2 * pos + 1]);
}
int get(int pos, int u, int v, int l, int r){
    if (v < l || u > r) return 0;
    if (u<=l && r<=v) return tree[pos];
    
    int mid = (l + r) >> 1;
    return max( get(2 * pos, u, v, l, mid), get(2 * pos + 1, u, v, mid + 1, r) );
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int ans, r1, r2, x, y;
    while ( scanf("%d",&n) && n) {
        scanf("%d",&q);
        for (int i=0;i<N;i++) {
            fre[i] = 0;
            in[i] = -1;
        }
        for (int i=0;i<n;i++) {
            scanf("%d",&a[i]);
            if (!fre[a[i] + c]) in[a[i] + c] = i;
            fre[a[i] + c]++;
        }
        build(1, 0, 200000);
        while (q--) {
            scanf("%d %d",&x,&y);
            x--; y--; ans = 0;
            if (a[x] == a[y]) ans = y - x + 1;
            else {
                if (!fre[a[x] + c]) r1 = 0;
                else r1 = fre[a[x] + c] - (x - in[a[x] + c]);
                if (!fre[a[y] + c]) r2 = 0;
                else r2 = y - in[a[y] + c] + 1;
                ans = max(ans, max(r1, r2));
            }
            x = a[x] + c + 1; y = a[y] + c - 1;
            if (x <= y) ans = max(ans, get(1, x, y, 0, 200000));
            printf("%d\n",ans);
        }
    }
}

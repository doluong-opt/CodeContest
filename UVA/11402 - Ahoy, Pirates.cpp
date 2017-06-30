/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11402 - Ahoy, Pirates!
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
#define N 1024010

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
struct node {
    int sum, no;
};
node tree[8 * N];
int m, n, a[N];
void build(int pos, int l, int r) {
    if (l == r) {
        tree[pos].no = 0;
        tree[pos].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * pos, l, mid);
    build(2 * pos + 1, mid + 1, r);
    tree[pos].sum = tree[2 * pos].sum + tree[2 * pos + 1].sum;
}
void update(int pos, int u, int v, int l, int r) {
    if (v < l || u > r) return;
    if (u<=l && r<=v) {
        tree[pos].sum = (r - l + 1);
        return;
    }
    int mid = (l + r) >> 1;
    update(2 * pos, u, v, l, mid);
    update(2 * pos + 1, u, v, mid + 1, r);
    tree[pos].sum = tree[2 * pos].sum + tree[2 * pos + 1].sum;
}
void update1(int pos, int u, int v, int l, int r) {
    if (v < l || u > r) return;
    if (u<=l && r<=v) {
        tree[pos].sum = 0;
        return;
    }
    int mid = (l + r) >> 1;
    update1(2 * pos, u, v, l, mid);
    update1(2 * pos + 1, u, v, mid + 1, r);
    tree[pos].sum = tree[2 * pos].sum + tree[2 * pos + 1].sum;
}
int get(int pos, int u, int v, int l, int r) {
    if (v < l && u > r) return 0;
    if (u<=l && r<=v) return tree[pos].sum;
    
    int mid = (l + r) >> 1;
    
    return get(2 * pos, u, v, l, mid) + get(2 * pos + 1, u, v, mid + 1, r);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int caseno = 0, cases, x, y, T, q, sumCur;
    char s[55];
    scanf(" %d ",&cases);
    while ( cases-- ) {
        scanf(" %d ",&m);
        n = 0;
        while (m--) {
            scanf(" %d ",&T);
            scanf(" %s ",s);
            while (T--)
                for (int i=0;s[i];i++) a[n++] = s[i] - '0';
        }
        build(1, 0, n - 1);
//        printf("tree : %d", tree[1].sum);
        printf("Case %d:\n",++caseno);
        scanf(" %d ",&q);
        while (q--) {
            scanf(" %s ",s);
            scanf("%d %d",&x,&y);
            if (s[0] == 'F') update(1, x, y, 0, n - 1);
            else
            if (s[0] == 'E') update1(1, x, y, 0, n - 1);
            else
            if (s[0] == 'I') {
                update(1, x, y, 0, n - 1, -sumCur);
                update(1, x, y, 0, n - 1, y - x + 1 - sumCur);
            }
            else printf("Q%d: %d\n",get(1, x, y, 0, n - 1));
        }
    }
}

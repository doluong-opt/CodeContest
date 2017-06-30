/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1103 - Castle Walls ->AC
* Algorithm BIT
* Time Limit 0.318s
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
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
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
struct node {
    int x, y;
    node(){}
    node(int xx, int yy) {
        x = xx; y = yy;
    }
    bool operator <(const node& other) const{
        if (y != other.y) return y < other.y;
        return x < other.x;
    }
};
node a[2 * N], b[2 * N], c[2 * N];
int tree[2 * N];
int color[2 * N];
int n, m;
void update(int i) {
    while ( i <= n + m ) {
        tree[i]++;
        i+=(i&-i);
    }
}
int get(int i) {
    int x = 0;
    while ( i ) {
        x+=tree[i];
        i-=(i&-i);
    }
    return x;
}
void reset() {
    for (int i=0;i<=n + m;i++) {
        tree[i] = 0;
        color[i] = 0;
    }
}
int red() {
    int ans;
    for (int i=0;i<=n + m;i++) tree[i] = 0;
    sort(b, b + n);
    b[n].y = ans = 0;
    for (int i=n - 1;i>=0;i--) {
        update(b[i].x);
        ans+=get(b[i].x - 1);
    }
    return ans;
}
int blue() {
    int ans;
    for (int i=0;i<=m + n;i++) tree[i] = 0;
    sort(c, c + m);
    c[m].y = ans = 0;
    for (int i=m - 1;i>=0;i--) {
        update(c[i].x);
        ans+=get(c[i].x - 1);
    }
    return ans;
}
int main() {
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    int64 ans;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d",&n,&m);
        reset();
        ans = 0;
        for (int i=0;i<n;i++) {
            scanf("%d %d",&a[i].x,&a[i].y);
            b[i] = a[i];
            color[a[i].y] = 1;
        }
        for (int i=n;i<m + n;i++) {
            scanf("%d %d",&a[i].x,&a[i].y);
            c[i-n] = a[i];
            if (color[a[i].y]) ans++;
        }
        sort(a, a + n + m);
        for (int i=n + m - 1;i>=0;i--) {
            update(a[i].x);
            ans+=get(a[i].x - 1);
        }
        printf("Case %d: %lld\n",++caseno, ans - red() - blue());
    }
}

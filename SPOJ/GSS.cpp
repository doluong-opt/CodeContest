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
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 50010

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
struct seg{
    int left, right, sum;
};
seg tree[8 * N];
int a[N], f[N];
int ans, temp;
void update(int pos, int l, int r) {
    if (l == r) {
        tree[pos].left = a[l];
        tree[pos].right = a[l];
        tree[pos].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    update(2 * pos, l, mid);
    update(2 * pos + 1, mid + 1, r);
    tree[pos].left = max(tree[2 * pos].left, tree[2 * pos + 1].left + f[mid] - f[l-1]);
    tree[pos].right = max(tree[2 * pos + 1].right, tree[2 * pos].right + f[r] - f[mid]);
    tree[pos].sum = max(max(max(tree[2 * pos].sum, tree[2 * pos + 1].sum), tree[2 * pos + 1].left + tree[2 * pos].right), max(tree[pos].left, tree[pos].right));
}
void get(int pos, int u, int v, int l, int r) {
    if (v < l || u > r) return;
    if (u<=l && r<=v) {
        ans = max(ans, max(tree[pos].sum, tree[pos].left + temp));
        temp = max(0, max(f[r] - f[l-1] + temp, tree[pos].right));
        return;
    }
    int mid = (l + r) >> 1;
    get(2 * pos, u, v, l, mid);
    get(2 * pos + 1, u, v, mid + 1, r);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, q, x, y;
    scanf("%d",&n); f[0] = 0;
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        f[i] = f[i-1] + a[i];
    }
    update(1, 1, n);
    puts("tree[].sum");
    
    for (int i=1;i<=25;i++)
        printf("%d ",tree[i].sum);
        
    cout<<endl;
    puts("tree[].left");
    for (int i=1;i<=25;i++)
        printf("%d ",tree[i].left);
    cout<<endl;
    
    puts("tree[].right");
    for (int i=1;i<=25;i++)
        printf("%d ",tree[i].right);
    cout<<endl;
    scanf("%d",&q);
    while (q--) {
        scanf("%d %d",&x,&y);
        temp = 0;
        ans = -INF;
        get(1, x, y, 1, n);
        printf("%d\n",ans);
    }
}

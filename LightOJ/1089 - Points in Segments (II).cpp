/***********************************************
* Author LUONG VAN DO                        *
* Problem 1089 - Points in Segments (II) 
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
#define INF 111222333
#define N 200010

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node{
    int val, id;
    node(){}
    node(int _val, int _id){
        val = _val;
        id = _id;
    }
    bool operator < (const node& other) const{
        return (val < other.val);
    }
}a[N];
struct IT{
    int inc, sum;
    IT(){}
    IT(int _inc, int _sum){
        inc = _inc;
        sum = _sum;
    }
}tree[4 * N];
int b[N], n, m, q;
void buildIT(int pos, int l, int r) {
    if (l == r) {
        tree[pos].inc = 0;
        tree[pos].sum = 0;
        return;
    }
    int c = 2 * pos, mid = (l + r) >> 1;
    buildIT(c, l, mid);
    buildIT(c + 1, mid + 1, r);
    tree[pos].sum = tree[c].sum + tree[c + 1].sum;
    tree[pos].inc = tree[c].inc + tree[c + 1].inc;
}
void updateIT(int pos, int u, int v, int l, int r) {
    if (r < u || l > v) return;
    if (u <= l && r <= v) {
        tree[pos].inc++;
        tree[pos].sum += (r - l + 1);
        return;
    }
    int c = 2 * pos, mid = (l + r) >> 1;
    if (tree[pos].inc) {
        tree[c].inc += tree[pos].inc;
        tree[c + 1].inc += tree[pos].inc;
        tree[c].sum += (mid - l + 1) * tree[pos].inc;
        tree[c + 1].sum += (r - mid) * tree[pos].inc;
        tree[pos].inc = tree[pos].sum = 0;
    }
    updateIT(c, u, v, l, mid);
    updateIT(c + 1, u, v, mid + 1, r);
    tree[pos].sum = tree[c].sum + tree[c + 1].sum;
}
int getIT(int pos, int u, int v, int l, int r) {
    if (r < u || l > v) return 0;
    if (u <= l && r <= v) return tree[pos].sum;
    
    int c = 2 * pos, mid = (l + r) >> 1;
    
    if (tree[pos].inc) {
        tree[c].inc += tree[pos].inc;
        tree[c + 1].inc += tree[pos].inc;
        tree[c].sum += (mid - l + 1) * tree[pos].inc;
        tree[c + 1].sum += (r - mid) * tree[pos].inc;
        tree[pos].inc = tree[pos].sum = 0;
    }
    
    return getIT(c, u, v, l, mid) + getIT(c + 1, u, v, mid + 1, r);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d",&n, &q);
        fr(i, 1, 2 * n) {
            scanf("%d", &a[i].val);
            a[i].id = i;
        }
        fr(i, 2 * n + 1, q + 2 * n) {
            scanf("%d", &a[i].val);
            a[i].id = i;
        }
        sort(a + 1, a + 2 * n + q + 1);
        a[0].val = a[1].val - 1; m = 0;
        fr(i, 1, 2 * n + q) {
            if (a[i].val > a[i - 1].val) m++;
            b[a[i].id] = m;
        }
        printf("Case %d:\n", ++caseno);
        buildIT(1, 1, m);
        for (int i = 1;i <= 2 * n;i+=2)
            updateIT(1, b[i], b[i + 1], 1 ,m);
        fr(i, 2 * n + 1, q + 2 * n)
            printf("%d\n", getIT(1, b[i], b[i], 1, m));
    }
}

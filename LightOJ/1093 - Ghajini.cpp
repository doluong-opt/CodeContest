/***********************************************
* Author LUONG VAN DO                        *
* Problem 1093 - Ghajini 
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
#define N 100000

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
    int minVal, maxVal;
    node(){}
    node(int _minVal, int _maxVal){
        minVal = _minVal;
        maxVal = _maxVal;
    }
}tree[8 * N];
int n, d, a[N];
void buildIT(int pos, int l, int r) {
    if (l == r) {
        tree[pos].minVal = a[l];
        tree[pos].maxVal = a[l];
        return;
    }
    int c = (2 * pos), mid = (l + r) >> 1;
    buildIT(c, l, mid);
    buildIT(c + 1, mid + 1, r);
    tree[pos].minVal = min(tree[c].minVal, tree[c + 1].minVal);
    tree[pos].maxVal = max(tree[c].maxVal, tree[c + 1].maxVal);
}
int getminIT(int pos, int u, int v, int l, int r) {
    if (r < u || l > v) return INF;
    if (u <= l && r <= v) return tree[pos].minVal;
    
    int c = 2 * pos, mid = (l + r) >> 1;
    int a = getminIT(c, u, v, l, mid);
    int b = getminIT(c + 1, u, v, mid + 1, r);
    return min(a, b);
}
int getmaxIT(int pos, int u, int v, int l, int r) {
    if (r < u || l > v) return -INF;
    if (u <= l && r <= v) return tree[pos].maxVal;
    
    int c = 2 * pos, mid = (l + r) >> 1;
    int a = getmaxIT(c, u, v, l, mid);
    int b = getmaxIT(c + 1, u, v, mid + 1, r);
    return max(a, b);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, r1, r2, ans;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d", &n, &d);
        for (int i = 1;i <= n;i++) scanf("%d", &a[i]);
        buildIT(1, 1, n);
        ans = 0;
        for (int i = 1;i <= n - d + 1;i++) {
            r1 = getminIT(1, i, i + d - 1, 1, n);
            r2 = getmaxIT(1, i, i + d - 1, 1, n);
            ans = max(ans, r2 - r1);
        }
        printf("Case %d: %d\n", ++caseno, ans);
    }
}

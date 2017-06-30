/***********************************************
* Author LUONG VAN DO                        *
* Problem LITES
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
    int mx[3];
    int sum;
}tree[8 * N];

int n, m;
void buildIT(int pos, int l, int r) {
    if (l == r) {
        tree[pos].mx[0] = 1;
        tree[pos].mx[1] = 0;
        tree[pos].sum = 0;
        return;
    }
    int c = 2 * pos, mid = (l + r) >> 1;
    buildIT(c, l, mid);
    buildIT(c + 1, mid + 1, r);
    tree[pos].sum = tree[c].sum + tree[c + 1].sum;
    for (int i = 0;i < 2;i++)
        tree[pos].mx[i] = tree[c].mx[i] + tree[c + 1].mx[i];
}
node shift(node a) {
    int temp = a.mx[0];
    a.mx[0] = a.mx[1];
    a.mx[1] = temp;
    return a;
}
void updateIT(int pos, int u, int v, int l, int r) {
    if (r < u || l > v) return;
    if (u <= l && r <= v) {
        tree[pos].sum++;
        tree[pos] = shift(tree[pos]);
        return;
    }
    int c = 2 * pos, mid = (l + r) >> 1;
    if (tree[pos].sum) {
        tree[c].sum += tree[pos].sum;
        tree[c + 1].sum += tree[pos].sum;
        for (int i = 0;i < tree[pos].sum % 2;i++) {
            tree[c] = shift(tree[c]);
            tree[c + 1] = shift(tree[c + 1]);
        }
        tree[pos].sum = 0;
    }
    updateIT(c, u, v, l, mid);
    updateIT(c + 1, u, v, mid + 1, r);
    for (int i = 0;i < 2;i++)
        tree[pos].mx[i] = tree[c].mx[i] + tree[c + 1].mx[i];
}
int getIT(int pos, int u, int v, int l, int r) {
    if (r < u || l > v) return 0;
    if (u <= l && r <= v) return tree[pos].mx[0];
    
    int c = 2 * pos, mid = (l + r) >> 1;
    if ( tree[pos].sum ) {
        tree[c].sum += tree[pos].sum;
        tree[c + 1].sum += tree[pos].sum;
        for (int i = 0;i < tree[pos].sum % 2;i++) {
            tree[c] = shift(tree[c]);
            tree[c + 1] = shift(tree[c + 1]);
        }
        tree[pos].sum = 0;
    }
    return getIT(c, u, v, l, mid) + getIT(c + 1, u, v, mid + 1, r);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int u, v, c;
    scanf("%d %d", &n, &m);
    buildIT(1, 1, n);
    for (int i = 0;i < m;i++) {
        scanf("%d %d %d", &c, &u, &v);
        if (c == 0)
            updateIT(1, u, v, 1, n);
        else
            printf("%d\n", v - u + 1 - getIT(1, u, v, 1, n));
    }
}

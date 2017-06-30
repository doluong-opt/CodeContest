/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1135 - Count the Multiples of 3 ->AC
* Algorithm IT
* Time Limit 0.284s
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
#define N 100000
 
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
struct node{
    int mx[3];
};
int n, q, id;
node tree[4 * N];
int sum[4 * N];
char s[30];
node shift(node a) {
    int temp = a.mx[0];
    a.mx[0] = a.mx[2];
    a.mx[2] = a.mx[1];
    a.mx[1] = temp;
    return a;
}
void build_tree(int pos, int l, int r) {
    if (l == r) {
        tree[pos].mx[0] = 1;
        tree[pos].mx[1] = 0;
        tree[pos].mx[2] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build_tree(pos<<1, l, mid);
    build_tree((pos<<1) | 1, mid + 1, r);
    tree[pos].mx[0] = tree[pos<<1].mx[0] + tree[(pos<<1) | 1].mx[0];
    tree[pos].mx[1] = tree[pos<<1].mx[1] + tree[(pos<<1) | 1].mx[1];
    tree[pos].mx[2] = tree[pos<<1].mx[2] + tree[(pos<<1) | 1].mx[2];
    sum[pos] = 0;
}
void update(int pos, int x, int y, int l, int r) {
    if (y < l || x > r) return;
    if (x<=l && r<=y) {
        sum[pos]++;
        tree[pos] = shift(tree[pos]);
        return;
    }
    int mid = (l + r) >> 1;
    if (sum[pos]) {
        sum[pos<<1] += sum[pos];
        sum[(pos<<1)|1]+=sum[pos];
        for (int i=0;i<sum[pos] % 3;i++) {
            tree[pos<<1] = shift(tree[pos<<1]);
            tree[(pos<<1)|1] = shift(tree[(pos<<1)|1]);
        }
        sum[pos] = 0;
    }
    update(pos<<1, x, y, l, mid);
    update((pos<<1) | 1, x, y, mid + 1, r);
 
    for (int i=0;i<3;i++)
        tree[pos].mx[i] = tree[pos<<1].mx[i] + tree[(pos<<1) | 1].mx[i];
}
int get(int pos, int x, int y, int l, int r) {
    if (y < l || x > r) return 0;
    if (x<=l && r<=y) return tree[pos].mx[0];
    int mid = (l + r) >> 1;
    if (sum[pos]) {
        sum[pos<<1] +=sum[pos];
        sum[(pos<<1)|1]+=sum[pos];
        for (int i=0;i<sum[pos] % 3;i++) {
            tree[pos<<1] = shift(tree[pos<<1]);
            tree[(pos<<1)|1] = shift(tree[(pos<<1)|1]);
        }
        sum[pos] = 0;
    }
    return get(pos<<1, x, y, l, mid) + get((pos<<1) | 1, x, y, mid + 1, r);
}
int getInt(int n) {
    int val = 0;
    while (id < n && s[id]!=' ') val = val * 10 + s[id++] - '0';
    return val;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    int x, y, c, l;
    gets(s); id = 0; cases = getInt(strlen(s));
    while (cases--) {
        gets(s); id = 0;
        n = getInt(strlen(s)); ++id;
        q = getInt(strlen(s));
        build_tree(1, 1, n);
        printf("Case %d:\n",++caseno);
        for (int i=0;i<q;i++) {
            gets(s); l = strlen(s); id = 0; c = getInt(l); ++id;
            if (!c) {
                x = getInt(l); ++id;
                y = getInt(l);
                ++x; ++y;
                update(1, x, y, 1, n);
            }
            else {
                x = getInt(l); ++id;
                y = getInt(l);
                ++x; ++y;
                printf("%d\n",get(1, x, y, 1, n));
            }
        }
    }
}

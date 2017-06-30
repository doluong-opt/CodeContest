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
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 100111

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
    int maxAmount, maxLeft, maxRight;
    int valLeft, valRight;
    node(){}
    node(int _m1, int _m2, int _m3, int _m4, int _m5){
        maxAmount = _m1;
        maxLeft = _m2;
        maxRight = _m3;
        valLeft = _m4;
        valRight = _m5;
    }
};

int n, c, q, s, e, x, y;
int a[N];
node tree[8 * N];
void build(int pos, int l, int r) {
    if (l == r) {
        tree[pos].maxAmount = 1;
        tree[pos].maxLeft = 1;
        tree[pos].maxRight = 1;
        tree[pos].valLeft = tree[pos].valRight = a[l];
        return;
    }
    int mid = (l + r) >> 1, c = 2 * pos;
    build(c, l, mid); build(c + 1, mid + 1, r);
    tree[pos].valLeft = tree[c].valLeft;
    tree[pos].valRight = tree[c + 1].valRight;
    
    if ( tree[c].valLeft == tree[c + 1].valLeft )
        tree[pos].maxLeft = tree[c].maxLeft + tree[c + 1].maxLeft;
    else
        tree[pos].maxLeft = tree[c].maxLeft;
    if ( tree[c + 1].valRight == tree[c].valRight )
        tree[pos].maxRight = tree[c + 1].maxRight + tree[c].maxRight;
    else
        tree[pos].maxRight = tree[c + 1].maxRight;
    tree[pos].maxAmount = max(tree[c].maxAmount, tree[c + 1].maxAmount);
    if ( tree[c + 1].valLeft == tree[c].valRight )
        tree[pos].maxAmount = max(tree[pos].maxAmount, tree[c].maxRight + tree[c + 1].maxLeft);
}
node getmaxAmount(int pos, int u, int v, int l, int r) {
    if (r < u || l > v) return node(0, 0, 0, 0, 0);
    node res;
    if (u <= l && r <= v) res = tree[pos];
    else {
        int mid = (l + r) >> 1, c = 2 * pos;        
        node noLeft = getmaxAmount(c, u, v, l, mid);
        node noRight = getmaxAmount(c + 1, u, v, mid + 1, r);
        res.valLeft = noLeft.valLeft; res.valRight = noRight.valRight;
        
        if ( noLeft.valLeft == noRight.valLeft )
            res.maxLeft = noLeft.maxLeft + noRight.maxLeft;
        else
            res.maxLeft = noLeft.maxLeft;
        if ( noRight.valRight == noLeft.valRight )
            res.maxRight = noRight.maxRight + noLeft.maxRight;
        else
            res.maxRight = noRight.maxRight;
        res.maxAmount = max(noLeft.maxAmount, noRight.maxAmount);
        if ( noRight.valLeft == noLeft.valRight )
            res.maxAmount = max(res.maxAmount, noLeft.maxRight + noRight.maxLeft);
    }
    return res;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d %d %d", &n, &c, &q);	    
	    fr(i, 1, n) scanf("%d", &a[i]);
	    build(1, 1, n);
	    printf("Case %d:\n", ++caseno);
	    fr(i, 1, q) {
	        scanf("%d %d", &x, &y);
	        printf("%d\n", getmaxAmount(1, x, y, 1, n).maxAmount);
	    }
	}
	return 0;
}

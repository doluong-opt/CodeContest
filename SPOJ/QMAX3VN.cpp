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
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 2000000000
#define N 1010

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
int n, x, y;
char q;
struct node {
    int maxVal, size, val;
    node *left, *right, *parent;
};
node *root, *t1, *t2, *xx;
node *newNode(int v) {
    node *Node = new node();
    Node->left = NULL;
    Node->right = NULL;
    Node->parent = NULL;
    Node->maxVal = v;
    Node->val = v;
    Node->size = 1;
    return Node;
}
void init() {
    root = new node();
    root->maxVal = -INF;
    root->val = 0; root->size = 0;
}
void setL(node *x, node *y) {
    y->parent = x;
    x->left = y;
}
void setR(node *x, node *y) {
    y->parent = x;
    x->right = y;
}
node *NodeAt(node *x, int pos) {
    int ord;
    do {
        if ( x->left->size + 1 == pos ) return x;
        else if ( pos <= x->left->size ) x = x->left;
        else {
            pos -= (x->left->size + 1);
            x = x->right;
        }
    }while ( 1 );
}
int max3(int a, int b, int c) {
    return max(a, max(b, c));
}
void UpTree(node *x) {
    node *y, *z;
    y = x->parent;
    z = y->parent;
    if (x == y->left) {
        setL(y, x->right);
        setR(x, y);
    }
    else {
        setR(y, x->left);
        setL(x, y);
    }
    if (z->left == y) setL(z, x); else setR(z, x);
    if (y != NULL) {
        y->size = y->left->size + y->right->size + 1;
        y->maxVal = max3(y->left->maxVal, y->right->maxVal, y->val);
    }
        x->size = x->left->size + x->right->size + 1;
        x->maxVal = max3(x->left->maxVal, x->right->maxVal, x->val);
    
}
void Splay(node *x) {
    node *y, *z;
    do{
        y = x->parent;
        if (y == NULL) return;
        z = y->parent;
        if (z != NULL) {
            if ((y == z->left) == (x == y->left)) UpTree(y);
            else UpTree(x);
        }
        UpTree(x);
    }while ( 1 );
}
void Split(node *P, node *t1, node *t2, int pos) {
    if (pos == 0) {
        t1 = NULL;
        t2 = P;
        return;
    }
    else
    if (pos == P->size) {
        t1 = P;
        t2 = NULL;
        return;
    }
    else {
        t1 = NodeAt(P, pos);
        Splay(t1);
        t2 = t1->right;
        t1->right = NULL;
        t2->parent = NULL;
        t1->maxVal = max(t1->left->maxVal, t1->val);
        t1->size = t1->left->size + 1;
    }
}
node *Join(node *t1, node *t2, node *T) {
    if (t1 == NULL) return t2;
    if (t2 == NULL) return t1;
    while (t1->right != NULL) t1 = t1->right;
    Splay(t1);
    setR(t1, t2);
    t1->size = t1->left->size + t1->right->size + 1;
    t1->maxVal = max(t1->left->maxVal, t1->right->maxVal, t1->val);
    return t1;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf(" %d ", &n);
	init();
	for (int i = 1;i <= n;i++) {
	    scanf(" %c %d %d ", &q, &x, &y);
	    if (q == 'A') {
	        xx = newNode(x);
	        if (root == NULL) root = xx;
	        else {
	            Split(root, t1, t2, y - 1);
	            setL(xx, t1);
	            setR(xx, t2);
	            root = xx;
	        }
	    }
	    else {
	        Split(root, y);
	        Split(root, x - 1);
	        printf("%d\n", root->maxVal);
	        Join();
	    }
	}
}

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
#define MAX_LOG 20
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
struct treeNode{
    int val;
    treeNode *left;
    treeNode *right;
};
treeNode *root;
treeNode *newNode(int v) {
    treeNode *node = new treeNode();
    node->val = v;
    node->left = NULL;
    node->right = NULL;
    return node;
}
treeNode *insertTree(treeNode *node, int v) {
    if (node == NULL) {
        return newNode(v);
    }
    if (v > (node->val)) node->right = insertTree(node->right, v);
    else node->left = insertTree(node->left, v);
    return node;
}
void PrintInorder(treeNode *node) {
    if(node == NULL) return;
    printf("%d ",node->val);
    PrintInorder(node->left);
    PrintInorder(node->right);
}
int height(treeNode *node) {
    if (node == NULL) return -1;
    else return max(height(node->left), height(node->right)) + 1;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
    root = NULL;
    root = insertTree(root, 5);
    root = insertTree(root, -1);
    root = insertTree(root, 3);
    root = insertTree(root, -14);
    root = insertTree(root, 8);
    root = insertTree(root, 10);
    root = insertTree(root, 9);
    root = insertTree(root, 6);
    
    PrintInorder(root);
    cout<<endl;
    cout << height(root) << endl;
	return 0;
}

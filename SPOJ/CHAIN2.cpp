/***********************************************
* Author LUONG VAN DO                        *
* Problem CHAIN2
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
#define N 300000

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
    int max1, max2;
    node* next[27];
};
node* newNode() {
    node* Node = new node();
    Node->max1 = 0;
    Node->max2 = 0;
    rep(i, 26) Node->next[i] = NULL;
    return Node;
}
char s[N];
int n, m;
node* root, *p;
void dfs(node* root) {
    root->max2 = root->max1;
    rep(i, 26)
        if (root->next[i] != NULL) {
            dfs( root->next[i] );
            root->max2 = max(root->max2, root->next[i]->max2 + root->max1);
        }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    scanf(" %d ",&n);
    root = newNode();
    fr(i, 1, n) {
        gets(s); m = strlen(s);
        p = root;
        rep(j, m) {
            if ( p->next[ s[j] - 'a'] == NULL ) p->next[ s[j] - 'a' ] = newNode();
            p = p->next[ s[j] - 'a' ];
        }
        p->max1 = 1;
    }
    dfs( root );
    printf("%d\n", root->max2);
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 297 - Quadtrees ->AC
* Algorithm 0.008s
* Time Limit Adhoc
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
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define frr(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i=n - 1; i>=0; i--)
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 100000
#define C 1024
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
struct Node{
    char c;
    Node* next[4];
};
int n, m, ans, run;
char s1[N], s2[N];
Node* root1, *root2;

Node* newNode() {
    Node* node = new Node();
    node->c = 0;
    for (int i=0;i<4;i++) node->next[i] = NULL;
    return node;
}

Node* dfs(Node* u, int n, char *s) {
    run++;
    if (run == n) return NULL;
    u = newNode();
    u->c = s[run];
    if (s[run] == 'p') {
        for (int j=0;j<4;j++)
            if ( u->next[j] == NULL )
                u->next[j] = dfs(u->next[j], n, s);
    }
    return u;
}

void call(Node* u, Node* v, int level) {
    if (u == NULL && v == NULL) return;
    
    if (u == NULL) {
        if (v->c == 'f') {
//            cout<<(C>>(2*level))<<endl;
            ans+=(C >> (2 * level));
            return;
        }
        for (int j=0;j<4;j++)
            call(u, v->next[j], level + 1);
        return;
    }
    
    if (v == NULL) {
        if (u->c == 'f') {
//            cout<<(C>>(2*level))<<endl;
            ans+=(C >> (2 * level));
            return;
        }
        for (int j=0;j<4;j++)
            call(u->next[j], v, level + 1);
        return;
    }
    
    if (u->c == 'f' || v->c == 'f') {
//        cout<<(C>>(2*level))<<endl;
        ans+=(C >> (2 * level));
        return;
    }
    for (int i=0;i<4;i++)
        call(u->next[i], v->next[i], level + 1);
}
void deleteTree(Node* root) {
    for (int j=0;j<4;j++)
        if ( root->next[j] ) deleteTree( root->next[j] );
    delete root;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases;
    scanf(" %d ",&cases);
    while ( cases-- ) {
        gets(s1); n = strlen(s1);
        gets(s2); m = strlen(s2);
        run = -1;
        root1 = dfs(root1, n, s1);
        run = -1;
        root2 = dfs(root2, m, s2);
        ans = 0;
        call(root1, root2, 0);
        deleteTree(root1);
        deleteTree(root2);
        printf("There are %d black pixels.\n", ans);
    }
}

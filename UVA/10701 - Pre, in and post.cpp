 /***********************************************
* Author - LUONG VAN DO                        *
* Problem 10701 - Pre, in and post
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
#define N 56

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
char pre[N], in[N];
struct node{
    char lab;
    int lf, rt;
    node(){}
    node(char l, int ll, int rr){
        lab = l; lf = ll; rt = rr;
    }
};
vector <node> tree;
int n, pos;
int newNode(char c) {
    node n;
    n.lf = n.rt = -1;
    n.lab = c;
    tree.pb(n);
    return tree.size() - 1;
}
bool isLeft(char c) {
    for (int i=0;i<n;i++)
        if (c == in[i] && i < pos) return true;
    return false;
}
bool isRight(char c) {
    for (int i=0;i<n;i++)
        if (c == in[i] && i > pos) return true;
    return false;
}
void dfs(int root) {
    if (tree[root].lf != -1) dfs( tree[root].lf );
    if (tree[root].rt != -1) dfs( tree[root].rt );
    printf("%c",tree[root].lab);
}
bool Left(char a, char b) {
    int r1, r2;
    for (int i=0;i<n;i++)
        if (a == in[i]) r1 = i;
    else
        if (b == in[i]) r2 = i;
    return (r1 < r2);
}
bool Right(char a, char b) {
    int r1, r2;
    for (int i=0;i<n;i++)
        if (a == in[i]) r1 = i;
    else
        if (b == in[i]) r2 = i;
    return (r1 > r2);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, id, temp;
    int c_left, c_right, r1, r2, f;
    char c;
    scanf("%d",&cases);
    while (cases--) {
        scanf(" %d %s %s ",&n, pre, in);
        for (int i=0;i<n;i++)
            if (in[i] == pre[0]) pos = i;
            
        tree.clear();
        id = newNode(pre[0]);
        for (int i=1;i<n;i++) {
            if ( isLeft(pre[i]) ){
                do {
                    c = tree[id].lab;
                    if ( Left(pre[i], c) && tree[id].lf == -1) {
                        temp = newNode(pre[i]);
                        tree[id].lf = temp;
                        break;
                    }
                    else
                    if ( Right(pre[i], c) && tree[id].rt == -1) {
                        temp = newNode(pre[i]);
                        tree[id].rt = temp;
                        break;
                    }
                    else
                    if ( Left(pre[i], c) ) id = tree[id].lf;
                    else
                    if ( Right(pre[i], c) ) id = tree[id].rt;
                }while ( true );
            }
            else {
                do {
                    c = tree[id].lab;
                    if ( Left(pre[i], c) && tree[id].lf == -1) {
                        temp = newNode(pre[i]);
                        tree[id].lf = temp;
                        break;
                    }
                    else
                    if ( Right(pre[i], c) && tree[id].rt == -1) {
                        temp = newNode(pre[i]);
                        tree[id].rt = temp;
                        break;
                    }
                    else
                    if ( Left(pre[i], c) ) id = tree[id].lf;
                    else
                    if ( Right(pre[i], c) ) id = tree[id].rt;
                }while ( true );
            }
            id = 0;
        }
        dfs( 0 );
        puts("");
    }
}

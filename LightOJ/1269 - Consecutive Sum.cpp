/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1269 - Consecutive Sum ->AC
* Algorithm Trie
* Time Limit 1.283s
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
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 20000000000000LL
#define N 100000

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int64 And(int64 mask, int64 bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct Node{
    Node* next[3];
};
Node *root;
int bit[N], m;
Node *new_node(){
    Node* node = new Node();
    node->next[0] = NULL;
    node->next[1] = NULL;
    return node;
}
void convert(int64 x) {
    m = 0;
    while ( x ) {
        bit[m++] = x % 2;
        x>>=1;
    }
    while (m < 32) bit[m++] = 0;
    for (int i=0;i<16;i++) swap(bit[i], bit[m - i - 1]);
}
void add_trie(){
    Node* p = root;
    int64 x;
    for (int i=0;i<m;i++) {
        x = bit[i];
        if (p->next[x] == NULL) p->next[x] = new_node();
        p = p->next[x];
    }
}
int64 solve1(int64 x) {
    int64 b, sum;
    Node* p = root; sum = 0;
    for (int i=0;i<m;i++) {
        if (And(x, (m - i - 1))) b = 0;
        else b = 1;
        
        if (p->next[b] == NULL) b^=1;
        
        if (p->next[b] == NULL) return -1;
        
        sum = sum * 2 + b;
        p = p->next[b];
    }
    return sum;
}
int64 solve2(int64 x) {
    int64 b, sum;
    Node* p = root; sum = 0;
    for (int i=0;i<m;i++) {
        if (And(x, (m - i - 1))) b = 1;
        else b = 0;
        
        if ( p->next[b] == NULL )  b^=1;
        
        if ( p->next[b] == NULL ) return -1;
        
        sum = sum * 2 + b;
        p = p->next[b];
    }
    return sum;
}
void deleteTrie(Node *p) {
    for (int i=0;i<2;i++)
        if ( p->next[i] ) deleteTrie(p->next[i]);
    delete p;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, caseno = 0;
    int64 x, sum, ans_min, ans_max, r1, r2;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d",&n);
        sum = 0; root = new_node();
        ans_max = 0; ans_min = INF;
        for (int i=0;i<n;i++) {
            scanf("%lld",&x);
            sum^=x;
            if (x > ans_max) ans_max = x;
            if (sum > ans_max) ans_max = sum;
            if (x < ans_min) ans_min = x;
            if (sum < ans_min) ans_min = sum;
            
            convert( sum );
            r1 = solve1( sum );
            r2 = solve2( sum );
            
            if (r1!= -1 && (sum ^ r1) > ans_max) ans_max = (sum ^ r1);
            if (r2!= -1 && (sum ^ r2) < ans_min) ans_min = (sum ^ r2);
            
            add_trie();
        }
        printf("Case %d: %lld %lld\n",++caseno, ans_max, ans_min);
        deleteTrie(root);
    }
}

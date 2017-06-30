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

inline int64 max(int64 a, int64 b) { return a > b ? a : b; }
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
    Node *next[3];
};
Node *root;
int64 x, ans, sum, rMax;
int n, m, a[66];

Node *newNode() {
    Node *node = new Node();
    node->next[0] = NULL;
    node->next[1] = NULL;
    return node;
}
void convert(int64 x) {
    m = 0;
    while ( x ) {
        a[m++] = x % 2;
        x /= 2;
    }
    while (m < 64) a[m++] = 0;
    reverse(a, a + m);
}
void addTrie() {
    Node *p = root;
    for (int i = 0;i < m;i++) {
        int x = a[i];
        if (p->next[x] == NULL) p->next[x] = newNode();
        p = p->next[x];
    }
}
int64 solve() {
    Node *p = root;
    int64 sum = 0;
    for (int i = 0;i < m;i++) {
        int x = a[i] ^ 1;
        if ( p->next[x] == NULL ) x ^= 1;
        if ( p->next[x] == NULL ) return -1;
        sum = sum * 2 + x;
        p = p->next[x];
    }
    return sum;
}
void deleteTrie(Node *p) {
    rep(i, 2)
        if ( p->next[i] ) deleteTrie(p->next[i]);
    delete p;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d", &n);
	    ans = 0; sum = 0; root = newNode();
	    rep(i, n) {
	        scanf("%lld", &x);
	        ans = max(ans, x);
	        sum ^= x;
	        ans = max(ans, sum);
	        convert(sum);
	        rMax = solve();
	        if (rMax != -1 && rMax > ans) ans = rMax;
	        if (rMax != -1 && (rMax ^ sum) > ans) ans = rMax ^ sum;
	        addTrie();
	    }
	    deleteTrie(root);
	    printf("Case %d: %lld\n", ++caseno, ans);
	}
	return 0;
}

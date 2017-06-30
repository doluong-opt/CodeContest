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
#define KT child[child[rt][1]][0]
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

int n, m, k, x, y;
int a[N];

struct splayTree{
    int child[N][2];
    int parent[N], sw[N], sz[N], pos[N], first, rt;
    inline void newNode(int &x, int v, int far) {
        x = ++first;
        child[x][0] = child[x][1] = sw[x] = 0;
        parent[x] = far;
        sz[x] = 1; pos[x] = v;
    }
    inline void push_up(int x) {
        sz[x] = sz[child[x][0]] + sz[child[x][1]] + 1;
    }
    inline void push_down(int x) {
        if ( sw[x] ) {
            sw[child[x][0]] ^= 1;
            sw[child[x][1]] ^= 1;
            sw[x] = 0;
            swap(child[x][0], child[x][1]);
        }
    }
    inline void buildTree(int &x, int l, int r, int far) {
        if (l > r) return;
        int mid = (l + r) >> 1;
        newNode(x, mid, far);
        buildTree(child[x][0], l, mid - 1, x);
        buildTree(child[x][1], mid + 1, r, x);
        push_up(x);
        parent[x] = far;
    }
    inline void visit(int x) {
        if (x) {
            //push_down(x);
            printf("%2d:    %2d    %2d    %2d\n", x, child[x][0], child[x][1], pos[x]);
            visit(child[x][0]);
            //if ( pos[x] != -1 ) {                
            //}
            visit(child[x][1]);
        }
    }
    inline void init(int n) {
        rt = first = 0;
        child[rt][0] = child[rt][1] = parent[rt] = sz[rt] = sw[rt] = 0;
        newNode(rt, -1, 0);
        newNode(child[rt][1], -1, rt);
        push_up(child[rt][1]); push_up(rt);
        buildTree(KT, 1, n, child[rt][1]);
    }
    inline void uptree(int x, int f) {        
        int y = parent[x];
        push_down(y); push_down(x);
        child[y][!f] = child[x][f];
        parent[child[x][f]] = y;
        parent[x] = parent[y];
        if ( parent[x] ) child[parent[y]][child[parent[y]][1] == y] = x;
        child[x][f] = y;
        parent[y] = x;
        push_up(y);
    }
    inline void Splay(int x, int goal) {
        push_down(x);
        while ( parent[x] != goal ) {
            push_down(parent[parent[x]]); push_down(parent[x]); push_down(x);
            if ( parent[parent[x]] == goal ) uptree(x, child[parent[x]][0] == x);
            else {
                int y = parent[x], z = parent[y];
                int f = (child[z][0] == y);
                if ( child[y][f] == x ) uptree(x, !f), uptree(x, f);
                else uptree(y, f), uptree(x, f);
            }
        }
        push_up(x);
        if (goal == 0) rt = x;
    }
    inline int findK(int rt, int k) {
        int x = rt;
        push_down(x);
        while ( sz[child[x][0]] + 1 != k ) {
            if (k < sz[child[x][0]] + 1) {
                x = child[x][0];
            }
            else {
                k -= (sz[child[x][0]] + 1);
                x = child[x][1];
            }
            push_down(x);
        }
        return x;
    }
    inline void Excuted(int l, int r) {
        int x = findK(rt, l);
        Splay(x, 0);
        int y = findK(rt, r + 2);
        Splay(y, rt);
        sw[KT] ^= 1;
    }
    
    inline int output(int curPos) {
        int x = findK(rt, curPos);
        Splay(x, 0);
        int y = findK(rt, curPos + 2);
        Splay(y, rt);
        return pos[KT];
    }
}spl;
inline void nextint(int &res) {
    bool sign = false; char c; res = 0;
    do { c = getchar(); } while ((c < '0' || c > '9') && (c != '-'));
    if (c == '-') sign = true, c = getchar();
    do {
        res = res * 10 + c - '0'; c = getchar();
    }while (c >= '0' && c <= '9');
    if (sign) res = -res;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	nextint(n); nextint(m); spl.init(n);
	fr(i, 1, n) nextint(a[i]);
	fr(i, 1, m) {
	    nextint(k);
	    if (k == 1) {
	        nextint(x); nextint(y);	        
	        spl.Excuted(x, y);
	    }
	    else {
	        nextint(x);
	        printf("%d\n",a[spl.output(x)]);
	    }
	}
	return 0;
}

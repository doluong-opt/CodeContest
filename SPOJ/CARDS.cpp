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
int n, m, u, v, pos;
struct splayTree {
    int child[N][2];
    int parent[N], sz[N], val[N], rt, first, flag;
    inline void push_up(int x) {
        sz[x] = sz[ child[x][1] ] + sz[ child[x][0] ] + 1;
    }
    inline void visit(int x) {
        if (x) {
            printf("%2d:    %2d     %2d     %2d     %2d\n", x,   sz[x], child[x][0], child[x][1],   val[x]);
            visit(child[x][0]);
            visit(child[x][1]);
        }
    }
    inline void newNode(int &x, int v, int far) { //0 -1 1
        x = ++first;
        sz[x] = 1;
        val[x] = v;
        child[x][1] = child[x][0] = 0;
        parent[x] = far;
    }
    inline void buildTree(int &x, int l, int r, int par) {
        if (l > r) return;
        int mid = (l + r) >> 1;
        newNode(x, mid, par);
        buildTree(child[x][0], l, mid - 1, x);
        buildTree(child[x][1], mid + 1, r, x);
        parent[x] = par;
        push_up(x);
    }
    inline void init(int n) {
        rt = first = 0;
        child[rt][0] = child[rt][1] = parent[rt] = sz[rt] = val[rt] = 0;
        newNode(rt, -1, 0);
        newNode(child[rt][1], -1, rt);        
        push_up(child[rt][1]); push_up(rt);
        buildTree(KT, 1, n, child[rt][1]);
        
    }
    inline int findK(int rt, int k) {
        int x = rt;
        while ( sz[ child[x][0] ] + 1 != k ) {
            if (k < sz[ child[x][0] ] + 1)
                x = child[x][0];
            else {
                k -= (sz[ child[x][0] ] + 1);
                x = child[x][1];
            }
        }
        return x;
    }
    inline void uptree(int x, int f) {
        int y = parent[x];
        child[y][!f] = child[x][f];
        parent[ child[x][f] ] = y;
        parent[x] = parent[y];
        if ( parent[x] ) child[parent[y]][child[parent[y]][1] == y] = x;
        child[x][f] = y;
        parent[y] = x;
        push_up( y );
    }
    inline void Splay(int x, int goal) {
        while ( parent[x] != goal ) {
            if ( parent[parent[x]] == goal ) uptree(x, child[ parent[x] ][0] == x );
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
    inline void Excuted(int l, int r, int pos) {
        int x, y;
        x = findK(rt, l);
        Splay(x, 0);
        y = findK(rt, r + 2);
        Splay(y, rt);
        int temp = KT;
        KT = 0;
        push_up(child[rt][1]);
        push_up(rt);
        x = findK(rt, pos);
        Splay(x, 0);
        y = findK(rt, pos + 1);
        Splay(y, rt);
        KT = temp;
        parent[temp] = child[rt][1];
        push_up(child[rt][1]);
        push_up(rt);
    }
    inline void print(int x) {
        if (x) {
            print(child[x][0]);
            if (val[x] != -1) {
                if (flag) printf(" ");
                printf("%d", val[x]);
                flag = 1;
            }
            print(child[x][1]);
        }
    }
    inline void output() {
        flag = 0;
        print(rt);
        puts("");
    }
}spl;
inline void getInt(int &res) {
    bool sign = false; char ch; res = 0;
    do { ch = getchar(); } while ((ch  < '0' || ch > '9') && (ch != '-'));
    if ( ch == '-' ) sign = true, ch = getchar();
    do { res = res * 10 + ch - '0'; ch = getchar();
    }while (ch  >= '0' && ch <= '9');
    if (sign) res = -res;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	getInt(n); getInt(m); spl.init(n);
	spl.visit(1);
	fr(i, 1, m) {
	    getInt(u); getInt(v); getInt(pos);
	    v = v + u - 1;
	    spl.Excuted(u, v, pos);
	}
	spl.output();
	return 0;
}

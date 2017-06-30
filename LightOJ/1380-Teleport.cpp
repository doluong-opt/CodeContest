// =============================================================================
// Author LUONG VAN DO
// Problem
// Algorithm
// Time Limit
// =============================================================================
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
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint unsigned int

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 111222333
#define N 1010
#define M 10010
// opimization input / output
char buff[N];
int id, len;
int nextInt() {
    int v = 0;
    while (id < len && buff[id] != ' ') v = v * 10 + buff[id++] - '0';
    ++id;
    return v;
}

void prinln(int x) {
    if (!x) {
        puts("0");
        return;
    }
    len = 0;
    while ( x ) {
        buff[len++] = char(x % 10 + 48);
        x/=10;
    }
    repr(i, len) putchar(buff[i]);
    puts("");
}

struct edge{
    int x, y, c;
    edge(){}
    edge(int _x, int _y, int _c){
        x = _x; y = _y; c = _c;
    }
}e[M];

int n, m;
int cost[N], idx[N], pre[N], mark[N];
int dmst(int root) {
    int x, y, c, newn, ans = 0;
    while ( true ) {
        rep(i, n) cost[i] = INF;
        rep(i, m) {
            x = e[i].x;
            y = e[i].y;
            c = e[i].c;
            if (c < cost[y] && x != y) {
                cost[y] = c;
                pre[y] = x;
            }
        }
        rep(i, n) {
            if (i == root) continue;
            if (cost[i] == INF) return -1;
        }
        cost[root] = newn = 0;
        rep(i, n) idx[i] = mark[i] = -1;
        rep(i, n) {
            ans += cost[i];
            x = i;
            while (x != root && mark[x] != i && idx[x] == -1) {
                mark[x] = i;
                x = pre[x];
            }
            
            if (x != root && idx[x] == -1) {             
                for (int y = pre[x]; x != y; y = pre[y]) idx[y] = newn;
                idx[x] = newn++;
            }
        }
        if (!newn) break;
        rep(i, n) if (idx[i] == -1) idx[i] = newn++;
        
        rep(i, m) {
            x = e[i].x;
            y = e[i].y;
            e[i].x = idx[x];
            e[i].y = idx[y];
            if (e[i].x != e[i].y) e[i].c -= cost[y];
        }
        n = newn; root = idx[root];
    }
    return ans;
}
int main(){
	freopen("exam.inp","r",stdin);
	freopen("exam.out","w",stdout);
	int cases, caseno = 0, res, root;
    gets(buff); len = strlen(buff); id = 0;
    cases = nextInt();
    while (cases--) {
        gets(buff); gets(buff); len = strlen(buff); id = 0;
        n = nextInt(); m = nextInt(); root = nextInt();
        rep(i, m) {
            gets(buff); len = strlen(buff); id = 0;
            e[i].x = nextInt(); e[i].y = nextInt(); e[i].c = nextInt();
        }
        res = dmst(root);
        printf("Case %d: ", ++caseno);
        if (res != -1) prinln(res);
        else puts("impossible");
    }
}

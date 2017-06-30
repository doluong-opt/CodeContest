/***********************************************
* Author LUONG VAN DO                        *
* Problem 1234 - RACING
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
#define N 100000

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
struct node{
    int x, y, w;
    node(){}
    node(int xx, int yy, int ww){
        x = xx; y = yy; w = ww;
    }
};
int n, m;
node edge[N];
int lab[N];
int getSet(int v) {
    if (lab[v] < 0) return v;
    return lab[v] = getSet( lab[v] );
}
void unionSet(int r1, int r2) {
    int x = lab[r1] + lab[r2];
    if (lab[r1] > lab[r2]) {
        lab[r2] = x;
        lab[r1] = r2;
    }
    else {
        lab[r1] = x;
        lab[r2] = r1;
    }
}
bool cmp(node a, node b) {
    return (a.w > b.w);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, u, v, c, cnt, total, add;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d", &n, &m);
        total = 0;
        for (int i = 0;i < m;i++) {
            scanf("%d %d %d", &u, &v, &c);
            edge[i] = node(u, v, c);
            total+=c;
        }
        sort(edge, edge + m, cmp);
        for (int i = 1;i <= n;i++) lab[i] = -1;
        cnt = add = 0;
        for (int i = 0;i < m && cnt < n - 1;i++) {
            u = getSet(edge[i].x); v = getSet(edge[i].y);
            if (u != v) {
                unionSet(u, v);
                add+=edge[i].w;
                ++cnt;
            }
        }
        printf("%d\n", total - add);
    }
}

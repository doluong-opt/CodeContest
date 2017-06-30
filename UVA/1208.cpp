/***********************************************
* Author LUONG VAN DO                        *
* Problem 1208 - Oreon
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
#define N 1010
#define M 10010
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
struct node {
    int x, y, w;
    node(){}
    node(int xx, int yy, int ww){
        x = xx; y = yy; w = ww;
    }
};
char s[N];
int lab[N], a[N][N], nm;
node edge[M], ans[M];
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
    if (a.w != b.w) return a.w < b.w;
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
bool cmp1(node a, node b) {
    return a.w < b.w;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, id, m, n, j, x;
    int u, v, cnt;
    scanf("%d", &cases);
    while (cases--) {
        scanf(" %d ", &n);
        nm = 0;
        for (int i = 0;i < n;i++) {
            gets(s); m = strlen(s); id = 0;
            j = 0;
            while (id < m) {
                while (id < m && !isdigit(s[id])) ++id;
                x = 0;
                while (id < m && isdigit(s[id])) x = x * 10 + s[id++] - '0';
                //if (x) edge[nm++] = node(i, j++, x);
                a[i][j++] = x;
            }
        }
        for (int i = 0;i < n;i++)
            for (int j = i;j < n;j++)
                if (a[i][j]) {
                    //printf("%c %c %d\n", i + 65, j + 65, a[i][j]);
                    edge[nm++] = node(i, j, a[i][j]);
                }
        sort(edge, edge + nm, cmp1);
        for (int i = 0;i < n;i++) lab[i] = -1;
        printf("Case %d:\n", ++caseno);
        cnt = 0;
        for (int i = 0;i < nm && cnt < n - 1;i++) {
            u = getSet(edge[i].x); v = getSet(edge[i].y);
            if (u != v) {
                unionSet(u, v);
                ans[cnt++] = edge[i];
            }
        }
        sort(ans, ans + cnt, cmp);
        for (int i = 0;i < cnt;i++)
            printf("%c-%c %d\n", ans[i].x + 65, ans[i].y + 65, ans[i].w);
    }
}

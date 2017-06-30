/***********************************************
* Author LUONG VAN DO                        *
* Problem C11NHL
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
#define N 510

#define eps 1e-9
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

struct node{
    int x, y;
    double v;
    node(){}
    node(int xx, int yy, double vv){
        x = xx; y = yy;
        v = vv;
    }
};
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
double s[N][N];
int x, m, n, d;
int mark[N][N];
vector <node> res;
vector <ii> ans;
bool cmp(node a, node b) {
    if ( fabs(a.v - b.v) > eps ) return a.v > b.v;
    if ( a.x != b.x ) return a.x < b.x;
    return a.y < b.y;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    double val;
    int x, y, r1, r2, c1, c2;
    scanf("%d %d %d", &m, &n, &d);
    s[0][0] = 0.0;
    fill(mark, 0);
    for (int i = 1;i <= m;i++)
        for (int j = 1;j <= n;j++) {
            scanf("%d", &x);
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + log(x);
        }
    
    for (int i = 1;i <= m - d + 1;i++)
        for (int j = 1;j <= n - d + 1;j++) {
            x = i + d - 1;
            y = j + d - 1;
            val = s[x][y] - s[i - 1][y] - s[x][j - 1] + s[i - 1][j - 1];
            res.pb(node(i, j, val));
        }
    sort(res.begin(), res.end(), cmp);
    for (int i = 0;i < res.size();i++) {
        r1 = res[i].x; r2 = r1 + d - 1;
        c1 = res[i].y; c2 = c1 + d - 1;
        if (mark[r1][c1] || mark[r1][c2] || mark[r2][c1] || mark[r2][c2]) continue;
        ans.pb(ii(res[i].x, res[i].y));
        for (int i1 = r1;i1 <= r2;i1++)
            for (int i2 = c1;i2 <= c2;i2++) mark[i1][i2] = 1;
    }
    printf("%d\n", ans.size());
    for (int i = 0;i < ans.size();i++)
        printf("%d %d\n", ans[i].ff, ans[i].ss);
}

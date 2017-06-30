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
struct node {
    int x, y, z, w;
    node(){}
    node(int xx, int yy, int zz, int ww){
        x = xx; y = yy; z = zz; w = ww;
    }
};
vector <node> res, A, B;
int k, n, x[3], y[3], z[3];
int mark[5][5][5];
bool cmp(node a, node b) {
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return (a.z < b.z);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
    scanf("%d", &k);
    scanf("%d %d %d %d %d %d", &x[0], &y[0], &z[0], &x[1], &y[1], &z[1]);
    int v1, v2, v3;
    while ( scanf("%d", &v1) != EOF ) {
        scanf("%d %d", &v2, &v3);
        A.pb(node(v1, v2, v3, 0));
        scanf("%d %d %d", &v1, &v2, &v3);
        B.pb(node(v1, v2, v3, 0));
    }
    fill(mark, 0); n = A.size();
    queue <node> q; q.push(node(x[0], y[0], z[0], 0)); mark[x[0]][y[0]][z[0]] = 1;
    while ( !q.empty() ) {
        node u = q.front(); q.pop();
        if (u.x >= x[1] && u.y >= y[1] && u.z >= z[1] && u.w <= k) {
            res.pb(node(u.x, u.y, u.z, u.w));
            continue;
        }
        for (int i = 0;i < n;i++) {
            int nx = u.x - A[i].x;
            int ny = u.y - A[i].y;
            int nz = u.z - A[i].z;
            if (nx < 0 || ny < 0 || nz < 0) continue;
            nx += B[i].x; ny += B[i].y; nz += B[i].z;
            if (nx > 4 || ny > 4 || nz > 4) continue;
            if ( !mark[nx][ny][nz] ) {
                mark[nx][ny][nz] = 1;
                q.push(node(nx, ny, nz, u.w + 1));
            }
        }
    }
    if (!res.size()) puts("-1");
    else {
        sort(res.begin(), res.end(), cmp);
        printf("%d\n", res.size());
        rep(i, res.size())
            printf("%d %d %d %d\n", res[i].x, res[i].y, res[i].z, res[i].w);
    }
	return 0;
}

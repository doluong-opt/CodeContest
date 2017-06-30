/***********************************************
* Author LUONG VAN DO                        *
* Problem CHESSCBG
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
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
char a[5][5], b[5][5];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int d[5][5];
int bfs(int x, int y) {
    queue <ii> q;
    rep(i, 4)
        rep(j, 4) d[i][j] = INF;
    d[x][y] = 0;
    q.push(ii(x, y));
    while ( !q.empty() ) {
        ii u = q.front(); q.pop();
        rep(k, 4) {
            int nx = u.ff + dx[k];
            int ny = u.ss + dy[k];
            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
            if (b[nx][ny] == '1' && a[nx][ny] != '1' ) {
                b[nx][ny] = '0';
                return d[u.ff][u.ss] + 1;
            }
            if (d[nx][ny] == INF && a[nx][ny] != '1' ) {
                q.push(ii(nx, ny));
                d[nx][ny] = d[u.ff][u.ss] + 1;
            }
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int ans;
    rep(i, 4) gets(a[i]);
    rep(i, 4) gets(b[i]);
    rep(i, 4)
        rep(j, 4)
            if (a[i][j] == b[i][j]) a[i][j] = b[i][j] = '0';
    ans = 0;
    rep(i, 4)
        rep(j, 4)
            if (a[i][j] == '1') {
                a[i][j] = '0';
                ans+=bfs(i, j);
            }
    printf("%d\n",ans);
}

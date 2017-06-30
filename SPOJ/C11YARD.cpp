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
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1010

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
char s[N][N];
int f[N][N], mark[N][N], color[N][N], n, m, k, flag, ans, scc;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
int bfs(int x, int y, int scc) {
    queue <ii> q;
    q.push(ii(x, y));    
    for (int i = x;i <= x + k - 1;i++)
        for (int j = y;j <= y + k - 1;j++) color[i][j] = scc;
    while ( !q.empty() ) {
        ii u = q.front(); q.pop();
        for (int i = 0;i < 4;i++) {
            int nx = u.ff + dx[i];
            int ny = u.ss + dy[i];
            if (nx >= 1 && ny >= 1 && nx <= m && ny <= n && mark[nx][ny]) {                
                mark[nx][ny] = 0;
                for (int i = nx;i <= nx + k - 1;i++)
                    for (int j = ny;j <= ny + k - 1;j++)                        
                        color[i][j] = scc;
                q.push(ii(nx, ny));
            }
        }
    }
    int total = 0;
    for (int i = 1;i <= m;i++) {
        for (int j = 1;j <= n;j++)
            if (color[i][j] == scc) total++;
    }
    return total;
}

int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf(" %d %d %d ", &m, &n, &k);
	for (int i = 0;i <= m;i++) for (int j = 0;j <= n;j++) {
	    f[i][j] = 0;
	    mark[i][j] = 0;
	    color[i][j] = 0;
	}
	for (int i = 0;i < m;i++) gets(s[i]);
	for (int i = 1;i <= m;i++)
        for (int j = 1;j <= n;j++)
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + (s[i - 1][j - 1] == '#');
    flag = 0;
    for (int i = 1;i <= m - k + 1;i++)
        for (int j = 1;j <= n - k + 1;j++) {
            int x = i + k - 1;
            int y = j + k - 1;
            int val = f[x][y] - f[i - 1][y] - f[x][j - 1] + f[i - 1][j - 1];
            if (val == 0) {
                mark[i][j] = 1;
                flag = 1;
            }
        }
    if (!flag) {
        printf("-1\n");
        return 0;
    }
    ans = 0; scc = 0;
    for (int i = 1;i <= m;i++)
        for (int j = 1;j <= n;j++)
            if (mark[i][j]) ans = max(ans, bfs(i, j, ++scc));
    printf("%d\n", ans);
    return 0;
}

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
#define N 555

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
int dx[] = {-1, 0};
int dy[] = {0, -1};

int m, n, first, last, x, y;
int a[N][N], p[N][N], sl[N * N], tempLast;
ii q[N * N];
string ans;
bool inside(int u, int v) {
    return (u >= 1 && v >= 1 && u <= m && v <= n);
}
void solve() {
    fill(p, -1);
    first = last = 1;
    sl[1] = 1; q[1] = ii(1, 1);
    while (first <= last) {
        tempLast = last;
        for (int i = first;i <= sl[first];i++) {
            x = q[i].ff + 1;
            y = q[i].ss;
            if ( inside(x, y) && a[x][y] == 1 && p[x][y] == -1) {
                last++; q[last] = ii(x, y);
                p[x][y] = 0;
            }
            x = q[i].ff;
            y = q[i].ss + 1;
            if ( inside(x, y) && a[x][y] == 1 && p[x][y] == -1) {
                last++; q[last] = ii(x, y);
                p[x][y] = 1;
            }
        }
        sl[tempLast + 1] = last;
        tempLast = last;
        for (int i = first;i <= sl[first];i++) {
            x = q[i].ff + 1;
            y = q[i].ss;
            if ( inside(x, y) && a[x][y] == 0 && p[x][y] == -1) {
                last++; q[last] = ii(x, y);
                p[x][y] = 0;
            }
            x = q[i].ff;
            y = q[i].ss + 1;
            if ( inside(x, y) && a[x][y] == 0 && p[x][y] == -1) {
                last++; q[last] = ii(x, y);
                p[x][y] = 1;
            }
        }
        sl[tempLast + 1] = last;
        first = sl[first] + 1;
    }
}
void findAnswer() {
    x = m; y = n; ans = "";
    int xx, yy;
    while (x != 1 || y != 1) {
        ans += char(a[x][y] + 48);
        xx = x; yy = y;
        x = x + dx[p[xx][yy]];
        y = y + dy[p[xx][yy]];
    }
    ans += char(a[1][1] + 48);
    repr(i, ans.size()) putchar(ans[i]);
    puts("");
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d", &m, &n);
	fr(i, 1, m) fr(j, 1, n) scanf("%d", &a[i][j]);
	solve(); findAnswer();
	return 0;
}

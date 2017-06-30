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
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i = b;i >= a;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define pb push_back
#define ff first
#define ss second
#define fill(arr, val) memset(arr, val, sizeof(arr))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint32 unsigned int
#define INF 1000000000
#define N 55

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
int m, n, cnt, ans;
ii pos;
char s[N][N];
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
bool isOutside(int x, int y) {
    return (x >= 0 && x < m && y >= 0 && y < n);
}
int solve(int x, int y) {
    int c = 0;
    rep(i, 8) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!isOutside(nx, ny)) continue;
        if (s[nx][ny] == 'o') c++;
    }
    s[x][y] = '.';
    return c;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf(" %d %d ", &m, &n);
	rep(i, m) gets(s[i]); ans = 0;
	rep(i, m) rep(j, n)
        if (s[i][j] == '.') {
            cnt = solve(i, j);
            if (cnt > ans) ans = cnt, pos = ii(i, j);
        }
    s[pos.ff][pos.ss] = 'o'; ans = 0;
    //rep(i, m) cout<<s[i]<<endl;
    rep(i, m) rep(j, n)
        if (s[i][j] == 'o') ans += solve(i, j);
    printf("%d\n", ans);
	return 0;
}

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
int m, n, a[N][N], b[N][N];
char s[N][N];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
ii st, end;
bool isInside(int u, int v) {
    return (u >= 0 && u < m && v >= 0 && v < n);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf(" %d %d ", &m, &n);
	rep(i, m) gets(s[i]);
	fill(a, -1); fill(b, -1); queue <ii> q;
	rep(i, m) rep(j, n) {
        if (s[i][j] == 'S') {
            st = ii(i, j);
            s[i][j] = '.';
        }
        if (s[i][j] == 'D') end = ii(i, j);
        if (s[i][j] == '*') a[i][j] = 0;
        if (s[i][j] == '.') {
            bool flood = false;
            rep(k, 4) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (!isInside(nx, ny)) continue;
                if ( s[nx][ny] == '*' ) flood = true;
            }
            if ( flood ) {
                q.push(ii(i, j));
                a[i][j] = 1;
            }
        }
	}
	while ( !q.empty()) {
	    int x = q.front().ff;
	    int y = q.front().ss;
        q.pop();
        rep(i, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if ( !isInside(nx, ny) ) continue;
            if ( a[nx][ny] == -1 && s[nx][ny] != 'X' && s[nx][ny] != 'D' ) {
                a[nx][ny] = a[x][y] + 1;
                q.push(ii(nx, ny));
            }
        }
	}
	b[st.ff][st.ss] = 0; q.push(st);
	while (!q.empty()) {
	    int x = q.front().ff;
	    int y = q.front().ss;
        q.pop();
        rep(i, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if ( !isInside(nx, ny) ) continue;
            if ( b[nx][ny] == -1 && s[nx][ny] != 'X' )
                if ( a[nx][ny] > b[x][y] + 1 || a[nx][ny] == -1 ) {
                    b[nx][ny] = b[x][y] + 1;
                    q.push(ii(nx, ny));
                }
        }
	}
	if ( b[end.ff][end.ss] != -1 )
        printf("%d\n", b[end.ff][end.ss]);
    else
        puts("KAKTUS");
	return 0;
}

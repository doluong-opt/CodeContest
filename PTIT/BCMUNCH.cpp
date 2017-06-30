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
#define N 111

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
struct node{
    int x, y, c;
    node(){}
    node(int _x, int _y, int _c){
        x = _x; y = _y; c = _c;
    }
};
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int m, n, ans, mark[N][N];
char s[N][N];
ii st, end;
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf(" %d %d ", &m, &n);
	rep(i, m) gets(s[i]);
	rep(i, m) rep(j, n) {
        if (s[i][j] == 'C') st = ii(i, j);
        if (s[i][j] == 'B') end = ii(i, j);
        mark[i][j] = 0;
	}
	queue <node> q; q.push(node(st.ff, st.ss, 1)); mark[st.ff][st.ss] = 1;
	while (!q.empty()) {
	    node u = q.front(); q.pop();
	    if (u.x == end.ff && u.y == end.ss) {
	        ans = u.c;
	        break;
	    }
	    rep(i, 4) {
	        int nx = u.x + dx[i];
	        int ny = u.y + dy[i];
	        if (nx >= 0 && nx < m && ny >= 0 && ny < n && !mark[nx][ny] && s[nx][ny] == '.' || s[nx][ny] == 'B') {
	            int cost = u.c;
	            if (s[nx][ny] == '.') cost++;
	            q.push(node(nx, ny, cost));
	            mark[nx][ny] = 1;
            }
	    }
	}
	printf("%d\n", ans);
	return 0;
}

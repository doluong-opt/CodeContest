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
struct node{
    int x, y, d;
    node(){}
    node(int _x, int _y, int _d){
        x = _x; y = _y; d = _d;
    }
};
int m, n, lo, hi, ans, mark[N][N], a[N][N];
char s[N][N];
vector <ii> tree;
ii st;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
queue <node> Q;
bool inside(int x, int y) {
    return (x >= 0 && y >= 0 && x < m && y < n);
}
bool check(int x) {
    queue <ii> q; q.push(st);
    rep(i, m) rep(j, n) mark[i][j] = 0;
    ii u; mark[st.ff][st.ss] = 1;
    if (a[st.ff][st.ss] < x) return false;
    while ( !q.empty() ) {
        u = q.front(); q.pop();
        rep(i, 4) {
            int nx = u.ff + dx[i];
            int ny = u.ss + dy[i];
            if ( !inside(nx, ny) || s[nx][ny] == '+' || mark[nx][ny]) continue;
            if ( s[nx][ny] == '.' || s[nx][ny] == 'J' ) {
                if ( a[nx][ny] >= x ) {
                    q.push(ii(nx, ny));
                    mark[nx][ny] = 1;
                    if ( s[nx][ny] == 'J' ) return true;
                }
            }
        }
    }
    return false;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf(" %d %d ", &m, &n);
	rep(i, m) gets(s[i]);
	rep(i, m) rep(j, n)
        if (s[i][j] == '+') tree.pb(ii(i, j));
    else 
        if (s[i][j] == 'V') st = ii(i, j);
    fill(a, -1);
    rep(i, m) rep(j, n)
        if (s[i][j] == '+') {
            a[i][j] = 0;
            Q.push(node(i, j, 0));
        }
    while ( !Q.empty() ) {
        node u = Q.front(); Q.pop();
        rep(i, 4) {
            int nx = u.x + dx[i];
            int ny = u.y + dy[i];
            if ( !inside(nx, ny) || a[nx][ny] > -1 ) continue;
            a[nx][ny] = u.d + 1;
            Q.push(node(nx, ny, u.d + 1));
        }
    }
    /*rep(i, m) {
        rep(j, n)
        printf("%d ", a[i][j]);
        cout<<endl;
    }*/
    lo = ans = 0; hi = m + n;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if ( check(mid) ) {
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    printf("%d\n", ans);
	return 0;
}

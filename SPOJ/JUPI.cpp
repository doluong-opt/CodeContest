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
#define N 222

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
    int x, y, p;
    node(){}
    node(int xx, int yy, int pp){
        x = xx; y = yy; p = pp;
    }
};
int mark[N][N][5], r, c;
int d1[N][N][5], d2[N][N][5];
char s[N][N];
ii st;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int direc(char c) {
    if (c == 'E') return 0;
    if (c == 'W') return 1;
    if (c == 'S') return 2;
    if (c == 'N') return 3;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf(" %d %d ", &r, &c);
	rep(i, r) gets(s[i]);
	fill(mark, 0); fill(d1, 0); fill(d2, 0);
	rep(i, r) rep(j, c)
        if (s[i][j] == 'E' || s[i][j] == 'W' || s[i][j] == 'S' || s[i][j] == 'N')
            st = ii(i, j);
    d2[st.ff][st.ss][direc(s[st.ff][st.ss])] = 1;
    mark[st.ff][st.ss][direc(s[st.ff][st.ss])] = 1;
    queue <node> q;
    q.push(node(st.ff, st.ss, direc(s[st.ff][st.ss])));
    while ( !q.empty() ) {
        node u = q.front(); q.pop();
        if (u.p == 0) {
            rep(i, 4) {
                int nx = 
            }
        }
    }
	return 0;
}

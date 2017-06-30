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
#define MAX_LOG 20
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

int m, n, x, y, cntTree, curTree;
int a[16][16];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char direc[] = {'D','N','T','B'};
string pathCur, path;
bool isInside(int x, int y) {
    return (x >= 0 && x < m && y >= 0 && y < n);
}
void dfs(int x, int y) {
    if ( cntTree > curTree ) {
        curTree = cntTree;
        path = pathCur;
    }
    for (int k = 0;k < 4;k++) {
        int xx = x + dx[k];
        int yy = y + dy[k];
        if ( !isInside(xx, yy) || a[xx][yy] == 1 ) continue;
        a[xx][yy] = 1;
        cntTree++;
        pathCur += direc[k];
        dfs(xx, yy);
        a[xx][yy] = 0;
        cntTree--;
        pathCur.erase(pathCur.size() - 1);
    }
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
    scanf("%d %d %d %d", &m, &n, &x, &y);
    for (int i = 0;i < m;i++) for (int j = 0;j < n;j++) {
        scanf("%d", &a[i][j]);
    }
    dfs(x - 1, y - 1);
    cout << path << endl;
	return 0;
}

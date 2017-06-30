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
#define N 111
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
int n, m;
int a[N][N], b[N][N];
vector <ii> pos;
int calc(int x, int y) {
    int p = 0;
    if (x - 1 >= 0 && b[x - 1][y] == 1) p++;
    if (x + 1 < n && b[x + 1][y] == 1) p++;
    if (y - 1 >= 0 && b[x][y - 1] == 1) p++;
    if (y + 1 < n && b[x][y + 1] == 1) p++;
    return p >= 2;
}
/*bool check(int x, int y) {
    int sum = 0;
    a[x][y] = 1;
    for (int i = 0;i < n;i++) for (int j = 0;j < n;j++)
        sum += a[i][j];
    if (sum == 1) return true;
    for (int i = 0;i < n;i++) for (int j = 0;j < n;j++)
        if ( a[i][j] == 0 && calc(i, j, a) ) return true;
    a[x][y] = 0;
    return false;
}*/
bool isOk() {
    for (int i = 0;i < n;i++) for (int j = 0;j < n;j++) b[i][j] = a[i][j];
    
    while ( true ) {
        bool flag = false;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                if (b[i][j] == 0 && calc(i, j)) {
                    b[i][j] = 1;
                    flag = true;
                }
        if (!flag) break;
    }
    for (int i = 0;i < n;i++) for (int j = 0;j < n;j++)
        if (b[i][j] == 0) return false;
    return true;
}
int solve(int limit, int x, int preX, int preY) {
    if (limit == n) {
        if (isOk()) return 1;
        return 0;
    }
    int res = 0;
    for (int i = x;i < m;i++)
            if (a[pos[i].ff][pos[i].ss] == 0 && abs(preX - pos[i].ff) + abs(preY - pos[i].ss) >= 2 ) {
                a[pos[i].ff][pos[i].ss] = 1;
                res += solve(limit + 1, i + 1, pos[i].ff, pos[i].ss);
                a[pos[i].ff][pos[i].ss] = 0;
            }
    return res;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
    scanf("%d", &n);
    for (int i = 0;i < n;i++) for (int j = 0;j < n;j++)
        pos.pb(ii(i, j));
    m = n * n;
    cout << solve(0, 0, -1, -1) << endl;
	return 0;
}

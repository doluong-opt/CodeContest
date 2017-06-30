// =============================================================================
// Author LUONG VAN DO
// Problem B. Chess
// Algorithm
// Time Limit
// =============================================================================
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
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
char s1[3], s2[3];
int mark[9][9];
int dx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
int isOk(int u, int v) {
    return (u >= 1 && u <= 8 && v >= 1 && v <= 8);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int res = 0, u, v, u1, v1, nx, ny;
    scanf(" %s ", s1);
    scanf(" %s ", s2);
    u = s2[0] - 'a' + 1;
    v = s2[1] - '0';
    u1 = s1[0] - 'a' + 1;
    v1 = s1[1] - '0';
    fr(i, 1, 8) fr(j, 1, 8) mark[i][j] = 0;
    fr(i, 1, 8) mark[u1][i] = 1;
    fr(i, 1, 8) mark[i][v1] = 1;
    rep(i, 9) {
        nx = u + dx[i];
        ny = v + dy[i];
        if ( isOk(nx, ny) ) mark[nx][ny] = 1;
        nx = u1 + dx[i];
        ny = v1 + dy[i];
        if ( isOk(nx, ny) ) mark[nx][ny] = 1;
    }
    fr(i, 1, 8)
        fr(j, 1, 8)
            if (!mark[i][j]) res++;
    printf("%d\n", res);
}

/***********************************************
* Author LUONG VAN DO                        *
* Problem 1061 - N Queen Again 
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
#define N 10

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
const int status[95][10] = {
{1,5,8,6,3,7,2,4},
{1,6,8,3,7,4,2,5},
{1,7,4,6,8,2,5,3},
{1,7,5,8,2,4,6,3},
{2,4,6,8,3,1,7,5},
{2,5,7,1,3,8,6,4},
{2,5,7,4,1,8,6,3},
{2,6,1,7,4,8,3,5},
{2,6,8,3,1,4,7,5},
{2,7,3,6,8,5,1,4},
{2,7,5,8,1,4,6,3},
{2,8,6,1,3,5,7,4},
{3,1,7,5,8,2,4,6},
{3,5,2,8,1,7,4,6},
{3,5,2,8,6,4,7,1},
{3,5,7,1,4,2,8,6},
{3,5,8,4,1,7,2,6},
{3,6,2,5,8,1,7,4},
{3,6,2,7,1,4,8,5},
{3,6,2,7,5,1,8,4},
{3,6,4,1,8,5,7,2},
{3,6,4,2,8,5,7,1},
{3,6,8,1,4,7,5,2},
{3,6,8,1,5,7,2,4},
{3,6,8,2,4,1,7,5},
{3,7,2,8,5,1,4,6},
{3,7,2,8,6,4,1,5},
{3,8,4,7,1,6,2,5},
{4,1,5,8,2,7,3,6},
{4,1,5,8,6,3,7,2},
{4,2,5,8,6,1,3,7},
{4,2,7,3,6,8,1,5},
{4,2,7,3,6,8,5,1},
{4,2,7,5,1,8,6,3},
{4,2,8,5,7,1,3,6},
{4,2,8,6,1,3,5,7},
{4,6,1,5,2,8,3,7},
{4,6,8,2,7,1,3,5},
{4,6,8,3,1,7,5,2},
{4,7,1,8,5,2,6,3},
{4,7,3,8,2,5,1,6},
{4,7,5,2,6,1,3,8},
{4,7,5,3,1,6,8,2},
{4,8,1,3,6,2,7,5},
{4,8,1,5,7,2,6,3},
{4,8,5,3,1,7,2,6},
{5,1,4,6,8,2,7,3},
{5,1,8,4,2,7,3,6},
{5,1,8,6,3,7,2,4},
{5,2,4,6,8,3,1,7},
{5,2,4,7,3,8,6,1},
{5,2,6,1,7,4,8,3},
{5,2,8,1,4,7,3,6},
{5,3,1,6,8,2,4,7},
{5,3,1,7,2,8,6,4},
{5,3,8,4,7,1,6,2},
{5,7,1,3,8,6,4,2},
{5,7,1,4,2,8,6,3},
{5,7,2,4,8,1,3,6},
{5,7,2,6,3,1,4,8},
{5,7,2,6,3,1,8,4},
{5,7,4,1,3,8,6,2},
{5,8,4,1,3,6,2,7},
{5,8,4,1,7,2,6,3},
{6,1,5,2,8,3,7,4},
{6,2,7,1,3,5,8,4},
{6,2,7,1,4,8,5,3},
{6,3,1,7,5,8,2,4},
{6,3,1,8,4,2,7,5},
{6,3,1,8,5,2,4,7},
{6,3,5,7,1,4,2,8},
{6,3,5,8,1,4,2,7},
{6,3,7,2,4,8,1,5},
{6,3,7,2,8,5,1,4},
{6,3,7,4,1,8,2,5},
{6,4,1,5,8,2,7,3},
{6,4,2,8,5,7,1,3},
{6,4,7,1,3,5,2,8},
{6,4,7,1,8,2,5,3},
{6,8,2,4,1,7,5,3},
{7,1,3,8,6,4,2,5},
{7,2,4,1,8,5,3,6},
{7,2,6,3,1,4,8,5},
{7,3,1,6,8,5,2,4},
{7,3,8,2,5,1,6,4},
{7,4,2,5,8,1,3,6},
{7,4,2,8,6,1,3,5},
{7,5,3,1,6,8,2,4},
{8,2,4,1,7,5,3,6},
{8,2,5,3,1,7,4,6},
{8,3,1,6,2,5,7,4},
{8,4,1,3,6,2,7,5}
};

struct point{
    int x, y;
    point(){}
    point(int xx, int yy){
        x = xx; y = yy;
    }
};
point p[N];
char s[N][N];
int dp[N][(1<<8) + 5];
int f(int r1, int c1, int r2, int c2) {
    if (r1 == r2 && c1 == c2) return 0;
    if (r1 == r2 || c1 == c2) return 1;
    if (abs(r1 - r2) == abs(c1 - c2)) return 1;
    return 2;
}
int run(int cur, int mask, int pos) {
    if (cur == 8) return 0;
    int &res = dp[cur][mask];
    if (res != -1) return res;
    res = INF;
    for (int i = 0;i < 8;i++) {
        if ( !And(mask, i) ) {
            int tempCost = f(i + 1, status[pos][i], p[cur].x, p[cur].y);
            res = min(res, tempCost + run(cur + 1, Or(mask, i), pos));
        }
    }
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, ans, m;
    char buffer[N];
    scanf(" %d ", &cases);
    while (cases--) {
        rep(i, 8) gets(s[i]);
        m = 0;
        rep(i, 8)
            rep(j, 8)
                if (s[i][j] == 'q') p[m++] = point(i + 1, j + 1);
        ans = INF;
        rep(i, 92) {
            fill(dp, -1);
            ans = min(ans, run(0, 0, i));
        }
        printf("Case %d: %d\n", ++caseno, ans);
        gets(buffer);
    }
}

/***********************************************
* Author LUONG VAN DO                        *
* Problem 11391 - Blobs in the Board
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
#define N 16

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
int64 dp[5][5][(1<<N) + 5];
int r, c, n, x, y, mask;
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
int isOk(int x, int y) {
    return (x >= 0 && y >= 0 && x < r && y < c);
}
int64 run(int mask, int cur) {
    if (cur == n) return 1;
    int64 &res = dp[r - 1][c - 1][mask];
    if (res != -1) return res;
    int nextmask;
    res = 0;
    for (int i = 0;i < r;i++)
        for (int j = 0;j < c;j++)
            if ( And(mask, i * c + j) ) {
                for (int k = 0;k < 8;k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    int nxx = i + 2 * dx[k];
                    int nyy = j + 2 * dy[k];
                    if ( !isOk(nx, ny) || !isOk(nxx, nyy) ) continue;
                    if ( And(mask, nx * c + ny) && !And(mask, nxx * c + nyy) ) {
                        nextmask = Xor(mask, i * c + j);
                        nextmask = Xor(nextmask, nx * c + ny);
                        nextmask = Or(nextmask, nxx * c + nyy);
                        res+=run(nextmask, cur + 1);
                    }
                }
            }
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    scanf("%d", &cases);
    fill(dp, -1);
    while (cases--) {
        scanf("%d %d %d",&r, &c, &n);
        mask = 0;
        for (int i = 0;i < n;i++) {
            scanf("%d %d", &x, &y);
            x--; y--;
            mask = Or(mask, x * c + y);
        }
        printf("Case %d: %lld\n",++caseno, run(mask, 1));
    }
}

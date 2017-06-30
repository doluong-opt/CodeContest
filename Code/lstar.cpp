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
#define N 100100

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
char s[6][10];
int total[7], f[15];
int xx[15], yy[15], n;
ii getPos(int x, int y) {
    if (x == 1 && y == 5) return ii(1, 2);
    if (x == 2 && y == 2) return ii(3, 4);
    if (x == 2 && y == 4) return ii(1, 3);
    if (x == 2 && y == 6) return ii(2, 3);
    if (x == 2 && y == 8) return ii(3, 5);
    if (x == 3 && y == 3) return ii(1, 4);
    if (x == 3 && y == 7) return ii(2, 5);
    if (x == 4 && y == 2) return ii(1, 6);
    if (x == 4 && y == 4) return ii(4, 6);
    if (x == 4 && y == 6) return ii(5, 6);
    if (x == 4 && y == 8) return ii(2, 6);
    if (x == 5 && y == 5) return ii(4, 5);
}

bool check() {
    for (int i = 0;i < 6;i++)
        if (total[i] != 26) return false;
    return true;
}
bool solve(int limit) {
    if (limit == n) {
        if ( check() ) return true;
        return false;
    }
    ii posCur = getPos(xx[limit], yy[limit]);
    bool res;
    for (int i = 1;i <= 12;i++) {
        if ( f[i] ) continue;
        if (total[posCur.ff - 1] + i <= 26 && total[posCur.ss - 1] + i <= 26) {
            total[posCur.ff - 1] += i;
            total[posCur.ss - 1] += i;
            f[i] = 1;
            s[xx[limit] - 1][yy[limit] - 1] = (i - 1) + 'A';
            res = solve(limit + 1);
            if (res) return res;
            f[i] = 0;
            total[posCur.ff - 1] -= i;
            total[posCur.ss - 1] -= i;
            s[xx[limit] - 1][yy[limit] - 1] = 'x';
        }
    }
    return false;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
    for (int i = 0;i < 5;i++) gets(s[i]);
    for (int i = 0;i < 6;i++) total[i] = 0;
    for (int i = 1;i <= 12;i++) f[i] = 0;
    n = -1;
    for (int i = 0;i < 5;i++) for (int j = 0;j < 9;j++) {
        if ( s[i][j] == 'x' ) {
            n++;
            xx[n] = i + 1; yy[n] = j + 1;
        }
        else
        if ( s[i][j] >= 'A' && s[i][j] <= 'Z' ) {
            ii posCur = getPos(i + 1, j + 1);
            posCur.ff--; posCur.ss--;
            total[posCur.ff] += (s[i][j] - 'A' + 1);
            total[posCur.ss] += (s[i][j] - 'A' + 1);
            f[s[i][j] - 'A' + 1] = 1;
        }
    }
    n++;
    solve(0);
    for (int i = 0;i < 5;i++) puts(s[i]);
	return 0;
}

/***********************************************
* Author LUONG VAN DO                        *
* Problem 1266 - Magic Square
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
#define N 20

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
int a[N][N];
int f(int x) {
    int s = 0;
    while (x) {
        x/=10;
        s++;
    }
    return s;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int total = 0, caseno = 0, n;
    int x, y, run, len;
    while ( scanf("%d", &n) != EOF) {
        if ( caseno ) puts("");
        caseno = 1;
        if (n == 1) {
            puts("n=1, sum=1");
            puts(" 1");
            continue;
        }
        fill(a, 0);
        y = (1 + n) >> 1; run = 1;
        x = 1; 
        a[x][y] = run;
        while ( run < n * n) {
            x--;
            if (x <= 0) x = n;
            y++;
            if (y > n) y = 1;
            if (!a[x][y]) a[x][y] = ++run;
            else
            if (a[x][y]) {
                x+=2;
                y--;
                if (x > n) x = 1;
                if (y <= 0) y = n;
                a[x][y] = ++run;
            }
            if (x == 1 && y == n) {
                x++;
                if (x > n) x = 1;
                a[x][y] = ++run;
            }
        }
        total = 0;
        len = f(n * n);
        fr(i, 1, n) total+=a[1][i];
        printf("n=%d, sum=%d\n", n, total);
        fr(i, 1, n) {
            fr(j, 1, n) {
                x = f(a[i][j]);
                for (int k = 1;k <= len - x + 1;k++) printf(" ");
                printf("%d", a[i][j]);
            }
            puts("");
        }
    }
}

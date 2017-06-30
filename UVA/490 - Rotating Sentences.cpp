/***********************************************
* Author - LUONG VAN DO                        *
* Problem 490 - Rotating Sentences ->AC
* Algorithm Adhoc
* Time Limit 0.008s
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
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define M 110

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
int row[M];
char s[M][M];
char ans[M][M];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int m, n, maxr;
    int x, y;
    m = n = maxr = 0;
    while ( gets(s[m++]) ) {
        row[n++] = strlen(s[m-1]);
        maxr = max(maxr, row[n-1]);
    }
    m--;
    y = 0;
    x = m - 1;
    for (int i=0;i<maxr;i++)
        for (int j=0;j<m;j++) {
            if (y < row[x]) ans[i][j] = s[x][y];
            else ans[i][j] = ' ';
            x--;
            if (x < 0) {
                x = m - 1;
                y++;
            }
        }
    for (int i=0;i<maxr;i++) {
        for (int j=0;j<m;j++) printf("%c",ans[i][j]);
        printf("\n");
    }
}

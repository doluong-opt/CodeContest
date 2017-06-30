/***********************************************
* Author - LUONG VAN DO                        *
* Problem 737 - Gleaming the Cubes ->AC
* Algorithm Adhoc
* Time Limit 0.028s
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
#define M 1000

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

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, A, B, C, Ans;
    int X1, Y1, Z1;
    int X2, Y2, Z2;
    int a[M + 1], b[M + 1], c[M + 1], d[M + 1];
    while ( scanf("%d",&n) && n) {
        REP(i, n)
            scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
        X1 = Y1 = Z1 = -INF;
        X2 = Y2 = Z2 = INF;
        REP(i, n) {
            X1 = max(X1, a[i]);
            Y1 = max(Y1, b[i]);
            Z1 = max(Z1, c[i]);
            X2 = min(X2, a[i] + d[i]);
            Y2 = min(Y2, b[i] + d[i]);
            Z2 = min(Z2, c[i] + d[i]);
        }
        A = X2 - X1; B = Y2 - Y1; C = Z2 - Z1;
        Ans = A * B * C;
        if (Ans <= 0) printf("0\n");
        else printf("%d\n",Ans);
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11040 - Add bricks in the wall ->AC
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
#define M 100000

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
int Ans[10][10];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, x;
    scanf("%d",&test);
    FOR(t, 1, test) {
        memset(Ans, 0, sizeof(Ans));
        FOR(i, 1, 5) {
            FOR(j, 1, i) {
                scanf("%d",&x);
                Ans[2 * i - 1][2 * j - 1] = x;
            }
        }
        for (int i=2;i<=8;i+=2)
            Ans[9][i] = (Ans[7][i-1] - (Ans[9][i-1] + Ans[9][i + 1])) >> 1;
        for (int i=8;i>=1;i--)
            for (int j=1;j<=i;j++)
                if (!Ans[i][j]) Ans[i][j] = Ans[i + 1][j] + Ans[i + 1][j + 1];
        FOR(i, 1, 9) {
            FOR(j, 1, i) {
                if (j > 1) printf(" ");
                printf("%d",Ans[i][j]);
            }
            printf("\n");
        }
    }
}

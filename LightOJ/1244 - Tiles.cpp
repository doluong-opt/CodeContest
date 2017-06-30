/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1244 - Tiles ->AC
* Algorithm Adhoc
* Time Limit 0.061s
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
#define MOD 10007
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
int base[4][4];
int ans[4][4];
void init() {
    base[0][0] = 0; base[0][1] = 1; base[0][2] = 0;
    base[1][0] = 0; base[1][1] = 0; base[1][2] = 1;
    base[2][0] = 1; base[2][1] = 0; base[2][2] = 2;
    memset(ans, 0, sizeof(ans));
    for (int i=0;i<3;i++) ans[i][i] = 1;
}
void m1() {
    int temp[4][4];
    memset(temp, 0, sizeof(temp));
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            for (int k=0;k<3;k++) {
                temp[i][j]+=ans[i][k] * base[k][j];
                temp[i][j]%=MOD;
            }
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++) ans[i][j] = temp[i][j];
}
void m2() {
    int temp[4][4];
    memset(temp, 0, sizeof(temp));
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            for (int k=0;k<3;k++) {
                temp[i][j]+=base[i][k] * base[k][j];
                temp[i][j]%=MOD;
            }
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++) base[i][j] = temp[i][j];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, Ans, n;
    int caseno = 0;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d",&n);
        init();
        while ( n ) {
             if (n & 1) m1();
             n>>=1;
             m2();
        }
        Ans = ans[0][0] + ans[0][1] + ans[0][2] * 2;
        Ans%=MOD;
        printf("Case %d: %d\n",++caseno, Ans);
    }
}

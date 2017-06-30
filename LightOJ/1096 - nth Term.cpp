/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1096 - nth Term ->AC
* Algorithm mutiple matrix
* Time Limit 0.002s
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
int ma[5][5], base[5][5];
void init(int a, int b) {
    base[0][0] = 0; base[0][1] = 1; base[0][2] = base[0][3] = 0;
    base[1][0] = 0; base[1][1] = 0; base[1][2] = 1; base[1][3] = 0;
    base[2][0] = b; base[2][1] = 0; base[2][2] = a; base[2][3] = 1;
    base[3][0] = 0; base[3][1] = 0; base[3][2] = 0; base[3][3] = 1;
    memset(ma, 0, sizeof(ma));
    for (int i=0;i<4;i++) ma[i][i] = 1;
}
void mutiple1() {
    int val;
    int temp[5][5];
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++) {
            val = 0;
            for (int k=0;k<4;k++) {
                val+=(ma[i][k] * base[k][j]);
                val%=MOD;
            }
            temp[i][j] = val;
        }
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++) ma[i][j] = temp[i][j];
}
void mutiple2() {
    int val;
    int temp[5][5];
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++) {
            val = 0;
            for (int k=0;k<4;k++) {
                val+=(base[i][k] * base[k][j]);
                val%=MOD;
            }
            temp[i][j] = val;
        }
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++) base[i][j] = temp[i][j];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    int Ans, a, b, c, n;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d %d %d",&n,&a,&b,&c);
        printf("Case %d: ",++caseno);
        init(a, b);
        while ( n ) {
            if (n & 1) mutiple1();
            n>>=1;
            mutiple2();
        }
        Ans = ((ma[0][3] % MOD) * (c % MOD)) % MOD;
        printf("%d\n",Ans);
    }
}

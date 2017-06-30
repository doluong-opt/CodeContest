/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1131 - Just Two Functions ->AC
* Algorithm Adhoc
* Time Limit 0.086s
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
#define N 100000

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
int f[3], g[3];
int base[6][6];
int ans[6][6], M;
void p1() {
    int val;
    int temp[6][6];
    for (int i=0;i<6;i++)
        for (int j=0;j<6;j++) {
            val = 0;
            for (int k=0;k<6;k++) {
                val+=ans[i][k] * base[k][j];
                val%=M;
            }
            temp[i][j] = val;
        }
    for (int i=0;i<6;i++)
        for (int j=0;j<6;j++) ans[i][j] = temp[i][j];
}
void p2() {
    int val;
    int temp[6][6];
    for (int i=0;i<6;i++)
        for (int j=0;j<6;j++) {
            val = 0;
            for (int k=0;k<6;k++) {
                val+=base[i][k] * base[k][j];
                val%=M;
            }
            temp[i][j] = val;
        }
    for (int i=0;i<6;i++)
        for (int j=0;j<6;j++) base[i][j] = temp[i][j];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif  
    int cases, caseno = 0;
    int a1, b1, c1, a2, b2, c2, q, n;
    int64 fn, gn;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d %d %d %d %d",&a1,&b1,&c1,&a2,&b2,&c2);
        scanf("%d %d %d %d %d %d",&f[0],&f[1],&f[2],&g[0],&g[1],&g[2]);
        scanf("%d",&M);
        scanf("%d",&q);
        printf("Case %d:\n",++caseno);
        while (q--) {
            scanf("%d",&n);
            if (n <= 2) printf("%d %d\n",f[n] % M, g[n] % M);
            else {
                n-=2;
                memset(ans, 0, sizeof(ans));
                memset(base, 0, sizeof(base));
                for (int i=0;i<6;i++) ans[i][i] = 1;
                base[0][0] = a1 % M; base[0][1] = b1 % M; base[0][5] = c1 % M;
                base[1][0] = 1; base[2][1] = 1; base[3][2] = c2 % M; base[3][3] = a2 % M;
                base[3][4] = b2 % M; base[4][3] = 1; base[5][4] = 1;
                while ( n ) {
                    if (n & 1) p1();
                    n>>=1;
                    p2();
                }
                fn = f[2] * ans[0][0] + f[1] * ans[0][1] + f[0] * ans[0][2] + g[2] * ans[0][3] + g[1] * ans[0][4] + g[0] * ans[0][5];
                gn = f[2] * ans[3][0] + f[1] * ans[3][1] + f[0] * ans[3][2] + g[2] * ans[3][3] + g[1] * ans[3][4] + g[0] * ans[3][5];
                printf("%lld %lld\n",fn%M, gn%M);
            }
        }
    }
}

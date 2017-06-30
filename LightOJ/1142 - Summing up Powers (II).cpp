/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1142 - Summing up Powers (II) ->AC
* Algorithm matrix
* Time Limit 0.306s
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
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 35

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
struct node{
    int m[N][N];
};
node base[3][3];
node res[3][3];
int a[N][N], n;
node one, zero, A;
void I() {
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++)
            one.m[i][j] = 0;
        one.m[i][i] = 1;
    }
}
void Z() {
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) zero.m[i][j] = 0;
}
void AA() {
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) A.m[i][j] = a[i][j];
}
void build() {
    for (int i=1;i<=2;i++) {
        for (int j=1;j<=2;j++) {
            res[i][j] = zero;
            base[i][j] = zero;
        }
        res[i][i] = one;
    }
    base[1][1] = one; base[2][1] = zero;
    base[1][2] = A; base[2][2] = A;
}
node mutip(node a, node b) {
    node ans;
    int v;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            v = 0;
            for (int k=1;k<=n;k++) {
                v+=(a.m[i][k] * b.m[k][j]);
                v%=10;
            }
            ans.m[i][j] = v;
        }
    }
    return ans;
}
node add(node a, node b) {
    node ans;
    ans = zero;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) {
            ans.m[i][j] = (a.m[i][j] + b.m[i][j]);
            ans.m[i][j]%=10;
        }
    return ans;
}
void c1() {
    node ans;
    node temp[5][5];
    for (int i=1;i<=2;i++) {
        for (int j=1;j<=2;j++) {
            ans = zero;
            for (int k=1;k<=2;k++)
                ans = add(ans, mutip(res[i][k], base[k][j]));
            temp[i][j] = ans;
        }
    }
    for (int i=1;i<=2;i++)
        for (int j=1;j<=2;j++) res[i][j] = temp[i][j];
}
void c2() {
    node ans;
    node temp[5][5];
    for (int i=1;i<=2;i++) {
        for (int j=1;j<=2;j++) {
            ans = zero;
            for (int k=1;k<=2;k++)
                ans = add(ans, mutip(base[i][k], base[k][j]));
            temp[i][j] = ans;
        }
    }
    for (int i=1;i<=2;i++)
        for (int j=1;j<=2;j++) base[i][j] = temp[i][j];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, k, caseno = 0;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d",&n,&k);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
        I(); Z(); AA();
        build();
        while ( k ) {
            if (k & 1) c1();
            k>>=1;
            c2();
        }
        printf("Case %d:\n",++caseno);
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++)
            printf("%d",res[1][2].m[i][j] % 10);
            puts("");
        }
    }
}

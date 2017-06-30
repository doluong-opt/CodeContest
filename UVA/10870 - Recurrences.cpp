/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10870 - Recurrences ->AC
* Algorithm power mutiple
* Time Limit 0.100s
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
#define N 16

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
int64 a[N];
int64 f[N];
int n, m, d;
int64 base[N][N];
int64 res[N][N];
void init() {
    int index;
    memset(base, 0, sizeof(base));
    memset(res, 0, sizeof(res));
    for (int i=0;i<d;i++) res[i][i] = 1;
    for (int i=0;i<d;i++) base[0][i] = a[i] % m;
    int x = 1, y = 0;
    while (x<d && y<d) base[x++][y++] = 1;
    /*for (int i=0;i<d;i++) {
        for (int j=0;j<d;j++)
        cout<<base[i][j]<<" ";
        cout<<endl;
    }*/
}
void c1() {
    int64 temp[N][N], v;
    for (int i=0;i<d;i++) {
        for (int j=0;j<d;j++) {
            v = 0;
            for (int k=0;k<d;k++) {
                v += (base[i][k] * res[k][j]);
                v%=m;
            }
            temp[i][j] = v;
        }
    }
    for (int i=0;i<d;i++)
        for (int j=0;j<d;j++) res[i][j] = temp[i][j];
}
void c2() {
    int64 temp[N][N], v;
    for (int i=0;i<d;i++) {
        for (int j=0;j<d;j++) {
            v = 0;
            for (int k=0;k<d;k++) {
                v += (base[i][k] * base[k][j]);
                v%=m;
            }
            temp[i][j] = v;
        }
    }
    for (int i=0;i<d;i++)
        for (int j=0;j<d;j++) base[i][j] = temp[i][j];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int64 ans;
    while (scanf("%d %d %d",&d,&n,&m) && (d + n + m)) {
        for (int i=0;i<d;i++) scanf("%lld",&a[i]);
        for (int i=0;i<d;i++) scanf("%lld",&f[i]);
        init();
        if (n <= d) {
            printf("%lld\n",f[n-1] % m);
            continue;
        }
        n-=d; ans = 0;
        while ( n ) {
            if (n & 1) c1();
            n>>=1;
            c2();
        }
        for (int i=0;i<d;i++) {
            ans+=(f[d-i-1] * res[0][i]);
            ans%=m;
        }
        printf("%lld\n",ans);
    }
}

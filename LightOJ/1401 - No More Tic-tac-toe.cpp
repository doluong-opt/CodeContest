/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1401 - No More Tic-tac-toe ->AC 
* Algorithm gundy function
* Time Limit 0.011s
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
#define N 110

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
char s[N];
int n;
int f[4][N], mark[N];

void reset() {
    for (int i=0;i<=100;i++) mark[i] = 0;
}

void build_f() {
    int g;
    memset(f, 0, sizeof(f));
    for (int k=1;k<=100;k++) {
        
        // compute - f[0][k];
        reset();
        for (int i=0;i<k;i++) mark[ f[1][i] ^ f[1][k-i-1] ] = 1;
        for (int i=1;i<k-1;i++) mark[ f[0][i] ^ f[0][k-i-1] ] = 1;
        g = 0;
        while ( mark[g] ) g++;
        f[0][k] = g;
        
        // compute - f[1][k];
        reset();
        for (int i=0;i<k-1;i++) mark[ f[1][i] ^ f[0][k-i-1] ] = 1;
        for (int i=1;i<k;i++) mark[ f[0][i] ^ f[1][k-i-1] ] = 1;
        g = 0;
        while ( mark[g] ) g++;
        f[1][k] = g;
        
        // compute - f[2][k];
        reset();
        for (int i=0;i<k;i++) mark[ f[1][i] ^ f[2][k-i-1] ] = 1;
        for (int i=1;i<k;i++) mark[ f[0][i] ^ f[2][k-i-1] ] = 1;
        g = 0;
        while ( mark[g] ) g++;
        f[2][k] = g;
        
        // compute - f[3][k];
        reset();
        for (int i=0;i<k;i++) mark[ f[2][i] ^ f[2][k-i-1] ] = 1;
        g = 0;
        while ( mark[g] ) g++;
        f[3][k] = g;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, cnt, caseno = 0, nim, p;
    char pre;
    build_f();
    scanf(" %d ",&cases);
    while (cases--) {
        gets(s); n = strlen(s);
        pre = '.'; cnt = nim = p = 0;
        for (int i=0;i<n;i++) {
            if (s[i] == '.') p++;
            else {
                cnt++;
                if (pre == '.') nim^=f[2][p];
                else
                if (s[i] == pre) nim^=f[0][p];
                else nim^=f[1][p];
                p = 0;
                pre = s[i];
            }
        }
        nim^=f[2][p]; printf("Case %d: ",++caseno);
        if (!cnt && !f[3][n]) puts("No");
        else
        if (!cnt && f[3][n]) puts("Yes");
        else
        if ( cnt % 2 == 0) {
            if (nim) puts("Yes");
            else puts("No");
        }
        else {
            if (nim) puts("No");
            else puts("Yes");
        }
    }
}

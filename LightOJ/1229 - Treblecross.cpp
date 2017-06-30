/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1229 - Treblecross ->AC
* Algorithm grundy function
* Time Limit 0.020s
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
#define N 210

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
int f[2][N], mark[N];
char s[N];
int n;
void reset() {
    for (int i=0;i<=200;i++) mark[i] = 0;
}
void build_f() {
    int g;
    memset(f, 0, sizeof(f));
    
    for (int k=1;k<=200;k++) {
        // compute - f[0][k]
        reset();
        for (int i=2;i<k-2;i++) mark[ f[0][i] ^ f[0][k-i-1] ] = 1;
        g = 0;
        while ( mark[g] ) g++;
        f[0][k] = g;
        
        // compute - f[1][k]
        reset();
        for (int i=2;i<k;i++) mark[ f[0][i] ^ f[1][k-i-1] ] = 1;
        for (int i=0;i<k-2;i++) mark[ f[1][i] ^ f[0][k-i-1] ] = 1;
        g = 0;
        while ( mark[g] ) g++;
        f[1][k] = g;
        
    }
}
bool win(int pos) {
    
    /*if (pos > 0 && pos < n - 1 && s[pos - 1] == 'X' && s[pos + 1] == 'X') return true;
    if (pos < n - 1 && s[pos + 1] == 'X' && s[pos + 2] == 'X') return true;
    if (pos > 1 && s[pos - 1] == 'X' && s[pos - 2] == 'X') return true;
    
    if (pos > 0 && s[pos - 1] == 'X') return false;
    if (pos < n - 1 && s[pos + 1] == 'X') return false;
    if (pos > 1 && pos < n - 2 && s[pos - 2] == 'X' || s[pos + 2] == 'X') return false;*/
    
    s[pos] = 'X';
    for (int i=0;i<n - 2;i++)
        if (s[i] == 'X' && s[i + 1] == 'X' && s[i + 2] == 'X') {
            s[pos] = '.';
            return true;
        }
    for (int i=0;i<n - 1;i++)
        if (s[i] == 'X' && s[i + 1] == 'X') {
            s[pos] = '.';
            return false;
        }
    for (int i=0;i<n - 2;i++)
        if (s[i] == 'X' && s[i + 2] == 'X') {
            s[pos] = '.';
            return false;
        }
    char pre = '.';
    int nim = 0, p = 0, ff = 0;
    for (int i=0;i<n;i++) {
        if ( s[i] == '.' ) p++;
        else {
            if (pre == '.')
                nim^=f[1][p];
            else
                nim^=f[0][p];
            p = 0;
            pre = s[i];
        }
    }
    s[pos] = '.';
    nim^=f[1][p];
    return (nim == 0);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, ff, tt;
    build_f();
    scanf(" %d ",&cases);
    while (cases--) {
        gets(s); n = strlen(s);
        printf("Case %d:",++caseno);
        ff = 0;
        for (int i=1;i<=n;i++)
            if (s[i - 1] == '.' && win(i - 1) ) {
                printf(" %d",i);
                ff = 1;
            }
        if (!ff) printf(" 0\n");
        else printf("\n");
    }
}
